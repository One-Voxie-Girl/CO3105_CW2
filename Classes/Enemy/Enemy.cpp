//
// Created by Temmie on 28/11/2023.
//

#include "Enemy.h"

Enemy::Enemy(string id, string desc, int aggression, vector<string> killedBy) {
    this->id = id;
    this->desc = desc;
    this->aggression = aggression;
    this->killedBy = killedBy;
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

vector<string> Enemy::get_killed_by() {
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