#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;
	
	

int main()
{
	setlocale(LC_ALL, "rus");
	cout<<"Введите строку для поиска"<<endl;
	string a; cin >> a; //строка для поиска
	char buff[5000]; // буфер для текста из файла
	ifstream file("text.txt"); // открыли файл для чтения
	while (!file.eof())//Цикл для считывания файла
	{
		file.getline(buff, sizeof(buff));
		cout << buff << endl;
	}
	int res = -1;
	int countS = 0;
	int countI = a.length();
	for(int x = 0; x<5000; x++){ //вычисляем длдинну строки в файле
		if(buff[x] != '\0'){
		 countS = x;
		} else {
			break;
		}
	}
	char str[countS];
	for(int x = 0; x<countS; x++){
		str[x] = buff[x]; //Заполняем конечный массив нужного размера
	}

	for(int x = 0; x<countS; x++){ //Выполняем прямой поиск в массиве
		int C = 0;
		if(str[x] == a[0]){
			res = x;
			for(int y = 1; y<countI;y++){
				if(str[x+y]==a[y]) C++;
			}
		}
	}
	if(res == -1) cout <<"Фрагмент не встречается "<< endl;
	else cout <<"Индекс начала фрагмента: "<< res << endl;
	return 0;
}
