#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include "draft.cpp"
using namespace std;
string state;
void centertext(string x){
	for(int i=0;i<(84-x.length())/2;i++)cout<<" ";
	cout<<x<<"\n";
}
int main(){
	//adjust console's size
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 640, 480, TRUE);
   //clear screen
   system("CLS");
   //set current state and cout menu
   state="main";
   cout<<"\n";
   string title="CLASH OF CHAMPIONS",play="press 'p' to play!!!",viewc="press 'v' to view champions!",quit="press 'q' to quit";
   centertext(title);
   centertext(play);
   centertext(viewc);
   centertext(quit);
   //below is a main menu code, each pressed button should only work when there is a showed description. Ex. press q to quit only at main menu, in other state but main menu, press q should not quit the game
   char p='a';
   int i=0;
   while(p!='p'||p!='v'||p!='q'){
   	char p=_getch();
   }
   while(p=='v'){
   	system("CLS");
   	champion view=upload(i);
   	centertext(view.name);
   	for(int j=0;j<view.tag.size();j++)cout<<view.tag[j]<<", ";
   	viewstat(view);
   	viewskill(view);
   	cout<<"'w' to go up 's' to go down 'b' to back to main menu...";
   	while(p!='w'||p!='s'||p!='b'){
   		char p=_getch();
	   }
	   if(p=='w'){
	   	i--;
	   	p='v';
	   }
	   else if(p=='s'){
	   	i++;
	   	p='v';
	   }else break;
   }
   while(p=='p'){
   	
   }
   if(p=='b'){
   	main();
   }
   return 0;
}
