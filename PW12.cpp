#include <vector>
#include <iostream>
#include <list>
#include <bits/stdc++.h> 
#include <fstream>
using namespace std;

struct element{ //Структура элемен та множества 
	int number; //Переменная номера читательского билета(согласно варианта)
	string name; //Имя владельца билета 
	string adres; //Адрес владельца билета
	element(){ //Конструктор, рандомно заполняющий поля структуры
		srand(time(0)+rand()); //Инициализация генератора рандомных чисел
		number = 1 + rand() % 99999; //Запонение номера
		name = "Name_" + to_string(number); //Заполнение поля имени
		adres = "Adr_" + to_string(number); //Заполнение поля адреса
	}	
};
class aboniment{ //Класс множества
	public:
	element M[10000]; //Массив элементов
	int max_move = 0; //Переменная максимального сдвига(нужна для поиска в нескольких дублирующихся элементах)
	aboniment(){ //Конструктор множества, делает множество изначально пустым
		for(int i=0; i<10000;i++){ //Для каждой ячейкит множества
			M[i].number = 0; //Удаление номера
			M[i].name = ""; //Удаление имени
			M[i].adres = ""; //Удаление адреса
		}
		max_move = 0;		
	}
	int hashFunc(int num){ //Метод создания хэш суммы из номера
		int hash;
		num = num/10;
		if(num%2){
			hash = num/2;
		} else {
			hash =  10000 - num/2;
		}
		return hash;
	}
	void add(element A){ //Метод добавления элемента к множеству
		int h = hashFunc(A.number); //Вычисление хэш суммы
		int place = 0; //Переменная для места в таблице
		if(M[h].name == ""){ //Поиск пустой ячейки в начале 
			M[h] = A; //Запись элемента в множество
		} else {
			for(int i=1; i<10000;i++){ //Поиск пустой ячейки
				if(h + i < 10000) {  //Поиск в ячейках ПОСЛЕ хэш номера
					if(M[h + i].name == ""){
						M[h+i] = A; //Запись элемента в множество
						max_move = i; //Заполним максимальное смещение при исправлении коллизии
						break;
					}
				} else {
					if(M[h + i].name == ""){ //Поиск в ячейках ДО хэш номера(с переносом из конца массива в начало)
						M[h+i-10000] = A; //Запись элемента в множество
						max_move = i; //Заполним максимальное смещение при исправлении коллизии
						break;
					}
				}								
			}	
		}
	}
	void list(){ //Метод для вывода элементов множества
		for(int i=0; i<10000;i++){ //Для всех ячеек в множества
			if(M[i].name != ""){ //Если ячейка НЕ пустая 
						cout<<"\tЭлемент: "<<i<<") "<<"\tНомер: "<<M[i].number<<"\tИмя: "<<M[i].name<<"\tАдрес: "<<M[i].adres<<endl;	//Выводим содержимое ячейки
					}			
		}		
	} 
	void rem(int num){ //Метод для удаления элемента по номеру
		int h = hashFunc(num); //Вычисляем хэш сумму по номеру элемента
				M[h].number = 0; M[h].name = ""; M[h].adres = ""; //Удаляем элемент испуользуя хэш сумму для прямого доступа
	}
	void find(int num){ //Мутод для поиска элемента множества по его номеру с использованием хэш суммы
		int h = hashFunc(num); //Вычисляем хэш сумму
				cout<<"\tЭлемент: "<<h<<") "<<"\tНомер: "<<M[h].number<<"\tИмя: "<<M[h].name<<"\tАдрес: "<<M[h].adres<<endl;	 //Удаляем элемент используя хэш сумму для прямого доступа ко множеству
	}
	
	void clean(){
		for(int i=0; i<10000;i++){ //Для каждой ячейкит множества
			M[i].number = 0; //Удаление номера
			M[i].name = ""; //Удаление имени
			M[i].adres = ""; //Удаление адреса
		}
		max_move = 0;	//Обнуление счётчика переносов
	}
};

