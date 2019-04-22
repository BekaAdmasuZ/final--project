
#ifndef GRAPH_HPP
#define GRAPH_HPP
// #pragma once


#include <string>

#include <queue>

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
  std::queue<char>currPla;
};

struct Player{
  char C;
  std::string name;
  int money;
  std::vector <Property *> owned;
  int doublesRolled;
  int x;
  int y;
  bool jail;
};

class Monopoly{
  public:
    Monopoly();
    ~Monopoly();
    int rollDice();
    // bool isEmpty();
    // bool isFull();
    // void isTurn();//keeps track of palyers turn and what the rolled on the dice and everything!
    void addplayer(std::string name,char);//enque
    void printplayers();
    void game();
    void addmatrix();
    void printBoard();
    void removeplayer(std::string name);//deque
    void addProperty(std::string title, std::string color, int initialCost, int land, int h1,int h2, int h3, int hh, int hc, int hhc);//use a hashtable for property
    void addlinkedlist(std::string name_,std::string color_,int retail_,int rent_,int house_,int house2_,int house3_,int hotel_,int costHouse_,int costHotel_,bool cc_,bool chance_,bool jail_,int Freepark_,bool GO_,bool EX_,bool tax_,bool owned_,int xIndex_,int yIndex_);
    void loser();
    void setPlayerNum(int n);
    int getPlayersIn(){return playersIn;};
  private:
    // head of the linked list goes here
    Property * head;
    Property *tail;
    int numPlayers;
    int playersIn;
    // prev->next=head;
    Property matrix[11][11];

    int Front;             // the index in queue[] that will be dequeued next
    int End;               // the index in queue[] that was most recently enqueued
    Player playerarray[8];

};
#endif
