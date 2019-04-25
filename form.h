#include<vector>
#include<string>
#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;
int turn=-1,enemy=-1,dmg=0;
double base_dmg=0;
string stat[4]={"Max HP","Attack","Defense","Speed"};
char p='a';
void centertext(string x){
	for(int i=0;i<(84-x.length())/2;i++)cout<<" ";
	cout<<x<<"\n";
}
struct status{
	int max_hp=0,atk=0,def=0,spd=0;
};
struct skill{
	string name,des;
	char type;
	int cd,bcd;
};
struct position{
	string name;
	int id=-1,player=0,tm=0,prior=1;
	int hp_up=0,atk_up=0,def_up=0,spd_up=0,hp_down=0,atk_down=0,def_down=0,spd_down=0,protect=0,stealth=0,silenced=0,hp=0,heal_block=0,knock=0;
	status base_stat,current_stat;
	bool block=false,evade=false,blind=false,stun=false;
	skill skill[2];
	vector<int> bleed;
	vector<int> regeneration;
	vector<string> tag;
};
struct champion{
	string name,role;
	int hp,atk,def,spd,id;
	skill skill[2];
	vector<string> tag;
};
position pos[10];
vector<champion> champions;
bool skill_used;
