#include "skill_function.h"
using namespace std;
champion spartan;
champion samurai;
champion berserker;
champion jaguar;
champion crusader;
champion khopesh;
champion legion;
champion ninja;
champion monk;
champion shaman;
champion priest;
champion impi;
champion prophet;
champion eagle;
champion puma;
champion gladiator;
champion hoplite;
champion hypaspist;
champion zande;
champion immortal;
champion ronin;
champion templar;
champion mongul;
champion nomad;
champion maori;
champion rajput;
champion pictish;
champion gallic;
champion druid;
void declare(){
spartan.name="Spartan";
spartan.role="Tank";
spartan.id=0;
spartan.hp=167;
spartan.atk=15;
spartan.def=16;
spartan.spd=13;
if(spartan.tag.size()==0){
	spartan.tag.push_back("Greek");
spartan.tag.push_back("Classical");
spartan.tag.push_back("Mediterranean");
spartan.tag.push_back("Bronze");
}
spartan.skill[0].name="Spartar Slash";
spartan.skill[0].type='b';
spartan.skill[0].cd=-1;
spartan.skill[0].bcd=-1;
spartan.skill[0].des="Deal dmg to an enemy. Spartan has 50% chance to gain Block.";
spartan.skill[1].name="Shield Bash";
spartan.skill[1].type='s';
spartan.skill[1].cd=0;
spartan.skill[1].bcd=2;
spartan.skill[1].des="Deal dmg to an enemy. On hitting enemy without Stun, consume Spartan's Block to Stun. On enemy's evade, remove 50% turn meter from enemy and Spartan gains +50% turn meter.";
champions.push_back(spartan);

samurai.name="Samurai";
samurai.role="Attacker";
samurai.id=1;
samurai.hp=144;
samurai.atk=18;
samurai.def=14;
samurai.spd=15;
if(samurai.tag.size()==0){
	samurai.tag.push_back("Japanese");
samurai.tag.push_back("Asian");
samurai.tag.push_back("Medieval");
samurai.tag.push_back("Steel");
}
samurai.skill[0].name="Katana Draw";
samurai.skill[0].type='b';
samurai.skill[0].cd=-1;
samurai.skill[0].bcd=-1;
samurai.skill[0].des="Deal dmg to an enemy. +1% Damage per each 1% of max hp lost from Samurai.";
samurai.skill[1].name="Kamikaze";
samurai.skill[1].type='s';
samurai.skill[1].cd=0;
samurai.skill[1].bcd=3;
samurai.skill[1].des="Samurai gains Deathproof. Deal dmg to an enemy. If this attack hits, Samurai also deals 20% of the damage to himself and loses Deathproof.";
champions.push_back(samurai);

berserker.name="Berserker";
berserker.role="Attacker";
berserker.id=2;
berserker.hp=178;
berserker.atk=14;
berserker.def=14;
berserker.spd=14;
if(berserker.tag.size()==0){
	berserker.tag.push_back("Norse");
berserker.tag.push_back("Scandinavian");
berserker.tag.push_back("Medieval");
berserker.tag.push_back("Iron");
}
berserker.skill[0].name="Fury Swipe";
berserker.skill[0].type='b';
berserker.skill[0].cd=-1;
berserker.skill[0].bcd=-1;
berserker.skill[0].des="Deal dmg to an enemy. +20% Damage per living enemies.";
berserker.skill[1].name="Enrage";
berserker.skill[1].type='s';
berserker.skill[1].cd=0;
berserker.skill[1].bcd=2;
berserker.skill[1].des="Heal self for 30% of max health. Gain 50% turn meter, Attack Up and Speed Up for 1 turn but also gain Defense Down for 1 turn.";
champions.push_back(berserker);

jaguar.name="Jaguar";
jaguar.role="Attacker";
jaguar.id=3;
jaguar.hp=144;
jaguar.atk=17;
jaguar.def=13;
jaguar.spd=18;
if(jaguar.tag.size()==0){
	jaguar.tag.push_back("Mesoamerican");
	jaguar.tag.push_back("American");
	jaguar.tag.push_back("Medieval");
	jaguar.tag.push_back("Obsidian");
}
jaguar.skill[0].name="Macuahuitl Smash";
jaguar.skill[0].type='b';
jaguar.skill[0].cd=-1;
jaguar.skill[0].bcd=-1;
jaguar.skill[0].des="Deal dmg to an enemy. Inflicts Bleed for 3 turns. If this attack defeats the enemy, Jaguar gain 100% turn meter.";
jaguar.skill[1].name="Predator Sense";
jaguar.skill[1].type='s';
jaguar.skill[1].cd=0;
jaguar.skill[1].bcd=4;
jaguar.skill[1].des="Jaguar permanently gain +1 Attack and Speed. Jaguar gains Stealth for 2 turns and removes Stealth from all enemies which can't be evaded.";
champions.push_back(jaguar);

crusader.name="Crusader";
crusader.role="Tank";
crusader.id=4;
crusader.hp=156;
crusader.atk=14;
crusader.def=17;
crusader.spd=12;
if(crusader.tag.size()==0){
	crusader.tag.push_back("European");
	crusader.tag.push_back("Medieval");
	crusader.tag.push_back("Steel");
}
crusader.skill[0].name="Pilgrim Slash";
crusader.skill[0].type='b';
crusader.skill[0].cd=-1;
crusader.skill[0].bcd=-1;
crusader.skill[0].des="Deal dmg to an enemy. Applies Attack Down to the enemy for 1 turn. Deal 25% more damage to Middle-Eastern.";
crusader.skill[1].name="Faithful Praying";
crusader.skill[1].type='s';
crusader.skill[1].cd=0;
crusader.skill[1].bcd=5;
crusader.skill[1].des="Dispel all Debuffs from All Allies. All allies recover 25% of Max HP.";
champions.push_back(crusader);

khopesh.name="Khopesh";
khopesh.role="Attacker";
khopesh.id=5;
khopesh.hp=144;
khopesh.atk=15;
khopesh.def=13;
khopesh.spd=13;
if(khopesh.tag.size()==0){
	khopesh.tag.push_back("Mesopotamian");
	khopesh.tag.push_back("Ancient");
	khopesh.tag.push_back("Bronze");
	khopesh.tag.push_back("African");
}
khopesh.skill[0].name="Scythe Cleave";
khopesh.skill[0].type='b';
khopesh.skill[0].cd=-1;
khopesh.skill[0].bcd=-1;
khopesh.skill[0].des="Deal dmg to an enemy. If the enemy has less than 50%, deals Double damage.";
khopesh.skill[1].name="Rejuvenate";
khopesh.skill[1].type='s';
khopesh.skill[1].cd=0;
khopesh.skill[1].bcd=3;
khopesh.skill[1].des="Recover 50% HP, Gain Attack Up for 1 turn and Deathproof.";
champions.push_back(khopesh);

legion.name="Legion";
legion.role="Tank";
legion.id=6;
legion.hp=178;
legion.atk=14;
legion.def=13;
legion.spd=13;
if(legion.tag.size()==0){
	legion.tag.push_back("Roman");
	legion.tag.push_back("Mediterranean");
	legion.tag.push_back("Classical");
	legion.tag.push_back("Iron");
}
legion.skill[0].name="Gladius Slash";
legion.skill[0].type='b';
legion.skill[0].cd=-1;
legion.skill[0].bcd=-1;
legion.skill[0].des="Deal dmg to an enemy. 50% Chance to gain Defense Up for 1 turns.";
legion.skill[1].name="Clear the path";
legion.skill[1].type='s';
legion.skill[1].cd=0;
legion.skill[1].bcd=4;
legion.skill[1].des="Deal dmg to an enemy, applies Knock for 2 turns, dispel all Buffs from them and Legion gain Protect for 1 turn. All Roman allies gain Defense Up for 2 turns.";
champions.push_back(legion);

ninja.name="Ninja";
ninja.role="Attacker";
ninja.id=7;
ninja.hp=122;
ninja.atk=16;
ninja.def=13;
ninja.spd=18;
if(ninja.tag.size()==0){
	ninja.tag.push_back("Japanese");
	ninja.tag.push_back("Asian");
	ninja.tag.push_back("Medieval");
	ninja.tag.push_back("Steel");
}
ninja.skill[0].name="Black Egg Assault";
ninja.skill[0].type='b';
ninja.skill[0].cd=-1;
ninja.skill[0].bcd=-1;
ninja.skill[0].des="Deal damage to an enemy. 50% Chance to applies Blind. If there is a non-stealthed ally, Ninja gain Stealth for 1 turn, else, Ninja has 50% chance to gain Evade.";
ninja.skill[1].name="Shuriken";
ninja.skill[1].type='s';
ninja.skill[1].cd=0;
ninja.skill[1].bcd=3;
ninja.skill[1].des="Deal damage to an enemy. Triple damage if it is not blocked.";
champions.push_back(ninja);

monk.name="Monk";
monk.role="Support";
monk.id=8;
monk.hp=133;
monk.atk=17;
monk.def=12;
monk.spd=17;
if(monk.tag.size()==0){
	monk.tag.push_back("Asian");
	monk.tag.push_back("Mystic");
	monk.tag.push_back("Medieval");
}
monk.skill[0].name="Staff Slam";
monk.skill[0].type='b';
monk.skill[0].cd=-1;
monk.skill[0].bcd=-1;
monk.skill[0].des="Deal dmg to an enemy. 50% chance to Stun them. Can't be evaded.";
monk.skill[1].name="Enlighten";
monk.skill[1].type='s';
monk.skill[1].cd=0;
monk.skill[1].bcd=5;
monk.skill[1].des="Remove Blind from all allies and Evade from all enemies which can't be evaded. All allies gain 50% turn meter and Attack Up for 1 turn.";
champions.push_back(monk);

shaman.name="Shaman";
shaman.role="Support";
shaman.id=9;
shaman.hp=167;
shaman.atk=14;
shaman.def=13;
shaman.spd=13;
if(shaman.tag.size()==0){
	shaman.tag.push_back("American");
	shaman.tag.push_back("Amerindian");
	shaman.tag.push_back("Mystic");
	shaman.tag.push_back("Ancient");
}
shaman.skill[0].name="Spiritual Assault";
shaman.skill[0].type='b';
shaman.skill[0].cd=-1;
shaman.skill[0].bcd=-1;
shaman.skill[0].des="Deal dmg to an enemy. Remove 10% turn meter from all enemies.";
shaman.skill[1].name="Hallucination";
shaman.skill[1].type='s';
shaman.skill[1].cd=0;
shaman.skill[1].bcd=5;
shaman.skill[1].des="Apllies Blind to all enemies which can't be evaded. All allies have their health percentage equalized, then they heal for 25% of their max hp.";
champions.push_back(shaman);

priest.name="Priest";
priest.role="Support";
priest.id=10;
priest.hp=122;
priest.atk=15;
priest.def=12;
priest.spd=13;
if(priest.tag.size()==0){
	priest.tag.push_back("Mesopotamian");
	priest.tag.push_back("African");
	priest.tag.push_back("Mystic");
	priest.tag.push_back("Ancient");
}
priest.skill[0].name="Cursed Staff";
priest.skill[0].type='b';
priest.skill[0].cd=-1;
priest.skill[0].bcd=-1;
priest.skill[0].des="Deal dmg to an enemy. 50% chance to dispel all Buffs from the enemy.";
priest.skill[1].name="Shallow Tomb";
priest.skill[1].type='s';
priest.skill[1].cd=0;
priest.skill[1].bcd=5;
priest.skill[1].des="Revives a random ally at 25% of their max HP. Mesopotamian allies always take the priority and revive at 50% HP instead with 100% turn meter.";
champions.push_back(priest);

impi.name="Impi";
impi.role="Attacker";
impi.id=11;
impi.hp=144;
impi.atk=15;
impi.def=13;
impi.spd=17;
if(impi.tag.size()==0){
	impi.tag.push_back("African");
	impi.tag.push_back("Iron");
	impi.tag.push_back("Medieval");
}
impi.skill[0].name="Iklwa";
impi.skill[0].type='b';
impi.skill[0].cd=-1;
impi.skill[0].bcd=-1;
impi.skill[0].des="Deal dmg to an enemy, has 50% defense penetration and applies Defense Down for 2 turns.";
impi.skill[1].name="Combat Reflexes";
impi.skill[1].type='s';
impi.skill[1].cd=0;
impi.skill[1].bcd=4;
impi.skill[1].des="Impi gain 100% turn meter, Evade and Attack Up for 2 turns";
champions.push_back(impi);

prophet.name="Prophet";
prophet.role="Support";
prophet.id=12;
prophet.hp=133;
prophet.atk=15;
prophet.def=13;
prophet.spd=12;
if(prophet.tag.size()==0){
	prophet.tag.push_back("Mesoamerican");
	prophet.tag.push_back("American");
	prophet.tag.push_back("Mystic");
	prophet.tag.push_back("Classical");
}
prophet.skill[0].name="B'aktun-Shifting Strike";
prophet.skill[0].type='b';
prophet.skill[0].cd=-1;
prophet.skill[0].bcd=-1;
prophet.skill[0].des="Deal dmg to an enemy. Targeted enemy and 50% chance for other enemies to have their cooldown increased by 1. Prophet and 50% for other allies to have their cooldown reduced by 1. Cooldown reduction can't be evaded.";
prophet.skill[1].name="Celestial Apocalypse";
prophet.skill[1].type='s';
prophet.skill[1].cd=9;
prophet.skill[1].bcd=9;
prophet.skill[1].des="Deal dmg to all enemies which can't be evaded. Starts on cooldown.";
champions.push_back(prophet);

eagle.name="Eagle";
eagle.role="Tank";
eagle.id=13;
eagle.hp=167;
eagle.atk=14;
eagle.def=16;
eagle.spd=14;
if(eagle.tag.size()==0){
	eagle.tag.push_back("Mesoamerican");
	eagle.tag.push_back("American");
	eagle.tag.push_back("Obsidian");
	eagle.tag.push_back("Medieval");
}
eagle.skill[0].name="Obsidian Lance";
eagle.skill[0].type='b';
eagle.skill[0].cd=-1;
eagle.skill[0].bcd=-1;
eagle.skill[0].des="Deal dmg to an enemy. This attack has 25% defense penetration which is doubled agains enemies without Stealth.";
eagle.skill[1].name="Guardian Eagle";
eagle.skill[1].type='s';
eagle.skill[1].cd=0;
eagle.skill[1].bcd=4;
eagle.skill[1].des="Dispel all Debuffs from Eagle and gain Block. Eagle permanently gain +1 Defense and +10 Max HP.";
champions.push_back(eagle);

puma.name="Puma";
puma.role="Attacker";
puma.id=14;
puma.hp=167;
puma.atk=15;
puma.def=13;
puma.spd=12;
if(puma.tag.size()==0){
	puma.tag.push_back("Andean");
	puma.tag.push_back("American");
	puma.tag.push_back("Bronze");
	puma.tag.push_back("Medieval");
}
puma.skill[0].name="Grand Cleave";
puma.skill[0].type='b';
puma.skill[0].cd=-1;
puma.skill[0].bcd=-1;
puma.skill[0].des="Deal dmg to all enemies.";
puma.skill[1].name="Rising Altitude";
puma.skill[1].type='s';
puma.skill[1].cd=0;
puma.skill[1].bcd=2;
puma.skill[1].des="Deal dmg to an enemy. Dispel all Buffs from them. Puma permanently gains +1 Attack.";
champions.push_back(puma);

gladiator.name="Gladiator";
gladiator.role="Attacker";
gladiator.id=15;
gladiator.hp=178;
gladiator.atk=16;
gladiator.def=12;
gladiator.spd=14;
if(gladiator.tag.size()==0){
	gladiator.tag.push_back("Roman");
	gladiator.tag.push_back("Mediterranean");
	gladiator.tag.push_back("Iron");
	gladiator.tag.push_back("Classical");
}
gladiator.skill[0].name="Trident Attack";
gladiator.skill[0].type='b';
gladiator.skill[0].cd=-1;
gladiator.skill[0].bcd=-1;
gladiator.skill[0].des="Deal dmg to an enemy. 25% Chance per defeated enemy to applies Defense Down for 2 turns and for Gladiator to gains Attack Up for 1 turn if target already has Defense Down.";
gladiator.skill[1].name="Quarter Net";
gladiator.skill[1].type='s';
gladiator.skill[1].cd=0;
gladiator.skill[1].bcd=5;
gladiator.skill[1].des="Stun, remove 100% turn meter and all Buffs, then applies Knock to the enemy for 2 turns.";
champions.push_back(gladiator);

hoplite.name="Hoplite";
hoplite.role="Tank";
hoplite.id=16;
hoplite.hp=156;
hoplite.atk=15;
hoplite.def=16;
hoplite.spd=13;
if(hoplite.tag.size()==0){
	hoplite.tag.push_back("Greek");
	hoplite.tag.push_back("Mediterranean");
	hoplite.tag.push_back("Bronze");
	hoplite.tag.push_back("Classical");
}
hoplite.skill[0].name="Steady Thrust";
hoplite.skill[0].type='b';
hoplite.skill[0].cd=-1;
hoplite.skill[0].bcd=-1;
hoplite.skill[0].des="Deal dmg to an enemy. If Hoplite has Block, heals Greek allies for 5% of max HP.";
hoplite.skill[1].name="Phalanx";
hoplite.skill[1].type='s';
hoplite.skill[1].cd=0;
hoplite.skill[1].bcd=3;
hoplite.skill[1].des="All allies gain Block and Defense Up for 1 turns. All allies lose Knock.";
champions.push_back(hoplite);

hypaspist.name="Hypaspist";
hypaspist.role="Attacker";
hypaspist.id=17;
hypaspist.hp=133;
hypaspist.atk=15;
hypaspist.def=12;
hypaspist.spd=17;
if(hypaspist.tag.size()==0){
	hypaspist.tag.push_back("Greek");
	hypaspist.tag.push_back("Mediterranean");
	hypaspist.tag.push_back("Bronze");
	hypaspist.tag.push_back("Classical");
}
hypaspist.skill[0].name="Dory Barrage";
hypaspist.skill[0].type='b';
hypaspist.skill[0].cd=-1;
hypaspist.skill[0].bcd=-1;
hypaspist.skill[0].des="Remove Block from an enemy and give it to Hypaspist. Deal dmg to an enemy. Remove all Buffs from Middle-Eastern and attack them again.";
hypaspist.skill[1].name="Mobilizing";
hypaspist.skill[1].type='s';
hypaspist.skill[1].cd=0;
hypaspist.skill[1].bcd=4;
hypaspist.skill[1].des="Hypaspist gain 50% turn meter and Speed Up for 2 turns. If has Block, gain double turn meter and also Attack Up for 2 turns.";
champions.push_back(hypaspist);

zande.name="Zande";
zande.role="Attacker";
zande.id=18;
zande.hp=144;
zande.atk=16;
zande.def=13;
zande.spd=14;
if(zande.tag.size()==0){
	zande.tag.push_back("African");
	zande.tag.push_back("Iron");
	zande.tag.push_back("Classical");
}
zande.skill[0].name="Decapitator";
zande.skill[0].type='b';
zande.skill[0].cd=-1;
zande.skill[0].bcd=-1;
zande.skill[0].des="Deal dmg to an enemy. If the enemy's health is below 25%, this attack ignores defense. On finishing blow, Zande recovers 50% of max HP.";
zande.skill[1].name="Savage Spirit";
zande.skill[1].type='s';
zande.skill[1].cd=0;
zande.skill[1].bcd=4;
zande.skill[1].des="Dispel all Debuffs from Zande. Zande gains 20% turn meter and recovers 15% of max HP per each debuff dispelled.";
champions.push_back(zande);

immortal.name="Immortal";
immortal.role="Tank";
immortal.id=19;
immortal.hp=144;
immortal.atk=13;
immortal.def=15;
immortal.spd=14;
if(immortal.tag.size()==0){
	immortal.tag.push_back("Middle-Eastern");
	immortal.tag.push_back("Bronze");
	immortal.tag.push_back("Classical");
}
immortal.skill[0].name="Mortal Smack";
immortal.skill[0].type='b';
immortal.skill[0].cd=-1;
immortal.skill[0].bcd=-1;
immortal.skill[0].des="Deal dmg to an enemy. Remove Buff Block from Immortal. 50% Chance to gain Deathproof.";
immortal.skill[1].name="Immortalize";
immortal.skill[1].type='s';
immortal.skill[1].cd=0;
immortal.skill[1].bcd=2;
immortal.skill[1].des="Remove Heal Block from Immortal if there is. Recovers 30% of lost HP. Gain 1 Regeneration for 1 turn for each defeated ally.";
champions.push_back(immortal);

ronin.name="Ronin";
ronin.role="Tank";
ronin.id=20;
ronin.hp=156;
ronin.atk=14;
ronin.def=15;
ronin.spd=13;
if(ronin.tag.size()==0){
	ronin.tag.push_back("Japanese");
	ronin.tag.push_back("Asian");
	ronin.tag.push_back("Steel");
	ronin.tag.push_back("Medieval");
}
ronin.skill[0].name="Naginata";
ronin.skill[0].type='b';
ronin.skill[0].cd=-1;
ronin.skill[0].bcd=-1;
ronin.skill[0].des="Deal dmg to an enemy. If target has Attack Down, applies Defense Down for 2 turns.";
ronin.skill[1].name="Intimidating";
ronin.skill[1].type='s';
ronin.skill[1].cd=0;
ronin.skill[1].bcd=3;
ronin.skill[1].des="Applies Silenced and Attack Down to target for 2 turns and other enemies for 1 turn. Remove 50% turn meter from all enemies(Double remove on target). Can't be evaded.";
champions.push_back(ronin);

templar.name="Templar";
templar.role="Attacker";
templar.id=21;
templar.hp=144;
templar.atk=16;
templar.def=15;
templar.spd=14;
if(templar.tag.size()==0){
	templar.tag.push_back("European");
	templar.tag.push_back("Steel");
	templar.tag.push_back("Medieval");
}
templar.skill[0].name="Determined Slash";
templar.skill[0].type='b';
templar.skill[0].cd=-1;
templar.skill[0].bcd=-1;
templar.skill[0].des="Deal dmg to an enemy. Applies Heal Block for 2 turns. If already has Heal Block, applies Silence for 2 turns. If already has Silence, increases their cooldown by 1.";
templar.skill[1].name="Breakthrough";
templar.skill[1].type='s';
templar.skill[1].cd=0;
templar.skill[1].bcd=4;
templar.skill[1].des="Deal damage to an enemy. +15% Damage and +5% Defense Penetration per each defeated ally. Templar heals for 5% of max health and has +25% chance to gain Block per other living ally.";
champions.push_back(templar);

mongul.name="Mongul";
mongul.role="Tank";
mongul.id=22;
mongul.hp=178;
mongul.atk=14;
mongul.def=14;
mongul.spd=12;
if(mongul.tag.size()==0){
	mongul.tag.push_back("Eurasian");
	mongul.tag.push_back("Asian");
	mongul.tag.push_back("Steel");
	mongul.tag.push_back("Medieval");
}
mongul.skill[0].name="Mace Smash";
mongul.skill[0].type='b';
mongul.skill[0].cd=-1;
mongul.skill[0].bcd=-1;
mongul.skill[0].des="Deal dmg to an enemy. 50% Chance per Buffs on target to applies Knock for 2 turns, if already has Knock, 25% chance per buffs on target to Stun.";
mongul.skill[1].name="War Cry";
mongul.skill[1].type='s';
mongul.skill[1].cd=0;
mongul.skill[1].bcd=3;
mongul.skill[1].des="Mongul gain Protect and Defense Up for 2 turns. Other allies gain Attack Up for 2 turns. Other Eurasian allies also gain 50% turn meter";
champions.push_back(mongul);

nomad.name="Nomad";
nomad.role="Attacker";
nomad.id=23;
nomad.hp=133;
nomad.atk=16;
nomad.def=12;
nomad.spd=14;
if(nomad.tag.size()==0){
	nomad.tag.push_back("Eurasian");
	nomad.tag.push_back("Asian");
	nomad.tag.push_back("Steel");
	nomad.tag.push_back("Medieval");
}
nomad.skill[0].name="Man Hunting";
nomad.skill[0].type='b';
nomad.skill[0].cd=-1;
nomad.skill[0].bcd=-1;
nomad.skill[0].des="Deal dmg to an enemy. If this attack defeats the enemy, all allies gain 25% turn meter.";
nomad.skill[1].name="Nomadic Survivor";
nomad.skill[1].type='s';
nomad.skill[1].cd=0;
nomad.skill[1].bcd=3;
nomad.skill[1].des="Nomad gain Attack Up and Speed Up for 1 turns. Nomad also gain Evade. All allies gain +5% turn meter per each buff on all enemies.";
champions.push_back(nomad);

maori.name="Maori";
maori.role="Attacker";
maori.id=24;
maori.hp=167;
maori.atk=14;
maori.def=12;
maori.spd=16;
if(maori.tag.size()==0){
	maori.tag.push_back("Polynesian");
	maori.tag.push_back("Obsidian");
	maori.tag.push_back("Classical");
}
maori.skill[0].name="Cannibal Strike";
maori.skill[0].type='b';
maori.skill[0].cd=-1;
maori.skill[0].bcd=-1;
maori.skill[0].des="Deal dmg to an enemy. If this attack defeats the enemy, Maori heals equal to 100% of defeated enemy's max health and gain";
maori.skill[1].name="Haka";
maori.skill[1].type='s';
maori.skill[1].cd=0;
maori.skill[1].bcd=6;
maori.skill[1].des="All enemies gain Silenced for 1 turn which can't be evaded. All allies gain Block, Health Up, Attack Up and Defense Up for 2 turns.";
champions.push_back(maori);

rajput.name="Rajput";
rajput.role="Attacker";
rajput.id=25;
rajput.hp=167;
rajput.atk=18;
rajput.def=15;
rajput.spd=16;
if(rajput.tag.size()==0){
	rajput.tag.push_back("Asian");
	rajput.tag.push_back("Indian");
	rajput.tag.push_back("Iron");
	rajput.tag.push_back("Classical");
}
rajput.skill[0].name="Katar Slash";
rajput.skill[0].type='b';
rajput.skill[0].cd=-1;
rajput.skill[0].bcd=-1;
rajput.skill[0].des="Deal dmg to an enemy. Rajput gains +10% turn meter per each buff on the target.";
rajput.skill[1].name="Chakram";
rajput.skill[1].type='s';
rajput.skill[1].cd=0;
rajput.skill[1].bcd=4;
rajput.skill[1].des="Deals dmg to an enemy, if this attack hits, it will continue to attack other random enemies until every enemies is hit by this attack unblocked or an enemy evades it.";
champions.push_back(rajput);

pictish.name="Pictish";
pictish.role="Attacker";
pictish.id=26;
pictish.hp=144;
pictish.atk=14;
pictish.def=11;
pictish.spd=16;
if(pictish.tag.size()==0){
	pictish.tag.push_back("Scandinavian");
	pictish.tag.push_back("Celtic");
	pictish.tag.push_back("Iron");
	pictish.tag.push_back("Classical");
}
pictish.skill[0].name="Barbaric Assault";
pictish.skill[0].type='b';
pictish.skill[0].cd=-1;
pictish.skill[0].bcd=-1;
pictish.skill[0].des="Deal dmg to an enemy. Double damage agains enemy without any buffs.";
pictish.skill[1].name="Furor Celtica";
pictish.skill[1].type='s';
pictish.skill[1].cd=0;
pictish.skill[1].bcd=3;
pictish.skill[1].des="Deal dmg to all enemies. Gain +20% turn meter per enemy hit. Pictish gains Defense Down for 2 turns.";
champions.push_back(pictish);

gallic.name="Gallic";
gallic.role="Tank";
gallic.id=27;
gallic.hp=156;
gallic.atk=14;
gallic.def=14;
gallic.spd=14;
if(gallic.tag.size()==0){
	gallic.tag.push_back("Scandinavian");
gallic.tag.push_back("Celtic");
gallic.tag.push_back("Iron");
gallic.tag.push_back("Classical");
}
gallic.skill[0].name="Gallic Bladework";
gallic.skill[0].type='b';
gallic.skill[0].cd=-1;
gallic.skill[0].bcd=-1;
gallic.skill[0].des="Deal damage to an enemy. If hit a target with Knock, all Celtic allies heal for 5% of max health.";
gallic.skill[1].name="Shield Crash";
gallic.skill[1].type='s';
gallic.skill[1].cd=0;
gallic.skill[1].bcd=3;
gallic.skill[1].des="Deal damage to an enemy. Applies Knock for 3 turns. Gallic gains Speed Down for 2 turns.";
champions.push_back(gallic);

druid.name="Druid";
druid.role="Support";
druid.id=28;
druid.hp=122;
druid.atk=14;
druid.def=13;
druid.spd=12;
if(druid.tag.size()==0){
	druid.tag.push_back("Scandinavian");
druid.tag.push_back("Celtic");
druid.tag.push_back("Mystic");
druid.tag.push_back("Classical");
}
druid.skill[0].name="Wild Smack";
druid.skill[0].type='b';
druid.skill[0].cd=-1;
druid.skill[0].bcd=-1;
druid.skill[0].des="Deal dmg to an enemy. +1% chance to Stun and for Druid to gain Attack Down per 2% of Max HP left on the enemy.";
druid.skill[1].name="Call of the Wild";
druid.skill[1].type='s';
druid.skill[1].cd=0;
druid.skill[1].bcd=3;
druid.skill[1].des="Swaps Stat Down debuff on all allies into it's opposite. Celtic allies gain 1 Regeneration for 1 turn.";
champions.push_back(druid);
}
void spartarslash(){
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}if(rand()%2>0)gain(turn,"Block",-1);
	}
}
void shieldbash(){
	base_dmg=2;
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(!pos[enemy].stun&&pos[turn].block==true&&pos[enemy].hp>0){
				pos[turn].block=false;
				stun(enemy);
				cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<" loses Block!\n";
			}
		}else{
			remove_turn_meter(enemy,50);
			gain_turn_meter(turn,50);
		}
	}
}
void spartan_skill(int skill_num){
	if(skill_num==1)spartarslash();
	else shieldbash();
}


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
void kamikaze(){
	base_dmg=4.2;
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		gain(turn,"Deathproof",-1);
		if(hit()){
			int temp=enemy;
			enemy=turn;
			deal_dmg(base_dmg*0.2,pos[turn].current_stat.def);
			enemy=temp;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}if(pos[turn].deathproof){
			pos[turn].deathproof=false;
		cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<" loses Deathproof!\n";
		}
	}
}
void samurai_skill(int skill_num){
	if(skill_num==1)katanadraw();
	else kamikaze();
}


