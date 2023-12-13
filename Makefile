CXX = g++

CXXFLAGS = -std=c++17

main: main.cpp Enemy.o Item.o Player.o Room.o Map.o Objective.o map_parser.o player_choice.o
	$(CXX) $(CXXFLAGS) main.cpp Enemy.o Item.o Player.o Room.o Map.o Objective.o map_parser.o player_choice.o -o main

Enemy.o: Classes\Enemy\Enemy.cpp Classes\Enemy\Enemy.h
	$(CXX) $(CXXFLAGS) -c Classes\Enemy\Enemy.cpp -o Enemy.o

Item.o: Classes\Item\Item.cpp Classes\Item\Item.h
	$(CXX) $(CXXFLAGS) -c Classes\Item\Item.cpp -o Item.o

Player.o: Classes\Player\Player.cpp Classes\Player\Player.h
	$(CXX) $(CXXFLAGS) -c Classes\Player\Player.cpp -o Player.o

Room.o: Classes\Room\Room.cpp Classes\Room\Room.h
	$(CXX) $(CXXFLAGS) -c Classes\Room\Room.cpp -o Room.o

Map.o: Classes\Map\Map.cpp Classes\Map\Map.h
	$(CXX) $(CXXFLAGS) -c Classes\Map\Map.cpp -o Map.o

Objective.o: Classes\Objective\Objective.cpp Classes\Objective\Objective.h
	$(CXX) $(CXXFLAGS) -c Classes\Objective\Objective.cpp -o Objective.o

map_parser.o: map_parser.cpp map_parser.h
	$(CXX) $(CXXFLAGS) -c map_parser.cpp -o map_parser.o

player_choice.o: player_choice.cpp player_choice.h
	$(CXX) $(CXXFLAGS) -c player_choice.cpp -o player_choice.o


deepclean:
	rm -f *.o main main.exe *.stackdump