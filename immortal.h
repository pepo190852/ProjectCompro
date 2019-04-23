#include "form.h"
#include "skill_function.h"
champion immortal;
immortal.name="Immortal";
immortal.role="Tank";
immortal.id=19;
immortal.hp=144;
immortal.atk=13;
immortal.def=15;
immortal.spd=14;
immortal.tag.push_back("Middle-Eastern");
immortal.tag.push_back("Bronze");
immortal.tag.push_back("Classical");
void immortal_skill(int skill_num){
	if(skill_num==1)mortalsmack();
	else immortalize();
}
immortal.skill[0].name="Mortal Smack";
immortal.skill[0].type='b';
immortal.skill[0].cd=-1;
immortal.skill[0].bcd=-1;
immortal.skill[0].des="Deal dmg to an enemy. Applies Heal Block for 1 turn.";
void mortalsmack(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.8;	
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp>0)gain(enemy,"Heal Block",1);
			}
	}
}
immortal.skill[1].name="Immortalize";
immortal.skill[1].type='s';
immortal.skill[1].cd=0;
immortal.skill[1].bcd=2;
immortal.skill[1].des="Remove Heal Block from Immortal if there is. Recovers 25% of lost HP. Gain Block and Defense Up for 1 turn. Also gain Regeneration for 1 turns.";
void immortalize(){
		system("CLS");
		skill_use(1);
		if(pos[turn].heal_block>0){
			pos[turn].heal_block=0;
			cout<<pos[turn].name<<" loses Heal Block!\n";
		}int lost_hp=pos[turn].current_stat-pos[turn].hp;
		heal(turn,lost_hp/4);
		gain(turn,"Block",-1);
		gain(turn,"Defense Up",1);
		gain_regeneration(turn,1);
}
champions.push_back(immortal);
