//
// Created by Temmie on 28/11/2023.
//

#ifndef CO3105_CW2_MAP_H
#define CO3105_CW2_MAP_H


#include "../Room/Room.h"
#include <vector>
#include <iostream>

using namespace std;

class Map {

public:
    Map();
    int get_room_count();
    bool add_room(Room room);
    Room get_room(string id);
    int get_room_id(string id);
    string print();
    vector<Room> rooms;
private:
    int room_count;
    map<string, int> room_ids;
};


#endif //CO3105_CW2_MAP_H
