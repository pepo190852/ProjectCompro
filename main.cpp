#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
void centertext(string x){
	for(int i=0;i<(84-x.length())/2;i++)cout<<" ";
	cout<<x<<"\n";
}
void viewchampions(){
	cout<<"champions";
}
int main(){
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 640, 480, TRUE);
   cout<<"\n";
   string title="CLASH OF CHAMPIONS",play="press 'p' to play!!!",viewc="press 'v' to view champions!",quit="press 'q' to quit";
   centertext(title);
   centertext(play);
   centertext(viewc);
   centertext(quit);
   char o;
   if(_getch()=='v'){
   		viewchampions();
	   }
   while(o!='q'){
   	o=_getch();
   	if(o=='v'||o=='p'){
   		break;
	   }
   }
   if(o=='v')viewchampions();
   return 0;
}
