#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int counter = 0;

void int_massiv( long size, int* array) //���������� ������� ���������� �������
{
   // ���������� ���������� 
   srand(time(0)); // ������������� ��������� ��������� �����
   //���������� ����� ��������� ������ �� n ��������� �� 1 �� 10
   for (long i = 0; i < size; i++)
     array[i] = 2 + rand() % 9;
     cout <<"��������� ������� ���������"<< endl;
}

	int Search_Binary (int arr[], int left, int right, int key) //������� ��� ��������� ������
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;
		
		if (key < arr[midd])       // ���� ������� ������ �������� � ������
			right = midd - 1;      // ������� ������ ������� ������
		else if (key > arr[midd])  // ���� ������� ������ �������� � ������
			left = midd + 1;	   // ������� ����� ������� ������
		else                       // ����� (�������� �����)
			return midd;           // ������� ���������� ������ ������
		if (left > right)          // ���� ������� ���������� 
			return -1;
	}
}
	   
int main()
{
	setlocale(LC_ALL,"Russian"); //����� ����� ������ � ��������
	long N = 20; //���-�� ���������
	int res, key;
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // ������ ���������� �������
	int a[N]; 
	int_massiv(N, a); //������� � ������� ��� ����������
	//��������� ������
	int temp=0; 
	for (int i=0; i<=N ; i++)
		{
		for (int j=0; j<=N-i; j++) 
		{
	if (a [j]>a [j+1]) 
	{
	counter++;
	temp=a[j]; 
	a [j]=a [j+1];
	a [j+1]=temp;
	}}}
	
	// �������� �����
	cout<<"������� ���� ��� ������"<<endl;
	cin>>key;
	res = Search_Binary (a, 0, N, key);
	if(res == -1) cout<<"�� ��������"<<endl;
	else cout<<"������� ��� ��������:"<<res<<endl;
	for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // ����� ���������������� �������
	cout << endl;
}
