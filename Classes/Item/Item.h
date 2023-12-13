#ifndef CO3105_CW2_ITEM_H
#define CO3105_CW2_ITEM_H

#include <iostream>
#include <string>

using namespace std;


class Item {
public:
    Item(string id, string desc, string type);
    bool set_id(string id);
    bool set_desc(string desc);
    bool set_type(string type);
    string get_id();
    string get_desc();
    string get_type();
    string print();



private:
    string id;
    string desc;
    string type;
};


#endif //CO3105_CW2_ITEM_H
