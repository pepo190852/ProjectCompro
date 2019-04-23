#include "form.h"
#include "skill_function.h"
champion berserker;
berserker.name="Berserker";
berserker.role="Attacker";
berserker.id=2;
berserker.hp=178;
berserker.atk=14;
berserker.def=14;
berserker.spd=14;
berserker.tag.push_back("Norse");
berserker.tag.push_back("Scandinavian");
berserker.tag.push_back("Medieval");
berserker.tag.push_back("Iron");
void berserker_skill(int skill_num){
	if(skill_num==1)furyswipe();
	else enrage();
}
berserker.skill[0].name="Fury Swipe";
berserker.skill[0].type='b';
berserker.skill[0].cd=-1;
berserker.skill[0].bcd=-1;
berserker.skill[0].des="Deal dmg to an enemy. +1% Damage per each 2% of max hp left on the enemy.";
void furyswipe(){
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			double multiplier;
			multiplier=(pos[enemy].hp*100)/pos[enemy].current_stat.max_hp;
			multiplier/=200;
			base_dmg+=base_dmg*multiplier;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
berserker.skill[1].name="Enrage";
berserker.skill[1].type='s';
berserker.skill[1].cd=0;
berserker.skill[1].bcd=2;
berserker.skill[1].des="Heal self for 15% of max health. Gain 50% turn meter, Attack Up and Speed Up for 1 turn.";
void enrage(){
	system("CLS");
	skill_use(1);
	heal(turn,pos[turn].current_stat.max_hp*0.15);
	gain_turn_meter(turn,50);
	gain(turn,"Attack Up",1);
	gain(turn,"Speed Up",1);
}
champions.push_back(berserker);
