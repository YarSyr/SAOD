		
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <algorithm>  
using namespace std;
unsigned long counter=0; //�������� ��������� ��������� �������� ��������

void int_massiv( long size, int* array)
{
   // ���������� ���������� 
   srand(time(0)); // ������������� ��������� ��������� �����
   //���������� ����� ��������� ������ �� n ��������� �� 1 �� 10
   for (long i = 0; i < size; i++)
     array[i] = 1 + rand() % 9;
     cout <<"��������� ������� ���������"<< endl;
}



void Merge(int *A, int first, int last) { // �������� �������
  int middle, start, final, j;
  int *mas = new int[last+1];
  middle = (first + last) / 2;  //���������� �������� ��������
  start = first;                //������ ����� �����
  final = middle + 1;           //������ ������ �����
  for (j = first; j <= last; j++)  //��������� �� ������ �� �����
    if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
      mas[j] = A[start];
      start++;
    } else {
      mas[j] = A[final];
      final++;
    }
  for (j = first; j <= last; j++) //����������� ���������� � ������
    A[j] = mas[j];
  delete[] mas;
};
void MergeSort(int *A, int first, int last) { //����������� ������� ����������
  if (first < last) {
  	counter++;
    MergeSort(A, first, (first + last) / 2);  //���������� ����� �����
    MergeSort(A, (first + last) / 2 + 1, last);  //���������� ������ �����
    Merge(A, first, last);  //������� ���� ������
  }
}


int main()
{
	setlocale(LC_ALL,"Russian"); //����� ����� ������ � ��������
	long N = 1050; //���-�� ���������
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // ������ ���������� �������
	int a[N]; cout <<""<< endl;
	int_massiv(N, a); //������� � ������� ��� ����������
	DWORD time1 = ::GetTickCount(); //���������� � ���������� ����� ������ ����������
	MergeSort(a, 0, N); // ���������� ������� ��������
	DWORD time2 = ::GetTickCount() - time1; //���������� � ���������� ����� ����� ����������
	for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // ����� ���������������� �������
	cout << endl;
	cout<<"����� ��������� ��������� ����������(��� ������� �� �����) �����: "<<time2<<"��"<<endl<<"����� �������� ��������� � �����������:"<<counter*counter<<endl;
}
