#include "commandProcessor.h"

#if 0
#define LOG(format, ...) printf(format, __VA_ARGS__);
#else
#define LOG(...)
#endif

CommandProcessor::CommandProcessor(CommandProcessorInterface *intf) {
    interface = intf;
}

int CommandProcessor::parseCommand(const std::string &name) {
    LOG("%s:\tparsing command %s\n", __func__, name.c_str());
    bool found = false;
    for (Command command : commands) {
        if (command.match(name)) {
            command.execute();
            found = true;
            break;
        }
    }
    if (!found) interface->asyncWrite("Couldn't find command\n");
    return 0;
}

int CommandProcessor::receiveCharacter(char character) {
    if (character == '\n') {
        parseCommand(buffer);    
        buffer.clear();
    } else {
        LOG("%s:\treceived %c\n", __func__, character);
        buffer.push_back(character);
    }
    return 0;
}

void CommandProcessor::registerCommand(const std::string &name, command_t command, void *arg) {
    // register command inside the command vector
    commands.push_back(Command(command, name, this, arg));
}

void CommandProcessor::response(const std::string &str) {
    interface->asyncWrite(str);
}
