#include <iostream>

using namespace std;

const int hp=75,maxhp=100;

int main(){
	int per=0,hp=::hp,maxhp=::maxhp;
	while(true){
	cin >> per;
	maxhp=maxhp+(::maxhp*per)/100;
	hp=hp+(::hp*per)/100;
	cout << hp <<"/"<<maxhp<<endl;
	}
}