void furyswipe(){
	base_dmg=1.4;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			int count=0;
			for(int i=0;i<10;i++){
				if(pos[i].player!=pos[turn].player&&pos[i].hp>0)count++;
			}
			double multiplier=1+(count*0.2);
			base_dmg*=multiplier;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
void enrage(){
	system("CLS");
	skill_use(1);
	heal(turn,pos[turn].current_stat.max_hp*0.3);
	gain_turn_meter(turn,50);
	gain(turn,"Attack Up",1);
	gain(turn,"Speed Up",1);
	gain(turn,"Defense Down",1);
}
void berserker_skill(int skill_num){
	if(skill_num==1)furyswipe();
	else enrage();
}


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
void predatorsense(){
	system("CLS");
	skill_use(1);
	pos[turn].base_stat.atk++;
	pos[turn].base_stat.spd++;
	gain(turn,"Stealth",2);
	for(int i=0;i<10;i++){
		if(pos[i].player!=pos[turn].player&&pos[i].stealth>0&&pos[i].hp>0){
			pos[i].stealth=0;
			cout<<"Player "<<pos[i].player<<"'s "<<pos[i].name<<" loses Stealth!\n";
		}
	}
}
void jaguar_skill(int skill_num){
	if(skill_num==1)macuahuitlsmash();
	else predatorsense();
}


void pilgrimslash(){
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			if(find_tag(enemy,"Middle-Eastern"))base_dmg*=1.25;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0)gain(enemy,"Attack Down",1);
		}
	}
}
void faithfulpraying(){
	system("CLS");
	skill_use(1);
	for(int i=0;i<10;i++){
		if(pos[i].player==pos[turn].player&&pos[i].hp>0){
			dispel_debuff(i);
			heal(i,pos[i].current_stat.max_hp/4);
		}
	}
}
void crusader_skill(int skill_num){
	if(skill_num==1)pilgrimslash();
	else faithfulpraying();
}


