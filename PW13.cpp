#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node //Структура узла графа
{
	int start; //Поле значения для первой вершины
	int end; //Поле значения второй вершины
	int length; //Поле значения ребра графа
}; 
vector<Node> mini; //Вектор для минимального остовного дерева
bool compare(Node a, Node b) //Метод - компаратор, нужна для работы алгоритма сортировки
{
	return a.length < b.length; //Возвращает результат сранения длин рёбер
}
void Kruskal(vector<Node> &arr, vector<bool> &visited) //Метод  для построения минимального остовного дерева и нахождения его веса
{
	int M, N; //переменные количества вершин и рёбер
	M = visited.size(); //Заполнение переменных из размеров векторов
	N = arr.size(); //Заполнение переменных из размеров векторов
	for (int i = 0; i < N; i++)  //Вод с клавиатуры каждого ребора
	{
		cin >> arr[i].start >> arr[i].end >> arr[i].length;  //Ввёд рёбер
	}
	sort(arr.begin(), arr.end(), compare);  //Сортировка рёбер по длинне
	int weight = 0;  //Переменная для итогового минимального веса
	for (int i = 0; i < N; i++)   //Для всех рёбер
	{
		if (!visited[arr[i].start] || !visited[arr[i].end])  //Проверяем, обходили ли мы уже данное ребро
		{
			weight += arr[i].length;  //Увеличиваем вес итогового минимального остовного дерева
			mini.push_back (arr[i]);  //Добавляем ребро в вектор с итоговым древом
			visited[arr[i].start] = true;  //Отмечаем вершины как задействованные
			visited[arr[i].end] = true; //Отмечаем вершины как задействованные
		}
	}
	 cout << "Минимальный вес связующего дерева:";
	cout << weight << endl;// Выводим минимальынй вес
}
int main()
{
	setlocale(LC_ALL, "Russian"); //Установка языка
	int M; //Переменная количества рёбер
	cin>>M; //Ввод с клавиатуры количества рёбер
	vector<Node> arr(M); //Вектор для всех рёбер
	vector<bool> visited(M); //Вектор для всех вершин
	Kruskal(arr,visited); //Вызываем метод для нахождения веса и дерева
	for (int i = 0; i < mini.size(); i++) //Для всех рёбер в минимальном остовном дереве
	{
		cout<<mini[i].start<<" "<<mini[i].end<<" "<<mini[i].length<<endl; //Вывод рёбер остовного ререва
	}
	return 0;
}
