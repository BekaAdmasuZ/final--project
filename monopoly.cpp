<<<<<<< HEAD
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<vector>
#include"monopoly.hpp"
using namespace std;
Monopoly::Monopoly(){
   //consturctor
  head= NULL;
  tail=NULL;
  numPlayers=0;
  playersIn=0;
}
 Monopoly::~Monopoly(){
   //distructor

 }
 int Monopoly::rollDice(){
   int value = rand() % 6 + 1;//randomizes number
   return value;
 }
 // void Monopoly::addplayer(string name){
 //   	if(isEmpty())
 //   	{
 //      playerarray[End+1]=name;
 //      End=0;
 //      Front=0;
 //      return;
 //   	}
 //   	if(isFull())
 //   	{
 //   		cout<<"Limted 8 players, cannot add new player"<<endl;
 //   		return;
 //   	}
 //   	else
 //   	{
 //   		if(End==SIZE-1)
 //   		{
 //   			End=-1;
 //   		}
 //   		playerarray[End+1]=name;
 //   		End++;
 //   	}
 //   	return;
 //   }
 //
 // void Monopoly::removeplayer(string name){
 //   //if a player has no money or in debt and can't pay back they get dequeued
 //
 // }
 // void Monopoly::isTurn(){
 //   //call the roll dice twice and check what they headt
 //   //update the players status and what property they're on.
 // }