void scythecleave(){
	base_dmg=1.4;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			if(pos[enemy].hp<pos[enemy].current_stat.max_hp/2)base_dmg*=2;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
void rejuvenate(){
	system("CLS");
	skill_use(1);
	heal(turn,pos[turn].current_stat.max_hp/2);
	gain(turn,"Attack Up",1);
	gain(turn,"Deathproof",-1);
}
void khopesh_skill(int skill_num){
	if(skill_num==1)scythecleave();
	else rejuvenate();
}


void gladiusslash(){
	base_dmg=1.6;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(rand()%2)gain(turn,"Defense Up",1);
		}
	}
}
void clearthepath(){
	base_dmg=2;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0){
				dispel_buff(enemy);
				gain(enemy,"Knock",2);
			}
		}gain(turn,"Protect",1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&find_tag(i,"Roman"))gain(i,"Defense Up",2);
		}
	}
}
void legion_skill(int skill_num){
	if(skill_num==1)gladiusslash();
	else clearthepath();
}


void blackeggassault(){
	bool another_ally=false;
	base_dmg=0.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0&&rand()%2)gain(enemy,"Blind",-1);
		}for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&i!=turn&&pos[i].hp>0&&pos[i].prior>0){
				another_ally=true;
				break;
			}
		}if(another_ally)gain(turn,"Stealth",1);
		else{
			if(rand()%2)gain(turn,"Evade",-1);
		}
	}
}
void shuriken(){
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			if(!pos[enemy].block)base_dmg*=3;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
		}
	}
}
void ninja_skill(int skill_num){
	if(skill_num==1)blackeggassault();
	else shuriken();
}


