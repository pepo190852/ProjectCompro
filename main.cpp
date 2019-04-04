#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
string state;
void centertext(string x){
	for(int i=0;i<(84-x.length())/2;i++)cout<<" ";
	cout<<x<<"\n";
}
void viewchampions(){
	state="viewchampions";
	system("CLS");
	cout<<"press 'b' to go back...";
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
   char p;
   while(p!='q'){
   	p= _getch();
   	if(p=='v'&&state=="main"){
   		viewchampions();
	   }
	if(p=='b'&&state!="main"){
		main();
		state="main";
	}
   }
   return 0;
}
