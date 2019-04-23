#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion khopesh;
khopesh.name="Khopesh";
khopesh.role="Attacker";
khopesh.id=5;
khopesh.hp=144;
khopesh.atk=15;
khopesh.def=13;
khopesh.spd=13;
khopesh.tag.push_back("Mesopotamian");
khopesh.tag.push_back("Ancient");
khopesh.tag.push_back("Bronze");
khopesh.tag.push_back("African");
void khopesh_skill(int skill_num){
	if(skill_num==1)scythecleave();
	else rejuvenate();
}
khopesh.skill[0].name="Scythe Cleave";
khopesh.skill[0].type='b';
khopesh.skill[0].cd=-1;
khopesh.skill[0].bcd=-1;
khopesh.skill[0].des="Deal dmg to an enemy. If the enemy has less than 50%, deals Double damage.";
void scythecleave(){
	base_dmg=1.4;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			if(pos[enemy].hp<pos[enemy].current_stat.max_hp/2)base_dmg*=2;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
khopesh.skill[1].name="Rejuvenate";
khopesh.skill[1].type='s';
khopesh.skill[1].cd=0;
khopesh.skill[1].bcd=5;
khopesh.skill[1].des="Recover 100% HP, Gain 50% turn meter and Attack Up for 1 turn.";
void rejuvenate(){
	system("CLS");
	skill_use(1);
	heal(turn,pos[turn].current_stat.max_hp);
	gain_turn_meter(turn,50);
	gain(turn,"Attack Up",1);
}
champions.push_back(khopesh);
