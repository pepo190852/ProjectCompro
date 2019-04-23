#include<windows.h>
#include "form.h"
#include "skill_function.h"
#include "draft.h"
using namespace std;
int main(){
	p='a';
	srand(time(0));
	//adjust console's size
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 640, 480, TRUE);
   //clear screen
   system("CLS");
   //set current state and cout menu
   cout<<"\n";
   centertext("CLASH OF CHAMPIONS");
   centertext("press 'p' to play!!!");
   centertext("press 'v' to view champions!");
   centertext("press 'q' to quit");
   //below is a main menu code, each pressed button should only work when there is a showed description. Ex. press q to quit only at main menu, in other state but main menu, press q should not quit the game
   int i=0,draftstate=0,player_draft=1,hp1=1,hp2=1,turn,tp=0,skill_num=-1;
   bool ban,share_pool,banned[champions.size()],picked[champions.size()],choose=false;
   for(int j=0;j<champions.size();j++){
   	banned[j]=false;
   	picked[j]=false;
   }
   champion view;
   int queue[10]={1,2,2,1,1,2,2,1,1,2},p1_f=0,p2_f=5;
   while(p!='p'&&p!='v'&&p!='q'){
   	char p=_getch();
   }
   while(p=='v'){
   	system("CLS");
   	view=upload(i);
   	centertext(view.name);
   	centertext(view.role);
   	for(int j=0;j<view.tag.size();j++)cout<<view.tag[j]<<" ";
   	cout<<"\n";
   	viewstat(view);
   	viewskill(view);
   	cout<<"'w' to go up 's' to go down 'b' to back to main menu...";
   	while(p!='w'&&p!='s'&&p!='b'){
   		p=_getch();
	   }
	   if(p=='w'){
	   	if(i==0)i=champions.size()-1;
	   	else i--;
	   	p='v';
	   }
	   else if(p=='s'){
	   	if(i==champions.size()-1)i=0;
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
   		while(p!='y'&&p!='n'&&p!='b'){
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
				if(ban){
					if(j==0||j==4||j==8){
						for(int k=0;k<4;k++){
								while(p=='p'){
									system("CLS");
									if(k%2==0)centertext("Player 1's turn to BAN!!");
									else centertext("Player 2's turn to BAN!!");
									if(!share_pool){
										while(banned[i]||picked[i]){
											if(i==champions.size()-1)i=0;
	   										else i++;
										}
									}else{
										while(banned[i]){
										if(i==champions.size()-1)i=0;
	   									else i++;
										}
									}
									view=upload(i);
   									centertext(view.name);
   									centertext(view.role);
   									for(int m=0;m<view.tag.size();m++)cout<<view.tag[m]<<" ";
   									cout<<"\n";
   									viewstat(view);
   									viewskill(view);
   									if(k%2==0){
   										cout<<"'d' to BAN!! 'w' to go up 's' to go down 'v' to view drafted 'b' to go back to main menu...";
   										while(p!='d'&&p!='w'&&p!='s'&&p!='b'&&p!='v'){
   											p=_getch();
					  				 	}
									   }else{
									   	cout<<"'k' to BAN!! 'o' to go up 'l' to go down 'v' to view drafted 'b' to go back to main menu...";
   										while(p!='k'||p!='o'||p!='l'||p!='b'||p!='v'){
   											p=_getch();
					  				 	}
									   }
									if(p=='w'||p=='o'){
	   										if(i==0)i=champions.size()-1;
	   										else i--;
	   										p='p';
	   									}
	  								else if(p=='s'||p=='l'){
	   									if(i==champions.size()-1)i=0;
	   									else i++;
	   									p='p';
	 								  }else if(p=='v'){
	   									viewdraft(pos);
	   									p='p';
	 								  }else if(p=='d'||p=='k')ban[i]=true;
								}
								if(p=='b')break;
								else p='p';
								if(j==8&&k==1)break;
							}

						}
					}
				choose=false;
				while(queue[j]==1&&p=='p'){
					system("CLS");
					centertext("Player 1's turn to DRAFT!!!");
					if(!share_pool){
						while(banned[i]||picked[i]){
						if(i==champions.size()-1)i=0;
	   					else i++;
						}
					}else{
						while(banned[i]){
						if(i==champions.size()-1)i=0;
	   					else i++;
						}
					}
					view=upload(i);
   					centertext(view.name);
   					centertext(view.role);
   					for(int m=0;m<view.tag.size();m++)cout<<view.tag[m]<<" ";
   					cout<<"\n";
   					viewstat(view);
   					viewskill(view);
   					cout<<"'d' to DRAFT!!! 'w' to go up 's' to go down 'v' to view drafted 'b' to go back to main menu...";
   					while(p!='d'||p!='w'||p!='s'||p!='b'||p!='v'){
   						p=_getch();
					   }
					if(p=='w'){
	   						if(i==0)i=champions.size()-1;
	   						else i--;
	   						p='p';
	   					}
	  				else if(p=='s'){
	   					if(i==champions.size()-1)i=0;
	   					else i++;
	   					p='p';
	 				  }else if(p=='v'){
	   									viewdraft(pos);
	   									p='p';
	 								  }
					   else if(p=='d')choose=true;
					 }
					while(queue[j]==2&&p=='p'){
					system("CLS");
					centertext("Player 2's turn to DRAFT!!!");
					if(!share_pool){
						while(banned[i]||picked[i]){
						if(i==champions.size()-1)i=0;
	   					else i++;
						}
					}else{
						while(banned[i]){
						if(i==champions.size()-1)i=0;
	   					else i++;
						}
					}
					view=upload(i);
   					centertext(view.name);
   					centertext(view.role);
   					for(int m=0;m<view.tag.size();m++)cout<<view.tag[m]<<" ";
   					cout<<"\n";
   					viewstat(view);
   					viewskill(view);
   					cout<<"'k' to DRAFT!!! 'o' to go up 'l' to go down 'v' to view drafted 'b' to go back to main menu...";
   					while(p!='k'||p!='o'||p!='l'||p!='b'||p!='v'){
   						p=_getch();
					   }
					if(p=='o'){
	   						if(i==0)i=champions.size()-1;
	   						else i--;
	   						p='p';
	   					}
	  				else if(p=='l'){
	   					if(i==champions.size()-1)i=0;
	   					else i++;
	   					p='p';
	 				  }else if(p=='v'){
	   									viewdraft(pos);
	   									p='p';
	 								  }
					   else if(p=='k')choose=true;
					 }
					 if(choose){
					 	pos[j].name=view.name;
					 	for(int m=0;m<view.tag.size();m++)pos[j].tag.push_back(view.tag[m]);
					 	pos[j].id=view.id;
					 	pos[j].player=queue[j];
					 	pos[j].base_stat.max_hp=view.hp;
					 	pos[j].hp=view.hp;
	 					pos[j].base_stat.atk=view.atk;
	 					pos[j].base_stat.def=view.def;
	 					pos[j].base_stat.spd=view.spd;
	 					for(int k=0;k<2;k++)pos[j].skill[k]=view.skill[k];
	 					picked[i]==true;
						 }
						 if(p=='b')break;
					 }
					 draftstate++;
				}
				else if(draftstate==3){
					update_stat();
					while(hp1>0&&hp2>0){
						turn=cal_turn_meter();
						begin_turn();
						skill_used=false;
						enemy=-1;
						if(pos[turn].hp>0&&!pos[turn].stun){
							while(!skill_used){
							skill_num=-1;
							do{skill_num=start_turn();}while(pos[turn].skill[skill_num-1].cd>0);
						use_skill(pos[turn].id,skill_num);
						}
						}else if(pos[turn].stun&&pos[turn].hp>0){
							pos[turn].stun==false;
							cout<<pos[turn].name<<" recovered from Stun.\n";
						}else if(pos[turn].hp==0)defeat(turn);
						endturn();
						hp1=0;
						hp2=0;
						for(int m=0;m<10;m++){
							if(pos[m].player==1)hp1+=pos[m].hp;
							else hp2+=pos[m].hp;
						}
						if(hp1==0||hp2==0)break;
						else{
						if(pos[turn].player==1)cout<<"'d";
						else cout<<"'j";
						cout<<"' to continue...";
					    if(pos[turn].player==1){
					    	while(p!='d')p=_getch();
						}else{
							while(p!='j')p=_getch();
						}
						p='p';
						}
						}
						if(hp1>0)centertext("PLAYER 1'S VICTORY!");
						else centertext("PLAYER 2'S VICTORY!");
						p='a';
					}
				}
				if(p=='b')main();
				return 0;
			}