void staffslam(){
	base_dmg=1;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		block();
		deal_dmg(base_dmg,pos[enemy].current_stat.def);
		if(pos[enemy].hp>0){
			if(rand()%2==1)stun(enemy);
		}
	}
}
void enlighten(){
	system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].blind&&pos[i].hp>0){
				pos[i].blind=false;
				cout<<"Player "<<pos[i].player<<"'s "<<pos[i].name<<" loses Blind!\n";
			}
		}
		for(int i=0;i<10;i++){
			if(pos[i].player!=pos[turn].player&&pos[i].evade&&pos[i].hp>0){
				pos[i].evade=false;
				cout<<"Player "<<pos[i].player<<"'s "<<pos[i].name<<" loses Evade!\n";
			}
		}
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp>0){
				gain_turn_meter(i,50);
				gain(i,"Attack Up",1);
			}
		}
}
void monk_skill(int skill_num){
	if(skill_num==1)staffslam();
	else enlighten();
}


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
				heal(i,pos[i].current_stat.max_hp/4);
			}
		}
}
void shaman_skill(int skill_num){
	if(skill_num==1)spiritualassault();
	else hallucination();
}


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
void shallowtomb(){
	vector<int> revive_position;
	int r=0;
	system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp==0){
				if(find_tag(i,"Mesopotamian"))revive_position.push_back(i);
			}
		}//cout<<"passed find defeated Mesopotamian allies state...\n";
		if(revive_position.size()==0){
			//cout<<"No Mesopotamian allies found. Continue searching for defeated allies...\n";
			for(int i=0;i<10;i++){
				if(pos[i].player==pos[turn].player&&pos[i].hp==0)revive_position.push_back(i);
			}//cout<<"Passed find defeated allies state, start randomizing an ally to be revived...\n";
			if(revive_position.size()>0){
				r=revive_position[rand()%revive_position.size()];
				revive(r,pos[r].current_stat.max_hp/4);
			}
			//cout<<"Ally acquired, start reviving "<<pos[r].name<<"...\n";
			//cout<<"Ally's revived...\n";
		}else{
			//cout<<"Passed find defeated Mesopotamian allies state, start randomizing an ally to be revived...\n";
			if(revive_position.size()>0){
				r=revive_position[rand()%revive_position.size()];
				revive(r,pos[r].current_stat.max_hp/2);
				gain_turn_meter(r,100);
			}
			//cout<<"Mesopotamian ally acquired, start reviving "<<pos[r].name<<"...\n";

			//cout<<"Mesopotamian ally's revived...\n";

			//cout<<"Mesopotamian ally gain turn meter...\n";
		}
}
void priest_skill(int skill_num){
	if(skill_num==1)cursedstaff();
	else shallowtomb();
}


