#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define MAX_TREE_HT 256
using namespace std;
map<char, string> codes;
map<char, int> freq;
struct Node{
    char data;          		 // Один из символов ввода
    int freq;           		 // Частота персонажа
    Node* left, * right;		 // Левый и правый ребенок
    Node(char data, int freq){   //Конструктор структуры
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare{ //Структура для метода - компаратора
    bool operator()(Node* l, Node* r)  // Функция сравнения для очереди приоритетов
    {return (l->freq > r->freq);}
};
void PrintC(struct Node* root, string str){ //Метод для вывода кодов отдельных символов
    if (!root) return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    PrintC(root->left, str + "0");
    PrintC(root->right, str + "1");
}
void storeCodes(struct Node* root, string str){ //Хранение символов и значений в хэш-таблице
    if (root == NULL) return;
    if (root->data != '$')
        codes[root->data] = str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}
priority_queue<Node*, vector<Node*>, compare> Heap; //Приоритетная очередь STL для хранения дерева
void HuffmanCodes(int size){ //Метод для построения дерева Хаффмана и его дальнейшего сохранения
    struct Node* left, * right, * top;
    for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
        Heap.push(new Node(v->first, v->second));
    while (Heap.size() != 1){
        left = Heap.top();
        Heap.pop();
        right = Heap.top();
        Heap.pop();
        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        Heap.push(top);
    }
    storeCodes(Heap.top(), "");
}
void calcFreq(string str, int n){ //Сохранение карты частот символов из исходной строки
    for (int i = 0; i < str.size(); i++)
        freq[str[i]]++;
}
string decode_string(struct Node* root, string s){ //Функция преобразования кода хаффмана в текст
    string ans = "";
    struct Node* curr = root;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;
        if (curr->left == NULL and curr->right == NULL) //Если данный узел является конечным
        {
            ans += curr->data;
            curr = root;
        }
    }
    return ans + '\0';
}
int main(){
    setlocale(LC_ALL, "Rus"); //Установка языка  вывода консоли
    string str = "Syrych Yaroslav Igorevich" ; //Исходная строка согласно персонального варианта
    string codedString, decodedString; //Строковые переменные для кодированной и декодированной строк
    calcFreq(str, str.length()); //Вычислние частот символов в строке
    HuffmanCodes(str.length()); //Созданик кода хаффмана для строки
    cout << "Кодированные символы: \n";
    for (auto v = codes.begin(); v != codes.end(); v++) //Для всех символов в строке
        cout << v->first << ' ' << v->second << endl; //Вывод всех кодов символов в строке
    for (char i : str) //Для всех символов в строке
        codedString += codes[i]; //Заполнение строки кодированных символов в строковую переменную
    cout << "\nКодированная строка:\n" << codedString << endl;
    decodedString = decode_string(Heap.top(), codedString); //Вызов метода декодирования строки
    cout << "\nОбратное декодирование:\n" << decodedString << endl; //Вывод строки после обратного декодирования
    return 0;
}
