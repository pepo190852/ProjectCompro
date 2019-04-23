#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion hoplite;
hoplite.name="Hoplite";
hoplite.role="Tank";
hoplite.id=16;
hoplite.hp=156;
hoplite.atk=15;
hoplite.def=16;
hoplite.spd=13;
hoplite.tag.push_back("Greek");
hoplite.tag.push_back("Mediterranean");
hoplite.tag.push_back("Bronze");
hoplite.tag.push_back("Classical");
void hoplite_skill(int skill_num){
	if(skill_num==1)steadythrust();
	else phalanx();
}
hoplite.skill[0].name="Steady Thrust";
hoplite.skill[0].type='b';
hoplite.skill[0].cd=-1;
hoplite.skill[0].bcd=-1;
hoplite.skill[0].des="Deal dmg to an enemy. If Hoplite has Block, heals Greek allies for 5% of max HP.";
void steadythrust(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		bool add=false;
		system("CLS");
		skill_use(0);
		if(hit()){
			base_dmg=1.8;	
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}if(pos[turn].block){
				for(int i=0;i<10;i++){
					if(pos[i].player==pos[turn].player&&pos[i].hp>0&&find_tag(i,"Greek"))heal(i,pos[i].current_stat.max_hp/20);
				}
			}
	}
}
hoplite.skill[1].name="Phalanx";
hoplite.skill[1].type='s';
hoplite.skill[1].cd=0;
hoplite.skill[1].bcd=4;
hoplite.skill[1].des="All allies gain Block and Defense Up for 2 turns.";
void phalanx(){
		system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp>0){
				gain(i,"Block",-1);
				gain(i,"Defense Up",2);
			}
		}
}
champions.push_back(hoplite);