int main()
{
	setlocale(LC_ALL, "Russian"); //Меняем язык вывода консоли
	aboniment N1; //Создаём объект множества для записи в текстовый файл
	element E1,E2,E3,E4,E5,E6; //Объявляем элементы, которые вставим в множество
	N1.add(E1); N1.add(E2); N1.add(E3); N1.add(E4); N1.add(E5); N1.add(E6);//Добавляем элементы во множество
	cout<<"Выведем изначальную структуру, далее запишем её в текстовый файл"<<endl<<"(Согласно варианта текстовый файл должен быть изначально, но мы и его на всякий случай создадим и заполним заново)"<<endl;
	N1.list(); //Выведем исходный список
	ofstream fout; //Создадим объект для записи списка в текстовый файл
	aboniment N2; //Создадим основное множество, с которым будем работать впоследствии
	element temp, temp2; //Временные переменные элемента множества
	ifstream fin; //объект потока для чтения из файла
	fout.open("TEXT.txt"); //Открываем текстовый файл для записи в него данных множества
	
	for(int i=0; i<10000;i++){ //Для всех ячеек в множества
			if(N1.M[i].name != ""){ //Если ячейка НЕ пустая 
						fout<<i<<" "<<N1.M[i].number<<" "<<N1.M[i].name<<" "<<N1.M[i].adres<<endl;	//Записываем все ячейки мноржества в текстовый файл
					}			
		}
	fout.close(); //Закрываем файл для записи
	
	int TC,TN; //Временные переменные для чтения из файла
	string TF, TA; //Временные переменные для чтения из файла
	fin.open("TEXT.txt"); //Открываем текстовый файл для чтения
	while(!fin.eof()){ //Пока не кончится файл считываем поэлементно множество
        fin >> TC >> temp.number >> temp.name >> temp.adres; //Считывание элементов множества из файла
		N2.add(temp); //Добавляем элементы в рабочее множество
    }
	N2.rem(temp.number); 
	fin.close(); //Заканчиваем чтение из файла
	cout<<"Далее прочитаем множество из текстового файла"<<endl;
	N2.list(); //Выводим прочтённое из файла множество
	cout<<"И преобразуем данные из текстового файла в двоичный"<<endl;
	remove( "BIN.dat" ); //Удалим бинарный файл, если он был ранее
	FILE *F; //Создаём указатель для работы с бинарным файлом
	F = fopen("BIN.dat", "ab+"); //Открываем бинарный файл для чтения и записи, если файла нет - создаём
	fwrite(&N1, sizeof(aboniment), 1, F); //Записываем в файл рабочее множество
	fclose(F); // закрываем файл 
	N2.clean(); //Очищаем рабочее множество
	F = fopen("BIN.dat", "ab+"); //Открываем бинарный файл
	cout<<"Теперь прочитаем двоичный файл"<<endl;
	fread(&N2, sizeof(aboniment), 1, F); //Считываем данные из бинарного файла в рабочее множество
	N2.list(); //Вывод считанного из файла множества
	fclose(F); // закрываем файл
	cout<<"Продемонстрируем работу с данными из бинарного файла"<<endl;
	cout<<"Удалим элемент множества"<<endl;
	N2.rem(E2.number); //Демонстрируем удаление из множества
	N2.list(); //Вывод множества после удаления элемента
	cout<<"Добавим элемент во множество"<<endl;
	element T; //Временный элемент для добавления во множество
	N2.add(T); //Демонстрируем добавления элемента во множество
	N2.list(); //Вывод множества после дополнения новым элементом
	cout<<"Выполним поиск элемента в множестве"<<endl;
	N2.find(E4.number); //Демонтрация поиска элементов м ножестве
	remove( "BIN.dat" ); //Удаляем старый бинарный файл
	F = fopen("BIN.dat", "ab+"); //Создаём и о ткрываем бинарный файл для чтения и записи
	fwrite(&N2, sizeof(aboniment), 1, F); //Записываем изменённую запись в бинарный файл
	N2.clean(); //Очищаем рабочее множество
	fclose(F); // закрываем файл
    return 0;
}
