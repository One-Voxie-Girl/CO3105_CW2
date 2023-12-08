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
    Room();
    bool set_id(string id);
    bool set_desc(string desc);
    bool set_exits(json exits);
    string get_id();
    bool add_enemy(Enemy enemy);
    bool add_item(Item item);
    bool add_player(Player player);
    Player get_player();
    vector<Item> get_items();
    vector<Enemy> get_enemies();
    string print();

private:
    string id;
    string desc;
    json exits;
    vector<Enemy> enemies;
    vector<Item> items;
    Player player;
};


#endif //CO3105_CW2_ROOM_H
