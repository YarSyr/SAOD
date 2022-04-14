#include "iostream"
using namespace std;
const int n=10, col_razr=3; //Количество чисел и их разрядность
int velich_razr(int chislo,int razr) //Поиск значения конкретного разряда
{
    while(razr>1) //Уменьшаем число до нужного размера
    {
        chislo/=10;
        razr--;
    }
    return chislo%10; //Возвращаем конкретный разряд "razr" числа
}
 
void sort_razr(int dop_mas[n][n], int mas[n], int razr) //Функция для сортировки массива по разрядам
{
    int mas_col[n], i,j, temp=0;
    for(i=0; i<n; i++)
        mas_col[i]=0;
    for(i=0; i<n; i++)
    {
        int a=velich_razr(mas[i], razr);
        dop_mas[mas_col[a]][a]=mas[i];
        mas_col[a]++;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<mas_col[i]; j++)
        {
            mas[temp]=dop_mas[j][i];
            temp++;
        }
    }
}
 
int main()
{
    
    int razr, i;
    int mas[n]={623, 543, 120, 935, 423, 610, 732, 126, 784, 648};
    int dop_mas[n][n]; //Двумерный массив для хранения очередей
    for(razr=1; razr<4; razr++) //Поразрядно вызываем метод сортировки
        sort_razr(dop_mas, mas, razr); //Сортируем по каждому разряду
    for(i=0; i<n; i++) //Вывод отсортированного массива
        cout<<mas[i]<<endl;
    return 0;
}
