#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
int counter = 0;

void int_massiv( long size, int* array)
{
   // определяем переменные 
   srand(time(0)); // инициализация генерации случайных чисел
   //генерируем целый случайный массив из n эелментов от 1 до 10
   for (long i = 0; i < size; i++)
     array[i] = 2 + rand() % 9;
     cout <<"Генерация массива завершена"<< endl;
}




	int search(int* x, long k, int key){
		int res;
		int temp[k+1];
		for(int i = 0; i<k; i++) temp[i] = x[i];
		temp[k] = key;
		for (int i = 0; i<k+1; i++){
			counter++;
			if(temp[i] == key) {
				res = i;
				break;
			}
		}
	return res;
	  }
	  
	  
	  
int main()
{
	setlocale(LC_ALL,"Russian"); //смена языка вывода в консооль
	long N = 200000; //Кол-во элементов
	int res, key;
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // прямое заполнение массива
	int a[N]; cout <<""<< endl;
	int_massiv(N, a); //передаём в функцию для заполнения
	unsigned long counter=0; //обявляем перменную счётчика операций
	int buff = 0; // для хранения перемещаемого значения
	// поиск с барьером
	cout<<"Введите ключ для поиска"<<endl;
	cin>>key;
	res = search(a,N,key);
	if(res == N) cout<<"Не неайдено"<<endl;
	else cout<<"Найдено под позицией:"<<res<<endl;

	cout << endl;
}
