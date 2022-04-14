#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


struct student //��������� ���������� ����(��������)
{
	int nomber = 0; //����� �������
	int group = 0; //����� ������
	short mark = 0; //������
	struct student *past = NULL;
	struct student *prev = NULL;
	void out(){ //����� ������� ��� ���������� ��������
		cout<<"������: "<<group<<"	������: "<<mark<<"	�����: "<<nomber<<endl;
	}
	~student(){ //���������
		student *past = NULL;
		student *prev = NULL;
	}
};
struct spisok //��������� ��� ������
{
	student *S; //��������� ��� ������������� ������� ���������
	int size = 0; //���� ������� �������
	
	spisok(){ //����������� ������� ������
	S = new student[0];
	size = 0;
	}
	
	spisok(int size){ //����������� ��� ���������� ������
	S = new student[size];
	this->size = size;
		for(int i = 0; i<size;i++){
			if(i == 0){S[0].prev = NULL;S[0].past = NULL;} //������� ������ �������, �� �������� ��� ���� ������
			else {S[i].prev = &S[i-1];S[i].past = NULL;} //���� ������� �� ������, ��������� ��������� � ����������� ��������
			S[i].group = 10000+i;
			S[i].nomber = i;
			srand(time(0)+10*i); S[i].mark = 1 + rand() % 5;
		}	
	}
	void add(student TempS){ //������� ���������� �������� � ������ � ������������ � ���������
		int index = -1;
		for(int i = 0; i<size;i++){
			if(S[i].nomber == TempS.nomber){
				index = i;
				break;
			};
		};
		student T[size]; // ������ - ����� �������� �������
		for(int i = 0; i<size;i++){
			T[i] = S[i]; //��������� �����
		}
		delete []S; //������� ������ ������
		S = new student[size+1]; //������ ����� ������ � ������ ��������
		if (index != -1){ //��������� ����� ������ � ��������� �����, ���� ������� �����������
			for(int i = 0; i<index;i++){
				S[i] = T[i];
			}
			S[index] = TempS;
			for(int i = index; i<size;i++){
				S[i+1] = T[i];
			}
		} else { //���������� �������, ���� ������ ������ ����� �� ����������
			for(int i = 0; i<size;i++){
				if(T[i].nomber > TempS.nomber){
					index = i;
					break;
				};
			};
			for(int i = 0; i<index;i++){
					S[i] = T[i];
				}
				S[index] = TempS;
				for(int i = index; i<size;i++){
					S[i+1] = T[i];
				}
		}
		size++;	//���������� ������ � ������ ������ ��������
	};
	
	void rem(int Ngroup){ //�������� �������� �� ������ �������
		student T[size]; //������ ��������� �����
		int counter = size;
		int s = 0;
		for(int i = 0; i<size;i++){ //��������� � ����� ��� �������� ����� ����, ������� ���������� �������
			if(S[i].group == Ngroup){
				counter--;
			} else {
				T[s] = S[i];
				s++;
			}
		}
		delete [] S; size = counter; //������� ������ ������ � ������ ������ �� ����������
		S = new student[size]; //����� �� ������� ��������� ����� ������ � ����� ��������
		for(int i = 0; i<counter;i++){ //�������� �������� ������ �� ������
			S[i] = T[i];
		}
	}
	
	void out(bool derection){ // ������� ������ � ������� �����������
		if(size == 0) {cout<<"������ ���� :("<<endl; return;}
		if(derection){ //����� ������ � ������ ������������
			for(int i = size-1; i>=0;i--){ //����� ������ � ������ � �����
					cout<<"������: "<<S[i].group<<"	������: "<<S[i].mark<<"	�����: "<<S[i].nomber<<endl;
			}
		} else{
			for(int i = 0; i<size;i++){// ����� ������ � ����� � ������
					cout<<"������: "<<S[i].group<<"	������: "<<S[i].mark<<"	�����: "<<S[i].nomber<<endl;
			}
		}	
	}
	
	student *Sfind(int N){ //������� ������ �������� �� ������ ���. ������
		for(int i = 0; i<size;i++){ //���������� ���� ������
			if(S[i].nomber == N) return &S[i]; //���� ����� ������ �������, ���������� �� ���� ���������
		}
	return NULL; //����� �� �����, ���������� NULL
	}
	
	spisok form(){ //������� ������������ ������ ������, � ������������ � ���������
		int num = 0;
		spisok temp(size);
		int countT = 0;
		for(int i = 0; i<size;i++){ //���� ��� ������ � ������� �������
			if(S[i].mark == 2){
				temp.S[countT] = this->S[i]; //��������� ��� ���� � ������� 2 � ����� ������
				countT++; //������� ������ ��� ������ �������
			}
		}
		for(int i = 0; i<size;i++){
			if(this->S[i].mark == 2){ //���  ��� ������� ��� ���� � ������� 2
			this->rem(this->S[i].group); // ������� ����, �������� ��������
			}
		}
		spisok res(countT); // ������ ������ ����������� �������
		for(int i = 0; i<countT;i++){ //��������� �������� ������ �� ������
		res.S[i] = temp.S[i];
		}
		res.size = countT; //������� �������� ������ ������
		return res; //�������� ����� ��������� ������, �������� ��������
	}
};	




int main()
{
	setlocale(LC_ALL, "rus");
	spisok a(6);
	a.out(0);
	cout<<endl;
	a.out(1);
	cout<<endl;
	a.Sfind(1)->out();
	cout<<endl;
	student V;
	//a.rem(10003);
	a.out(0);
	cout<<endl;
	a.form().out(0);
	cout<<endl;
	a.out(0);
	cout<<endl;
	V.nomber = 2;
	a.add(V);
	a.out(0);
	
}

