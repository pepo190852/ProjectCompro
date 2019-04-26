#include "Champion.h"
//include more champion header
int next_champion(int i){
	//do{
		if(i==champions.size()-1)i=0;
		else i++;
	//}while(banned[i])
	return i;
}
int prev_champion(int i){
	//do{
		if(i==0)i=champions.size()-1;
		else i--;
	//}while(banned[i])
	return i;
}
/*void banning(int j){
	int i=champions.size()-1;
	if(j==0||j==4||j==8){
						for(int k=0;k<4;k++){
								while(p=='p'){
									system("CLS");
									if(k%2==0)centertext("Player 1's turn to BAN!!");
									else centertext("Player 2's turn to BAN!!");
									i=next_champion(i);
									view=upload(i);
   									centertext(view.name);
   									centertext(view.role);
   								cout<<"\n";
   	for(int j=0;j<view.tag.size();j++)cout<<view.tag[j]<<"     ";
   									cout<<"\n\n";
   									viewstat(view);
   									viewskill(view);
   									if(k%2==0){
   										cout<<"'d' to BAN!! 'w' to go up 's' to go down 'v' to view drafted 'b' to go back to main menu...";
   										while(p!='d'&&p!='w'&&p!='s'&&p!='b'&&p!='v'){
   											p=_getch();
					  				 	}
									   }else{
									   	cout<<"'k' to BAN!! 'o' to go up 'l' to go down 'v' to view drafted 'b' to go back to main menu...";
   										while(p!='k'&&p!='o'&&p!='l'&&p!='b'&&p!='v'){
   											p=_getch();
					  				 	}
									   }
									if(p=='w'||p=='o'){
										do{
											i=prev_champion(i);
										}while(picked[i])
	   										p='p';
	   									}
	  								else if(p=='s'||p=='l'){
	   									i=next_champion(i);
	   									p='p';
	 								  }else if(p=='v'){
	   									viewdraft(pos);
	   									p='p';
	 								  }else if(p=='d'||p=='k')banned[i]=true;
								}
								if(p=='b')break;
								p='p';
								if(j==8&&k==1)break;
							}
							if(p=='b'){
								p='a';
								break;
							}
						}
}*/
void viewdraft(position view[]){
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
champion upload(int i){
	return champions[i];
}
void use_skill(int id,int skill_num){
	if(id==0)spartan_skill(skill_num);
	else if(id==1)samurai_skill(skill_num);
	else if(id==2)berserker_skill(skill_num);
	else if(id==3)jaguar_skill(skill_num);
	else if(id==4)crusader_skill(skill_num);
	else if(id==5)khopesh_skill(skill_num);
	else if(id==6)legion_skill(skill_num);
	else if(id==7)ninja_skill(skill_num);
	else if(id==8)monk_skill(skill_num);
	else if(id==9)shaman_skill(skill_num);
	else if(id==10)priest_skill(skill_num);
	else if(id==11)impi_skill(skill_num);
	else if(id==12)prophet_skill(skill_num);
	else if(id==13)eagle_skill(skill_num);
	else if(id==14)puma_skill(skill_num);
	else if(id==15)gladiator_skill(skill_num);
	else if(id==16)hoplite_skill(skill_num);
	else if(id==17)hypaspist_skill(skill_num);
	else if(id==18)zande_skill(skill_num);
	else if(id==19)immortal_skill(skill_num);
	else if(id==20)ronin_skill(skill_num);
	else if(id==21)templar_skill(skill_num);
	else if(id==22)mongul_skill(skill_num);
	else if(id==23)nomad_skill(skill_num);
	else if(id==24)maori_skill(skill_num);
	else if(id==25)rajput_skill(skill_num);
	//else if(id==26)pictish_skill(skill_num);
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
void view_status(){
	char key[10]={'e','i','u','r','t','y','j','f','g','h'};
	p='p';
	int state=1;
	while(state>=1){
		system("CLS");
	cout<<"Champions left for Player 1\n";
	for(int i=0;i<10;i++){
		if(pos[i].hp>0&&pos[i].player==1){
			cout<<"'"<<key[i]<<"' "<<pos[i].name<<" HP : "<<pos[i].hp<<"/"<<pos[i].current_stat.max_hp<<" turn meter : "<<pos[i].tm<<"/100\n";
		}
	}
	cout<<"Champions left for Player 2\n";
	for(int i=0;i<10;i++){
		if(pos[i].hp>0&&pos[i].player==2){
			cout<<"'"<<key[i]<<"' "<<pos[i].name<<" HP : "<<pos[i].hp<<"/"<<pos[i].current_stat.max_hp<<" turn meter : "<<pos[i].tm<<"/100\n";
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
		cout<<"Player "<<pos[view].player<<"'s "<<pos[view].name<<" HP : "<<pos[view].hp<<"/"<<pos[view].current_stat.max_hp<<" turn meter : "<<pos[view].tm<<"/100\n";
		for(int i=0;i<pos[view].tag.size();i++){
			cout<<pos[view].tag[i]<<" ";
		}cout<<"\n";
			cout<<"Max Health : "<<pos[view].current_stat.max_hp<<"/"<<pos[view].base_stat.max_hp<<"\n";
			cout<<"Attack : "<<pos[view].current_stat.atk<<"/"<<pos[view].base_stat.atk<<"\n";
			cout<<"Defense : "<<pos[view].current_stat.def<<"/"<<pos[view].base_stat.def<<"\n";
			cout<<"Speed : "<<pos[view].current_stat.spd<<"/"<<pos[view].base_stat.spd<<"\n";
		cout<<"\n";
		if(pos[view].hp_up>0)cout<<" Health Up("<<pos[view].hp_up<<")";
			if(pos[view].hp_down>0)cout<<" Health Down("<<pos[view].hp_down<<")";
			if(pos[view].atk_up>0)cout<<" Attack Up("<<pos[view].atk_up<<")";
			if(pos[view].atk_down>0)cout<<" Attack Down("<<pos[view].atk_down<<")";
			if(pos[view].def_up>0)cout<<" Defense Up("<<pos[view].def_up<<")";
			if(pos[view].def_down>0)cout<<" Defense Down("<<pos[view].def_down<<")";
			if(pos[view].spd_up>0)cout<<" Speed Up("<<pos[view].spd_up<<")";
			if(pos[view].spd_down>0)cout<<" Speed Down("<<pos[view].spd_down<<")";
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
		cout<<"\n'b' to go back...";
		while(p!='b'){
			p=_getch();
		}
		state--;
		p='p';
	}
	}
}
int start_turn(){
	char p='p';
	while(p=='p'){
		system("CLS");
	cout<<"Player "<<pos[turn].player<<"'s "<<pos[turn].name<<"\n"<<"HP : "<<pos[turn].hp<<"/"<<pos[turn].current_stat.max_hp<<"\n";
	if(pos[turn].player==1)cout<<"'q' ";
	else cout<<"'i' ";
	cout<<pos[turn].skill[0].name<<"\n"<<pos[turn].skill[0].des<<"\n";
	if(pos[turn].skill[1].cd==0&&!pos[turn].silenced){
		if(pos[turn].player==1)cout<<"'w' ";
		else cout<<"'o' ";
		cout<<pos[turn].skill[1].name<<"\n"<<pos[turn].skill[1].des<<"\n";
	}else if(pos[turn].skill[1].cd>0)cout<<pos[turn].skill[1].name<<" is on cooldown ("<<pos[turn].skill[1].cd<<")\n";
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


void begin_turn(){
	update_stat();
	regeneration();
	bleed();
}
void endturn(){
	if(pos[turn].atk_down>0)pos[turn].atk_down--;
	if(pos[turn].atk_up>0)pos[turn].atk_up--;
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
	cout<<"MAX HP : "<<view.hp<<"\n";
	cout<<"ATTACK : "<<view.atk<<"\n";
	cout<<"DEFENSE : "<<view.def<<"\n";
	cout<<"SPEED : "<<view.spd<<"\n";
	/*cout<<"HP : |";
   	for(int o=100;o<view.hp;o+=11){
   		cout<<"|";
   		if(o=155)o+=1;
	   }
	   cout<<" "<<view.hp<<"\n";
	cout<<"Attack : |";
	for(int o=10;o<view.atk;o+=1){
   		cout<<"|";
   		if(o=14)o+=1;
	   }
	   cout<<" "<<view.atk<<"\n";
	cout<<"Defense : |";
	for(int o=10;o<view.def;o+=1){
   		cout<<"|";
   		if(o=14)o+=1;
	   }
	   cout<<" "<<view.def<<"\n";
	cout<<"Speed : |";
	for(int o=10;o<view.spd;o+=1){
   		cout<<"|";
   		if(o=14)o+=1;
	   }
	   cout<<" "<<view.spd<<"\n";*/
}
void viewskill(champion x){
		cout<<"Basic : "<<x.skill[0].name<<"\n"<<x.skill[0].des<<"\n\nSpecial : "<<x.skill[1].name<<" (Cooldown:"<<x.skill[1].bcd<<")\n"<<x.skill[1].des<<"\n\n";
}
int drafting(int player,bool picked1[],bool picked2[]){
	int i=0;
	champion view;
	while(p=='p'){
					system("CLS");
					if(player==1){
						while(picked1[i])i=next_champion(i);
					centertext("Player 1's turn to DRAFT!!!");	
					}
					else{
						while(picked2[i])i=next_champion(i);
						centertext("Player 2's turn to DRAFT!!!");
					} 
					view.tag.clear();
					view=upload(i);
					cout<<"Champion's ID : "<<view.id<<"\n";
   					centertext(view.name);
   					centertext(view.role);
   					cout<<"\n";
   	for(int j=0;j<view.tag.size();j++)cout<<view.tag[j]<<"     ";
   	cout<<"\n\n";
   					viewstat(view);
   					viewskill(view);
   					if(player==1){
   							cout<<"'d' to DRAFT!!! 'w' to go up 's' to go down 'v' to view drafted 'b' to go back to main menu...";
   							while(p!='d'&&p!='w'&&p!='s'&&p!='b'&&p!='v'){
   							p=_getch();
					   	}
					   	if(p=='w'){
					   		do{
					   			i=prev_champion(i);
							   }while(picked1[i]);
							   p='p';
						   }else if(p=='s'){
						   	do{
						   		i=next_champion(i);
							   }while(picked1[i]);
							   p='p';
						   }else if(p=='v'){
						   	viewdraft(pos);
						   	p='p';
						   }else if(p=='d'){
						   	picked1[i]=true;
						   	p='p';
						   	return i;
						   }
					   }else{
					   	cout<<"'k' to DRAFT!!! 'o' to go up 'l' to go down 'v' to view drafted 'b' to go back to main menu...";
   					while(p!='k'&&p!='o'&&p!='l'&&p!='b'&&p!='v'){
   						p=_getch();
					   }
					   if(p=='o'){
					   		do{
					   			i=prev_champion(i);
							   }while(picked2[i]);
							   p='p';
						   }else if(p=='l'){
						   	do{
						   		i=next_champion(i);
							   }while(picked2[i]);
							   p='p';
						   }else if(p=='v'){
						   	viewdraft(pos);
						   	p='p';
						   }else if(p=='k'){
						   	picked2[i]=true;
						   	p='p';
						   	return i;
						   }
					
}}return -1;}

