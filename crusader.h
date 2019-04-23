#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion crusader;
crusader.name="Crusader";
crusader.role="Tank";
crusader.id=4;
crusader.hp=156;
crusader.atk=14;
crusader.def=17;
crusader.spd=12;
crusader.tag.push_back("European");
crusader.tag.push_back("Medieval");
crusader.tag.push_back("Steel");
void crusader_skill(int skill_num){
	if(skill_num==1)pilgrimslash();
	else faithfulpraying();
}
crusader.skill[0].name="Pilgrim Slash";
crusader.skill[0].type='b';
crusader.skill[0].cd=-1;
crusader.skill[0].bcd=-1;
crusader.skill[0].des="Deal dmg to an enemy. Applies Attack Down to the enemy for 1 turn. Deal 25% more damage to Middle-Eastern.";
void pilgrimslash(){
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			if(find_tag(enemy,"Middle-Eastern"))base_dmg*=1.25;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0&&)gain(enemy,"Attack Down",1);
		}
	}
}
crusader.skill[1].name="Faithful Praying";
crusader.skill[1].type='s';
crusader.skill[1].cd=0;
crusader.skill[1].bcd=5;
crusader.skill[1].des="Dispel all Debuffs from All Allies. All allies recover 25% of Max HP.";
void faithfulpraying(){
	system("CLS");
	skill_use(1);
	for(int i=0;i<10;i++){
		if(pos[i].player==pos[turn].player&&pos[i].hp>0){
			int temp=dispel_debuff(i);
			heal(i,pos[i].current_stat.max_hp/4);
		}
	}
}
champions.push_back(crusader);
