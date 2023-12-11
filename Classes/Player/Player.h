#ifndef CO3105_CW2_PLAYER_H
#define CO3105_CW2_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "../Item/Item.h"


using namespace std;

class Player {
public:
    Player(string room);
    string set_room(string room);
    string get_room();
    bool add_item(Item item);
    bool remove_item(Item item);
    vector<Item> get_items();
    string print();
    bool set_health(int inputHealth);
    int get_health();



private:
    string room;
    vector<Item> items;
    int health = 1;
};


#endif //CO3105_CW2_PLAYER_H
