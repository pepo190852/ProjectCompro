#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion shaman;
shaman.name="Shaman";
shaman.role="Support";
shaman.id=9;
shaman.hp=167;
shaman.atk=14;
shaman.def=13;
shaman.spd=13;
shaman.tag.push_back("American");
shaman.tag.push_back("Amerindian");
shaman.tag.push_back("Mystic");
shaman.tag.push_back("Ancient");
void shaman_skill(int skill_num){
	if(skill_num==1)spiritualassault();
	else hallucination();
}
shaman.skill[0].name="Spiritual Assault";
shaman.skill[0].type='b';
shaman.skill[0].cd=-1;
shaman.skill[0].bcd=-1;
shaman.skill[0].des="Deal dmg to an enemy. Remove 10% turn meter from all enemies.";
void spiritualassault(){
	base_dmg=1.2;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
		for(int i=0;i<10;i++){
			if(pos[i].player!=pos[turn].player&&pos[i].hp>0){
				remove_turn_meter(i,10);
			}
		}
	}
}
shaman.skill[1].name="Hallucination";
shaman.skill[1].type='s';
shaman.skill[1].cd=0;
shaman.skill[1].bcd=5;
shaman.skill[1].des="Apllies Blind to all enemies which can't be evaded. All allies have their health percentage equalized, then they heal for 25% of their max hp.";
void hallucination(){
	int total_max_hp=0,total_hp=0;
	double percentage=0;
	system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player!=pos[turn].player&&pos[i].hp>0)gain(i,"Blind",-1);
		}
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp>0){
				total_max_hp+=pos[i].current_stat.max_hp;
				total_hp+=pos[i].hp;
			}
		}
		percentage=(total_hp*100)/total_max_hp;
		percentage/=100;
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp>0){
				pos[i].hp=pos[i].current_stat.max_hp*percentage;
				cout<<pos[i].name<<"'s HP set to"<<pos[i].hp<<"!\n";
				heal(i,pos[i].current_stat/4);
			}
		}
}
champions.push_back(shaman);
