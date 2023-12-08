#include "player_choice.h"

Map player_choice(Map map) {
    string playerInput;
    cout << "What do you want to do?" << endl;
    getline(cin, playerInput);
    cout << playerInput;
    return map;
}