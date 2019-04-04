#include<vector>
struct target{
	string name;
	vector<string> tag;
	int stat[9][2],hp;
	vector<string> buff;
	vector<string> buff_timer;
	vector<string> debuff;
	vector<string> debuff_timer;
	vector<skill> skill;
};
struct skill{
	string name,des;
	char type;
	int cd;
};
struct champion{
	string name;
	vector<string> tag;
	int hp,off,mdef,pdef,acc,eva,bc,ba,spd;
	vector<skill> skill;
};
