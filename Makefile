##
## Command-line Processor
## Copyright (C) 2018 AllThingsEmbedded
## 
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

BUILD_DIR := build
TARGET := clp

SRC_FILES := \
    src/command.cpp \
    src/commandProcessor.cpp \
    src/commandProcessorInterface.cpp \
    src/commandProcessorSimulator.cpp \
    src/main.cpp

INC_DIRS := \
    -I./inc

LIB_DIRS :=
LIBS := -lstdc++

WARNING_FLAGS := -Wall -Werror 
CFLAGS := $(INC_DIRS)
STD := -std=c++17


# Target Definition
OBJECTS := $(addprefix $(BUILD_DIR)/,$(patsubst %.cpp,%.o, $(SRC_FILES)))
$(BUILD_DIR)/%.o: %.cpp Makefile
	mkdir -p $(dir $@)
	g++ -c $(WARNING_FLAGS) $(CFLAGS) $(STD) -o $@ $<

$(BUILD_DIR)/$(TARGET): $(OBJECTS) 
	gcc -o $@ $^ $(LIBS)

all: $(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
