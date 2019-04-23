#include "form.h"
#include "skill_function.h"
champion monk;
monk.name="Monk";
monk.role="Support";
monk.id=8;
monk.hp=133;
monk.atk=17;
monk.def=12;
monk.spd=17;
monk.tag.push_back("Asian");
monk.tag.push_back("Mystic");
monk.tag.push_back("Medieval");
void monk_skill(int skill_num){
	if(skill_num==1)staffslam();
	else enlighten();
}
monk.skill[0].name="Staff Slam";
monk.skill[0].type='b';
monk.skill[0].cd=-1;
monk.skill[0].bcd=-1;
monk.skill[0].des="Deal dmg to an enemy. 50% chance to Stun them. Can't be evaded.";
void staffslam(){
	base_dmg=1;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		block();
		deal_dmg(base_dmg,pos[enemy].current_stat.def);
		if(pos[enemy].hp>0){
			if(rand()%2==1)stun(enemy);
		}
	}
}
monk.skill[1].name="Enlighten";
monk.skill[1].type='s';
monk.skill[1].cd=0;
monk.skill[1].bcd=5;
monk.skill[1].des="Remove Blind from all allies and Evade from all enemies which can't be evaded. All allies gain 50% turn meter and Attack Up for 1 turn.";
void enlighten(){
	system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].blind&&pos[i].hp>0){
				pos[i].blind=false;
				cout<<pos[i].name<<" loses Blind!\n";
			}
		}
		for(int i=0;i<10;i++){
			if(pos[i].player!=pos[turn].player&&pos[i].evade&&pos[i].hp>0){
				pos[i].evade=false;
				cout<<pos[i].name<<" loses Evade!\n";
			}
		}
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp>0){
				gain_turn_meter(i,50);
				gain(i,"Attack Up",1);
			}
		}
}
champions.push_back(monk);
