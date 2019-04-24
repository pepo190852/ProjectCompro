#include "form.h"
#include "skill_function.h"


champion samurai;
declare() {
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
	void samurai_skill(int skill_num) {
		if(skill_num==1)katanadraw();
		else kamikaze();
	}
	samurai.skill[0].name="Katana Draw";
	samurai.skill[0].type='b';
	samurai.skill[0].cd=-1;
	samurai.skill[0].bcd=-1;
	samurai.skill[0].des="Deal dmg to an enemy. +1% Damage per each 1% of max hp lost from Samurai.";
	void katanadraw() {
		base_dmg=1.8;
		enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
		if(enemy!=-2) {
			system("CLS");
			skill_use(0);
			if(hit()) {
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
	void kamikaze() {
		base_dmg=4.4;
		enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
		if(enemy!=-2) {
			system("CLS");
			skill_use(1);
			if(hit()) {
				block();
				int dmg;
				double multiplier,num=20;
				multiplier=num/(pos[turn].current_stat.def+num);
				dmg=0.88*pos[turn].current_stat.atk*multiplier;
				int unstable=dmg/10;
				if(unstable>0) {
					unstable=(rand()%((unstable*2)+1))-unstable;
					dmg+=unstable;
				}
				pos[turn].hp-=dmg;
				if(pos[turn].hp<=0)pos[enemy].hp=1;
				cout<<pos[turn].name<<" takes "<<dmg<<" damage! HP : "<<pos[turn].hp<<"/"<<pos[turn].current_stat.max_hp<<"\n";
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
		}
	}
	champions.push_back(samurai);
}

champion berserker;
declare(){
	berserker.name="Berserker";
berserker.role="Attacker";
berserker.id=2;
berserker.hp=178;
berserker.atk=14;
berserker.def=14;
berserker.spd=14;
berserker.tag.push_back("Norse");
berserker.tag.push_back("Scandinavian");
berserker.tag.push_back("Medieval");
berserker.tag.push_back("Iron");
void berserker_skill(int skill_num) {
	if(skill_num==1)furyswipe();
	else enrage();
}
berserker.skill[0].name="Fury Swipe";
berserker.skill[0].type='b';
berserker.skill[0].cd=-1;
berserker.skill[0].bcd=-1;
berserker.skill[0].des="Deal dmg to an enemy. +1% Damage per each 2% of max hp left on the enemy.";
void furyswipe() {
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
			double multiplier;
			multiplier=(pos[enemy].hp*100)/pos[enemy].current_stat.max_hp;
			multiplier/=200;
			base_dmg+=base_dmg*multiplier;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
berserker.skill[1].name="Enrage";
berserker.skill[1].type='s';
berserker.skill[1].cd=0;
berserker.skill[1].bcd=2;
berserker.skill[1].des="Heal self for 15% of max health. Gain 50% turn meter, Attack Up and Speed Up for 1 turn.";
void enrage() {
	system("CLS");
	skill_use(1);
	heal(turn,pos[turn].current_stat.max_hp*0.15);
	gain_turn_meter(turn,50);
	gain(turn,"Attack Up",1);
	gain(turn,"Speed Up",1);
}
champions.push_back(berserker);
}

champion jaguar;
declare(){
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
void jaguar_skill(int skill_num) {
	if(skill_num==1)macuahuitlsmash();
	else predatorsense();
}
jaguar.skill[0].name="Macuahuitl Smash";
jaguar.skill[0].type='b';
jaguar.skill[0].cd=-1;
jaguar.skill[0].bcd=-1;
jaguar.skill[0].des="Deal dmg to an enemy. Inflicts Bleed for 3 turns. If this attack defeats the enemy, Jaguar gain 100% turn meter.";
void macuahuitlsmash() {
	base_dmg=1.2;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
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
void predatorsense() {
	system("CLS");
	skill_use(1);
	pos[turn].base_stat.atk++;
	pos[turn].base_stat.spd++;
	gain(turn,"Stealth",2);
	for(int i=0; i<10; i++) {
		if(pos[i].player!=pos[turn].player&&pos[i].stealth>0&&pos[i].hp>0) {
			pos[i].stealth=0;
			cout<<pos[i].name<<" loses Stealth!\n";
		}
	}
}
champions.push_back(jaguar);
}

champion crusader;
declare(){
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
void crusader_skill(int skill_num) {
	if(skill_num==1)pilgrimslash();
	else faithfulpraying();
}
crusader.skill[0].name="Pilgrim Slash";
crusader.skill[0].type='b';
crusader.skill[0].cd=-1;
crusader.skill[0].bcd=-1;
crusader.skill[0].des="Deal dmg to an enemy. Applies Attack Down to the enemy for 1 turn. Deal 25% more damage to Middle-Eastern.";
void pilgrimslash() {
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
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
void faithfulpraying() {
	system("CLS");
	skill_use(1);
	for(int i=0; i<10; i++) {
		if(pos[i].player==pos[turn].player&&pos[i].hp>0) {
			int temp=dispel_debuff(i);
			heal(i,pos[i].current_stat.max_hp/4);
		}
	}
}
champions.push_back(crusader);
}

champion khopesh;
declare(){
	khopesh.name="Khopesh";
khopesh.role="Attacker";
khopesh.id=5;
khopesh.hp=144;
khopesh.atk=15;
khopesh.def=13;
khopesh.spd=13;
khopesh.tag.push_back("Mesopotamian");
khopesh.tag.push_back("Ancient");
khopesh.tag.push_back("Bronze");
khopesh.tag.push_back("African");
void khopesh_skill(int skill_num) {
	if(skill_num==1)scythecleave();
	else rejuvenate();
}
khopesh.skill[0].name="Scythe Cleave";
khopesh.skill[0].type='b';
khopesh.skill[0].cd=-1;
khopesh.skill[0].bcd=-1;
khopesh.skill[0].des="Deal dmg to an enemy. If the enemy has less than 50%, deals Double damage.";
void scythecleave() {
	base_dmg=1.4;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
			if(pos[enemy].hp<pos[enemy].current_stat.max_hp/2)base_dmg*=2;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
khopesh.skill[1].name="Rejuvenate";
khopesh.skill[1].type='s';
khopesh.skill[1].cd=0;
khopesh.skill[1].bcd=5;
khopesh.skill[1].des="Recover 100% HP, Gain 50% turn meter and Attack Up for 1 turn.";
void rejuvenate() {
	system("CLS");
	skill_use(1);
	heal(turn,pos[turn].current_stat.max_hp);
	gain_turn_meter(turn,50);
	gain(turn,"Attack Up",1);
}
champions.push_back(khopesh);
}

champion legion;
declare(){
	legion.name="Legion";
legion.role="Tank";
legion.id=6;
legion.hp=178;
legion.atk=14;
legion.def=13;
legion.spd=13;
legion.tag.push_back("Roman");
legion.tag.push_back("Mediterranean");
legion.tag.push_back("Classical");
legion.tag.push_back("Iron");
void legion_skill(int skill_num) {
	if(skill_num==1)gladiusslash();
	else clearthepath();
}
legion.skill[0].name="Gladius Slash";
legion.skill[0].type='b';
legion.skill[0].cd=-1;
legion.skill[0].bcd=-1;
legion.skill[0].des="Deal dmg to an enemy. +25% damage per defeated enemies.";
void gladiusslash() {
	base_dmg=1.4;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
			for(int i=0; i<10; i++) {
				if(pos[i].player!=pos[turn].player&&pos[i].hp==0)base_dmg+=0.35;
			}
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
legion.skill[1].name="Clear the path";
legion.skill[1].type='s';
legion.skill[1].cd=0;
legion.skill[1].bcd=4;
legion.skill[1].des="Deal dmg to an enemy. Dispel all Buffs from them and Legion gain Protect for 1 turn. Other Roman allies gain 50% turn meter.";
void clearthepath() {
	base_dmg=2.0;
	system("CLS");
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(1);
		if(hit()) {
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0) {
				int temp=dispel_buff(enemy);
			}
		}
		gain(turn,"Protect",1);
		for(int i=0; i<10; i++) {
			if(pos[i].player==pos[turn].player&&find_tag(i,"Roman")&&i!=turn)gain_turn_meter(i,50);
		}
	}
}
champions.push_back(legion);
}

champion ninja;
declare(){
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
void ninja_skill(int skill_num) {
	if(skill_num==1)shuriken();
	else blackegg();
}
ninja.skill[0].name="Shuriken";
ninja.skill[0].type='b';
ninja.skill[0].cd=-1;
ninja.skill[0].bcd=-1;
ninja.skill[0].des="Deal dmg to an enemy. If this attack is not blocked, It will deals Double damage.";
void shuriken() {
	base_dmg=1.4;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
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
void blackegg() {
	bool another_ally=false;
	system("CLS");
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(1);
		if(hit()) {
			gain(enemy,"Blind",-1);
		}
		for(int i=0; i<10; i++) {
			if(pos[i].player==pos[turn].player&&i!=turn&&pos[i].hp>0) {
				another_ally=true;
				break;
			}
		}
		if(another_ally)gain(turn,"Stealth",2);
		else {
			gain(turn,"Evade",-1);
			gain_turn_meter(turn,50);
		}
	}
}
champions.push_back(ninja);
}

champion monk;
declare(){
	monk.name="Monk";
monk.role="Support";
monk.id=8;
monk.hp=133;
monk.atk=17;
monk.def=12;
monk.spd=17;
monk.tag.push_back("Asian");
monk.tag.push_back("Mystic");
monk.tag.push_back("Medieval");
void monk_skill(int skill_num) {
	if(skill_num==1)staffslam();
	else enlighten();
}
monk.skill[0].name="Staff Slam";
monk.skill[0].type='b';
monk.skill[0].cd=-1;
monk.skill[0].bcd=-1;
monk.skill[0].des="Deal dmg to an enemy. 50% chance to Stun them. Can't be evaded.";
void staffslam() {
	base_dmg=1;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		block();
		deal_dmg(base_dmg,pos[enemy].current_stat.def);
		if(pos[enemy].hp>0) {
			if(rand()%2==1)stun(enemy);
		}
	}
}
monk.skill[1].name="Enlighten";
monk.skill[1].type='s';
monk.skill[1].cd=0;
monk.skill[1].bcd=5;
monk.skill[1].des="Remove Blind from all allies and Evade from all enemies which can't be evaded. All allies gain 50% turn meter and Attack Up for 1 turn.";
void enlighten() {
	system("CLS");
	skill_use(1);
	for(int i=0; i<10; i++) {
		if(pos[i].player==pos[turn].player&&pos[i].blind&&pos[i].hp>0) {
			pos[i].blind=false;
			cout<<pos[i].name<<" loses Blind!\n";
		}
	}
	for(int i=0; i<10; i++) {
		if(pos[i].player!=pos[turn].player&&pos[i].evade&&pos[i].hp>0) {
			pos[i].evade=false;
			cout<<pos[i].name<<" loses Evade!\n";
		}
	}
	for(int i=0; i<10; i++) {
		if(pos[i].player==pos[turn].player&&pos[i].hp>0) {
			gain_turn_meter(i,50);
			gain(i,"Attack Up",1);
		}
	}
}
champions.push_back(monk);
}

champion shaman;
declare(){
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
void shaman_skill(int skill_num) {
	if(skill_num==1)spiritualassault();
	else hallucination();
}
shaman.skill[0].name="Spiritual Assault";
shaman.skill[0].type='b';
shaman.skill[0].cd=-1;
shaman.skill[0].bcd=-1;
shaman.skill[0].des="Deal dmg to an enemy. Remove 10% turn meter from all enemies.";
void spiritualassault() {
	base_dmg=1.2;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
		for(int i=0; i<10; i++) {
			if(pos[i].player!=pos[turn].player&&pos[i].hp>0) {
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
void hallucination() {
	int total_max_hp=0,total_hp=0;
	double percentage=0;
	system("CLS");
	skill_use(1);
	for(int i=0; i<10; i++) {
		if(pos[i].player!=pos[turn].player&&pos[i].hp>0)gain(i,"Blind",-1);
	}
	for(int i=0; i<10; i++) {
		if(pos[i].player==pos[turn].player&&pos[i].hp>0) {
			total_max_hp+=pos[i].current_stat.max_hp;
			total_hp+=pos[i].hp;
		}
	}
	percentage=(total_hp*100)/total_max_hp;
	percentage/=100;
	for(int i=0; i<10; i++) {
		if(pos[i].player==pos[turn].player&&pos[i].hp>0) {
			pos[i].hp=pos[i].current_stat.max_hp*percentage;
			cout<<pos[i].name<<"'s HP set to"<<pos[i].hp<<"!\n";
			heal(i,pos[i].current_stat/4);
		}
	}
}
champions.push_back(shaman);
}

champion priest;
declare(){
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
void priest_skill(int skill_num) {
	if(skill_num==1)cursedstaff();
	else shallowtomb();
}
priest.skill[0].name="Cursed Staff";
priest.skill[0].type='b';
priest.skill[0].cd=-1;
priest.skill[0].bcd=-1;
priest.skill[0].des="Deal dmg to an enemy. 50% chance to dispel all Buffs from the enemy.";
void cursedstaff() {
	base_dmg=1.6;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0) {
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
void shallowtomb() {
	vector<int> revive_position;
	int r=0;
	system("CLS");
	skill_use(1);
	for(int i=0; i<10; i++) {
		if(pos[i].player==pos[turn].player&&pos[i].hp==0) {
			if(find_tag(i,"Mesopotamian"))revive_position.push_back(i);
		}
	}
	if(revive_position.size()==0) {
		for(int i=0; i<10; i++) {
			if(pos[i].player==pos[turn].player&&pos[i].hp==0)revive_position.push_back(i);
		}
		r=revive_position[rand()%revive_position.size()];
		revive(r,pos[r].current_stat.max_hp/4);
	} else {
		r=revive_position[rand()%revive_position.size()];
		revive(r,pos[r].current_stat.max_hp/2);
		gain_turn_meter(r,100);
	}
}
champions.push_back(priest);
}

champion impi;
declare(){
	impi.name="Impi";
impi.role="Attacker";
impi.id=11;
impi.hp=144;
impi.atk=15;
impi.def=13;
impi.spd=17;
impi.tag.push_back("African");
impi.tag.push_back("Iron");
impi.tag.push_back("Medieval");
void impi_skill(int skill_num) {
	if(skill_num==1)iklwa();
	else combatreflexes();
}
impi.skill[0].name="Iklwa";
impi.skill[0].type='b';
impi.skill[0].cd=-1;
impi.skill[0].bcd=-1;
impi.skill[0].des="Deal dmg to an enemy, This attack can't be blocked and will dispel Block if the enemy has.";
void iklwa() {
	base_dmg=1.6;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].block&&pos[enemy].hp>0) {
				pos[enemy].block=false;
				cout<<pos[enemy].name<<" loses Block!\n";
			}
		}
	}
}
impi.skill[1].name="Combat Reflexes";
impi.skill[1].type='s';
impi.skill[1].cd=0;
impi.skill[1].bcd=3;
impi.skill[1].des="Impi gain 100% turn meter and Attack Up for 1 turn";
void combatreflexes() {
	system("CLS");
	skill_use(1);
	gain_turn_meter(turn,100);
	gain(turn,"Attack Up",1);
}
champions.push_back(impi);
}

champion prophet;
declare(){
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
void prophet_skill(int skill_num) {
	if(skill_num==1)baktunshiftingstrike();
	else celestialapocalypse();
}
prophet.skill[0].name="B'aktun-Shifting Strike";
prophet.skill[0].type='b';
prophet.skill[0].cd=-1;
prophet.skill[0].bcd=-1;
prophet.skill[0].des="Deal dmg to an enemy. Targeted enemy and 50% chance for other enemies to have their cooldown increased by 1. Prophet and 50% for other allies to have their cooldown reduced by 1. Cooldown reduction can't be evaded.";
void baktunshiftingstrike() {
	base_dmg=1.2;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
		for(int i=0; i<10; i++) {
			if(pos[i].player==pos[turn].player&&pos[i].hp>0) {
				if(i==turn) {
					if(pos[i].skill[1].cd>0)pos[i].skill[1].cd--;
					cout<<pos[i].name<<"'s cooldown reduced by 1!\n";
				} else {
					if(rand()%2==1) {
						if(pos[i].skill[1].cd>0)pos[i].skill[1].cd--;
						cout<<pos[i].name<<"'s cooldown reduced by 1!\n";
					}
				}
			} else if(pos[i].player!=pos[turn].player&&pos[i].hp>0) {
				if(i==enemy) {
					pos[i].skill[1].cd++;
					cout<<pos[i].name<<"'s cooldown increased by 1!\n";
				} else {
					if(rand()%2==1) {
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
void celestialapocalypse() {
	system("CLS");
	skill_use(1);
	for(int i=0; i<10; i++) {
		if(pos[i].player!=pos[turn].player&&pos[i].hp>0) {
			enemy=i;
			base_dmg=5.2;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
champions.push_back(prophet);
}

champion eagle;
declare(){
	eagle.name="Eagle";
eagle.role="Tank";
eagle.id=13;
eagle.hp=167;
eagle.atk=14;
eagle.def=16;
eagle.spd=14;
eagle.tag.push_back("Mesoamerican");
eagle.tag.push_back("American");
eagle.tag.push_back("Obsidian");
eagle.tag.push_back("Medieval");
void eagle_skill(int skill_num) {
	if(skill_num==1)obsidianlance();
	else guardianeagle();
}
eagle.skill[0].name="Obsidian Lance";
eagle.skill[0].type='b';
eagle.skill[0].cd=-1;
eagle.skill[0].bcd=-1;
eagle.skill[0].des="Deal dmg to an enemy. This attack has 25% defense penetration which is doubled agains enemies without Stealth.";
void obsidianlance() {
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
			block();
			if(!pos[enemy].stealth)deal_dmg(base_dmg,pos[enemy].current_stat.def/2);
			else deal_dmg(base_dmg,pos[enemy].current_stat.def*0.75);
		}
	}
}
eagle.skill[1].name="Guardian Eagle";
eagle.skill[1].type='s';
eagle.skill[1].cd=0;
eagle.skill[1].bcd=4;
eagle.skill[1].des="Dispel all Debuffs from Eagle and gain Block. Eagle permanently gain +1 Defense and +10 Max HP.";
void guardianeagle() {
	system("CLS");
	skill_use(1);
	pos[turn].base_stat.def++;
	pos[turn].base_stat.max_hp+=10;
	dispel_debuff(turn);
	gain(turn,"Block",-1);
}
champions.push_back(eagle);
}

champion puma;
declare(){
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
void puma_skill(int skill_num) {
	if(skill_num==1)grandcleave();
	else risingaltitude();
}
puma.skill[0].name="Grand Cleave";
puma.skill[0].type='b';
puma.skill[0].cd=-1;
puma.skill[0].bcd=-1;
puma.skill[0].des="Deal dmg to all enemies.";
void grandcleave() {
	system("CLS");
	skill_use(0);
	for(int i=0; i<10; i++) {
		if(pos[i].player!=pos[turn].player&&pos[i].hp>0) {
			enemy=i;
			if(hit()) {
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
void risingaltitude() {
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(1);
		if(hit()) {
			base_dmg=2.2;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0)int temp=dispel_buff(enemy);
		}
		pos[turn].base_stat.atk++;
	}
}
champions.push_back(puma);
}

champion gladiator;
decalre(){
	gladiator.name="Gladiator";
gladiator.role="Attacker";
gladiator.id=15;
gladiator.hp=178;
gladiator.atk=16;
gladiator.def=12;
gladiator.spd=14;
gladiator.tag.push_back("Roman");
gladiator.tag.push_back("Mediterranean");
gladiator.tag.push_back("Iron");
gladiator.tag.push_back("Classical");
void gladiator_skill(int skill_num) {
	if(skill_num==1)tridentattack();
	else quarternet();
}
gladiator.skill[0].name="Trident Attack";
gladiator.skill[0].type='b';
gladiator.skill[0].cd=-1;
gladiator.skill[0].bcd=-1;
gladiator.skill[0].des="Deal dmg to an enemy. Applies Defense Down for 2 turns. If the enemy already has Defense Down, Gladiator gains Attack Up for 1 turn.";
void tridentattack() {
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		bool add=false;
		system("CLS");
		skill_use(0);
		if(pos[enemy].def_down>0)add=true;
		if(hit()) {
			base_dmg=1.4;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0)gain(enemy,"Defense Down",2);
		}
		if(add)gain(turn,"Attack Up",1);
	}
}
gladiator.skill[1].name="Quarter Net";
gladiator.skill[1].type='s';
gladiator.skill[1].cd=0;
gladiator.skill[1].bcd=5;
gladiator.skill[1].des="Stun, remove 100% turn meter and all Buffs, then applies Knock to the enemy for 2 turns.";
void quarternet() {
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(1);
		if(hit()) {
			stun(enemy);
			remove_turn_meter(enemy,100);
			int temp=dispel_buff(enemy);
			gain(enemy,"Knock",2);
		}
	}
}
champions.push_back(gladiator);
}

champion hoplite;
decalre(){
	hoplite.name="Hoplite";
hoplite.role="Tank";
hoplite.id=16;
hoplite.hp=156;
hoplite.atk=15;
hoplite.def=16;
hoplite.spd=13;
hoplite.tag.push_back("Greek");
hoplite.tag.push_back("Mediterranean");
hoplite.tag.push_back("Bronze");
hoplite.tag.push_back("Classical");
void hoplite_skill(int skill_num) {
	if(skill_num==1)steadythrust();
	else phalanx();
}
hoplite.skill[0].name="Steady Thrust";
hoplite.skill[0].type='b';
hoplite.skill[0].cd=-1;
hoplite.skill[0].bcd=-1;
hoplite.skill[0].des="Deal dmg to an enemy. If Hoplite has Block, heals Greek allies for 5% of max HP.";
void steadythrust() {
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		bool add=false;
		system("CLS");
		skill_use(0);
		if(hit()) {
			base_dmg=1.8;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
		if(pos[turn].block) {
			for(int i=0; i<10; i++) {
				if(pos[i].player==pos[turn].player&&pos[i].hp>0&&find_tag(i,"Greek"))heal(i,pos[i].current_stat.max_hp/20);
			}
		}
	}
}
hoplite.skill[1].name="Phalanx";
hoplite.skill[1].type='s';
hoplite.skill[1].cd=0;
hoplite.skill[1].bcd=4;
hoplite.skill[1].des="All allies gain Block and Defense Up for 2 turns.";
void phalanx() {
	system("CLS");
	skill_use(1);
	for(int i=0; i<10; i++) {
		if(pos[i].player==pos[turn].player&&pos[i].hp>0) {
			gain(i,"Block",-1);
			gain(i,"Defense Up",2);
		}
	}
}
champions.push_back(hoplite);
}

champion hypaspist;
declare(){
	hypaspist.name="Hypaspist";
hypaspist.role="Attacker";
hypaspist.id=17;
hypaspist.hp=133;
hypaspist.atk=15;
hypaspist.def=12;
hypaspist.spd=17;
hypaspist.tag.push_back("Greek");
hypaspist.tag.push_back("Mediterranean");
hypaspist.tag.push_back("Bronze");
hypaspist.tag.push_back("Classical");
void hypaspist_skill(int skill_num) {
	if(skill_num==1)dorybarrage();
	else mobilizing();
}
hypaspist.skill[0].name="Dory Barrage";
hypaspist.skill[0].type='b';
hypaspist.skill[0].cd=-1;
hypaspist.skill[0].bcd=-1;
hypaspist.skill[0].des="Deal dmg to an enemy 2 times.";
void dorybarrage() {
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		for(int i=0; i<2; i++) {
			if(hit()) {
				base_dmg=1.0;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
		}
	}
}
hypaspist.skill[1].name="Mobilizing";
hypaspist.skill[1].type='s';
hypaspist.skill[1].cd=0;
hypaspist.skill[1].bcd=5;
hypaspist.skill[1].des="Hypaspist gain 50% turn meter and Speed Up for 2 turns, other allies gain half the amount and have 50% chance to also gain Speed Up for 2 turns.";
void mobilizing() {
	system("CLS");
	skill_use(1);
	gain_turn_meter(turn,50);
	gain(turn,"Speed Up",2);
	for(int i=0; i<10; i++) {
		if(pos[i].player==pos[turn].player&&i!=turn&&pos[i].hp>0) {
			gain_turn_meter(i,25);
			if(rand()%2==1)gain(i,"Speed Up",2);
		}
	}
}
champions.push_back(hypaspist);
}


champion zande;
decalre(){
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
void zande_skill(int skill_num) {
	if(skill_num==1)decapitator();
	else savagespirit();
}
zande.skill[0].name="Decapitator";
zande.skill[0].type='b';
zande.skill[0].cd=-1;
zande.skill[0].bcd=-1;
zande.skill[0].des="Deal dmg to an enemy. If the enemy's health is below 25%, this attack ignores defense. On finishing blow, Zande recovers 50% of max HP.";
void decapitator() {
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
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
void savagespirit() {
	system("CLS");
	skill_use(1);
	int count=dispel_debuff(turn);
	if(count>0) {
		gain_turn_meter(turn,20*count);
		heal(turn,pos[turn].current_stat.max_hp*0.15*count);
	}
}
champions.push_back(zande);
}

champion immortal;
declare(){
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
void immortal_skill(int skill_num) {
	if(skill_num==1)mortalsmack();
	else immortalize();
}
immortal.skill[0].name="Mortal Smack";
immortal.skill[0].type='b';
immortal.skill[0].cd=-1;
immortal.skill[0].bcd=-1;
immortal.skill[0].des="Deal dmg to an enemy. Applies Heal Block for 1 turn.";
void mortalsmack() {
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2) {
		system("CLS");
		skill_use(0);
		if(hit()) {
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
void immortalize() {
	system("CLS");
	skill_use(1);
	if(pos[turn].heal_block>0) {
		pos[turn].heal_block=0;
		cout<<pos[turn].name<<" loses Heal Block!\n";
	}
	int lost_hp=pos[turn].current_stat-pos[turn].hp;
	heal(turn,lost_hp/4);
	gain(turn,"Block",-1);
	gain(turn,"Defense Up",1);
	gain_regeneration(turn,1);
}
champions.push_back(immortal);
}
