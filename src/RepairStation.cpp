#include "RepairStation.h"

RepairStation::RepairStation(int x, int y):Dot(x, y) {
    //ctor
}
double RepairStation::get_distance(Generator* g) {
    return Dot::get_distance(g)*g->LVL();
}
void RepairStation::repos() {
    int sum_x=0, sum_y=0;
    if(_generators.size()!=0) {
        for(auto& it: _generators) {
            sum_x+=it->X();
            sum_y+=it->Y();
        }
        _pos[0]= sum_x/_generators.size();
        _pos[1]= sum_y/_generators.size();
    }
}

RepairStation::~RepairStation() {}
RepairStation::RepairStation() {}
