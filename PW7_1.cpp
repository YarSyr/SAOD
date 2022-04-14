#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


struct student //Структура отдельного узла(студента)
{
	int nomber = 0; //Номер зачётки
	int group = 0; //Номер группы
	short mark = 0; //Оценка
	struct student *past = NULL;
	struct student *prev = NULL;
	void out(){ //Метод выводла для отдельного студента
		cout<<"Группа: "<<group<<"	Оценка: "<<mark<<"	Номер: "<<nomber<<endl;
	}
	~student(){ //Диструтор
		student *past = NULL;
		student *prev = NULL;
	}
};
struct spisok //Структура для списка
{
	student *S; //Указатель для динамического массива студентов
	int size = 0; //Поле размера массива
	
	spisok(){ //Конструктор пустого списка
	S = new student[0];
	size = 0;
	}
	
	spisok(int size){ //Конструктор для заполнения списка
	S = new student[size];
	this->size = size;
		for(int i = 0; i<size;i++){
			if(i == 0){S[0].prev = NULL;S[0].past = NULL;} //Еслиэто первый элемент, не запоняем для него адреса
			else {S[i].prev = &S[i-1];S[i].past = NULL;} //Если элемент не первый, заполняем указатель у предыдущего элемента
			S[i].group = 10000+i;
			S[i].nomber = i;
			srand(time(0)+10*i); S[i].mark = 1 + rand() % 5;
		}	
	}
	void add(student TempS){ //Функция добавления студента в список в соответствии с вариантом
		int index = -1;
		for(int i = 0; i<size;i++){
			if(S[i].nomber == TempS.nomber){
				index = i;
				break;
			};
		};
		student T[size]; // Список - буфер большего размера
		for(int i = 0; i<size;i++){
			T[i] = S[i]; //Заполняем буфер
		}
		delete []S; //Удаляем старый массив
		S = new student[size+1]; //Создаём новый массив с нужным размером
		if (index != -1){ //Заполняем новый массив в требуемой форме, если элемент встречалсся
			for(int i = 0; i<index;i++){
				S[i] = T[i];
			}
			S[index] = TempS;
			for(int i = index; i<size;i++){
				S[i+1] = T[i];
			}
		} else { //Заполнение массива, если данный лемент ранее не встречался
			for(int i = 0; i<size;i++){
				if(T[i].nomber > TempS.nomber){
					index = i;
					break;
				};
			};
			for(int i = 0; i<index;i++){
					S[i] = T[i];
				}
				S[index] = TempS;
				for(int i = index; i<size;i++){
					S[i+1] = T[i];
				}
		}
		size++;	//Исправляем размер с учётом нового элемента
	};
	
	void rem(int Ngroup){ //Удаление студента по номеру групппы
		student T[size]; //Создаём временный буфер
		int counter = size;
		int s = 0;
		for(int i = 0; i<size;i++){ //Переносим в буфер все элементы кроме того, который необходимо удалить
			if(S[i].group == Ngroup){
				counter--;
			} else {
				T[s] = S[i];
				s++;
			}
		}
		delete [] S; size = counter; //Удаляем старый массив и меняем размер на корректный
		S = new student[size]; //Содаём по старому указателю новый массив с новым размером
		for(int i = 0; i<counter;i++){ //Запоняем основной массив из буфера
			S[i] = T[i];
		}
	}
	
	void out(bool derection){ // Функция вывода с выбором направления
		if(size == 0) {cout<<"Список пуст :("<<endl; return;}
		if(derection){ //Вывод списка в разных направлениях
			for(int i = size-1; i>=0;i--){ //Вывод списка с начала к концу
					cout<<"Группа: "<<S[i].group<<"	Оценка: "<<S[i].mark<<"	Номер: "<<S[i].nomber<<endl;
			}
		} else{
			for(int i = 0; i<size;i++){// Вывод списка с конца к началу
					cout<<"Группа: "<<S[i].group<<"	Оценка: "<<S[i].mark<<"	Номер: "<<S[i].nomber<<endl;
			}
		}	
	}
	
	student *Sfind(int N){ //Функция поиска студента по номеру зач. книжки
		for(int i = 0; i<size;i++){ //Перебираем весь списоа
			if(S[i].nomber == N) return &S[i]; //Если нашли нужный элемент, возвращаем на него указатель
		}
	return NULL; //Ессли не нашли, возвращаем NULL
	}
	
	spisok form(){ //Функция формирования нового списка, в соответствии с вариантом
		int num = 0;
		spisok temp(size);
		int countT = 0;
		for(int i = 0; i<size;i++){ //Ищем все двойки в исхдном массива
			if(S[i].mark == 2){
				temp.S[countT] = this->S[i]; //Переносим все узлы с оценкой 2 в новый массив
				countT++; //Считаем размер для нового массива
			}
		}
		for(int i = 0; i<size;i++){
			if(this->S[i].mark == 2){ //ещё  раз находим все узлы с оценкой 2
			this->rem(this->S[i].group); // Удаляем узлы, согласно варианта
			}
		}
		spisok res(countT); // Создаём список корректного размера
		for(int i = 0; i<countT;i++){ //Заполняем итоговый список из буфера
		res.S[i] = temp.S[i];
		}
		res.size = countT; //Находим итоговый размер списка
		return res; //Воврщаем новый требуемый список, согласно варианта
	}
};	




int main()
{
	setlocale(LC_ALL, "rus");
	spisok a(6);
	a.out(0);
	cout<<endl;
	a.out(1);
	cout<<endl;
	a.Sfind(1)->out();
	cout<<endl;
	student V;
	//a.rem(10003);
	a.out(0);
	cout<<endl;
	a.form().out(0);
	cout<<endl;
	a.out(0);
	cout<<endl;
	V.nomber = 2;
	a.add(V);
	a.out(0);
	
}

