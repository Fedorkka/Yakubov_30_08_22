#ifndef REPAIRSTATION_H
#define REPAIRSTATION_H

#include <Dot.h>
#include <Generator.h>
#include <vector>
#include <algorithm>
using namespace std;
class RepairStation : public Dot {
public:
    RepairStation(int x, int y);
    RepairStation();
    double get_distance(Generator* g);
    void repos();
    virtual ~RepairStation();
    vector<Generator*> _generators;

protected:

private:
};

#endif // REPAIRSTATION_H
