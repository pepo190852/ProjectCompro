#include "form.h"
#include "skill_function.h"
champion spartan;
spartan.name="Spartan";
spartan.tag.push_back("Greek");
spartan.tag.push_back("Tank");
spartan.tag.push_back("Classical");
spartan.tag.push_back("Mediterranean");
spartan.tag.push_back("Bronze");
spartan.hp=167;
spartan.off=16;
spartan.mdef=12;
spartan.pdef=12;
spartan.acc=14;
spartan.eva=12;
spartan.bc=19;
spartan.ba=20;
spartan.spd=13;
temp.name="Spartar Slash";
temp.type='b';
temp.cd=0;
temp.des="Deal melee dmg to an enemy. Spartan has 50% chance to gain 1 Block. This attack can't be countered";
spartan.skill.push_back(temp);
void spartarslash(int pos){
	int target=targetenemy(pos);
}
temp.name="Shield Bash";
temp.type='s';
temp.cd=3;
temp.des="Deal melee dmg to an enemy. Stun them and apply Knock, Evasion Down and Buff Blocker for 3 turns. This attack can't be evaded. Consume 1 Block from Spartan to gain 100% turn meter.";
spartan.skill.push_back(temp);
temp.name="Moraled Strike";
temp.type='s';
temp.cd=4;
temp.des="Deal melee dmg to an enemy. Has +1% piercing and dmg per every 2% of HP lost from Spartan. If target has more than 50% HP, deal double dmg. Else, remove 50% turn meter from target and reduce Moraled Strike's cooldown by 1";
spartan.skill.push_back(temp);
temp.name="Spartar Slash";
temp.type="Basic";
temp.cd=0;
temp.des="Deal melee dmg to an enemy. Spartan has 50% chance to gain 1 Block. This attack can't be countered";
spartan.skill.push_back(temp);
