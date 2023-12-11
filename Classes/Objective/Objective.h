//
// Created by onevo on 11/12/2023.
//

#ifndef CO3105_CW2_OBJECTIVE_H
#define CO3105_CW2_OBJECTIVE_H

#include <iostream>
#include <string>
#include "../Player/Player.h"




class Objective {

public:
    Objective(string type, vector<string> targets);
    bool check_obj(Player player);
    string get_type();
    vector<string> get_targets();
    bool remove_target(string tar);


private:
    string type;
    vector<string> targets;


};


#endif //CO3105_CW2_OBJECTIVE_H
