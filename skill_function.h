#include "form.h"
int targetenemy(string name,string des){
	char key[10]={'i','q','w','o','p','e','a','k','l','s'},p='p';
	while(p=='p'){
		system("CLS");
	cout<<"Use "<<name<<" at..."<<"\n\n";
	int prior=pos[0].prior;
	for(int i=0;i<10;i++){
		if(pos[i].player!=pos[turn].player&&pos[i].hp>0){
			if(pos[i].prior>prior)prior=pos[i].prior;
		}
	}
	for(int i=0;i<10;i++){
		if(pos[i].player!=pos[turn].player&&pos[i].prior==prior&&pos[i].hp>0){
			cout<<"'"<<key[i]<<"' "<<pos[i].name<<" HP : "<<pos[i].hp<<"/"<<pos[i].current_stat.max_hp<<" turn meter : "<<pos[i].tm<<"/100\n";
			if(pos[i].hp_up>0)cout<<" HlUp("<<pos[i].hp_up<<")";
			if(pos[i].hp_down>0)cout<<" HlDw("<<pos[i].hp_down<<")";
			if(pos[i].atk_up>0)cout<<" AtUp("<<pos[i].atk_up<<")";
			if(pos[i].atk_down>0)cout<<" AtDw("<<pos[i].atk_down<<")";
			if(pos[i].def_up>0)cout<<" DfUp("<<pos[i].def_up<<")";
			if(pos[i].def_down>0)cout<<" DfDw("<<pos[i].def_down<<")";
			if(pos[i].spd_up>0)cout<<" SpUp("<<pos[i].spd_up<<")";
			if(pos[i].spd_down>0)cout<<" SpDw("<<pos[i].spd_down<<")";
			if(pos[i].block)cout<<" Blc";
			if(pos[i].evade)cout<<" Evd";
			if(pos[i].blind)cout<<" Bli";
			if(pos[i].stun)cout<<" Stun";
			if(pos[i].silenced>0)cout<<" Sil("<<pos[i].silenced<<")";
			if(pos[i].heal_block>0)cout<<" HlBl("<<pos[i].heal_block<<")";
			if(pos[i].knock>0)cout<<" Knoc("<<pos[i].knock<<")";
			if(pos[i].stealth>0)cout<<" Stlt("<<pos[i].stealth<<")";
			if(pos[i].protect>0)cout<<" Prot("<<pos[i].protect<<")";
			if(pos[i].buff_block>0)cout<<" BfBl("<<pos[i].buff_block<<")";
			if(pos[i].deathproof)cout<<" Dtpf";
			if(pos[i].bleed.size()>0)cout<<" Bl x"<<pos[i].bleed.size();
			if(pos[i].regeneration.size()>0)cout<<" Re x"<<pos[i].regeneration.size();
			cout<<"\n\n";
		}
	}
	cout<<"\n"<<des<<"\n\n'b' to cancle...";
	while(p!='b'){
		p=_getch();
		for(int i=0;i<10;i++){
			if(p==key[i]&&pos[i].player!=pos[turn].player&&pos[i].prior==prior&&pos[i].hp>0){
				return i;
			}else if(p=='b')break;
		}
	}
	}
	return -2;
}
int targetally(string name,string des){
	char key[10]={'i','q','w','o','p','e','a','k','l','s'},p='p';
	while(p=='p'){
		system("CLS");
	cout<<"Use "<<name<<" at..."<<"\n";
	for(int i=0;i<10;i++){
		if(pos[i].player==pos[turn].player&&pos[i].hp>0){
			cout<<"'"<<key[i]<<"' "<<pos[i].name<<" HP : "<<pos[i].hp<<"/"<<pos[i].current_stat.max_hp<<" turn meter : "<<pos[i].tm<<"/100\n";
		}
	}
	cout<<des<<"\n'b' to cancle...";
	while(p!='b'){
		p=_getch();
		for(int i=0;i<10;i++){
			if(p==key[i]&&pos[i].player==pos[turn].player&&pos[i].hp>0){
				return i;
			}else if(p=='b')break;
		}
	}
	}
	return -2;
}
void skill_use(int num){
	skill_used=true;
	cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<" uses "<<pos[turn].skill[num].name<<"!\n";
	if(num==1)pos[turn].skill[num].cd=pos[turn].skill[num].bcd;
}
bool hit(){
	if(!pos[turn].blind){
			if(!pos[enemy].evade){
				return true;
			}else if(!pos[enemy].stun){
				pos[enemy].evade=false;
				cout<<"Player "<<pos[enemy].player<<"'s "<<pos[enemy].name<<" evades!\n";
				return false;
			}else return true;
		}else{
			pos[turn].blind=false;
			cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<" misses!\n";
			return false;
		}
}
void block(){
	if(pos[enemy].block&&!pos[enemy].stun){
		pos[enemy].block=false;
		base_dmg*=0.5;
		cout<<"Player "<<pos[enemy].player<<"'s "<<pos[enemy].name<<" Block!\n";
	}
}
void defeat(int target){
	if(!pos[target].deathproof){
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
	pos[target].buff_block=0;
	pos[target].bleed.clear();
	pos[target].regeneration.clear();
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" is defeated!\n";
	}else{
		pos[target].hp=1;
		pos[target].deathproof=false;
		cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" is saved by Deathproof!\nHP : "<<pos[target].hp<<"/"<<pos[target].current_stat.max_hp<<"\n";
	}
}
void deal_dmg(double base,double armor){
	base*=global_dmg_multiplier;
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
	cout<<"Player "<<pos[enemy].player<<"'s "<<pos[enemy].name<<" takes "<<dmg<<" damage!\nPlayer "<<pos[enemy].player<<"'s "<<pos[enemy].name<<"'s HP : "<<pos[enemy].hp<<"/"<<pos[enemy].current_stat.max_hp<<"\n";
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
	bool blocked=false;
	if(target==turn)dur++;
	if(x=="Health Down"){
		if(pos[target].hp_down<=dur)pos[target].hp_down=dur;
	}else if(x=="Attack Down"){
		if(pos[target].atk_down<=dur)pos[target].atk_down=dur;
	}else if(x=="Defense Down"){
		if(pos[target].def_down<=dur)pos[target].def_down=dur;
	}else if(x=="Speed Down"){
		if(pos[target].spd_down<=dur)pos[target].spd_down=dur;
	}else if(x=="Silence"){
		if(pos[target].silenced<=dur)pos[target].silenced=dur;
	}else if(x=="Knock"){
		if(pos[target].knock<=dur)pos[target].knock=dur;
	}else if(x=="Heal Block"){
		if(pos[target].heal_block<=dur)pos[target].heal_block=dur;
	}else if(x=="Buff Block"){
		if(pos[target].buff_block<=dur)pos[target].buff_block=dur;
	}else if(x=="Blind")pos[target].blind=true;
	
	
	else if(pos[target].buff_block==0){
		if(x=="Health Up"){
		if(pos[target].hp_up<=dur)pos[target].hp_up=dur;
	}else if(x=="Attack Up"){
		if(pos[target].atk_up<=dur)pos[target].atk_up=dur;
	}else if(x=="Defense Up"){
		if(pos[target].def_up<=dur)pos[target].def_up=dur;
	}else if(x=="Speed Up"){
		if(pos[target].spd_up<=dur)pos[target].spd_up=dur;
	}else if(x=="Protect"){
		if(pos[target].protect<=dur)pos[target].protect=dur;
	}else if(x=="Stealth"){
		if(pos[target].stealth<=dur)pos[target].stealth=dur;
	}else if(x=="Block")pos[target].block=true;
	else if(x=="Evade")pos[target].evade=true;
	else if(x=="Deathproof")pos[target].deathproof=true;
	}else blocked=true;
	if(!blocked){
		cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" gains "<<x;
		if(temp>0)cout<<"("<<temp<<")";
	}else cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" cannot gains new buffs due to being Buff-Blocked("<<pos[target].buff_block<<")";
//else cout<<"no match for gain string!!!\nplease report this to dev";
	cout<<"!\n";
	update_stat();
}
int count_app(int target,string type){
	int count=0;
	if(type=="Buff"){
	if(pos[target].atk_up>0)count++;
	if(pos[target].def_up>0)count++;
	if(pos[target].hp_up>0)count++;
	if(pos[target].block)count++;
	if(pos[target].spd_up>0)count++;
	if(pos[target].protect>0)count++;
	if(pos[target].stealth>0)count++;
	if(pos[target].evade)count++;
	if(pos[target].deathproof)count++;
	count+=pos[target].regeneration.size();
	}else{
	if(pos[target].atk_down>0)count++;
	if(pos[target].def_down>0)count++;
	if(pos[target].hp_down>0)count++;
	if(pos[target].blind)count++;
	if(pos[target].spd_down>0)count++;
	if(pos[target].silenced>0)count++;
	if(pos[target].heal_block>0)count++;
	if(pos[target].knock>0)count++;
	if(pos[target].stun)count++;
	if(pos[target].buff_block>0)count++;
	count+=pos[target].bleed.size();
	}return count;
}
void dispel_buff(int target){
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" loses all Buffs!\n";
		pos[target].atk_up=0;
		pos[target].def_up=0;
		pos[target].hp_up=0;
		pos[target].block=false;
		pos[target].spd_up=0;
		pos[target].protect=0;
		pos[target].stealth=0;
		pos[target].evade=false;
		pos[target].deathproof=false;
	pos[target].regeneration.clear();
	update_stat();
}
void dispel_debuff(int target){
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" loses all Debuffs!\n";
		pos[target].atk_down=0;
		pos[target].def_down=0;
		pos[target].hp_down=0;
		pos[target].block=false;
		pos[target].spd_down=0;
		pos[target].silenced=0;
		pos[target].heal_block=0;
		pos[target].knock=0;
		pos[target].stun=false;
		pos[target].buff_block=0;
	pos[target].bleed.clear();
	update_stat();
}
void stun(int target){
	pos[target].stun=true;
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" is Stunned!\n";
}
void heal(int target,int heal){
	if(pos[target].heal_block==0){
		if(pos[target].hp+heal>pos[target].current_stat.max_hp)heal-=(pos[target].hp+heal)-pos[target].current_stat.max_hp;
	pos[target].hp+=heal;
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" heals for +"<<heal<<" HP! HP : "<<pos[target].hp<<"/"<<pos[target].current_stat.max_hp<<"\n";
	}else cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" cannot heal due to being Heal-Blocked("<<pos[target].heal_block<<")!\n";
}
void gain_turn_meter(int target,int gain){
	if(pos[target].knock==0){
		pos[target].tm+=gain;
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" gains +"<<gain<<"% turn meter!\n";
	}
	else cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" cannot gain bonus turn meter due to being Knocked("<<pos[target].knock<<")!\n";
}
void remove_turn_meter(int target,int remove){
	pos[target].tm-=remove;
	if(pos[target].tm<0)pos[target].tm=0;
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" loses -"<<remove<<"% turn meter!\n";
}
void inflict_bleed(int target,int dur){
	pos[target].bleed.push_back(dur);
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" gains Bleed("<<dur<<")!\n";
}
void gain_regeneration(int target,int dur){
	if(!pos[target].buff_block){
		pos[target].regeneration.push_back(dur);
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" gains Regeneration("<<dur<<")!\n";
	}else cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" cannot gains new buffs due to being Buff-Blocked("<<pos[target].buff_block<<")!\n";
}
void bleed(){
	system("CLS");
	int bleed_dmg=pos[turn].current_stat.max_hp*0.05*global_dmg_multiplier;
	if(bleed_dmg<1)bleed_dmg=1;
	for(int i=0;i<pos[turn].bleed.size();i++){
		pos[turn].hp-=bleed_dmg;
		if(pos[turn].hp<0)pos[turn].hp=0;
		cout<<bleed_dmg<<" bleed damage!\n";
	}
	if(pos[turn].bleed.size()>0){
		cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<"'s HP : "<<pos[turn].hp<<"/"<<pos[turn].current_stat.max_hp<<"\n";
		if(pos[turn].player==1){
			cout<<"'d' to continue...\n";
		p='z';
		while(p!='d')p=_getch();
		}
		else{
		cout<<"'k' to continue...\n";
		p='z';
		while(p!='k')p=_getch();
	}
	}
	for(int i=0;i<pos[turn].bleed.size();i++){
		pos[turn].bleed[i]--;
		if(pos[turn].bleed[i]==0)pos[turn].bleed.erase(pos[turn].bleed.begin()+i);
	}
}
void regeneration(){
	system("CLS");
	int heal_amount=pos[turn].current_stat.max_hp*0.1;
	if(heal_amount<1)heal_amount=1;
	if(pos[turn].heal_block)heal_amount=0;
	for(int i=0;i<pos[turn].regeneration.size();i++){
		pos[turn].hp+=heal_amount;
		if(pos[turn].hp>pos[turn].current_stat.max_hp)pos[turn].hp=pos[turn].current_stat.max_hp;
		if(pos[turn].heal_block)cout<<"Healing from Regeneration Blocked!\n";
		else cout<<"+"<<heal_amount<<" HP from regeneration!\n";
	}if(pos[turn].regeneration.size()>0){
		cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<"'s HP : "<<pos[turn].hp<<"/"<<pos[turn].current_stat.max_hp<<"\n";
		if(pos[turn].player==1){
			cout<<"'d' to continue...\n";
		p='z';
		while(p!='d')p=_getch();
		}
		else{
		cout<<"'k' to continue...\n";
		p='z';
		while(p!='k')p=_getch();
	}
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
	cout<<"Player "<<pos[target].player<<"'s "<<pos[target].name<<" is revived! HP : "<<pos[target].hp<<"/"<<pos[target].current_stat.max_hp<<"\n";
}
