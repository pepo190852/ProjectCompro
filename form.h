#include<vector>
#include<string>
#include<iostream>
#include<conio.h>
using namespace std;
int turn=-1,enemy=-1,dmg=0;
double base_dmg=0;
string stat[4]={"Max HP","Attack","Defense","Speed"};
bool skill_used;
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
champion spartan;
spartan.name="Spartan";
spartan.role="Tank";
spartan.id=0;
spartan.hp=167;
spartan.atk=15;
spartan.def=16;
spartan.spd=13;
spartan.tag.push_back("Greek");
spartan.tag.push_back("Classical");
spartan.tag.push_back("Mediterranean");
spartan.tag.push_back("Bronze");
spartan.skill[0].name="Spartar Slash";
spartan.skill[0].type='b';
spartan.skill[0].cd=-1;
spartan.skill[0].bcd=-1;
spartan.skill[0].des="Deal dmg to an enemy. Spartan has 50% chance to gain Block.";
void spartarslash(){
	base_dmg=1.6;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
		if(rand()%2>0)gain(turn,"Block",-1);
	}
}
spartan.skill[1].name="Shield Bash";

spartan.skill[1].type='s';
spartan.skill[1].cd=0;
spartan.skill[1].bcd=2;
spartan.skill[1].des="Deal dmg to an enemy. If Spartan has Block and this skill hits the enemy, Stun the enemy if they aren't already had Stun, then Spartan loses Block.";
void shieldbash(){
	base_dmg=2.4;
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(!pos[enemy].stun&&pos[turn].block==true&&pos[enemy].hp>0){
				pos[turn].block=false;
				cout<<pos[turn].name<<" loses Block!\n";
				stun(enemy);
			}
		}
	}
}
void spartan_skill(int skill_num){
	if(skill_num==1)spartarslash();
	else shieldbash();
}
champions.push_back(spartan);
