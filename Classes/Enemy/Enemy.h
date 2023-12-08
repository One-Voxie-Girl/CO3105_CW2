//
// Created by Temmie on 28/11/2023.
//
#ifndef CO3105_CW2_ENEMY_H
#define CO3105_CW2_ENEMY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Enemy {
public:
    Enemy(string id, string desc, int aggression, vector<string> killedBy);
    bool set_id(string id);
    bool set_desc(string desc);
    bool set_aggression(int aggression);
    bool set_killedBy(vector<string> killedBy);
    string get_id();
    string get_desc();
    int get_aggression();
    vector<string> get_killedBy();
    string print();

private:
    string id;
    string desc;
    int aggression;
    vector<string> killedBy;
};


#endif //CO3105_CW2_ENEMY_H
