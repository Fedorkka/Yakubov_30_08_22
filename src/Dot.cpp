#include "Dot.h"

Dot::Dot(int x, int y) {
    _pos[0]= x;
    _pos[1]= y;
}

Dot::Dot() {}

Dot::~Dot() {
    //dtor
}

int Dot::X() {
    return _pos[0];
}

int Dot::Y() {
    return _pos[1];
}
double Dot::get_distance(Dot* d) {
    return sqrt((d->X()-X())*(d->X()-X())+(d->Y()-Y())*(d->Y()-Y()));
}