void iklwa(){
	base_dmg=1.6;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def/2);
			if(pos[enemy].hp>0)gain(enemy,"Defense Down",2);
		}
	}
}
void combatreflexes(){
	system("CLS");
		skill_use(1);
		gain_turn_meter(turn,100);
		gain(turn,"Attack Up",2);
		gain(turn,"Evade",-1);
}
void impi_skill(int skill_num){
	if(skill_num==1)iklwa();
	else combatreflexes();
}


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
					cout<<"Player "<<pos[i].player<<"'s "<<pos[i].name<<"'s cooldown reduced by 1!\n";
				}else{
					if(rand()%2==1){
						if(pos[i].skill[1].cd>0)pos[i].skill[1].cd--;
						cout<<"Player "<<pos[i].player<<"'s "<<pos[i].name<<"'s cooldown reduced by 1!\n";
					}
				}
			}else if(pos[i].player!=pos[turn].player&&pos[i].hp>0){
				if(i==enemy){
					pos[i].skill[1].cd++;
					cout<<"Player "<<pos[i].player<<"'s "<<pos[i].name<<"'s cooldown increased by 1!\n";
				}else{
					if(rand()%2==1){
						pos[i].skill[1].cd++;
						cout<<"Player "<<pos[i].player<<"'s "<<pos[i].name<<"'s cooldown increased by 1!\n";
					}
				}
			}
		}
	}
}
void celestialapocalypse(){
	system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player!=pos[turn].player&&pos[i].hp>0){
				enemy=i;
				base_dmg=5.2;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
		}
}
void prophet_skill(int skill_num){
	if(skill_num==1)baktunshiftingstrike();
	else celestialapocalypse();
}


