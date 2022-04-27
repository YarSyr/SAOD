#include <iostream>
#include<ctype.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node //структура для узла дерева
{
	int element, height; //целочесиенные переменные для содержимого элемента и его уровня в дереве
	node *left, *right; //Указатели на левый и правый дочернпие элементы
};

 typedef struct node *nodeptr;

class bstree //Класс длоя самого дерева
{
	public:
		void insert(int,nodeptr &); //Объявляем метод для добавления элемента
		void del(int, nodeptr &); //Объявляем метод для удаления элемента
		int deletemin(nodeptr &); //Объявляем метод для удаления минимального элемента
		void find(int,nodeptr &); //Объявляем метод для поиска элемента по значению
		nodeptr findmin(nodeptr); //Объявляем метод для поиска узла с минимальным значнием
		nodeptr findmax(nodeptr); //Объявляем метод для нахождения узла с максимальным значением
		void makeempty(nodeptr &); //Объёявляем метод для опустошения дерева
		void copy(nodeptr &,nodeptr &); //Объёявляем метод для копирования из одного узла в другой
		nodeptr nodecopy(nodeptr &); //Объёявляем метод для копирования узла, возвращает ссылку на копируемый узел
		void preorder(nodeptr); //Объёявляем метод для прямого обхода дерева (вывовод содержимого)
		void inorder(nodeptr); //Объёявляем метод для центророванного обхода дерева (вывовод содержимого)
		void postorder(nodeptr); //Объёявляем метод для обратного обхода дерева (вывовод содержимого)
		int bsheight(nodeptr);  //Объёявляем метод для вывода высоты дерева
		nodeptr srl(nodeptr &);
		nodeptr drl(nodeptr &);
		nodeptr srr(nodeptr &);
		nodeptr drr(nodeptr &);
		int max(int,int); //Объявляем метод для поиска большего из двух чисел(промежуточный/внутренний/служебный метод)
};
// Inserting a node
void bstree::insert(int x,nodeptr &p)  //Реализация метода добавления узла в дерево
{
	if (p == NULL) //Если элемент пустой
	{
		p = new node; //Создаём элемент по указателю
		p->element = x; //Добавляем элементу значение
		p->left=NULL; //Заполняем поля
		p->right = NULL;
		p->height=0;
		if (p==NULL)
		{
			cout<<"Out of Space\n"<<endl; //Если не удалось создать элемент
		}
	}
	else //Если элемент изначально не был пуст
	{
		if (x<p->element) //Находим место в дереве для элемента
		{
			insert(x,p->left);
			if ((bsheight(p->left) - bsheight(p->right))==2)
			{
				if (x < p->left->element)
				{
					p=srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x>p->element) //Находим место в дереве для элемента
		{
			insert(x,p->right);
			if ((bsheight(p->right) - bsheight(p->left))==2)
			{
				if (x > p->right->element)
				{
					p=srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		else //Данный элемент уже есть в дереве
		{
			cout<<"Элемет существует\n"<<endl;
		}
}
int m,n,d;
m=bsheight(p->left);
n=bsheight(p->right);
d=max(m,n);
p->height = d + 1;
}

nodeptr bstree::findmin(nodeptr p) //Реализация метода для поиска узла с минимальным значением
{
	if (p==NULL)
	{
		cout<<"В дереве нет ни одного узла\n"<<endl; //Если поиск начат для пустого дерева
		return p;
	}
	else
	{
		while(p->left !=NULL) //Зная что минимальный узел будет в конце левой ветки, идём по ней до конца
		{
			p=p->left;
			//return p;
		}
		return p;
	}
}

nodeptr bstree::findmax(nodeptr p) //Реализация метода для поиска узла с максимальным значением
{
	if (p==NULL)
	{
		cout<<"В дереве нет ни одного узла\n"<<endl; //Если поиск начат для пустого дерева
		return p;
	}
	else
	{
		while(p->right !=NULL) //Зная что искомый узел будет в конце правой ветки, идём по ней до конца
		{
			p=p->right;
			//return p;
		}
		return p;
	}
}

void bstree::find(int x,nodeptr &p) //Реализация метода для поиска узла с конкретным значением
{
	if (p==NULL)
	{
		cout<<"Такого элемента нет\n"<<endl;
	}
	else
	{
		if (x < p->element) //Определяем направление поиска (лево или право)
		{
			find(x,p->left); //Рекурсивно продолжаем поиск в нужном направлении(левый узел)
		}
		else
		{
			if (x>p->element)
			{
				find(x,p->right); //Рекурсивно продолжаем поиск в нужном направлении(правый узел)
			}
			else
			{
				cout<<"Элемент, который вы искали есть в дереве!\n"<<endl;
			}
		}
	}
}

void bstree::copy(nodeptr &p,nodeptr &p1) //Реализация копирования узлов из одного в другой
{
	makeempty(p1);
	p1 = nodecopy(p);
}

void bstree::makeempty(nodeptr &p) //Метод для опустошения дерева от начального узла
{
	nodeptr d;
	if (p != NULL)
	{
		makeempty(p->left);  //Рекурсивнор удаляем все узлы слева
		makeempty(p->right); //Рекурсивнор удаляем все узлы справа
		d=p;
		free(d);
		p=NULL;
	}
}

nodeptr bstree::nodecopy(nodeptr &p) //Метод копирования, возвращает копию узла по его адресу
{
	nodeptr temp; //Создаём временный объект узла
	if (p==NULL)
	{
		return p;  //Если элемент пуст, возвращаем его без изменений
	}
	else
	{
		temp = new node; //Создаём по указателю временный узел 
		temp->element = p->element; //Заполняем временный узел
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp; //Возвращем заполненный временный узел
	}
}


void bstree::del(int x,nodeptr &p) //Реализация метода для удаления узла
{
	nodeptr d;
	if (p==NULL)
	{
		cout<<"Простите, но такого элемента нет\n"<<endl;
	}
	else if ( x < p->element)
	{
		del(x,p->left);
	}
	else if (x > p->element)
	{
		del(x,p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d=p;
		free(d);
		p=NULL;
		cout<<"Элемент удален\n"<<endl;
	}
	else if (p->left == NULL)
	{
		d=p;
		free(d);
		p=p->right;
		cout<<"Элемент удален\n"<<endl;
	}
	else if (p->right == NULL)
	{
		d=p;
		p=p->left;
		free(d);
		cout<<"Элемент удален\n"<<endl;
	}
	else
	{
		p->element = deletemin(p->right);
	}
}

int bstree::deletemin(nodeptr &p) //Удаление узла с минимальным значением
{
	int c;
	cout<<"Выбрано удаление минимального значения\n"<<endl;
	if (p->left == NULL)
	{
		c=p->element;
		p=p->right;
		return c;
	}
	else
	{
		c=deletemin(p->left);
		return c;
	}
}
void bstree::preorder(nodeptr p) //Реализация метода прямого обхода дерева (вывод)
{
	if (p!=NULL)
	{
		cout<<p->element<<"\t";
		preorder(p->left);
		preorder(p->right);
	}
}

void bstree::inorder(nodeptr p) //Реализация метода прямого центрированного обхода дерева (вывод)
{
	if (p!=NULL)
	{
		inorder(p->left);
		cout<<p->element<<"\t";
		inorder(p->right);
	}
}

void bstree::postorder(nodeptr p) //Реализация метода обратного обхода дерева (вывод)
{
	if (p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->element<<"\t";
	}
}

int bstree::max(int value1, int value2) //Служебный метод, возвращет большее из двух чисел
{
	return ((value1 > value2) ? value1 : value2);
}

int bstree::bsheight(nodeptr p) //Реализация метода вывода высоты дерева
{
	int t;
	if (p == NULL)
	{
		return -1; //Если дерево пусто
	}
	else
	{
		t = p->height; //Вывод высоты
		return t;
	}
}

nodeptr bstree:: srl(nodeptr &p1) //Служебная ункция добавления узлов слева
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left),p1->height) + 1;
	return p2;
}
nodeptr bstree:: srr(nodeptr &p1) //Служебная ункция добавления узлов справа
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(p1->height,bsheight(p2->right)) + 1;
	return p2;
}
nodeptr bstree:: drl(nodeptr &p1) //Служебная ункция добавления узлов слева
{
	p1->left=srr(p1->left);
	return srl(p1);
}
nodeptr bstree::drr(nodeptr &p1) //Служебная ункция добавления узлов справа
{
	p1->right = srl(p1->right);
	return srr(p1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	nodeptr root,root1,min,max;//,flag;
	int a,choice,findele,delele;
	char ch='y';
	bstree bst;
	root = NULL;
	root1=NULL;
	cout<<"\n\t\t\tИКБО-29-21\tСырых Я И"<<endl;
	cout<<"\n\t\t\t\tAVL Дерево"<<endl;
	cout<<"\t\t\t:::::::::::::::::::::::::::\n"<<endl;
	
	do
	{
		cout<<"\t\t:::::::::::::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::1 Вставить новый узел::::::::::::::"<<endl;
		cout<<"\t\t::::2 Найти минимальный элемент::::::::"<<endl;
		cout<<"\t\t::::3 Найти максимальный элемент:::::::"<<endl;
		cout<<"\t\t::::4 Поиск по значению::::::::::::::::"<<endl;
		cout<<"\t\t::::5 Удалить элемент::::::::::::::::::"<<endl;
		cout<<"\t\t::::6 Прямой обход дерева::::::::::::::"<<endl;
		cout<<"\t\t::::7 Центророванный обход дерева::::::"<<endl;
		cout<<"\t\t::::8 Обратный обход дерева::::::::::::"<<endl;
		cout<<"\t\t::::9 Показать высоту дерева:::::::::::"<<endl;
		cout<<"\t\t::::0 Выход::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t:::::::::::::::::::::::::::::::::::::::\n"<<endl;
		
		cout<<"\nВыберите нужное действие и нажмите Enter: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\n\t\tДобавление нового узла"<<endl;
				cout<<"\t\t:::::::::::::\n"<<endl;
				cout<<"Введите элемент: ";
				cin>>a;
				bst.insert(a,root);
				cout<<"\nНовый элемент добавлен успешно\n"<<endl;
				break;
			case 2:
				if (root !=NULL)
				{
					min=bst.findmin(root);
					cout<<"\nМинимальный элемент в дереве: "<<min->element<<endl;
				}
				break;
			case 3:
				if (root !=NULL)
				{
					max=bst.findmax(root);
					cout<<"\nМаксимальный элемент в дереве: "<<max->element<<endl;
				}
				break;
			case 4:
				cout<<"\nВведите искомый элемент: ";
				cin>>findele;
				if (root != NULL)
				{
					bst.find(findele,root);
				}
				break;
			case 5:
				cout<<"\nКакой узел удалять? : ";
				cin>>delele;
				bst.del(delele,root);
				bst.inorder(root);
				cout<<endl;
				break;
			case 6:
				cout<<"\n\t\tПрямой обход дерева"<<endl;
				bst.preorder(root);
				cout<<endl;
				break;
			case 7:
				cout<<"\n\t\tЦентророванный обход дерева"<<endl;
				bst.inorder(root);
				cout<<endl;
				break;
			case 8:
				cout<<"\n\t\tОбратный обход дерева"<<endl;
				bst.postorder(root);
				cout<<endl;
				break;
			case 9:
				cout<<"\n\t\tВЫСОТА\n"<<endl;
				cout<<"TДерево имеет высоту: "<<bst.bsheight(root)<<endl;
						
				break;
			case 0:
				cout<<"\n\tзавершение програмы\n"<<endl;
				break;
			default:
				cout<<"Выбор действия не верен\n"<<endl;
				break;
			
		}
		system("pause");
		system("cls");
	}while(choice != 0);
	return 0;
}

