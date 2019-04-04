#include "form.h"
#include "spartan.h"
struct upload(int i){
	if(i==0)return spartan;
}
void viewstat(champion view){
	cout<<"HP : |";
   	for(int j=100;j<view.hp;j+=11){
   		cout<<"|";
   		if(j=155)j+=1;
	   }
	   cout<<" "<<view.hp<<"\n";
	cout<<"Offense : |";
	for(int j=10;j<view.off;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.off<<"\n";
	cout<<"Melee Armor : |";
	for(int j=10;j<view.mdef;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.mdef<<"\n";
	cout<<"Pierce Armor : |";
	for(int j=10;j<view.pdef;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.pdef<<"\n";
	cout<<"Accuracy : |";
	for(int j=10;j<view.acc;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.acc<<"\n";
	cout<<"Evasion : |";
	for(int j=10;j<view.eva;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.eva<<"\n";
	cout<<"Defend Probability : |";
	for(int j=10;j<view.bc;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.bc<<"\n";
	cout<<"Defense : |";
	for(int j=10;j<view.ba;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.ba<<"\n";
	cout<<"Speed : |";
	for(int j=10;j<view.spd;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.spd<<"\n";
}
void viewskill(champion x){
	for(int i=0;i<x.skill.size();i++){
		cout<<"skill "<<i+1<<" "<<x.skill[i].name<<" (";
		if(x.skill[i].type='b')cout<<"basic";
		else if(x.skill[i].type='p')cout<<"passive";
		else{cout<<"cooldown : "<<x.skill[i].cd}
		cout<<")\n"<<x.skill[i].des<<"\n";
	}
}
