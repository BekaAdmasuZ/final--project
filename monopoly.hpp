#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP
// #pragma once


#include <string>
#include <vector>


struct Property{
  Property* next;
  std::string name;
  std::string color;
  int retail;
  int rent;
  int house;
  int house2;
  int house3;
  int hotel;
  int costHouse;
  int costHotel;
  int Freepark;
  bool owned;
  bool cc;
  bool chance;
  bool jail;
  bool GO;
  bool EX;
  bool tax;
  int xIndex;
  int yIndex;
};

struct Player{
  int money;
  std::vector <Property *> owned;
  std::string name;
  int doublesRolled;
  bool jail;
};

class Monopoly{
  public:
    Monopoly();
    ~Monopoly();
    int rollDice();
    bool isEmpty();
    void addmatrix();
    void printBoard();
    bool isFull();
    void isTurn();//keeps track of palyers turn and what the rolled on the dice and everything!
    void addplayer(std::string name);//enque
    void removeplayer(std::string name);//deque
    void addProperty(std::string title, std::string color, int initialCost, int land, int h1,int h2, int h3, int hh, int hc, int hhc);//use a hashtable for property
    void addlinkedlist(std::string name_,std::string color_,int retail_,int rent_,int house_,int house2_,int house3_,int hotel_,int costHouse_,int costHotel_,bool cc_,bool chance_,bool jail_,int Freepark_,bool GO_,bool EX_,bool tax_,bool owned_,int xIndex_,int yIndex_);
  private:
    // head of the linked list goes here
    Property * head;
    Property *tail;
    // prev->next=head;
    Property matrix[11][11];

    int Front;             // the index in queue[] that will be dequeued next
    int End;               // the index in queue[] that was most recently enqueued
    std::string playerarray[8];

};
#endif
