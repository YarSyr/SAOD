#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int counter = 0;

void int_massiv( long size, int* array) //Заполнение массива рандомными числами
{
   // определяем переменные 
   srand(time(0)); // инициализация генерации случайных чисел
   //генерируем целый случайный массив из n эелментов от 1 до 10
   for (long i = 0; i < size; i++)
     array[i] = 2 + rand() % 9;
     cout <<"Генерация массива завершена"<< endl;
}

	int Search_Binary (int arr[], int left, int right, int key) //функция для бинарного поиска
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;
		
		if (key < arr[midd])       // если искомое меньше значения в ячейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > arr[midd])  // если искомое больше значения в ячейке
			left = midd + 1;	   // смещаем левую границу поиска
		else                       // иначе (значения равны)
			return midd;           // функция возвращает индекс ячейки
		if (left > right)          // если границы сомкнулись 
			return -1;
	}
}
	   
int main()
{
	setlocale(LC_ALL,"Russian"); //смена языка вывода в консооль
	long N = 20; //Кол-во элементов
	int res, key;
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // прямое заполнение массива
	int a[N]; 
	int_massiv(N, a); //передаём в функцию для заполнения
	//сортируем массив
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
	
	// Двоичный поиск
	cout<<"Введите ключ для поиска"<<endl;
	cin>>key;
	res = Search_Binary (a, 0, N, key);
	if(res == -1) cout<<"Не неайдено"<<endl;
	else cout<<"Найдено под позицией:"<<res<<endl;
	for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // вывод отсортированного массива
	cout << endl;
}
