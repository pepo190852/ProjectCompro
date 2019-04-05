#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include "draft.cpp"
using namespace std;
int champions_num=1;
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
   int i=0,draftstate=0,player_draft=1;
   bool ban,share_pool,banned[champions_num],picked[champions_num],choose=false;
   for(int j=0;j<champions_num;j++){
   	banned[j]=false;
   	picked[j]=false;
   }
   champion view;
   target pos[10];
   int queue[10]={1,2,2,1,1,2,2,1,1,2},p1_f=0,p2_f=5;
   while(p!='p'||p!='v'||p!='q'){
   	char p=_getch();
   }
   while(p=='v'){
   	system("CLS");
   	view=upload(i);
   	centertext(view.name);
   	for(int j=0;j<view.tag.size();j++)cout<<view.tag[j]<<", ";
   	viewstat(view);
   	viewskill(view);
   	cout<<"'w' to go up 's' to go down 'b' to back to main menu...";
   	while(p!='w'||p!='s'||p!='b'){
   		p=_getch();
	   }
	   if(p=='w'){
	   	if(i==0)i=champions_num-1;
	   	else i--;
	   	p='v';
	   }
	   else if(p=='s'){
	   	if(i==champions_num-1)i=0;
	   	else i++;
	   	p='v';
	   }else break;
   }
   while(p=='p'){
   	system("CLS");
   	if(draftstate==0){
   		centertext("Enabling BAN?");
   		centertext("'y' yes");
   		centertext("'n' no");
   		centertext("'b' back");
   		while(p!='y'||p!='n'||p!='b'){
   			p=_getch();
	  	 }
	  	if(p=='y'){
	   		ban=true;
	   		p='p';
	   		draftstate++;
	   	}else if(p=='n'){
	   		ban=false;
	   		p='p';
	   		draftstate++;
	   	}
	   }
	else if(draftstate==1){
		centertext("Share Champions Draft Pool?");
		centertext("'y' yes");
   		centertext("'n' no");
   		centertext("'b' back");
   		if(p=='y'){
	   		share_pool=true;
	   		p='p';
	   		draftstate++;
	   	}else if(p=='n'){
	   		share_pool=false;
	   		p='p';
	   		draftstate++;
	   	}else{
	   		p='p';
	   		draftstate--;
		   }
	}
	else if(draftstate==2){
			for(int j=0;j<10;j++){
				choose=false;
				while(queue[j]==1&&p=='p'){
					system("CLS");
					centertext("Player 1's turn to DRAFT!!!");
					while(banned[i]){
						if(i==champions_num-1)i=0;
	   					else i++;
					}
					view=upload(i);
   					centertext(view.name);
   					for(int k=0;k<view.tag.size();k++)cout<<view.tag[k]<<", ";
   					viewstat(view);
   					viewskill(view);
   					cout<<"'d' to DRAFT!!! 'w' to go up 's' to go down 'b' to go back to main menu...";
   					while(p!='d'||p!='w'||p!='s'||p!='b'){
   						p=_getch();
					   }
					if(p=='w'){
	   						if(i==0)i=champions_num-1;
	   						else i--;
	   						p='p';
	   					}
	  				else if(p=='s'){
	   					if(i==champions_num-1)i=0;
	   					else i++;
	   					p='p';
	 				  }else if(p=='d')choose=true;	
					 }
					while(queue[j]==2&&p=='p'){
					system("CLS");
					centertext("Player 2's turn to DRAFT!!!");
					while(banned[i]){
						if(i==champions_num-1)i=0;
	   					else i++;
					}
					view=upload(i);
   					centertext(view.name);
   					for(int k=0;k<view.tag.size();k++)cout<<view.tag[k]<<", ";
   					viewstat(view);
   					viewskill(view);
   					cout<<"'k' to DRAFT!!! 'o' to go up 'l' to go down 'b' to go back to main menu...";
   					while(p!='k'||p!='o'||p!='l'||p!='b'){
   						p=_getch();
					   }
					if(p=='o'){
	   						if(i==0)i=champions_num-1;
	   						else i--;
	   						p='p';
	   					}
	  				else if(p=='l'){
	   					if(i==champions_num-1)i=0;
	   					else i++;
	   					p='p';
	 				  }else if(p=='k')choose=true;
					 }
					 if(choose){
					 	pos[j].name=view.name;
					 	for(int k=0;k<view.tag.size();k++)pos[j].tag.push_back(view.tag[k]);
					 	pos[j].id=i;
					 	pos[j].player=queue[j];
					 	pos[j].stat[0][0]=view.hp;
	 					pos[j].stat[1][0]=view.off;
	 					pos[j].stat[2][0]=view.mdef;
	 					pos[j].stat[3][0]=view.pdef;
	 					pos[j].stat[4][0]=view.acc;
	 					pos[j].stat[5][0]=view.eva;
	 					pos[j].stat[6][0]=view.bc;
	 					pos[j].stat[7][0]=view.ba;
	 					pos[j].stat[8][0]=view.spd;
	 					for(int k=0;k<view.skill.size();k++)pos[j].skill.push_back(view.skill[k]);
	 					picked[i]==true;
						 }
						 if(p=='b')break;	
					 }
				}
				/*for(int k=0;k<4;k++){
					while(p=='p'){
					view=upload(i);
   					centertext(view.name);
   					for(int j=0;j<view.tag.size();j++)cout<<view.tag[j]<<", ";
   					viewstat(view);
   					viewskill(view);
   					cout<<"'g' to BAN!! 'w' to go up 's' to go down";
   					while(p!='g'||p!='w'||p!='s'){
   						p=_getch();
					   }
					   if(p=='w'){
	   						if(i==0)i=champions_num-1;
	   						else i--;
	   						p='p';
	   					}
	  				 else if(p=='s'){
	   					if(i==champions_num-1)i=0;
	   					else i++;
	   					p='p';
	 				  }else{
	 				  	pos[]
					   }
					}
				}*/
			
			}
	}
   }
   if(p=='b'){
   	main();
   }
   return 0;
}
