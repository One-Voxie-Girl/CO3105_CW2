cmake_minimum_required(VERSION 3.26)
project(CO3105_CW2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CO3105_CW2 main.cpp
        map_parser.cpp
        map_parser.h
        Classes/Enemy/Enemy.cpp
        Classes/Enemy/Enemy.h
        Classes/Map/Map.cpp
        Classes/Map/Map.h
        Classes/Objective/Objective.cpp
        Classes/Objective/Objective.h
        Classes/Player/Player.cpp
        Classes/Player/Player.h
        Classes/Room/Room.cpp
        Classes/Room/Room.h
        Classes/Item/Item.cpp
        Classes/Item/Item.h
        player_choice.cpp
        player_choice.h
        Classes/Objective/Objective.cpp
)
