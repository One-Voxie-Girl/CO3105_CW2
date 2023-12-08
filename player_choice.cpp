#include "player_choice.h"

Map player_choice(Map map) {
    string playerInput;
    string input1;
    string input2;

    cout << "What do you want to do?" << endl;
    getline(cin, playerInput);
    transform(playerInput.begin(), playerInput.end(), playerInput.begin(), ::tolower);
    istringstream inputStream(playerInput);
    inputStream >> input1 >> input2;
    while(!inputStream.eof()) {
        input2 += " ";
        string tempInput;
        inputStream >> tempInput;
        input2 += tempInput;
    } // Splits the input string into the command and the parameter
    cout << input1 << endl << input2;
    return map;
}