void obsidianlance(){
	base_dmg=1.8;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		if(hit()){
			block();
			if(!pos[enemy].stealth)deal_dmg(base_dmg,pos[enemy].current_stat.def/2);
			else deal_dmg(base_dmg,pos[enemy].current_stat.def*0.75);
		}
	}
}
void guardianeagle(){
	system("CLS");
		skill_use(1);
		pos[turn].base_stat.def++;
		pos[turn].base_stat.max_hp+=10;
		dispel_debuff(turn);
		gain(turn,"Block",-1);
}
void eagle_skill(int skill_num){
	if(skill_num==1)obsidianlance();
	else guardianeagle();
}


void grandcleave(){
	system("CLS");
	skill_use(0);
	for(int i=0;i<10;i++){
		if(pos[i].player!=pos[turn].player&&pos[i].hp>0){
			enemy=i;
			if(hit()){
			base_dmg=1.6;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
		}
	}
}
void risingaltitude(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			base_dmg=2.2;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(pos[enemy].hp>0)dispel_buff(enemy);
			}pos[turn].base_stat.atk++;
	}
}
void puma_skill(int skill_num){
	if(skill_num==1)grandcleave();
	else risingaltitude();
}


void tridentattack(){
	bool has=false;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		int chance=0;
		for(int i=0;i<10;i++){
			if(pos[i].hp==0&&pos[i].player!=pos[turn].player)chance+=25;
		}
		system("CLS");
		skill_use(0);
		if(hit()){
			base_dmg=1.8;
			block();
			if(pos[enemy].def_down>0)has=true;
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			if(has&&rand()%100<chance)gain(turn,"Attack Up",1);
			if(pos[enemy].hp>0&&rand()%100<chance)gain(enemy,"Defense Down",2);
			}
	}
}
void quarternet(){
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		if(hit()){
			stun(enemy);
			remove_turn_meter(enemy,100);
			dispel_buff(enemy);
			gain(enemy,"Knock",2);
			}
	}
}
void gladiator_skill(int skill_num){
	if(skill_num==1)tridentattack();
	else quarternet();
}



