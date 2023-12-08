//
// Created by Temmie on 28/11/2023.
//

#include "Player.h"

Player::Player() {

}

string Player::set_room(string room) {
    this->room = room;
    return room;
}

string Player::get_room() {
    return room;
}

bool Player::add_item(Item item) {
    items.push_back(item);
    return true;
}

bool Player::remove_item(Item item) {
    for (int i = 0; i < items.size(); i++) {
        if (items.at(i).get_id() == item.get_id()) {
            items.erase(items.begin()+i);
            return true;
        }
    }
    return false;
}

vector<Item> Player::get_items() {
    return items;
}

string Player::print() {
    string output = "";
    output += "Player: "+room+"\n";
    output += "Items: "+to_string(items.size())+"\n";
    for (int i = 0; i < items.size(); i++) {
        output += items.at(i).print() + "\n";
    }
    return output;
}