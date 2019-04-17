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
  string name;
};

struct Player{
  int money;
  vector <Property *> owned;
  int doublesRolled;
  bool jail;
};


<<<<<<< HEAD
=======

>>>>>>> 89ea52d8ffe9e9dd28eb0b0641091f82795d4617
class Monopoly{
  public:
    Monopoly();
    ~Monopoly();
    int rollDice();
    void addplayer(string name);//enque
    void removeplayer(string name);//deque
    void addProperty(string title, string color, int initialCost, int land, int h1,int h2, int h3, int hh, int hc, int hhc,);
    


  private:
    // head of the linked list goes here
    Property * GO;
    Property * Tail;

};
