#include "Generator.h"

Generator::Generator(int x, int y, int lvl):Dot(x, y) {
    _lvl= lvl;
}
Generator::Generator() {}
int Generator::LVL() {
    return _lvl;
}

Generator::~Generator() {
    //dtor
}
