//
// Created by Temmie on 28/11/2023.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef CO3105_CW2_ITEM_H
#define CO3105_CW2_ITEM_H


class Item {
public:
    Item();
    bool set_id(string id);
    bool set_desc(string desc);
    string get_id();
    string get_desc();
    string print();



private:
    string id;
    string desc;
};


#endif //CO3105_CW2_ITEM_H
