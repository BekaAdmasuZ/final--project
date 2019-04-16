#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>


struct Property{

};

struct Player{
  int money;
  vector <Property *> owned;
  int doublesRolled;
};



class Monopoly{
  public:
    int rollDice();
    void addplayer(string name);//enque
    void removeplayer(string name);//deque


  private:
    // head of the linked list goes here

};
