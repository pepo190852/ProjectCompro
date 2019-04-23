#include "form.h"
#include "skill_function.h"
champion ninja;
ninja.name="Ninja";
ninja.role="Attacker";
ninja.id=7;
ninja.hp=122;
ninja.atk=16;
ninja.def=13;
ninja.spd=18;
ninja.tag.push_back("Japanese");
ninja.tag.push_back("Asian");
ninja.tag.push_back("Medieval");
ninja.tag.push_back("Steel");
void ninja_skill(int skill_num){
	if(skill_num==1)shuriken();
	else blackegg();
}
ninja.skill[0].name="Shuriken";
ninja.skill[0].type='b';
ninja.skill[0].cd=-1;
ninja.skill[0].bcd=-1;
ninja.skill[0].des="Deal dmg to an enemy. If this attack is not blocked, It will deals Double damage.";
void shuriken(){
	base_dmg=1.4;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			if(!pos[enemy].block)base_dmg*=2;
			else block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
ninja.skill[1].name="Black Egg";
ninja.skill[1].type='s';
ninja.skill[1].cd=0;
ninja.skill[1].bcd=3;
ninja.skill[1].des="Apllies Blind to the enemy and if there is at least one another ally, Ninja gains Stealth for 2 turns, else Ninja gains Evade and 50% turn meter instead.";
void blackegg(){
	bool another_ally=false;
	system("CLS");
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			gain(enemy,"Blind",-1);
		}for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&i!=turn&&pos[i].hp>0){
				another_ally=true;
				break;
			}
		}if(another_ally)gain(turn,"Stealth",2);
		else{
			gain(turn,"Evade",-1);
			gain_turn_meter(turn,50);
		}
	}
}
champions.push_back(ninja);
