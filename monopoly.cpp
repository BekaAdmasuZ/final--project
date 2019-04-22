#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>

#include<ctime>
#include <cstdlib>
#include <queue>
#include"monopoly.hpp"
using namespace std;
Monopoly::Monopoly(){
   //consturctor
  head= NULL;
  tail=NULL;
  numPlayers=0;
  playersIn=0;
  // playerarray[numPlayers];
}
 Monopoly::~Monopoly(){
   //distructor

 }
 int Monopoly::rollDice(){
   srand(time(NULL)); // Seed the tim
   int finalNum = rand()%(6-1+1)+1;//randomizes number

   return finalNum;
 }
 void Monopoly::addplayer(string name,char car){
     Player a;
     a.C=car;
     a.name = name;
     a.money = 1500;
     a.jail = false;
     a.doublesRolled = 0;
     a.x=10;
     a.y=10;
     if(numPlayers==8)
    	{
    		cout<<"Limted 8 players, cannot add new player"<<endl;
        return;
    	}
    if(numPlayers==0)
     	{
        playerarray[0]=a;
        numPlayers=1;
     	}
   	else
   	{
      cout<<"NUM PLAYER IS ABOVE"<<endl;
   		playerarray[numPlayers]=a;
   		numPlayers++;
   	}
    matrix[10][10].currPla.push(a.C);
    cout<<"NAME: "<<playerarray[numPlayers-1].name<<"'s' PIECE IS: "<<playerarray[numPlayers-1].C<<endl;
    playersIn=numPlayers;
   	return;
  }
 //
 // void Monopoly::removeplayer(string name){
 //   //if a player has no money or in debt and can't pay back they get dequeued
 //
 // }
 // void Monopoly::isTurn(){
 //   // player[0].charac='A';
 //   // player[1].charac='B';
 //   // player[3].charac='C';
 //   // player[4].charac='D';
 //   x=rolldice();
 //   y=rolldice();
 //   int g=x+y;
 //   for(int i=0; i<g;i++)
 //   {
 //     if(player.x==10&&player.y!=10)
 //     {
 //       player.y++;
 //     }
 //     if(player.x==0&&player.y!=0)
 //     {
 //       player.x++;
 //     }
 //     if(player.x==10&&player.y!=0)
 //     {
 //       player.x--;
 //     }
 //     if(player.x==0&&player.y!=10)
 //     {
 //       player.y--;
 //     }
 //   }
 //   // check players position
 //
 //
 //
 //   if(matrix[x][y].owned==true)
 //   {
 //     you owe someone, go thru players;
 //   }
 //   else{
 //     do you wanna buy it
 //     if(yes)
 //     {
 //       matrix[x][y].owned=true
 //     }
 //   }
 //
 // }
 //

