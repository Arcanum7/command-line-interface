#include "commandProcessor.h"
#include "commandProcessorSimulator.h"

static void testFunc(CommandProcessor *processor, void *arg) {
    processor->response("this is really cool!\n");
}

int main(int argc, char *argv[]) {
    CommandProcessorSimulator simulator;
    CommandProcessor processor(&simulator);

    simulator.setProcessor(&processor);

    processor.registerCommand("test", testFunc, nullptr);

    while(1);
}
