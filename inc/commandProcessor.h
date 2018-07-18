/*
 * Command-line Processor
 * Copyright (C) 2018 AllThingsEmbedded
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include "commandProcessorInterface.h"
#include "command.h"
#include <string>
#include <vector>

class CommandProcessor {
public:
    CommandProcessor(CommandProcessorInterface *interface);
    void registerCommand(std::string name, command_t command, void* arg);
private:
    CommandProcessorInterface *interface;
    std::string buffer;
    std::vector<Command> commands;
protected:
    int parseCommand(std::string name);
    int receiveCharacter(char character);
    friend class CommandProcessorInterface;
};

#endif
