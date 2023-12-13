#ifndef CO3105_CW2_MAP_H
#define CO3105_CW2_MAP_H


#include "../Room/Room.h"
#include "../Objective/Objective.h"
#include <vector>
#include <iostream>

using namespace std;

class Map {

public:
    Map(Player player, Objective objective);
    int get_room_count();
    bool add_room(Room room);
    Room get_room(string id);
    int get_room_id(string id);
    bool add_player(Player player);
    string print();
    bool add_objective(Objective objective);
    vector<Room> rooms;
    Player player;
    Objective objective;
private:
    int room_count;
    map<string, int> room_ids;


};


#endif //CO3105_CW2_MAP_H
