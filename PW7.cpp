#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;




struct spisok //��������� �������� ������
{
  int dat = 0; // ���� ������
  struct spisok *ptr = NULL; // ��������� �� ��������� �������
};



void fill_massiv( int size, spisok* array)
{
   // ���������� ���������� 
   //���������� ����� ��������� ������ �� n ��������� �� 1 �� 10
   for (int i = 0; i < size; i++){
     array[i].dat = 1 + rand() % 9; // �������� ������ ��������� ������
     if(i!=size-1 )array[i].ptr = &array[i+1]; //������� ��������� �� ��������� �������
     else array[i].ptr = NULL; //���� ��� ��������� ������� ��������� -> NULL
    }
}

int form(spisok* array1, int size1, spisok* array2, int size2){ // ������� ��� ����������� ������ ������
	spisok temp[1000]; //��������� �����
	int size = 0;
	for(int i=0; i<size1;i++){ //��� ������� �������� ������� ������� ����, ���������� �� �� �����
		bool t = 0;
		for(int j=0; j<size;j++){
			if(temp[j].dat == array1[i].dat){
				t = 1;
				break;
			}
		}
		if(!t){ //���� ������� �� �����������, �� ��������� ��� � ����� ������
			if(size==0){ //����������, ���� ������ ��� ����
				temp[0].ptr = NULL;
				temp[0].dat = array1[i].dat;
			}
     		else{ //����������, ���� ��� �� ������ ������� �������
				temp[size-1].ptr = &temp[size];
				temp[size].dat = array1[i].dat;
				temp[size].ptr = NULL;
			}
			size++; //������� ������ ��� ������ �������
			t = 0;
		}
	t = 0;
	}
	
	for(int i=0; i<size2;i++){ //���������� ��� ��� ������� ������, ��������� ��� �������� �������
		bool t = 0;
		for(int j=0; j<size;j++){
			if(temp[j].dat == array2[i].dat){
				t = 1;
				break;
			}
		}
		if(!t){
			if(size==0){ //��������� ���������� �������� ������� � ����� ������
				temp[0].ptr = NULL;
				temp[0].dat = array2[i].dat;
			}
     		else{
				temp[size-1].ptr = &temp[size];
				temp[size].dat = array2[i].dat;
				temp[size].ptr = NULL;
			}
			size++;
			t = 0;
		}
	t = 0;
	}
	
	

	cout << "��������� �������: "<<endl;
	for (int i = 0; i < size; i++){cout << temp[i].dat<< '\t';if(i!=0&&i%11==0){cout << endl;}} // ����� ������������� �������
	return size;
}
	

int main()
{
	setlocale(LC_ALL, "rus");
	spisok a[9],b[10]; //������ ��� ������
	int S1 = sizeof(a)/sizeof(a[0]); //������� ������ ������� ������
	int S2 = sizeof(b)/sizeof(b[0]); //����� ������ ������� ������
	srand(time(0)); fill_massiv(S1,a); //��������� ������� ���������� ����������
	srand(time(0)+1000); fill_massiv(S2,b); //����� ���������
	form(a,S1,b,S2); //��������� ����� ������, �������� ��������
	
	cout <<endl<< endl;
	
	for (int i = 0; i < S1; i++){cout << a[i].dat<< '\t';if(i!=0&&i%11==0){cout << endl;}} // ����� ������� 1
	cout << endl;
	for (int i = 0; i < S2; i++){cout << b[i].dat<< '\t';if(i!=0&&i%11==0){cout << endl;}} // ����� ������� 2
	return 0;
}

