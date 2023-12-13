//
// Created by Temmie on 28/11/2023.
//

#include "Item.h"

Item::Item(string id, string desc,string type) {
    this->id = id;
    this->desc = desc;
    this->type = type;

}

bool Item::set_id(string id) {
    this->id = id;
    return true;
}

bool Item::set_desc(string desc) {
    this->desc = desc;
    return true;
}

string Item::get_id() {
    return id;
}

string Item::get_desc() {
    return desc;
}

string Item::print() {
    string output = "";
    output += "Item: "+id+"\n";
    output += "Desc: "+desc+"\n";
    return output;
}

bool Item::set_type(string type) {
    this->type = type;
    return true;
}

string Item::get_type() {
    return type;
}


