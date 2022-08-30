#ifndef GENERATOR_H
#define GENERATOR_H

#include <Dot.h>


class Generator : public Dot {
public:
    Generator(int x, int y, int lvl);
    Generator();
    virtual ~Generator();
    int LVL();

protected:

private:
    int _lvl;
};

#endif // GENERATOR_H
