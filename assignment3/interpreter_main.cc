#include "interpreter.h"

int main() {
    Interpreter interp;
    interp.loadFromFile("program.bc");
    interp.run();
    return 0;
}