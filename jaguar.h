#include "form.h"
#include "skill_function.h"
champion jaguar;
jaguar.name="Jaguar";
jaguar.role="Attacker";
jaguar.id=3;
jaguar.hp=144;
jaguar.atk=17;
jaguar.def=13;
jaguar.spd=18;
jaguar.tag.push_back("Mesoamerican");
jaguar.tag.push_back("American");
jaguar.tag.push_back("Medieval");
jaguar.tag.push_back("Obsidian");
void jaguar_skill(int skill_num){
	if(skill_num==1)macuahuitlsmash();
	else predatorsense();
}
jaguar.skill[0].name="Macuahuitl Smash";
jaguar.skill[0].type='b';
jaguar.skill[0].cd=-1;
jaguar.skill[0].bcd=-1;
jaguar.skill[0].des="Deal dmg to an enemy. Inflicts Bleed for 3 turns. If this attack defeats the enemy, Jaguar gain 100% turn meter.";
void macuahuitlsmash(){
	base_dmg=1.2;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0)inflict_bleed(enemy,3);
			else gain_turn_meter(turn,100);
		}
	}
}
jaguar.skill[1].name="Predator Sense";
jaguar.skill[1].type='s';
jaguar.skill[1].cd=0;
jaguar.skill[1].bcd=4;
jaguar.skill[1].des="Jaguar permanently gain +1 Attack and Speed. Jaguar gain Stealth for 2 turns and enemy Stealth from all enemies which can't be eveded.";
void predatorsense(){
	system("CLS");
	skill_use(1);
	pos[turn].base_stat.atk++;
	pos[turn].base_stat.spd++;
	gain(turn,"Stealth",2);
	for(int i=0;i<10;i++){
		if(pos[i].player!=pos[turn].player&&pos[i].stealth>0&&pos[i].hp>0){
			pos[i].stealth=0;
			cout<<pos[i].name<<" loses Stealth!\n";
		}
	}
}
champions.push_back(jaguar);
