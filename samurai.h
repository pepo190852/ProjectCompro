#include "draft.h"
#include "form.h"
#include "skill_function.h"
champion samurai;
samurai.name="Samurai";
samurai.role="Attacker";
samurai.id=1;
samurai.hp=144;
samurai.atk=18;
samurai.def=14;
samurai.spd=15;
samurai.tag.push_back("Japanese");
samurai.tag.push_back("Asian");
samurai.tag.push_back("Medieval");
samurai.tag.push_back("Steel");
void samurai_skill(int skill_num){
	if(skill_num==1)katanadraw();
	else kamikaze();
}
samurai.skill[0].name="Katana Draw";
samurai.skill[0].type='b';
samurai.skill[0].cd=-1;
samurai.skill[0].bcd=-1;
samurai.skill[0].des="Deal dmg to an enemy. +1% Damage per each 1% of max hp lost from Samurai.";
void katanadraw(){
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			double hp_lost_percent;
			hp_lost_percent=pos[turn].current_stat.max_hp-pos[turn].hp;
			hp_lost_percent=(hp_lost_percent*100)/pos[turn].current_stat.max_hp;
			hp_lost_percent/=100;
			base_dmg+=base_dmg*hp_lost_percent;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
samurai.skill[1].name="Kamikaze";
samurai.skill[1].type='s';
samurai.skill[1].cd=0;
samurai.skill[1].bcd=3;
samurai.skill[1].des="Deal dmg to an enemy. If this attack hits, Samurai also takes 20% of the damage but will not be defeated by this damage.";
void kamikaze(){
	base_dmg=4.4;
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			block();
	int dmg;
	double multiplier,num=20;
	multiplier=num/(pos[turn].current_stat.def+num);
	dmg=0.88*pos[turn].current_stat.atk*multiplier;
	int unstable=dmg/10;
	if(unstable>0){
		unstable=(rand()%((unstable*2)+1))-unstable;
	dmg+=unstable;
	}
	pos[turn].hp-=dmg;
	if(pos[turn].hp<=0)pos[enemy].hp=1;
	cout<<pos[turn].name<<" takes "<<dmg<<" damage! HP : "<<pos[turn].hp<<"/"pos[turn].current_stat.max_hp<<"\n";
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
champions.push_back(samurai);
