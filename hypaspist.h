#include "form.h"
#include "skill_function.h"
champion hypaspist;
hypaspist.name="Hypaspist";
hypaspist.role="Attacker";
hypaspist.id=17;
hypaspist.hp=133;
hypaspist.atk=15;
hypaspist.def=12;
hypaspist.spd=17;
hypaspist.tag.push_back("Greek");
hypaspist.tag.push_back("Mediterranean");
hypaspist.tag.push_back("Bronze");
hypaspist.tag.push_back("Classical");
void hypaspist_skill(int skill_num){
	if(skill_num==1)dorybarrage();
	else mobilizing();
}
hypaspist.skill[0].name="Dory Barrage";
hypaspist.skill[0].type='b';
hypaspist.skill[0].cd=-1;
hypaspist.skill[0].bcd=-1;
hypaspist.skill[0].des="Deal dmg to an enemy 2 times.";
void dorybarrage(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		for(int i=0;i<2;i++){
			if(hit()){
				base_dmg=1.0;	
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
		}
	}
}
hypaspist.skill[1].name="Mobilizing";
hypaspist.skill[1].type='s';
hypaspist.skill[1].cd=0;
hypaspist.skill[1].bcd=5;
hypaspist.skill[1].des="Hypaspist gain 50% turn meter and Speed Up for 2 turns, other allies gain half the amount and have 50% chance to also gain Speed Up for 2 turns.";
void mobilizing(){
		system("CLS");
		skill_use(1);
		gain_turn_meter(turn,50);
		gain(turn,"Speed Up",2);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&i!=turn&&pos[i].hp>0){
				gain_turn_meter(i,25);
				if(rand()%2==1)gain(i,"Speed Up",2);
			}
		}
}
champions.push_back(hypaspist);
