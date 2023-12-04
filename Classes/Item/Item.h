//
// Created by Temmie on 28/11/2023.
//


#ifndef CO3105_CW2_ITEM_H
#define CO3105_CW2_ITEM_H

#include <iostream>
#include <string>

using namespace std;


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
