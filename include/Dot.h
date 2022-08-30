#ifndef DOT_H
#define DOT_H
#include <math.h>

class Dot {
public:
    Dot(int x, int y);
    virtual ~Dot();
    int X();
    int Y();
    double get_distance(Dot* d);

protected:
    Dot();
    int _pos[2];
private:

};

#endif // DOT_H
