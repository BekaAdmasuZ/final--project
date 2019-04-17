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
      playerarray[End+1]=name;
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
   		playerarray[End+1]=name;
   		End++;
   	}
   	return;
   }

 void Monopoly::removeplayer(string name){

 }
 int main(){
   Monopoly P;
   cout<<"WELCOME TO MONOPOLY"<<endl;
   cout<<"PRESS 1 IF YOU WANT TO LEARN THE RULE"<<endl;
   int value=0;
   cin>>value;
   if(value==1){
     cout<<"put all the rules in here"<<endl;
   }
   else{
     int counter=0;
     string name;
     cout<<"ENTER PLAYERS NAME: (players limited to 8)"<<endl;
     while(counter!=8){
       cin>>name;
       P.addplayer(name);
       counter++;
     }
   }
   P.isTurn();

   }
