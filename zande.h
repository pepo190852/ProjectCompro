#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion zande;
zande.name="Zande";
zande.role="Attacker";
zande.id=18;
zande.hp=144;
zande.atk=16;
zande.def=13;
zande.spd=14;
zande.tag.push_back("African");
zande.tag.push_back("Iron");
zande.tag.push_back("Classical");
void zande_skill(int skill_num){
	if(skill_num==1)decapitator();
	else savagespirit();
}
zande.skill[0].name="Decapitator";
zande.skill[0].type='b';
zande.skill[0].cd=-1;
zande.skill[0].bcd=-1;
zande.skill[0].des="Deal dmg to an enemy. If the enemy's health is below 25%, this attack ignores defense. On finishing blow, Zande recovers 50% of max HP.";
void decapitator(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.0;	
				block();
				if(pos[enemy].hp<pos[enemy].current_stat.max_hp/4)deal_dmg(base_dmg,0);
				else deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp==0)heal(turn,pos[turn].current_stat.max_hp);
			}
	}
}
zande.skill[1].name="Savage Spirit";
zande.skill[1].type='s';
zande.skill[1].cd=0;
zande.skill[1].bcd=4;
zande.skill[1].des="Dispel all Debuffs from Zande. Zande gains 20% turn meter and recovers 15% of max HP per each debuff dispelled.";
void savagespirit(){
		system("CLS");
		skill_use(1);
		int count=dispel_debuff(turn);
		if(count>0){
			gain_turn_meter(turn,20*count);
		heal(turn,pos[turn].current_stat.max_hp*0.15*count);
		}
}
champions.push_back(zande);
