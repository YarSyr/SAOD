
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

void int_massiv( long size, int* array)
{
   // определяем переменные 
   srand(time(0)); // инициализация генерации случайных чисел
   //генерируем целый случайный массив из n эелментов от 1 до 10
   for (long i = 0; i < size; i++)
     array[i] = 1 + rand() % 9;
     cout <<"Генерация массива завершена"<< endl;
}

int main()
{
	setlocale(LC_ALL,"Russian"); //смена языка вывода в консооль
	long N = 500000; //Кол-во элементов
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // прямое заполнение массива
	int a[N]; cout <<""<< endl;
	int_massiv(N, a); //передаём в функцию для заполнения
	unsigned long counter=0; //обявляем перменную счётчика операций
	int buff = 0; // для хранения перемещаемого значения
	DWORD time1 = ::GetTickCount(); //записываем в переменную время начала сортировки
	// сортировка алгоритмом Шелла
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
	//конец сортирповки
	DWORD time2 = ::GetTickCount() - time1; //записываем в переменную время конца сортировки
	//for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // вывод отсортированного массива
	cout << endl;
	cout<<"Итого временная сложность сортировки(без времени на вывод) равна: "<<time2<<"мс"<<endl<<"Всего операций сравнения и перемещения:"<<counter*2-N<<endl;
}
