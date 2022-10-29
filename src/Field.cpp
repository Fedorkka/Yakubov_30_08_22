#include "Field.h"

Field::Field(int size_x, int size_y, int max_lvl) {
    _size[0]= size_x;
    _size[1]= size_y;
    _max_lvl= max_lvl;
    srand(time(nullptr));
}

Field::~Field() {
    //dtor
}
void Field::random_fill(int dots_count) {
    int x, y, lvl;
    _gen_count= dots_count;
    _generators= new Generator[_gen_count];
    for(int i=0; i<dots_count; i++) {
        x= rand()%(_size[0]+1);
        y= rand()%(_size[1]+1);
        lvl= rand()%_max_lvl+1;
        _generators[i]= Generator(x, y, lvl);
    }
}

int Field::get_gen_count() {
    return _gen_count;
}

Generator Field::get_gen(int index) {
    return _generators[index];
}

int Field::size_x() {
    return _size[0];
}
int Field::size_y() {
    return _size[1];
}
void Field::random_cent() {
    int x, y, min_x, min_y, max_x, max_y;
    for(int i= 0; i<_gen_count; i++) {
        if(i == 0) {
            min_x= _generators[i].X();
            min_y= _generators[i].Y();
            max_x= _generators[i].X();
            max_y= _generators[i].Y();
        } else {
            if(_generators[i].X()<min_x) {
                min_x= _generators[i].X();
            }
            if(_generators[i].X()>max_x) {
                max_x= _generators[i].X();
            }
            if(_generators[i].Y()<min_y) {
                min_y= _generators[i].Y();
            }
            if(_generators[i].Y()>max_y) {
                max_y= _generators[i].Y();
            }
        }
    }
    _stations= new RepairStation[_stations_count];
    for(int i=0; i<_stations_count; i++) {
        x= min_x+rand()%(max_x-min_x);
        y= min_y+rand()%(max_y-min_y);
        _stations[i]= RepairStation(x, y);
    }
}

void Field::k_means_init(int k) {
    _stations_count= k;
    random_cent();
}
bool Field::k_means_step(){
    int dist, min_dist, min_index;
    static bool changed= true;
    int centroid[2];
    if(!changed){
        return changed;
    }
    changed= false;
    for(int i= 0; i<_stations_count; i++){
        _stations[i]._generators.clear();
    }
    for(int i=0; i<_gen_count; i++) {
        for(int j =0; j<_stations_count; j++) {
            dist= _stations[j].get_distance(&_generators[i]);
            if(j==0) {
                min_dist= dist;
                min_index= j;
            } else if(dist<min_dist) {
                min_dist= dist;
                min_index= j;
            }
        }
        _stations[min_index]._generators.push_back(&_generators[i]);
    }
    for(int i =0; i<_stations_count; i++) {
        centroid[0]= _stations[i].X();
        centroid[1]= _stations[i].Y();
        _stations[i].repos();
        if(centroid[0]!=_stations[i].X()||centroid[1]!=_stations[i].Y()){
            changed= true;
        }
    }
    return changed;

}
Generator Field::get_claster(int repair_station_index, int index) {
    return *_stations[repair_station_index]._generators.at(index);
}
int Field::get_claster_size(int repair_station_index) {
    return _stations[repair_station_index]._generators.size();
}
int Field::get_stations_count() {
    return _stations_count;
}
int Field::get_station_pos_x(int index) {
    return _stations[index].X();
}
int Field::get_stations_pos_y(int index) {
    return _stations[index].Y();
}
int Field::get_gen_pos_x(int index) {
    return _generators[index].X();
}
int Field::get_gen_pos_y(int index) {
    return _generators[index].Y();
}
int Field::get_gen_lvl(int index) {
    return _generators[index].LVL();
}






