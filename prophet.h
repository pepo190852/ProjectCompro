#include "form.h"
#include "skill_function.h"
#include "draft.h"
champion prophet;
prophet.name="Prophet";
prophet.role="Support";
prophet.id=12;
prophet.hp=133;
prophet.atk=15;
prophet.def=13;
prophet.spd=12;
prophet.tag.push_back("Mesoamerican");
prophet.tag.push_back("American");
prophet.tag.push_back("Mystic");
prophet.tag.push_back("Classical");
void prophet_skill(int skill_num){
	if(skill_num==1)baktunshiftingstrike();
	else celestialapocalypse();
}
prophet.skill[0].name="B'aktun-Shifting Strike";
prophet.skill[0].type='b';
prophet.skill[0].cd=-1;
prophet.skill[0].bcd=-1;
prophet.skill[0].des="Deal dmg to an enemy. Targeted enemy and 50% chance for other enemies to have their cooldown increased by 1. Prophet and 50% for other allies to have their cooldown reduced by 1. Cooldown reduction can't be evaded.";
void baktunshiftingstrike(){
	base_dmg=1.2;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp>0){
				if(i==turn){
					if(pos[i].skill[1].cd>0)pos[i].skill[1].cd--;
					cout<<pos[i].name<<"'s cooldown reduced by 1!\n";
				}else{
					if(rand()%2==1){
						if(pos[i].skill[1].cd>0)pos[i].skill[1].cd--;
						cout<<pos[i].name<<"'s cooldown reduced by 1!\n";
					}
				}
			}else if(pos[i].player!=pos[turn].player&&pos[i].hp>0){
				if(i==enemy){
					pos[i].skill[1].cd++;
					cout<<pos[i].name<<"'s cooldown increased by 1!\n";
				}else{
					if(rand()%2==1){
						pos[i].skill[1].cd++;
						cout<<pos[i].name<<"'s cooldown increased by 1!\n";
					}
				}
			}
		}
	}
}
prophet.skill[1].name="Celestial Apocalypse";
prophet.skill[1].type='s';
prophet.skill[1].cd=9;
prophet.skill[1].bcd=9;
prophet.skill[1].des="Deal dmg to all enemies which can't be evaded. Starts on cooldown.";
void celestialapocalypse(){
	base_dmg=5.2;
	system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player!=pos[turn].player&&pos[i].hp>0){
				enemy=i;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
		}
}
champions.push_back(prophet);
