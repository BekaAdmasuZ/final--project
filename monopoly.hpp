#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>



struct Player{
  int money;

}
struct Property{
Property* next;
int retail;
int rent;
int house;
int house2;
int house3;
int hotel;
int costHouse;
int costHotel;
bool owned;
string color;

}


class Monopoly{
  public:
    int rollDice();
    void addplayer(string name);

}
