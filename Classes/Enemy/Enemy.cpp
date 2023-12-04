//
// Created by Temmie on 28/11/2023.
//

#include "Enemy.h"

Enemy::Enemy() {
    aggression = 0;
}

bool Enemy::set_id(string id) {
    this->id = id;
    return true;
}

bool Enemy::set_desc(string desc) {
    this->desc = desc;
    return true;
}

bool Enemy::set_aggression(int aggression) {
    this->aggression = aggression;
    return true;
}

bool Enemy::set_killedBy(vector<string> killedBy) {
    this->killedBy = killedBy;
    return true;
}

string Enemy::get_id() {
    return id;
}

string Enemy::get_desc() {
    return desc;
}

int Enemy::get_aggression() {
    return aggression;
}

vector<string> Enemy::get_killedBy() {
    return killedBy;
}

string Enemy::print() {
    string output = "";
    output += "Enemy Name: "+id+"\n";
    output += "Description: "+desc+"\n";
    output += "Aggression: "+to_string(aggression)+"\n";
    output += "Killed By: "+to_string(killedBy.size())+"\n";
    for (int i = 0; i < killedBy.size(); i++) {
        output += killedBy.at(i) + "\n";
    }
    return output;
}