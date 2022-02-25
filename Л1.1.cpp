#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;


void int_massiv( long size, int* array)
{
   // определ€ем переменные 
   srand(time(0)); // инициализаци€ генерации случайных чисел
   //генерируем целый случайный массив из n эелментов от 1 до 10
   for (long i = 0; i < size; i++)
     array[i] = 1 + rand() % 9;
     cout <<"√енераци€ массива завершена"<< endl;
}

int main()
{
	setlocale(LC_ALL,"Russian"); //смена €зыка вывода в консооль
	long N = 500000; // ол-во элементов
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // пр€мое заполнение массива
	int a[N]; cout <<""<< endl;
	int_massiv(N, a); //передаЄм в функцию дл€ заполнени€
	unsigned long counter=0; //об€вл€ем перменную счЄтчика операций
	int buff = 0; // дл€ хранени€ перемещаемого значени€
	DWORD time1 = ::GetTickCount(); //записываем в переменную врем€ начала сортировки
	// сортировка простым выбором начало
	int temp=0; 
	for (int i=1; i<=N ; i++)
		{
		for (int j=1; j<=N-i; j++) 
		{
	if (a [j]>a [j+1]) 
	{
	counter++;
	temp=a[j]; 
	a [j]=a [j+1];
	a [j+1]=temp;
	}}}
	//конец сортирповки
	DWORD time2 = ::GetTickCount() - time1; //записываем в переменную врем€ конца сортировки
//	for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // вывод отсортированного массива
	cout << endl;
	cout<<"»того временна€ сложность сортировки(без времени на вывод) равна: "<<time2<<"мс"<<endl<<"¬сего операций сравнени€ и перемещени€:"<<counter*2-N<<endl;
}