//
void Monopoly::printBoard(){
    for(int i=0;i<110;i++){
      cout<<"-";
    }
    cout<<endl;
  for(int i=0;i<11;i++)
  {
    for(int j=0; j<11;j++)
    {
      int k = 15;
      if(j==0 || j==10 || ((j>=3 && j<=7) && (i>=3 && i<=7)) || i==0 || i == 10)
      {
        k = k - matrix[j][i].name.length();
        cout<<matrix[j][i].name;
        for(int r = 0; r < k ; r++){
          cout<<" ";
        }
        cout<<"|";
      }
      else{
        for(int r = 0; r < k ; r++){
          cout<<" ";
        }
        cout<<" ";
      }
    }
    cout<<endl;
  }

  for(int i=0;i<110;i++){
    cout<<"-";
  }
 }
 // void addplayer(string name){
 //   if(isFull()){
	//  cout<<"Limted 8 players, cannot add new player"<<endl;
 //   return;
 //   }
 //   Player a = new Player;
 //   a.name = name;
 //   a.money = 1500;
 //   a.jail = false;
 //   a.doublesRolled = 0;
 //   if(isEmpty()){
 //     playerarray[Front] = a;
 //     End = Front;
 //   }
 //   else{
 //    playerarray[End+1] = a;
 //    End++;
 //  }
 // }

 void Monopoly::addlinkedlist(string name_,string color_,int retail_,int rent_,int house_,int house2_,int house3_,int hotel_,int costHouse_,int costHotel_,bool cc_,bool chance_,bool jail_,int Freepark_,bool GO_,bool EX_,bool tax_,bool owned_,int xIndex_,int yIndex_){
   Property * temp= new Property;
   temp->retail=retail_;
   temp->rent=rent_;
   temp->house=house_;
   temp->house2=house2_;
   temp->house3=house3_;
   temp->hotel=hotel_;
   temp->costHouse=costHouse_;
   temp->costHotel=costHotel_;
   temp->owned=owned_;
   temp->color=color_;
   temp->name=name_;
   temp->xIndex=xIndex_;
   temp->yIndex=yIndex_;
   temp->name=name_;
   temp->color=color_;
   temp->chance=chance_;
   temp->jail=jail_;
   temp->Freepark=Freepark_;
   temp->tax=tax_;
   temp->cc=cc_;
   temp->GO=GO_;
   temp->EX=EX_;

   if(head==NULL )
   {
     temp->next=head;
     head= temp;
     tail=temp;
   }
   else{
    tail->next= temp;
    tail = temp;
    tail->next = head;
   }
// cout<<"hello"<<endl;
    // cout<<"hello"<<endl;
    return;
 }
 void Monopoly::addmatrix()
 {
   Property *islist=head;
   while(islist->next!=head)
   {
     matrix[islist->xIndex][islist->yIndex]=*islist;
     islist=islist->next;
   }
 }
 int main(){
   cout<<"WELCOME TO MONOPOLY"<<endl;
   cout<<"PRESS 1 IF YOU WANT TO LEARN THE RULE, PRESS ANYOTHER KEYS IF YOU DONT"<<endl;
   int value=0;
   cin>>value;
   if(value==1){
     cout<<"How does Monopoly work"<<endl;
 cout<<"Each player selects a Token to move around the board."<<endl;
 cout<<"Each token start at the Go box"<<endl;
 cout<<"Each player gets 1500$  (2* $500,  2* $100, 2* $50, 6* $20, 5*10, 5*$5, 5* 1  )"<<endl;
 cout<<"We need a banker that manages the money and property(I guess we can code this)"<<endl;
 cout<<"The blimp spaces send the player to the upper board"<<endl;

 cout<<"Objective"<<endl;
 cout<<"To be the richest "<<endl;
 cout<<"Every round a player rolls a dice(we can use our code from 1300) and then the number you get from the dice is the num of boxes you’re going to move."<<endl;
 cout<<"And the boxes will tell us what to do."<<endl;
   }

 //   cout<<"Welcome to Monopoly"<<endl;
 //   cout<<"How many players are playing? (4-8 players)"<<endl;
 //   string playerNumS=0;
 //   getline(cin,playerNumS);
 //   while(stoi(playerNumS)<4 || stoi(playerNumS)>8){
 //   if(stoi(playerNumS)<4 ||stoi(playerNumS)>8){
 //     cout<<"Please enter numbere in correct Range"<<endl;
 //     getline(cin,playerNumS);
 //   }
 // }
 //
 //    cout<<"The 1st player will be Player A, 2nd will be B, 3rd C etc."<<endl;
 //    cout<<"Decide who is who. This will also be the order";

     Monopoly M;
     string name, color;
     int retail, rent, house,house2, house3, hotel, costHouse, costHotel, Freepark;
     bool chance, jail, tax, owned, cc, GO, EX;
     int xIndex=0;
     int yIndex=0;
     ifstream myFile("monopoly.csv");
     if(myFile.is_open())
     {
       string line="";
       while(getline(myFile,line)){
         stringstream ss(line);
         // ss << line;
         string info="";
        getline(ss,info,',');
         name=info;
          // cout<<name<<endl;
        getline(ss,info,',');
         color=info;
          // cout<<color<<endl;
        getline(ss,info,',');
          // cout<<info<<endl;
          retail=stoi(info);
          // cout<<"hello"<<endl;
        getline(ss,info,',');
          rent=stoi(info);
        getline(ss,info,',');
          house=stoi(info);
        getline(ss,info,',');
          house2=stoi(info);
        getline(ss,info,',');
          house3=stoi(info);
        getline(ss,info,',');
          hotel=stoi(info);
        getline(ss,info,',');
          costHouse=stoi(info);
        getline(ss,info,',');
          costHotel=stoi(info);
        getline(ss,info,',');
          cc=stoi(info);
          //from here to bottom the stoi is for booleans
        getline(ss,info,',');
           chance=stoi(info);
        getline(ss,info,',');
          jail=stoi(info);
        getline(ss,info,',');
          Freepark=stoi(info);
        getline(ss,info,',');
          GO=stoi(info);
        getline(ss,info,',');
          EX=stoi(info);
        getline(ss,info,',');
          tax=stoi(info);
        getline(ss,info,',');
          owned=stoi(info);
        getline(ss,info,',');
          xIndex =stoi(info);
        getline(ss,info,',');
          yIndex =stoi(info);

        M.addlinkedlist(name,color,retail,rent,house,house2,house3,hotel,costHouse,costHotel,cc,chance,jail,Freepark,GO,EX,tax,owned,xIndex,yIndex);

       }
       myFile.close();
     }

     M.addmatrix();
     M.printBoard();




   // else{
   //   int counter=0;
   //   string name;
   //   cout<<"ENTER PLAYERS NAME: (players limited to 8)"<<endl;
   //   while(counter!=8){
   //     cin>>name;
   //     P.addplayer(name);
   //     counter++;
   //   }
   // }
   // P.isTurn();
   // cout<<"hi"<<<<"hello"

  }
=======
>>>>>>> cc5f66a20e5fffd550e38c84f544228032865ade
