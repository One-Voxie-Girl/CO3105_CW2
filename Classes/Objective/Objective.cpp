#include "Objective.h"

Objective::Objective(string type, vector<string> targets){
    this->type = type;
    this->targets = targets;
}


bool Objective::check_obj(Player player){
    if (targets.empty()){
        cout<<"no remaining objectives to fufill"<<endl;
        return true;
    }
    return false;
}

string Objective::get_type(){
    return type;
}

vector<string> Objective::get_targets() {
    return targets;
}

bool Objective::remove_target(string tar) {
    for (int i = 0; i < targets.size(); i++) {
        if (targets.at(i) == tar) {
            targets.erase(targets.begin());
            return true;
        }
    }
    return false;
}

