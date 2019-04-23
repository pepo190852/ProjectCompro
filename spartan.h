#include "form.h"
#include "skill_function.h"
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
void spartan_skill(int skill_num){
	if(skill_num==1)spartarslash();
	else shieldbash();
}
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
champions.push_back(spartan);
