//
// Created by Temmie on 28/11/2023.
//
#include <iostream>
#include <string>
#include "../../json.hpp"
#include "../Enemy/Enemy.h"

using namespace std;
using json = nlohmann::json;

#ifndef CO3105_CW2_ROOM_H
#define CO3105_CW2_ROOM_H


class Room {
public:
    Room();
    bool set_id(string id);
    bool set_desc(string desc);
    bool set_exits(json exits);
    string get_id();
    bool add_enemy(Enemy enemy);
    vector<Enemy> get_enemies();
    string print();

private:
    string id;
    string desc;
    json exits;
    vector<Enemy> enemies;
};


#endif //CO3105_CW2_ROOM_H
