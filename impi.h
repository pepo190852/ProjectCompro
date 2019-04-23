#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion impi;
impi.name="Impi";
impi.role="Attacker";
impi.id=11;
impi.hp=144;
impi.atk=15;
impi.def=13;
impi.spd=17;
impi.tag.push_back("African");
impi.tag.push_back("Iron");
impi.tag.push_back("Medieval");
void impi_skill(int skill_num){
	if(skill_num==1)iklwa();
	else combatreflexes();
}
impi.skill[0].name="Iklwa";
impi.skill[0].type='b';
impi.skill[0].cd=-1;
impi.skill[0].bcd=-1;
impi.skill[0].des="Deal dmg to an enemy, This attack can't be blocked and will dispel Block if the enemy has.";
void iklwa(){
	base_dmg=1.6;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].block&&pos[enemy].hp>0){
				pos[enemy].block=false;
				cout<<pos[enemy].name<<" loses Block!\n";
			}
		}
	}
}
impi.skill[1].name="Combat Reflexes";
impi.skill[1].type='s';
impi.skill[1].cd=0;
impi.skill[1].bcd=3;
impi.skill[1].des="Impi gain 100% turn meter and Attack Up for 1 turn";
void combatreflexes(){
	system("CLS");
		skill_use(1);
		gain_turn_meter(turn,100);
		gain(turn,"Attack Up",1);
}
champions.push_back(impi);
