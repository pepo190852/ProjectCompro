#include "form.h"
#include "skill_function.h"
champion legion;
legion.name="Legion";
legion.role="Tank";
legion.id=6;
legion.hp=178;
legion.atk=14;
legion.def=13;
legion.spd=13;
legion.tag.push_back("Roman");
legion.tag.push_back("Mediterranean");
legion.tag.push_back("Classical");
legion.tag.push_back("Iron");
void legion_skill(int skill_num){
	if(skill_num==1)gladiusslash();
	else clearthepath();
}
legion.skill[0].name="Gladius Slash";
legion.skill[0].type='b';
legion.skill[0].cd=-1;
legion.skill[0].bcd=-1;
legion.skill[0].des="Deal dmg to an enemy. +25% damage per defeated enemies.";
void gladiusslash(){
	base_dmg=1.4;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			for(int i=0;i<10;i++){
				if(pos[i].player!=pos[turn].player&&pos[i].hp==0)base_dmg+=0.35;
			}
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
legion.skill[1].name="Clear the path";
legion.skill[1].type='s';
legion.skill[1].cd=0;
legion.skill[1].bcd=4;
legion.skill[1].des="Deal dmg to an enemy. Dispel all Buffs from them and Legion gain Protect for 1 turn. Other Roman allies gain 50% turn meter.";
void clearthepath(){
	base_dmg=2.0;
	system("CLS");
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0){
				int temp=dispel_buff(enemy);
			}
		}gain(turn,"Protect",1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&find_tag(i,"Roman")&&i!=turn)gain_turn_meter(i,50);
		}
	}
}
champions.push_back(legion);
