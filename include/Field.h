#ifndef FIELD_H
#define FIELD_H
#include "RepairStation.h"
#include "Generator.h"
#include <random>
#include <time.h>
#include <iostream>
class Field {
public:
    int size_x();
    int size_y();
    void random_fill(int dots_count);
    int get_gen_count();
    int get_stations_count();
    int get_station_pos_x(int index);
    int get_stations_pos_y(int index);

    Generator get_claster(int repair_station_index,int index);
    int get_claster_size(int repair_station_index);
    Field(int size_x, int size_y, int max_lvl);
    void k_means_init(int k);
    bool k_means_step();
    virtual ~Field();
    int get_gen_pos_x(int index);
    int get_gen_pos_y(int index);
    int get_gen_lvl(int index);

protected:
private:
    Generator get_gen(int index);
    void random_cent();
    RepairStation* _stations;
    Generator* _generators;
    int _size[2];
    int _max_lvl, _gen_count, _stations_count;
};

#endif // FIELD_H
