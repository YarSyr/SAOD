#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;
	
	

int main()
{
	setlocale(LC_ALL, "rus");
	cout<<"������� ������ ��� ������"<<endl;
	string a; cin >> a; //������ ��� ������
	char buff[5000]; // ����� ��� ������ �� �����
	ifstream file("text.txt"); // ������� ���� ��� ������
	while (!file.eof())//���� ��� ���������� �����
	{
		file.getline(buff, sizeof(buff));
		cout << buff << endl;
	}
	int res = -1;
	int countS = 0;
	int countI = a.length();
	for(int x = 0; x<5000; x++){ //��������� ������� ������ � �����
		if(buff[x] != '\0'){
		 countS = x;
		} else {
			break;
		}
	}
	char str[countS];
	for(int x = 0; x<countS; x++){
		str[x] = buff[x]; //��������� �������� ������ ������� �������
	}

	for(int x = 0; x<countS; x++){ //��������� ������ ����� � �������
		int C = 0;
		if(str[x] == a[0]){
			res = x;
			for(int y = 1; y<countI;y++){
				if(str[x+y]==a[y]) C++;
			}
		}
	}
	if(res == -1) cout <<"�������� �� ����������� "<< endl;
	else cout <<"������ ������ ���������: "<< res << endl;
	return 0;
}
