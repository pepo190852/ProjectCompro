#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion eagle;
eagle.name="Eagle";
eagle.role="Tank";
eagle.id=13;
eagle.hp=167;
eagle.atk=14;
eagle.def=16;
eagle.spd=14;
eagle.tag.push_back("Mesoamerican");
eagle.tag.push_back("American");
eagle.tag.push_back("Obsidian");
eagle.tag.push_back("Medieval");
void eagle_skill(int skill_num){
	if(skill_num==1)obsidianlance();
	else guardianeagle();
}
eagle.skill[0].name="Obsidian Lance";
eagle.skill[0].type='b';
eagle.skill[0].cd=-1;
eagle.skill[0].bcd=-1;
eagle.skill[0].des="Deal dmg to an enemy. This attack has 25% defense penetration which is doubled agains enemies without Stealth.";
void obsidianlance(){
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			if(!pos[enemy].stealth)deal_dmg(base_dmg,pos[enemy].current_stat.def/2);
			else deal_dmg(base_dmg,pos[enemy].current_stat.def*0.75);
		}
	}
}
eagle.skill[1].name="Guardian Eagle";
eagle.skill[1].type='s';
eagle.skill[1].cd=0;
eagle.skill[1].bcd=4;
eagle.skill[1].des="Dispel all Debuffs from Eagle and gain Block. Eagle permanently gain +1 Defense and +10 Max HP.";
void guardianeagle(){
	system("CLS");
		skill_use(1);
		pos[turn].base_stat.def++;
		pos[turn].base_stat.max_hp+=10;
		dispel_debuff(turn);
		gain(turn,"Block",-1);
}
champions.push_back(eagle);
