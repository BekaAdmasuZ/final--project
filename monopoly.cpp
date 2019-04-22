#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include"monopoly.hpp"
using namespace std;
 Monopoly::Monopoly(){
   //consturctor
   head=NULL;
   tail=NULL;
   // for(int i=0;i<11;i++)
   // {
   //   for(int j=0;j<11;j++)
   //   {
   //     matrix[j][i]= -1;
   //   }
   // }
 }
 Monopoly::~Monopoly(){
   //distructor

 }
 // int Monopoly::rollDice(){
 //   int value = rand() % 6 + 1;//randomizes number
 //   return value;
 // }
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

 // struct Property{
 //   Property* next;
 //   std::string name;
 //   std::string color;
 //   int retail;
 //   int rent;
 //   int house;
 //   int house2;
 //   int house3;
 //   int hotel;
 //   int costHouse;
 //   int costHotel;
 //   int Freepark;
 //   bool owned;
 //   bool cc;
 //   bool chance;
 //   bool jail;
 //   bool GO;
 //   bool EX;
 //   bool tax;
 //   int xIndex;
 //   int yIndex;
 // };
 // Property * head=NULL;
 // Property *tail=NULL;
 // // prev->next=head;
 // Property matrix[11][11];

 void Monopoly::printBoard(){
    for(int i=0;i<110;i++){
      cout<<"-";
    }
    cout<<endl;


  for(int i=0;i<11;i++)
  {
    for(int j=0; j<11;j++)
    {
      if(j==0 || j==10 || i==0 || i == 10)
      {
        if(j==0)
        {
          cout<<setw(20)<<"|"<<matrix[j][i].name<<"|";
        }
        else{
          cout<<setw(20)<<matrix[j][i].name<<"|";
        }

      }
      else
      {
        for(int i=0; i<15;i++){
          cout<<" ";
        }      }
    }
    cout<<endl;
  }
    // cout<<setw(10)<<matrix[5][5].name<<"|"<<endl;

  // }
  // Property *temp=head;
  //  while(temp->next!=head){
  //
  //
  //      if(temp->yIndex==0)
  //      {
  //         cout<<setw(10)<<matrix[temp->xIndex][temp->yIndex].name<<"|";
  //      }
  //      if(temp->yIndex==11)
  //      {
  //
  //      }
  //      else{
  //
  //      }
  //      temp=temp->next;
  //  }
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
 void Monopoly::Loser(){
   playersIn--;
 }
 Void Monopoly::setNumPlayers(int n){
   numPlayers=n;
   playersIn=n;
 }
 int main(){
   int playerNum
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
        cout<<info<<endl;
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
   cout<<"Welcome to Monopoly"<<endl;
   cout<<"How many players are playing? (4-8 players)"<<endl;

   getline(cin,playerNum);
   while(playerNum<4 || playerNum>8){
   if(playerNum<4 || playerNum>8){
     cout<<"Please enter numbere in correct Range"<<endl;
     getline(cin,playerNum);
   }
 }
 M.setNumPlayers(playerNum);
    M.printBoard();
    while(M.playersIn()!=1){

    }

   M.printBoard();
   // Monopoly P;
   // cout<<"WELCOME TO MONOPOLY"<<endl;
   // cout<<"PRESS 1 IF YOU WANT TO LEARN THE RULE"<<endl;
   // int value=0;
   // cin>>value;
   // if(value==1){
   //   cout<<"put all the rules in here"<<endl;
   // }
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
