#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion gladiator;
gladiator.name="Gladiator";
gladiator.role="Attacker";
gladiator.id=15;
gladiator.hp=178;
gladiator.atk=16;
gladiator.def=12;
gladiator.spd=14;
gladiator.tag.push_back("Roman");
gladiator.tag.push_back("Mediterranean");
gladiator.tag.push_back("Iron");
gladiator.tag.push_back("Classical");
void gladiator_skill(int skill_num){
	if(skill_num==1)tridentattack();
	else quarternet();
}
gladiator.skill[0].name="Trident Attack";
gladiator.skill[0].type='b';
gladiator.skill[0].cd=-1;
gladiator.skill[0].bcd=-1;
gladiator.skill[0].des="Deal dmg to an enemy. Applies Defense Down for 2 turns. If the enemy already has Defense Down, Gladiator gains Attack Up for 1 turn.";
void tridentattack(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		bool add=false;
		system("CLS");
		skill_use(0);
		if(pos[enemy].def_down>0)add=true;
		if(hit()){
			base_dmg=1.4;	
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0)gain(enemy,"Defense Down",2);
			}if(add)gain(turn,"Attack Up",1);
	}
}
gladiator.skill[1].name="Quarter Net";
gladiator.skill[1].type='s';
gladiator.skill[1].cd=0;
gladiator.skill[1].bcd=5;
gladiator.skill[1].des="Stun, remove 100% turn meter and all Buffs, then applies Knock to the enemy for 2 turns.";
void quarternet(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			stun(enemy);
			remove_turn_meter(enemy,100);
			dispel_buff(enemy);
			gain(enemy,"Knock",2);
			}
	}
}
champions.push_back(gladiator);