void steadythrust(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		bool add=false;
		system("CLS");
		skill_use(0);
		if(hit()){
			base_dmg=1.8;
			block();
			deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}if(pos[turn].block){
				for(int i=0;i<10;i++){
					if(pos[i].player==pos[turn].player&&pos[i].hp>0&&find_tag(i,"Greek"))heal(i,pos[i].current_stat.max_hp/20);
				}
			}
	}
}
void phalanx(){
		system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp>0){
				gain(i,"Block",-1);
				gain(i,"Defense Up",1);
				pos[i].knock=0;
				cout<<"Player "<<pos[i].player<<"'s "<<pos[i].name<<" loses Knock!\n";
			}
		}
}
void hoplite_skill(int skill_num){
	if(skill_num==1)steadythrust();
	else phalanx();
}


void dorybarrage(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				if(pos[enemy].block){
			pos[enemy].block=false;
			cout<<"Player "<<pos[enemy].player<<"'s "<<pos[enemy].name<<" loses Block!\n";
			gain(turn,"Block",-1);
		}base_dmg=0.8;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}if(pos[enemy].hp>0&&find_tag(enemy,"Middle-Eastern")){
				dispel_buff(enemy);
				if(hit()){base_dmg=0.8;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
			}
	}
}
void mobilizing(){
		system("CLS");
		skill_use(1);
		if(pos[turn].block){
			gain_turn_meter(turn,100);
			gain(turn,"Attack Up",2);
		}
		else gain_turn_meter(turn,50);
		gain(turn,"Speed Up",2);
}
void hypaspist_skill(int skill_num){
	if(skill_num==1)dorybarrage();
	else mobilizing();
}


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
void savagespirit(){
		system("CLS");
		skill_use(1);
		int count=count_app(turn,"Debuff");
		dispel_debuff(turn);
		if(count>0){
			gain_turn_meter(turn,20*count);
		heal(turn,pos[turn].current_stat.max_hp*0.15*count);
		}
}
void zande_skill(int skill_num){
	if(skill_num==1)decapitator();
	else savagespirit();
}


void mortalsmack(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.6;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);	
			}if(pos[turn].buff_block){
			pos[turn].buff_block=0;
			cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<" loses Buff Block!\n";
		}if(rand()%2)gain(turn,"Deathproof",-1);
	}
}
void immortalize(){
		system("CLS");
		skill_use(1);
		if(pos[turn].heal_block>0){
			pos[turn].heal_block=0;
			cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<" loses Heal Block!\n";
		}int lost_hp=pos[turn].current_stat.max_hp-pos[turn].hp;
		heal(turn,lost_hp*0.3);
		for(int i=0;i<10;i++){
			if(pos[i].hp==0&&pos[i].player==pos[turn].player)gain_regeneration(turn,1);
		}
}
void immortal_skill(int skill_num){
	if(skill_num==1)mortalsmack();
	else immortalize();
}



void naginata(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.4;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp>0&&pos[enemy].atk_down)gain(enemy,"Defense Down",2);
			}
	}
}
void intimidating(){
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].hp>0&&pos[i].player!=pos[turn].player){
				if(i==enemy){
					gain(enemy,"Silence",2);
					gain(enemy,"Attack Down",2);
					remove_turn_meter(enemy,100);
				}else{
					gain(i,"Silence",1);
					gain(i,"Attack Down",1);
					remove_turn_meter(i,50);
				}
			}
		}
	}	
}
void ronin_skill(int skill_num){
	if(skill_num==1)naginata();
	else intimidating();
}



void breakthrough(){
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		double def_mul=1,dmg_mul=1;
		int oalive=0;
		system("CLS");
		skill_use(1);
			if(hit()){
				base_dmg=4;
				for(int i=0;i<10;i++){
					if(pos[i].hp==0&&pos[i].player==pos[turn].player){
						dmg_mul+=0.15;
						def_mul-=0.05;
					}
				}base_dmg*=dmg_mul;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def*def_mul);
	}for(int i=0;i<10;i++){
		if(pos[i].hp>0&&pos[i].player==pos[turn].player&&i!=turn)oalive++;
		heal(turn,pos[turn].current_stat.max_hp*0.05*oalive);
		if(rand()%100<oalive*25)gain(turn,"Block",-1);
	}
}
}
void determinedslash(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.4;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp>0){
					if(pos[enemy].silenced>0){
						pos[enemy].skill[1].cd++;
						cout<<"Player "<<pos[enemy].player<<"'s "<<pos[enemy].name<<"'s cooldown increased by 1!\n";
				}if(pos[enemy].heal_block>0)gain(enemy,"Silence",2);
				gain(enemy,"Heal Block",2);
			}
	}
}
}
void templar_skill(int skill_num){
	if(skill_num==1)determinedslash();
	else breakthrough();
}



