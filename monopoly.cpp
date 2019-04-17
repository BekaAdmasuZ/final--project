#include<iostream>
#include"monopoly.hpp"
using namespace std;
 Monopoly::Monopoly(){

 }
 Monopoly::~Monopoly(){

 }
 int Monopoly::rollDice(){
   int value = rand() % 6 + 1;
   return value;
 }
 void Monopoly::addplayer(string name){
   	if(isEmpty())
   	{
      playerarray[End+1]=player;
      End=0;
      Front=0;
      return;
   	}
   	if(isFull())
   	{
   		cout<<"Limted 8 players, cannot add new player"<<endl;
   		return;
   	}
   	else
   	{
   		if(End==SIZE-1)
   		{
   			End=-1;
   		}
   		playerarray[End+1]=player;
   		End++;
   	}
   	return;
   }

 }
 void Monopoly::removeplayer(string name){

 }
