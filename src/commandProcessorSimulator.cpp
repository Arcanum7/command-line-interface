#include "commandProcessorSimulator.h"
#include "commandProcessor.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <stdio.h>

void CommandProcessorSimulator::mainThreadFunction(CommandProcessorSimulator *intf) {
    std::cout << "Starting CommandProcessorSimulator" << std::endl;
    intf->runThread = true;
    while(intf->runThread) {
        // Do character reading and parsing here and pass execution to the command parser later.
        char character = getc(stdin);
        intf->receiveCharacter(character);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

CommandProcessorSimulator::CommandProcessorSimulator() {
    thread = std::thread(CommandProcessorSimulator::mainThreadFunction, this);
}

CommandProcessorSimulator::~CommandProcessorSimulator() {
    runThread = false;
}

int CommandProcessorSimulator::asyncWrite(std::string str) {
    std::cout << str << std::endl;
    return 0;
}