void macesmash(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				int num=count_app(enemy,"Buff");
				base_dmg=1.8;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp>0){
					if(pos[enemy].knock>0){
						if(rand()%100<25*num)stun(enemy);
					}
					if(rand()%100<50*num)gain(enemy,"Knock",2);
				}
			}
	}
}
void warcry(){
		system("CLS");
		skill_use(1);
		gain(turn,"Protect",2);
		gain(turn,"Defense Up,",2);
		for(int i=0;i<10;i++){
			if(pos[i].hp>0&&pos[i].player==pos[turn].player&&i!=turn){
				gain(i,"Attack Up",2);
				if(find_tag(i,"Eurasian"))gain_turn_meter(i,50);
			}
}}
void mongul_skill(int skill_num){
	if(skill_num==1)macesmash();
	else warcry();
}



void manhunting(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.8;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp==0){
					for(int i=0;i<10;i++){
						if(pos[i].player==pos[turn].player&&pos[i].hp>0)gain_turn_meter(i,25);
					}
				}
			}
	}
}
void nomadicsurvivor(){
		system("CLS");
		skill_use(1);
		gain(turn,"Attack Up",1);
		gain(turn,"Speed Up,",1);
		gain(turn,"Evade",-1);
		int all_buff=0;
		for(int i=0;i<10;i++){
			if(pos[i].hp>0&&pos[i].player!=pos[turn].player)all_buff+=count_app(i,"Buff");
		}
		for(int i=0;i<10;i++){
			if(pos[i].hp>0&&pos[i].player==pos[turn].player)gain_turn_meter(i,5*all_buff);
		}
}
void nomad_skill(int skill_num){
	if(skill_num==1)manhunting();
	else nomadicsurvivor();
}



void cannibalstrike(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.6;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp==0)heal(turn,pos[enemy].current_stat.max_hp);
			}
	}
}
void haka(){
		system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].hp>0&&pos[i].player!=pos[turn].player){
				gain(i,"Silenced",1);
			}else if(pos[i].hp>0&&pos[i].player==pos[turn].player){
				gain(i,"Health Up",2);
				gain(i,"Attack Up",2);
				gain(i,"Defense Up",2);
				gain(i,"Block",-1);
			}
		}
}
void maori_skill(int skill_num){
	if(skill_num==1)cannibalstrike();
	else haka();
}



void katarslash(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.6;
				int num=count_app(enemy,"Buff");
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(num>0)gain_turn_meter(turn,10*num);
			}
	}
}
void chakram(){
	vector<int> temp;
	int random;
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(1);
			if(hit()){
				base_dmg=2.4;
				if(pos[enemy].block)temp.push_back(enemy);
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				for(int i=0;i<10;i++){
					if(pos[i].hp>0&&pos[i].player!=pos[turn].player&&i!=enemy)temp.push_back(i);
				}
					while(temp.size()>0){
						random=rand()%temp.size();
						enemy=temp[random];
						if(!pos[enemy].block)temp.erase(temp.begin()+random);
						if(hit()){
							base_dmg=2.4;
							block();
							deal_dmg(base_dmg,pos[enemy].current_stat.def);
						}else break;
					}
					}
			}
	}
void rajput_skill(int skill_num){
	if(skill_num==1)katarslash();
	else chakram();
}


void barbaricassault(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
			if(hit()){
				base_dmg=1.2;
				if(count_app(enemy,"Buff")==0)base_dmg*=2;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
	}
}
void furorceltica(){
	int hit_count=0;
		system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].hp>0&&pos[i].player!=pos[turn].player){
				enemy=i;
				if(hit()){
				hit_count++;
				base_dmg=3.4;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}
			}
		}gain_turn_meter(turn,hit_count*20);
		gain(turn,"Defense Down",2);
	}
void pictish_skill(int skill_num){
	if(skill_num==1)barbaricassault();
	else furorceltica();
}


void gallicbladework(){
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		bool has=false;
		system("CLS");
		skill_use(0);
			if(hit()){
				if(pos[enemy].knock)has=true;
				base_dmg=1.8;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
			}if(has){
				for(int i=0;i<10;i++){
				if(pos[i].hp>0&&pos[i].player==pos[turn].player&&find_tag(i,"Celtic"))heal(i,pos[i].current_stat.max_hp/20);
			}
			}
	}
}
void shieldcrash(){
	int count=0;
	enemy=targetenemy(pos[turn].skill[1].name,pos[turn].skill[1].des);
		if(enemy!=-2){
		system("CLS");
		skill_use(1);
			if(hit()){
				base_dmg=3.2;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp>0)gain(enemy,"Knock",3);
			}gain(turn,"Speed Down",2);
	}
	}
void gallic_skill(int skill_num){
	if(skill_num==1)gallicbladework();
	else shieldcrash();
}



void wildsmack(){
	int percentage;
	enemy=targetenemy(pos[turn].skill[0].name,pos[turn].skill[0].des);
	if(enemy!=-2){
		system("CLS");
		skill_use(0);
		percentage=(pos[enemy].hp*100)/pos[enemy].current_stat.max_hp;
				percentage/=100;
				percentage/=2;
			if(hit()){
				base_dmg=1.8;
				block();
				deal_dmg(base_dmg,pos[enemy].current_stat.def);
				if(pos[enemy].hp>0){
					if(rand()%100<percentage)stun(enemy);
				}
			}if(rand()%100<percentage)gain(turn,"Attack Down",2);
	}
}
void callofthewild(){
		system("CLS");
		skill_use(1);
		for(int i=0;i<10;i++){
			if(pos[i].player==pos[turn].player&&pos[i].hp>0){
				if(pos[i].hp_down){
					gain(i,"Health Up",pos[i].hp_down);
					pos[i].hp_down=0;
				}if(pos[i].atk_down){
					gain(i,"Attack Up",pos[i].atk_down);
					pos[i].atk_down=0;
				}if(pos[i].def_down){
					gain(i,"Defense Up",pos[i].def_down);
					pos[i].def_down=0;
				}if(pos[i].spd_down){
					gain(i,"Speed Up",pos[i].spd_down);
					pos[i].spd_down=0;
				}if(find_tag(i,"Celtic"))gain_regeneration(i,1);
			}
		}
	}
void druid_skill(int skill_num){
	if(skill_num==1)wildsmack();
	else callofthewild();
}
