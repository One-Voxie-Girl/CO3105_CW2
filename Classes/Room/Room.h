//
// Created by Temmie on 28/11/2023.
//
#ifndef CO3105_CW2_ROOM_H
#define CO3105_CW2_ROOM_H

#include <iostream>
#include <string>
#include "../../json.hpp"
#include "../Enemy/Enemy.h"
#include "../Item/Item.h"
#include "../Player/Player.h"

using namespace std;
using json = nlohmann::json;


class Room {
public:

    Room(string id, string desc,map<string, string> exits);
    bool set_id(string id);
    bool set_desc(string desc);
    bool set_exits(json exits);
    map<string, string> get_exits();
    string get_id();
    bool add_enemy(Enemy enemy);
    bool add_item(Item item);
    Item pop_item(string id);
    Enemy pop_enemy(string id);
    vector<Item> get_items();
    vector<Enemy> get_enemies();
    string print();
    string get_exit(string direction);
    string get_desc();


private:
    string id;
    string desc;
    map<string, string> exits;
    vector<Enemy> enemies;
    vector<Item> items;

};


#endif //CO3105_CW2_ROOM_H
