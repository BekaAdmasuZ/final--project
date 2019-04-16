#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>


struct Property{

};

struct Player{
  int money;
  vector <Property *> owned;
};



class Monopoly{
  public:
    int rollDice();
    void addplayer(string name);

};
