
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

void int_massiv( long size, int* array)
{
   // ���������� ���������� 
   srand(time(0)); // ������������� ��������� ��������� �����
   //���������� ����� ��������� ������ �� n ��������� �� 1 �� 10
   for (long i = 0; i < size; i++)
     array[i] = 1 + rand() % 9;
     cout <<"��������� ������� ���������"<< endl;
}

int main()
{
	setlocale(LC_ALL,"Russian"); //����� ����� ������ � ��������
	long N = 500000; //���-�� ���������
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // ������ ���������� �������
	int a[N]; cout <<""<< endl;
	int_massiv(N, a); //������� � ������� ��� ����������
	unsigned long counter=0; //�������� ��������� �������� ��������
	int buff = 0; // ��� �������� ������������� ��������
	DWORD time1 = ::GetTickCount(); //���������� � ���������� ����� ������ ����������
	// ���������� ���������� �����
	int i, j, step;
    int tmp;
    for (step = N / 2; step > 0; step /= 2)
        for (i = step; i < N; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
	//����� �����������
	DWORD time2 = ::GetTickCount() - time1; //���������� � ���������� ����� ����� ����������
	//for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // ����� ���������������� �������
	cout << endl;
	cout<<"����� ��������� ��������� ����������(��� ������� �� �����) �����: "<<time2<<"��"<<endl<<"����� �������� ��������� � �����������:"<<counter*2-N<<endl;
}
