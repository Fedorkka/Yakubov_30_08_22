#include "RepairStation.h"

RepairStation::RepairStation(int x, int y):Dot(x, y) {
    //ctor
}
double RepairStation::get_distance(Generator* g) {
    return Dot::get_distance(g)*g->LVL();
}
void RepairStation::repos() {
    int sum_xm=0, sum_ym=0, sum_m=0;
    if(_generators.size()!=0) {
        for(auto& it: _generators) {
            sum_xm+=it->X()*it->LVL();
            sum_ym+=it->Y()*it->LVL();
            sum_m+=it->LVL();
        }
        _pos[0]= sum_xm/sum_m;
        _pos[1]= sum_ym/sum_m;
    }
}

RepairStation::~RepairStation() {}
RepairStation::RepairStation() {}