//
void Monopoly::printBoard(){
    for(int i=0;i<200;i++){
      cout<<"-";
    }
    cout<<endl;
  for(int i=0;i<11;i++)
  {
    for(int j=0; j<11;j++)
    {
      int k = 16;
      if(j==0 || j==10 || ((j==3 || j == 7) && i>=3 && i<=7) || ((i==3 || i == 7) && j>=3 && j<=7) || i==0 || i == 10)
      {
        k = k - matrix[j][i].name.length()-1;
        cout<<"|";
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
    cout<<"\n"<<endl;
    for(int j=0; j<11;j++)
    {
      int k = 16;
      if(j==0 || j==10 || ((j==3 || j == 7) && i>=3 && i<=7) || ((i==3 || i == 7) && j>=3 && j<=7) || i==0 || i == 10)
      {
        int sp=0;
        int num = matrix[j][i].retail;
        cout<<"|";
        if(num > 0){
          while(num != 0){
            num = num/10;
            sp++;
          }
          k = k - sp - 3;
          cout<<"$ "<<matrix[j][i].retail;
        }
        else{
          k--;
        }
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
    cout<<"\n"<<endl;
    for(int j=0; j<11;j++)
    {
      int k = 16;
      if(j==0 || j==10 || ((j==3 || j == 7) && i>=3 && i<=7) || ((i==3 || i == 7) && j>=3 && j<=7) || i==0 || i == 10)
      {
        int sp=0;
        queue<char> v;
        sp = matrix[j][i].currPla.size();
        cout<<"|";
        if(sp){
          k = k - 2*sp;
          int h;
          for(h = 0; h+1 < sp; h++){
            v.push(matrix[j][i].currPla.front());
            cout<<matrix[j][i].currPla.front()<<",";
            matrix[j][i].currPla.pop();
          }
          v.push(matrix[j][i].currPla.front());
          cout<<matrix[j][i].currPla.front();
          matrix[j][i].currPla.pop();
          for(h=0;h<sp;h++){
            matrix[j][i].currPla.push(v.front());
            v.pop();
          }
        }
        else{
          k--;
        }
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
    for(int j=0; j<11;j++)
    {
      int k = 16;
      if(j==0 || j==10 || ((j==3 || j == 7) && i>=3 && i<=7) || ((i==3 || i == 7) && j>=3 && j<=7) || i==0 || i == 10)
      {
        for(int r = 0; r < k+1 ; r++){
          cout<<"-";
        }
      }
      else{
        for(int r = 0; r < k ; r++){
          cout<<" ";
        }
        cout<<" ";
      }
    }
    cout<<"\n"<<endl;
  }

  for(int i=0;i<200;i++){
    cout<<"-";
  }
  cout<<endl;
 }
void Monopoly:: game(){
   int a,b,c;
   int savej;
   int ind=0;
   int index=0;

   for(int i=0; i<5; i++){
     a=rollDice();
      cout<< playerarray[index].C<<   " rolled a "<< a<<endl;
      system("PAUSE");
     b=rollDice();
     cout<<  playerarray[index].C<<" rolled a "<< b<<endl;
     c=a+b;
       system("PAUSE");
   //   for(int j=0; j<matrix[playerarray[index].x][playerarray[index].y].currPla.size();j++){
   // if(matrix[playerarray[index].x][playerarray[index].y].currPla[j]==playerarray[j].C){
   //   savej=j;
   //   break;
   // }
   // }

  matrix[playerarray[index].x][playerarray[index].y].currPla.pop();
  //index=ind %  numPlayers;
     for(int i=0; i<c; i++){

       if(playerarray[index].x==0 && playerarray[index].y!=0 && playerarray[index].y!=10 ){
         playerarray[index].y--;

       }
       else if(playerarray[index].x==10 && playerarray[index].y!=0&& playerarray[index].y!=10){
           playerarray[index].y++;
       }
       else if(playerarray[index].y==10 && playerarray[index].x!=0&& playerarray[index].x!=10){
           playerarray[index].x--;
       }
       else if(playerarray[index].y==0 && playerarray[index].x!=0&& playerarray[index].x!=10){
           playerarray[index].x++;
       }
       else if(playerarray[index].y==0 && playerarray[index].x==0){
         playerarray[index].x++;
       }
       else if(playerarray[index].y==0&&playerarray[index].x==10){
         playerarray[index].y++;
       }
       else if(playerarray[index].y==10&&playerarray[index].x==10){
         playerarray[index].x--;
       }
       else if(playerarray[index].y==10&&playerarray[index].x==0){
         playerarray[index].y--;
       }
       else if(playerarray[index].x==3 && playerarray[index].y!=3&& playerarray[index].y!=7){
           playerarray[index].y--;
       }
       else if(playerarray[index].x==7 && playerarray[index].y!=3&& playerarray[index].y!=7){
           playerarray[index].y++;
       }
       else if(playerarray[index].y==3 && playerarray[index].x!=3&& playerarray[index].x!=7){
           playerarray[index].x++;
       }
       else if(playerarray[index].y==7 && playerarray[index].x!=3&& playerarray[index].x!=7){
           playerarray[index].x--;
       }
       else if(playerarray[index].y==3&&playerarray[index].x==3){
         playerarray[index].x++;
       }
       else if(playerarray[index].y==3&&playerarray[index].x==7){
         playerarray[index].y++;
       }
       else if(playerarray[index].y==7&&playerarray[index].x==7){
         playerarray[index].x--;
       }
       else if(playerarray[index].y==7&&playerarray[index].x==3){
         playerarray[index].y--;
       }
     }


     matrix[playerarray[index].x][playerarray[index].y].currPla.push(playerarray[index].C);

printBoard();

index++;
   if(index==numPlayers){
     index=0;
   }
}

 }



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
 void Monopoly::printplayers()
 {
   cout<<"______________________________________"<<endl;
   cout<<"THIS ARE THE PLAYERS AND THEIR PIECE"<<endl;
   // cout<<"1"<<" ) "<<playerarray[0].name<<"----"<<playerarray[0].C<<endl;
   // cout<<"2"<<" ) "<<playerarray[1].name<<"----"<<playerarray[1].C<<endl;
   // cout<<"3"<<" ) "<<playerarray[2].name<<"----"<<playerarray[2].C<<endl;
   for(int i=0;i<numPlayers;i++)
   {
     cout<<i+1<<" ) "<<playerarray[i].name<<"----"<<playerarray[i].C<<endl;
   }
 }
 int main(){
   Monopoly M;
   string name, color,playersname;
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
   cout<<"WELCOME TO MONOPOLY"<<endl;
   cout<<"PRESS 1 IF YOU WANT TO LEARN THE RULE, PRESS 2 IF YOU DONT"<<endl;
   string value;
   getline(cin,value);
   if(stoi(value)==1){
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
        cout<<endl;

        cout<<"Great lets start"<<endl;
   }
   else{
     cout<<"Great lets start"<<endl;
   }
   char letters[8]={'A','B','C','D','E','F','G','H'};
   int count=0;
   string answer;
   cout<<"Put in players names"<<endl;
     for(int i=0;i<8;i++){
          getline(cin,playersname);
          M.addplayer(playersname,letters[i]);
          count++;
          if(count<2)
          {
           cout<<"Put in next players name"<<endl;
          }
          if(count>=2)
          {
           cout<<"Do you want to add more player?(Y/N)"<<endl;
           getline(cin,answer);
           if(answer=="y"||answer=="Y")
           {
             cout<<"Great lets start"<<endl;
             cout<<"Put in next players name"<<endl;
           }
           else{
             break;
           }
          }
     }
    M.printplayers();


 //    cout<<"Decide who is who. This will also be the order";





     M.printBoard();
     M.game();

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
