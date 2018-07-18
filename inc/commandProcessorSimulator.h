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

#ifndef COMMAND_PROCESSOR_SIMULATOR_H
#define COMMAND_PROCESSOR_SIMULATOR_H

#include "commandProcessorInterface.h"
#include <thread>
#include <string>

class CommandProcessorSimulator: public CommandProcessorInterface {
public: 
    CommandProcessorSimulator();
    ~CommandProcessorSimulator();
    virtual int asyncWrite(std::string str);
private:
    std::thread thread;
    bool runThread;
    static void mainThreadFunction(CommandProcessorSimulator *intf);
};

#endif
