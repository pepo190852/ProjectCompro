#include "form.h"
int targetenemy(string name,string des){
	char key[10]={'i','q','w','o','p','e','a','k','l','s'},p='p';
	while(p=='p'){
		system("CLS");
	cout<<"Use "<<name<<" at..."<<"\n";
	int prior=pos[0].prior;
	for(int i=0;i<10;i++){
		if(pos[i].player!=pos[turn].player){
			if(pos[i].prior>prior)prior=pos[i].prior;
		}
	}
	for(int i=0;i<10;i++){
		if(pos[i].player!=pos[turn].player&&pos[i].prior==prior&&pos[i].hp>0){
			cout<<"'"<<key[i]<<"' "<<pos[i].name<<" HP : "<<pos[i].hp<<"/"<<pos[i].current_stat.max_hp<<" turn meter : "<<pos[i].tm<<"/100\n";
		}
	}
	cout<<des<<"\n'b' to cancle...";
	while(p!='b'){
		p=_getch();
		for(int i=0;i<10;i++){
			if(p==key[i]&&pos[i].player!=pos[turn].player&&pos[turn].prior==prior&&pos[i].hp>0){
				return i;
			}else if(p=='b')break;
		}
	}
	}
	return -2;
}
void skill_use(int num){
	skill_used=true;
	cout<<pos[turn].name<<" uses "<<pos[turn].skill[num].name<<"!\n";
	if(num==1)pos[turn].skill[num].cd=pos[turn].skill[num].bcd;
}
bool hit(){
	if(!pos[turn].blind){
			if(!pos[enemy].evade){
				return true;
			}else if(!pos[enemy].stun){
				pos[enemy].evade=false;
				cout<<pos[enemy].name<<" evades!\n";
				return false;
			}else return true;
		}else{
			pos[turn].blind=false;
			cout<<pos[turn].name<<" misses!\n";
			return false;
		}
}
void block(){
	if(pos[enemy].block&&!pos[enemy].stun){
		pos[enemy].block=false;
		base_dmg*=0.5;
		cout<<pos[enemy].name<<" Block!\n";
	}
}
void defeat(int target){
	pos[target].prior=1;
	pos[target].tm=0;
	pos[target].hp_up=0;
	pos[target].hp_down=0;
	pos[target].atk_up=0;
	pos[target].atk_down=0;
	pos[target].def_up=0;
	pos[target].def_down=0;
	pos[target].spd_up=0;
	pos[target].spd_down=0;
	pos[target].protect=0;
	pos[target].stealth=0;
	pos[target].hp=0;
	pos[target].block=false;
	pos[target].evade=false;
	pos[target].blind=false;
	pos[target].stun=false;
	pos[target].silenced=0;
	pos[target].heal_block=0;
	pos[target].knock=0;
	pos[target].bleed.clear();
	pos[target].regeneration.clear();
	cout<<pos[target].name<<" is defeated!\n";
}
void deal_dmg(double base,int armor){
	int dmg;
	double multiplier,num=20;
	multiplier=num/(armor+num);
	dmg=base*pos[turn].current_stat.atk*multiplier;
	if(dmg<1)dmg=1;
	int unstable=dmg/10;
	if(unstable>0){
		unstable=(rand()%((unstable*2)+1))-unstable;
	dmg+=unstable;
	}
	pos[enemy].hp-=dmg;
	if(pos[enemy].hp<0)pos[enemy].hp=0;
	cout<<pos[enemy].name<<" takes "<<dmg<<" damage!\n"<<pos[enemy].name<<"'s HP : "<<pos[enemy].hp<<"/"<<pos[enemy].current_stat.max_hp<<"\n";
	if(pos[enemy].hp==0)defeat(enemy);
}
void start_stat(){
	for(int i=0;i<10;i++){
		pos[i].current_stat.max_hp=pos[i].base_stat.max_hp;
		pos[i].current_stat.atk=pos[i].base_stat.atk;
		pos[i].current_stat.def=pos[i].base_stat.def;
		pos[i].current_stat.spd=pos[i].base_stat.spd;
	}
}
void update_stat(){
	double multiplier,hp_percent,pre_max_hp;
	for(int i=0;i<10;i++){
		pre_max_hp=pos[i].current_stat.max_hp;
		hp_percent=(pos[i].hp*100)/pos[i].current_stat.max_hp;
		hp_percent/=100;
		multiplier=1;
		if(pos[i].hp_up>0)multiplier+=0.25;
		if(pos[i].hp_down>0)multiplier*=0.8;
		pos[i].current_stat.max_hp=pos[i].base_stat.max_hp*multiplier;
		int dif=pos[i].current_stat.max_hp-pre_max_hp;
		if(dif!=0){
			pos[i].hp+=dif*hp_percent;
		}
		multiplier=1;
		if(pos[i].atk_up>0)multiplier+=0.25;
		if(pos[i].atk_down>0)multiplier*=0.8;
		pos[i].current_stat.atk=pos[i].base_stat.atk*multiplier;
		multiplier=1;
		if(pos[i].def_up>0)multiplier+=0.25;
		if(pos[i].def_down>0)multiplier*=0.8;
		pos[i].current_stat.def=pos[i].base_stat.def*multiplier;
		multiplier=1;
		if(pos[i].spd_up>0)multiplier+=0.25;
		if(pos[i].spd_down>0)multiplier*=0.8;
		pos[i].current_stat.spd=pos[i].base_stat.spd*multiplier;
		if(pos[i].protect>0)pos[i].prior=2;
		else if(pos[i].stealth>0)pos[i].prior=0;
		else pos[i].prior=1;
	}
}
void gain(int target,string x,int dur){
	int temp=dur;
	if(target==turn)dur++;
	cout<<pos[target].name<<" gains "<<x;
	if(x=="Health Up"){
		if(pos[target].hp_up<=dur)pos[target].hp_up=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Attack Up"){
		if(pos[target].atk_up<=dur)pos[target].atk_up=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Defense Up"){
		if(pos[target].def_up<=dur)pos[target].def_up=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Speed Up"){
		if(pos[target].spd_up<=dur)pos[target].spd_up=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Health Down"){
		if(pos[target].hp_down<=dur)pos[target].hp_down=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Attack Down"){
		if(pos[target].atk_down<=dur)pos[target].atk_down=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Defense Down"){
		if(pos[target].def_down<=dur)pos[target].def_down=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Speed Down"){
		if(pos[target].spd_down<=dur)pos[target].spd_down=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Protect"){
		if(pos[target].protect<=dur)pos[target].protect=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Stealth"){
		if(pos[target].stealth<=dur)pos[target].stealth=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Silence"){
		if(pos[target].silenced<=dur)pos[target].silenced=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Knock"){
		if(pos[target].knock<=dur)pos[target].knock=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Heal Block"){
		if(pos[target].heal_block<=dur)pos[target].heal_block=dur;
		cout<<"("<<temp<<")";
	}else if(x=="Block")pos[target].block=true;
	else if(x=="Blind")pos[target].blind=true;
	else if(x=="Evade")pos[target].evade=true;
else cout<<"no match for gain string!!!\nplease report this to dev";
	cout<<"!\n";
	update_stat();
}
int dispel_buff(int target){
	cout<<pos[target].name<<" loses all Buffs!\n";
	int count=0;
	if(pos[target].atk_up>0){
		pos[target].atk_up=0;
		count++;
	}if(pos[target].def_up>0){
		pos[target].def_up=0;
		count++;
	}if(pos[target].hp_up>0){
		pos[target].hp_up=0;
		count++;
	}if(pos[target].block){
		pos[target].block=false;
		count++;
	}if(pos[target].spd_up>0){
		pos[target].spd_up=0;
		count++;
	}if(pos[target].protect>0){
		pos[target].protect=0;
		count++;
	}if(pos[target].stealth>0){
		pos[target].stealth=0;
		count++;
	}if(pos[target].evade){
		pos[target].evade=false;
		count++;
	}count+=pos[target].regeneration.size();
	pos[target].regeneration.clear();
	update_stat();
	return count;
}
int dispel_debuff(int target){
	cout<<pos[target].name<<" loses all Debuffs!\n";
	int count=0;
	if(pos[target].atk_down>0){
		pos[target].atk_down=0;
		count++;
	}if(pos[target].def_down>0){
		pos[target].def_down=0;
		count++;
	}if(pos[target].hp_down>0){
		pos[target].hp_down=0;
		count++;
	}if(pos[target].blind){
		pos[target].block=false;
		count++;
	}if(pos[target].spd_down>0){
		pos[target].spd_down=0;
		count++;
	}if(pos[target].silenced>0){
		pos[target].silenced=0;
		count++;
	}if(pos[target].heal_block>0){
		pos[target].heal_block=0;
		count++;
	}if(pos[target].knock>0){
		pos[target].knock=0;
		count++;
	}if(pos[target].stun){
		pos[target].stun=false;
		count++;
	}
	count+=pos[target].bleed.size();
	pos[target].bleed.clear();
	update_stat();
	return count;
}
void stun(int target){
	pos[target].stun=true;
	cout<<pos[target].name<<" is Stunned!\n";
}
void heal(int target,int heal){
	if(pos[target].heal_block==0){
		if(pos[target].hp+heal>pos[target].current_stat.max_hp)heal-=(pos[target].hp+heal)-pos[target].current_stat.max_hp;
	pos[target].hp+=heal;
	cout<<pos[target].name<<" heals for +"<<heal<<" HP! HP : "<<pos[target].hp<<"/"<<pos[target].current_stat.max_hp<<"\n";
	}else cout<<pos[target].name<<" cannot heal due to being Heal-Blocked("<<pos[target].heal_block<<")!\n";
}
void gain_turn_meter(int target,int gain){
	if(pos[target].knock==0){
		pos[target].tm+=gain;
	cout<<pos[target].name<<" gains +"<<gain<<"% turn meter!\n";
	}
	else cout<<pos[target].name<<" cannot gain bonus turn meter due to being Knocked("<<pos[target].knock<<")!\n";
}
void remove_turn_meter(int target,int remove){
	pos[target].tm-=remove;
	if(pos[target].tm<0)pos[target].tm=0;
	cout<<pos[target].name<<" loses -"<<remove<<"% turn meter!\n";
}
void inflict_bleed(int target,int dur){
	pos[target].bleed.push_back(dur);
	cout<<pos[target].name<<" gains Bleed("<<dur<<")!\n";
}
void gain_regeneration(int target,int dur){
	pos[target].regeneration.push_back(dur);
	cout<<pos[target].name<<" gains Regeneration("<<dur<<")!\n";
}
void bleed(){
	int bleed_dmg=pos[turn].current_stat.max_hp*0.05;
	if(bleed_dmg<1)bleed_dmg=1;
	for(int i=0;i<pos[turn].bleed.size();i++){
		pos[turn].hp-=bleed_dmg;
		if(pos[turn].hp<0)pos[turn].hp=0;
		cout<<bleed_dmg<<" bleed damage!\n";
	}
	for(int i=0;i<pos[turn].bleed.size();i++){
		pos[turn].bleed[i]--;
		if(pos[turn].bleed[i]==0)pos[turn].bleed.erase(pos[turn].bleed.begin()+i);
	}
}
void regeneration(){
	int heal_amount=pos[turn].current_stat.max_hp*0.1;
	if(heal_amount<1)heal_amount=1;
	for(int i=0;i<pos[turn].regeneration.size();i++){
		pos[turn].hp+=heal_amount;
		if(pos[turn].hp>pos[turn].current_stat.max_hp)pos[turn].hp=pos[turn].current_stat.max_hp;
		cout<<"+"<<heal_amount<<" HP from regeneration!\n";
	}
	for(int i=0;i<pos[turn].regeneration.size();i++){
		pos[turn].regeneration[i]--;
		if(pos[turn].regeneration[i]==0)pos[turn].regeneration.erase(pos[turn].regeneration.begin()+i);
	}
}
bool find_tag(int target,string x){
	for(int i=0;i<pos[target].tag.size();i++){
		if(pos[target].tag[i]==x)return true;
	}
	return false;
}

void revive(int target,int hp){
	pos[target].hp=hp;
	cout<<pos[target].name<<" is revived! HP : "<<pos[target].hp<<"/"<<pos[target].current_stat.max_hp<<"\n";
}
