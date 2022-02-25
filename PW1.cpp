#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;


void int_massiv( long size, int* array)
{
   // îïðåäåëÿåì ïåðåìåííûå 
   srand(time(0)); // èíèöèàëèçàöèÿ ãåíåðàöèè ñëó÷àéíûõ ÷èñåë
   //ãåíåðèðóåì öåëûé ñëó÷àéíûé ìàññèâ èç n ýåëìåíòîâ îò 1 äî 10
   for (long i = 0; i < size; i++)
     array[i] = 1 + rand() % 9;
     cout <<"Ãåíåðàöèÿ ìàññèâà çàâåðøåíà"<< endl;
}

int main()
{
	setlocale(LC_ALL,"Russian"); //ñìåíà ÿçûêà âûâîäà â êîíñîîëü
	long N = 500000; //Êîë-âî ýëåìåíòîâ
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // ïðÿìîå çàïîëíåíèå ìàññèâà
	int a[N]; cout <<""<< endl;
	int_massiv(N, a); //ïåðåäà¸ì â ôóíêöèþ äëÿ çàïîëíåíèÿ
	unsigned long counter=0; //îáÿâëÿåì ïåðìåííóþ ñ÷¸ò÷èêà îïåðàöèé
	int buff = 0; // äëÿ õðàíåíèÿ ïåðåìåùàåìîãî çíà÷åíèÿ
	DWORD time1 = ::GetTickCount(); //çàïèñûâàåì â ïåðåìåííóþ âðåìÿ íà÷àëà ñîðòèðîâêè
	// ñîðòèðîâêà ïðîñòûì âûáîðîì íà÷àëî
	int temp=0; 
	for (int i=1; i<=N ; i++)
		{
		for (int j=1; j<=N-i; j++) 
		{
	if (a [j]>a [j+1]) 
	{
	counter++;
	temp=a[j]; 
	a [j]=a [j+1];
	a [j+1]=temp;
	}}}
	//êîíåö ñîðòèðïîâêè
	DWORD time2 = ::GetTickCount() - time1; //çàïèñûâàåì â ïåðåìåííóþ âðåìÿ êîíöà ñîðòèðîâêè
//	for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // âûâîä îòñîðòèðîâàííîãî ìàññèâà
	cout << endl;
	cout<<"Èòîãî âðåìåííàÿ ñëîæíîñòü ñîðòèðîâêè(áåç âðåìåíè íà âûâîä) ðàâíà: "<<time2<<"ìñ"<<endl<<"Âñåãî îïåðàöèé ñðàâíåíèÿ è ïåðåìåùåíèÿ:"<<counter*2-N<<endl;
}
