#include<iostream>
#include<algorithm>
#include <queue>
#include <cstring>
using namespace std;
constexpr auto Max_size = 20;
int Best_choice[Max_size];// Оптимальное хранение раствора
int best = 0,weight = 0,Count = 0,sum_weight = 0,sum_value = 0;// Оптимальное значение, максимальная вместимость, количество предметов, общий вес предметов, общая стоимость предметов
struct Node { //Структура с информецией о каждом узле, а также связанная информация о рюкзаке
	int cp, rp;
	int rw;
	int id;
	int Choiced[Max_size];
	Node() { memset(Choiced, 0, sizeof(Choiced)); }// Вектор решения изначально равен нулю
	Node(int _cp, int _rp, int _rw, int _id) {// Конструктор, легко передавать параметры
		cp = _cp;
		rp = _rp;
		rw = _rw;
		id = _id;
	}
};
struct Goods { //Структура с данными о рюкзаке
	int weight;
	int value;
}goods[Max_size];
void bfs()
{
	int current = 0, current_cp = 0, current_rp = 0, current_rw = 0;
	queue<Node> q;// Создаем очередь
	q.push(Node(0, sum_value, weight, 1));// Отправляем начальный узел
	while (!q.empty())// Когда очередь не пуста
	{
		Node current_node, lchild, rchild;
		current_node = q.front();// Удаляем элемент головы
		q.pop();// Элемент головы гаснет
		current = current_node.id;//Номер предмета
		if (current > Count || current_node.rw == 0)// Когда последний элемент или когда не осталось места
		{
			if (current_node.cp >= best){
				for (int i = 1; i <= Count; i++)
					Best_choice[i] = current_node.Choiced[i];
				best = current_node.cp;
			}
			continue;
		}
		if (current_node.cp + current_node.rp < best)// Когда оптимальное значение не достигается
			continue;
		current_cp = current_node.cp;
		current_rp = current_node.rp - goods[current].value;
		current_rw = current_node.rw;// Оставшаяся емкость
		if (current_rw >= goods[current].weight)// Меньше чем вместимость рюкзака
		{
			lchild.rw = current_rw - goods[current].weight;
			lchild.cp = current_cp + goods[current].value;
			lchild = Node{ lchild.cp,current_rp,lchild.rw,current + 1 };
			for (int i = 1; i < current; i++)
				lchild.Choiced[i] = current_node.Choiced[i];
			lchild.Choiced[current] = 1;
			if (lchild.cp > best)// Обновление оптимального значения
				best = lchild.cp;
			q.push(lchild);// Левый ребенок присоединяется к очереди
		}
		if (current_cp + current_rp >= best)// Для выполнения условий
		{
			rchild = Node{ current_cp,current_rp,current_rw,current + 1 };
			for (int i = 1; i < current; i++)
				rchild.Choiced[i] = current_node.Choiced[i];
			rchild.Choiced[current] = 0;
			q.push(rchild);// Правыйый ребенок присоединяется к очереди
		}
	}
	return;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Пожалуйста, введите количество элементов:";
	cin >> Count;
	cout << "Укажите вместимость рюкзака:";
	cin >> weight;
	cout << "Пожалуйста, введите вес и стоимость каждого предмета (через пробел):" << endl;
	for (int i = 1; i <= Count; i++){
		cin >> goods[i].weight >> goods[i].value;
		sum_weight += goods[i].weight;
		sum_value += goods[i].value;
	}
	if (sum_weight <= weight) {
		best = sum_weight;
		cout << "Максимальное введенное значение:" << best << endl;
		cout << "Можно упаковать все предметы в рюкзак";
	}
	else {
		bfs();
		cout << "Максимальное введенное значение:" << best << endl;
		cout << "Возможные варианты:";
		for (int i = 1; i <= Count; i++)
			if (Best_choice[i] == 1)
				cout << i << " ";
	}
	cout << endl;
	return 0;
}
