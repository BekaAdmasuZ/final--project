#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>


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

};
struct Player{
  int money;
  vector <Property *> owned;
};


class Monopoly{
  public:
    Monopoly();
    ~Monopoly();
    int rollDice();
    void addplayer(string name);//enque
    void removeplayer(string name);//deque


  private:
    // head of the linked list goes here

};
