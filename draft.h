#include "Champion.h"
//include more champion header
champion upload(int i){
	return champions[i];
}
void use_skill(int id,int skill_num){
	if(id==0)spartan_skill(skill_num);
	else if(id==1)samurai_skill(skill_num);
	else if(id==2)samurai(skill_num);
	else if(id==3)samurai(skill_num);
	else if(id==4)samurai(skill_num);
	else if(id==5)samurai(skill_num);
	else if(id==6)samurai(skill_num);
	else if(id==7)samurai(skill_num);
	else if(id==8)samurai(skill_num);
	else if(id==9)samurai(skill_num);
	else if(id==10)samurai(skill_num);
	else if(id==11)samurai(skill_num);
	else if(id==12)samurai(skill_num);
	else if(id==13)samurai(skill_num);
	else if(id==14)samurai(skill_num);
	else if(id==15)samurai(skill_num);
	else if(id==16)samurai(skill_num);
	else if(id==17)samurai(skill_num);
	else if(id==18)samurai(skill_num);
	else if(id==19)samurai(skill_num);
}

int cal_turn_meter(){
	while(true){
		for(int i=0;i<10;i++){
			if(pos[i].tm>100)pos[i].tm=100;
		}
		for(int i=0;i<10;i++){
			if(pos[i].tm==100&&pos[i].hp>0)return i;
		}
		for(int j=0;j<10;j++){
			if(pos[j].hp>0){
				pos[j].tm+=pos[j].current_stat.spd;
				if(pos[j].tm>100)pos[j].tm=100;
			}
		}
	}	
}
int start_turn(){
	char p='p';
	while(p=='p'){
		system("CLS");
	cout<<"Player "<<pos[turn].player<<"'s"<<pos[turn].name<<"\n"<<"HP : "<<pos[turn].hp<<"/"<<pos[turn].current_stat.max_hp<<"\n";
	if(pos[turn].player==1)cout<<"'q' ";
	else cout<<"'i' ";
	cout<<pos[turn].skill[0].name<<"\n"<<pos[turn].skill[0].des<<"\n";
	if(pos[turn].skill[1].cd==0&&!pos[turn].silenced){
		if(pos[turn].player==1)cout<<"'w' ";
		else cout<<"'o' ";
		cout<<pos[turn].skill[1].name<<"\n"<<pos[turn].skill[1].des<<"\n";
	}else if(pos[turn].skill[1].cd>0)cout<<pos[turn].skill[1].name<<" is on cooldown ("<<pos[turn].skill[1].cd")\n";
	else cout<<"Silenced!("<<pos[turn].silenced<<")\n";
	cout<<"'g' to view...";
	if(pos[turn].player==1){
		while(p!='g'&&p!='q'&&p!='w'){
			p=_getch();
		}
	}else{
		while(p!='g'&&p!='i'&&p!='o'){
			p=_getch();
		}
	}
	if(p=='g'){
		view_status();
		p=='p';
	}else if(p=='q'||p=='i')return 1;
	else if(pos[turn].skill[1].cd==0&&!pos[turn].silenced)return 2;
	p='p';
	}	
}
void view_status(){
	char key[10]={'r','t','y','f','g','h','c','v','b','n'};	
	int state=1;
	p='p';
	while(state==1){
		system("CLS");
	cout<<"Champions left for Player 1\n";
	for(int i=0;i<10;i++){
		if(pos[i].player==1&&pos[i].hp>0)cout<<"'"<<key[i]<<"' "<<pos[i].name<<" HP : "<<pos[i].hp<<"/"<<pos[i].current_stat.max_hp<<" turn meter : "<<pos[i].tm<<"/100"<<"\n";
	}
	cout<<"Champions left for Player 2\n";
	for(int i=0;i<10;i++){
		if(pos[i].player==2&&pos[i].hp>0)cout<<"'"<<key[i]<<"' "<<pos[i].name<<" HP : "<<pos[i].hp<<"/"<<pos[i].current_stat.max_hp<<" turn meter : "<<pos[i].tm<<"/100"<<"\n";
	}
	cout<<"'b' to back...";
	int view=11;
	while(view==11&&p!='b'){
		p=_getch();
		for(int i=0;i<10;i++){
			if(p==key[i]){
				view=i;
				state++;
				break;
			}else if(p=='b'){
				state=0;
				break;
			}
		}
	}
}
	if(p!='b'){
		system("CLS");
		cout<<"Player "<<pos[view].player<<"'s "<<pos[view].name<<" HP : "<<pos[view].hp<<"/"<<pos[view].current_stat.max_hp<<" turn meter : "<<pos[view].tm<<"/100\n";
		for(int i=0;i<pos[view].tag.size();i++){
			cout<<pos[view].tag[i]<<" ";
		}
		cout<<"\n";
		if(pos[view].hp_up>0)cout<<" Health Up("<<pos[view].hp_up<<")";
			if(pos[view].hp_down>0)cout<<" Health Down("<<pos[view].hp_down<<")";
			cout<<" Max HP:"<<pos[view].current_stat.max_hp<<"/"<<pos[view].base_stat.max_hp;
			if(pos[view].atk_up>0)cout<<" Attack Up("<<pos[view].atk_up<<")";
			if(pos[view].atk_down>0)cout<<" Attack Down("<<pos[view].atk_down<<")";
			cout<<" Attack:"<<pos[view].current_stat.atk<<"/"<<pos[view].base_stat.atk;
			if(pos[view].def_up>0)cout<<" Defense Up("<<pos[view].def_up<<")";
			if(pos[view].def_down>0)cout<<" Defense Down("<<pos[view].def_down<<")";
			cout<<" Defense:"<<pos[view].current_stat.def<<"/"<<pos[view].base_stat.def;
			if(pos[view].spd_up>0)cout<<" Speed Up("<<pos[view].spd_up<<")";
			if(pos[view].spd_down>0)cout<<" Speed Down("<<pos[view].spd_down<<")";
			cout<<" Speed:"<<pos[view].current_stat.spd<<"/"<<pos[view].base_stat.spd;
			if(pos[view].block)cout<<" Block";
			if(pos[view].evade)cout<<" Evade";
			if(pos[view].blind)cout<<" Blind";
			if(pos[view].stun)cout<<" Stun";
			if(pos[view].silenced>0)cout<<" Silenced("<<pos[view].silenced<<")";
			if(pos[view].heal_block>0)cout<<" Heal Blocked("<<pos[view].heal_block<<")";
			if(pos[view].knock>0)cout<<" Knocked("<<pos[view].knock<<")";
			if(pos[view].stealth>0)cout<<" Stealth("<<pos[view].stealth<<")";
			if(pos[view].protect>0)cout<<" Protect("<<pos[view].protect<<")";
			if(pos[view].bleed.size()>0)cout<<" Bleed x"<<pos[view].bleed.size();
			if(pos[view].regeneration.size()>0)cout<<" Regeneration x"<<pos[view].regeneration.size();
		cout<<"'b' to go back...";
		while(p!='b'){
			p=_getch();
		}
		state--;
}
}
void view_status(){
	char key[10]={'r','t','y','f','g','h','c','v','b','n'};
	p='p';
	int state=1;
	while(state>=1){
		system("CLS");
	cout<<"Champions left for Player 1\n";
	for(int i=0;i<10;i++){
		if(pos[i].hp>0&&pos[i].player==1){
			cout<<"'"<<key[i]<<"' "<<pos[i].name<<"HP : "<<pos[i].counter_chance<<"/"<<pos[i].stat[0][1]<<" turn meter : "<<pos[i].tm<<"/100\n";
		}
	}
	cout<<"Champions left for Player 2\n";
	for(int i=0;i<10;i++){
		if(pos[i].hp>0&&pos[i].player==2){
			cout<<"'"<<key[i]<<"' "<<pos[i].name<<"HP : "<<pos[i].hp<<"/"<<pos[i].stat[0][1]<<" turn meter : "<<pos[i].tm<<"/100\n";
		}
	}
	cout<<"'b' to go back...";
	int view=11;
	while(view==11&&p!='b'){
		p=_getch();
		for(int i=0;i<10;i++){
			if(p==key[i]){
				view=i;
				state++;
				break;
			}else if(p=='b'){
				state=0;
				break;
			}
		}
	}
	if(p!='b'){
		system("CLS");
		cout<<"Player "<<pos[view].player<<"'s "<<pos[view].name<<" HP : "<<pos[view].hp<<"/"<<pos[view].stat[0][1]<<" turn meter : "<<pos[view].tm<<"/100\n";
		for(int i=0;i<9;i++){
			cout<<stat[i]<<" : "<<pos[view].stat[i][1]<<"/"<<pos[view].stat[i][0]<<"\n";
		}
		for(int i=0;i<pos[view].d_buff.size();i++){
			cout<<pos[view].d_buff[i].name;
			if(pos[view].d_buff[i].dur>0)cout<<"("<<pos[view].d_buff[i].dur<<"t)";
			if(!pos[view].d_buff[i].can_dispel)cout<<"(can't be removed)";
			cout<<":"<<pos[view].d_buff[i].des<<"\n";
		}
		cout<<"'b' to go back...";
		while(p!='b'){
			p=_getch();
		}
		state--;
	}
	}
	
}
void begin_turn(){
	update_stat();
	regeneration();
		bleed();
}
void endturn(){
	if(pos[turn].atk_down>0)pos[i].atk_down--;
	if(pos[turn].atk_up>0)pos[i].atk_up--;
	if(pos[turn].def_down>0)pos[turn].def_down--;
	if(pos[turn].def_up>0)pos[turn].def_up--;
	if(pos[turn].hp_down>0)pos[turn].hp_down--;
	if(pos[turn].hp_up>0)pos[turn].hp_up--;
	if(pos[turn].spd_down>0)pos[turn].spd_down--;
	if(pos[turn].spd_up>0)pos[turn].spd_up--;
	if(pos[turn].protect>0)pos[turn].protect--;
	if(pos[turn].stealth>0)pos[turn].stealth--;
	if(pos[turn].silenced>0)pos[turn].silenced--;
	if(pos[turn].heal_block>0)pos[turn].heal_block--;
	if(pos[turn].knock>0)pos[turn].knock--;
	update_stat();
	pos[turn].tm-=100;
	if(pos[turn].skill[1].cd>0)pos[turn].skill[1].cd--;
}
void viewstat(champion view){
	cout<<"HP : |";
   	for(int j=100;j<view.hp;j+=11){
   		cout<<"|";
   		if(j=155)j+=1;
	   }
	   cout<<" "<<view.hp<<"\n";
	cout<<"Attack : |";
	for(int j=10;j<view.atk;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.atk<<"\n";
	cout<<"Defense : |";
	for(int j=10;j<view.def;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.def<<"\n";
	cout<<"Speed : |";
	for(int j=10;j<view.spd;j+=1){
   		cout<<"|";
   		if(j=14)j+=1;
	   }
	   cout<<" "<<view.spd<<"\n";
}
void viewskill(champion x){
		cout<<"Basic : "<<x.skill[0].name<<"\n"<<x.skill[0].des<<"\nSpecial : "<<x.skill[1].name<<" (Cooldown:"<<x.skill[1].bcd<<")\n"<<x.skill[1].des;
}
void viewdraft(target view[]){
	char p='p';
	system("CLS");
	cout<<"Player 1's Champions...\n";
	for(int l=0;l<10;l++){
		if(view[l].id!=-1&&view[l].player==1){
			cout<<view[l].name<<"\n";
		}
	}
	cout<<"Player 2's Champions...\n";
	for(int l=0;l<10;l++){
		if(view[l].id!=-1&&view[l].player==2){
			cout<<view[l].name<<"\n";
		}
	}
	cout<<"'v' to go back";
	while(p!='v'){
		p=_getch();
	}
}
