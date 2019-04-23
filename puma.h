#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion puma;
puma.name="Puma";
puma.role="Attacker";
puma.id=14;
puma.hp=167;
puma.atk=15;
puma.def=13;
puma.spd=12;
puma.tag.push_back("Andean");
puma.tag.push_back("American");
puma.tag.push_back("Bronze");
puma.tag.push_back("Medieval");
void puma_skill(int skill_num){
	if(skill_num==1)grandcleave();
	else risingaltitude();
}
puma.skill[0].name="Grand Cleave";
puma.skill[0].type='b';
puma.skill[0].cd=-1;
puma.skill[0].bcd=-1;
puma.skill[0].des="Deal dmg to all enemies.";
void grandcleave(){
	system("CLS");
	skill_use(0);
	for(int i=0;i<10;i++){
		if(pos[i].player!=pos[turn].player&&pos[i].hp>0){
			enemy=i;
			if(hit()){
			base_dmg=1.6;	
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
		}
	}
}
puma.skill[1].name="Rising Altitude";
puma.skill[1].type='s';
puma.skill[1].cd=0;
puma.skill[1].bcd=2;
puma.skill[1].des="Deal dmg to an enemy. Dispel all Buffs from them. Puma permanently gains +1 Attack.";
void risingaltitude(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			base_dmg=2.2;	
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0)int temp=dispel_buff(enemy);
			}pos[turn].base_stat.atk++;
	}
}
champions.push_back(puma);
