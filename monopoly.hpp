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

const int SIZE =8;
class Monopoly{
  public:
    Monopoly();
    ~Monopoly();
    int rollDice();
    bool isEmpty();
    bool isFull();
    void addplayer(string name);//enque
    void removeplayer(string name);//deque
    void addProperty(string title, string color, int initialCost, int land, int h1,int h2, int h3, int hh, int hc, int hhc,);


  private:
    // head of the linked list goes here
    Property * GO;
    Property * Tail;

    int Front;             // the index in queue[] that will be dequeued next
    int End;               // the index in queue[] that was most recently enqueued
    std::string playerarray[SIZE];

};
