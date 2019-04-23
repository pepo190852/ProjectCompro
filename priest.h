#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion priest;
priest.name="Priest";
priest.role="Support";
priest.id=10;
priest.hp=122;
priest.atk=15;
priest.def=12;
priest.spd=13;
priest.tag.push_back("Mesopotamian");
priest.tag.push_back("African");
priest.tag.push_back("Mystic");
priest.tag.push_back("Ancient");
void priest_skill(int skill_num){
	if(skill_num==1)cursedstaff();
	else shallowtomb();
}
priest.skill[0].name="Cursed Staff";
priest.skill[0].type='b';
priest.skill[0].cd=-1;
priest.skill[0].bcd=-1;
priest.skill[0].des="Deal dmg to an enemy. 50% chance to dispel all Buffs from the enemy.";
void cursedstaff(){
	base_dmg=1.6;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0){
				if(rand()%2==1)dispel_buff(enemy);
			}
		}
	}
}
priest.skill[1].name="Shallow Tomb";
priest.skill[1].type='s';
priest.skill[1].cd=0;
priest.skill[1].bcd=5;
priest.skill[1].des="Revives a random ally at 25% of their max HP. Mesopotamian allies always take the priority and revive at 50% HP instead with 100% turn meter.";
void shallowtomb(){
	vector<int> revive_position;
	int r=0;
	system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp==0){
				if(find_tag(i,"Mesopotamian"))revive_position.push_back(i);
			}
		}if(revive_position.size()==0){
			for(int i=0;i<10;i++){
				if(pos[i].player==pos[turn].player&&pos[i].hp==0)revive_position.push_back(i);
			}
			r=revive_position[rand()%revive_position.size()];
			revive(r,pos[r].current_stat.max_hp/4);
		}else{
			r=revive_position[rand()%revive_position.size()];
			revive(r,pos[r].current_stat.max_hp/2);
			gain_turn_meter(r,100);
		}
}
champions.push_back(priest);
