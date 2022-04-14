#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;




struct spisok //структура элемента списка
{
  int dat = 0; // поле данных
  struct spisok *ptr = NULL; // указатель на следующий элемент
};



void fill_massiv( int size, spisok* array)
{
   // определяем переменные 
   //генерируем целый случайный массив из n эелментов от 1 до 10
   for (int i = 0; i < size; i++){
     array[i].dat = 1 + rand() % 9; // заполним массив рандомным числом
     if(i!=size-1 )array[i].ptr = &array[i+1]; //запоним указатель на следующий элемент
     else array[i].ptr = NULL; //если это последний элемент указатель -> NULL
    }
}

int form(spisok* array1, int size1, spisok* array2, int size2){ // функция для фрмирования нового списка
	spisok temp[1000]; //Временный буфер
	int size = 0;
	for(int i=0; i<size1;i++){ //Для каждого элемента первого массива ищем, встречался ли он ранее
		bool t = 0;
		for(int j=0; j<size;j++){
			if(temp[j].dat == array1[i].dat){
				t = 1;
				break;
			}
		}
		if(!t){ //Если элемент не встнречался, то добавлякм его в новый массив
			if(size==0){ //Добавление, если массив был пуст
				temp[0].ptr = NULL;
				temp[0].dat = array1[i].dat;
			}
     		else{ //Добавление, если это не первый элемент массива
				temp[size-1].ptr = &temp[size];
				temp[size].dat = array1[i].dat;
				temp[size].ptr = NULL;
			}
			size++; //Считаем размер для нового массива
			t = 0;
		}
	t = 0;
	}
	
	for(int i=0; i<size2;i++){ //Аналогично как для первого мссива, проверяем все элементы второго
		bool t = 0;
		for(int j=0; j<size;j++){
			if(temp[j].dat == array2[i].dat){
				t = 1;
				break;
			}
		}
		if(!t){
			if(size==0){ //Добавляем уникальные элементы массива в новый массив
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
	
	

	cout << "Результат слияния: "<<endl;
	for (int i = 0; i < size; i++){cout << temp[i].dat<< '\t';if(i!=0&&i%11==0){cout << endl;}} // вывод получившегося массива
	return size;
}
	

int main()
{
	setlocale(LC_ALL, "rus");
	spisok a[9],b[10]; //Создаём два списка
	int S1 = sizeof(a)/sizeof(a[0]); //Находим размер первого списка
	int S2 = sizeof(b)/sizeof(b[0]); //Также размер второго списка
	srand(time(0)); fill_massiv(S1,a); //Заполняем массивы рандомными значениями
	srand(time(0)+1000); fill_massiv(S2,b); //Также заполняем
	form(a,S1,b,S2); //Формируем новый массив, согласно варианта
	
	cout <<endl<< endl;
	
	for (int i = 0; i < S1; i++){cout << a[i].dat<< '\t';if(i!=0&&i%11==0){cout << endl;}} // вывод массива 1
	cout << endl;
	for (int i = 0; i < S2; i++){cout << b[i].dat<< '\t';if(i!=0&&i%11==0){cout << endl;}} // вывод массива 2
	return 0;
}

