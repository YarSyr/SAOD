		
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <algorithm>  
using namespace std;
unsigned long counter=0; //об€вл€ем глобально перменную счЄтчика операций

void int_massiv( long size, int* array)
{
   // определ€ем переменные 
   srand(time(0)); // инициализаци€ генерации случайных чисел
   //генерируем целый случайный массив из n эелментов от 1 до 10
   for (long i = 0; i < size; i++)
     array[i] = 1 + rand() % 9;
     cout <<"√енераци€ массива завершена"<< endl;
}



void Merge(int *A, int first, int last) { // фунекци€ сли€ни€
  int middle, start, final, j;
  int *mas = new int[last+1];
  middle = (first + last) / 2;  //вычисление среднего элемента
  start = first;                //начало левой части
  final = middle + 1;           //начало правой части
  for (j = first; j <= last; j++)  //выполн€ть от начала до конца
    if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
      mas[j] = A[start];
      start++;
    } else {
      mas[j] = A[final];
      final++;
    }
  for (j = first; j <= last; j++) //возвращение результата в список
    A[j] = mas[j];
  delete[] mas;
};
void MergeSort(int *A, int first, int last) { //рекурсивна€ функци€ сортировки
  if (first < last) {
  	counter++;
    MergeSort(A, first, (first + last) / 2);  //сортировка левой части
    MergeSort(A, (first + last) / 2 + 1, last);  //сортировка правой части
    Merge(A, first, last);  //сли€ние двух частей
  }
}


int main()
{
	setlocale(LC_ALL,"Russian"); //смена €зыка вывода в консооль
	long N = 1050; // ол-во элементов
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // пр€мое заполнение массива
	int a[N]; cout <<""<< endl;
	int_massiv(N, a); //передаЄм в функцию дл€ заполнени€
	DWORD time1 = ::GetTickCount(); //записываем в переменную врем€ начала сортировки
	MergeSort(a, 0, N); // сортировка простым сли€нием
	DWORD time2 = ::GetTickCount() - time1; //записываем в переменную врем€ конца сортировки
	for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // вывод отсортированного массива
	cout << endl;
	cout<<"»того временна€ сложность сортировки(без времени на вывод) равна: "<<time2<<"мс"<<endl<<"¬сего операций сравнени€ и перемещени€:"<<counter*counter<<endl;
}
