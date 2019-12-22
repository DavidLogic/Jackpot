#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Start();
void GetResults();

int i, j, life, maxrand;
char c;


void Start() {
	i = 0;
	j = 0;
	life = 0;
	maxrand = 6;

	cout <<"       "<< "ѡ��һ�����Ѽ���:\n"; // �û�����ѡ��һ�����Ѽ���
	cout <<"       "<< "1 : ѧͽ (0-15)   ����������=3��\n";
	cout <<"       "<< "2 : սʿ (0-30)   ����������=3��\n";
	cout <<"       "<< "3 : ���� (0-50)   ����������=5��\n";
	cout <<"       "<< "4 : ս��0-300�� ����������=7��\n";
	cout <<"       "<< "5 : ŷ�ʣ�0-1000������������=10������˵ŷ�ʵ�ʤ����ʽ�ܲ�ͬŶ����\n";
	cout <<"       "<< "6 : ��������˳���Ϸ\n";
	c = 30;
	cout<<"\n";
    cout<<"        "<<"�������������Ѽ���:"; 
	cin >> c;                   // read the user's choice 
	cout << "\n";

	switch (c) {
	case '1':
		maxrand = 15;life = 3;  // the random number will be between 0 and maxrand
		break;
	case '2':
		maxrand = 30;life = 3;
		break;
	case '3':
		maxrand = 50;life = 5;
		break;
	case '4':
			maxrand = 300;life = 7;
			break;
	case'5':
		maxrand = 1000;
		life = 10;
			break;
		default:
			exit(0);
			break;
	}

         // number of lifes of the player
	srand((unsigned)time(NULL)); // init Rand() function
	j = rand() % maxrand;  // j get a random value between 0 and maxrand

	GetResults();
}

void GetResults() {
	if (life <= 0) { // if player has no more life then he loses
		cout << "�ź���ͷ���������һ�� !\n\n";
		Start();
	}

	cout << "������һ������: \n";
	cin >> i;

	if ((i > maxrand) || (i < 0)) { // if the user number isn't correct, restart
		cout << "����: ���ֲ��� 0 �� " << maxrand<<"֮��"<<" "<<endl;
		GetResults();
	}

	if (i == j) {
		cout << "The Jackpot is yours!\n\n"; // the user found the secret number
		while(c=='5')
		{cout<<"!!!Jackpot!!!"; } 
	
		Start();
	}
	else if (i > j) {
		cout << "̫����\n";
		life = life - 1;
		cout << "����ʣ������: " << life << "\n\n";
		GetResults();
	}
	else if (i < j) {
		cout << "̫С��\n";
		life = life - 1;
		cout << "����ʣ������: " << life << "\n\n";
		GetResults();
	}
}

int main() {
	cout <<"                             "<< "** ������Jackpot������ **\n";
	cout <<"                                                        "<< "���ߣ�David Logic"   "����ʱ��:22/12/2019""�汾��v1.0""\n";
	cout <<"                                                        "<<"��Ŀ��ҳ��https://github.com/DavidLogic/Jackpot-Game"<<endl; 
	cout <<"                        "<< "��Ϸ�������ǵ�Ŀ���ǲ²�һ�����֡�\n";
	cout <<"                        "<< "Jackpot�������";
	cout << "��Ҫ�²����������С��\n\n";
	cout <<"                        "<< "׼��������\n";
	cout <<"                        "<< "ͷ�Է籩��ʼ������\n";
	cout <<"                        "<< "Let's win the Jackpot��\n";
		Start();
	return 0;
}


