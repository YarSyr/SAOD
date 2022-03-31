		
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <algorithm>  
using namespace std;
unsigned long counter=0; //îáÿâëÿåì ãëîáàëüíî ïåðìåííóþ ñ÷¸ò÷èêà îïåðàöèé

void int_massiv( long size, int* array)
{
   // îïðåäåëÿåì ïåðåìåííûå 
   srand(time(0)); // èíèöèàëèçàöèÿ ãåíåðàöèè ñëó÷àéíûõ ÷èñåë
   //ãåíåðèðóåì öåëûé ñëó÷àéíûé ìàññèâ èç n ýåëìåíòîâ îò 1 äî 10
   for (long i = 0; i < size; i++)
     array[i] = 1 + rand() % 9;
     cout <<"Ãåíåðàöèÿ ìàññèâà çàâåðøåíà"<< endl;
}



void Merge(int *A, int first, int last) { // ôóíåêöèÿ ñëèÿíèÿ
  int middle, start, final, j;
  int *mas = new int[last+1];
  middle = (first + last) / 2;  //âû÷èñëåíèå ñðåäíåãî ýëåìåíòà
  start = first;                //íà÷àëî ëåâîé ÷àñòè
  final = middle + 1;           //íà÷àëî ïðàâîé ÷àñòè
  for (j = first; j <= last; j++)  //âûïîëíÿòü îò íà÷àëà äî êîíöà
    if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
      mas[j] = A[start];
      start++;
    } else {
      mas[j] = A[final];
      final++;
    }
  for (j = first; j <= last; j++) //âîçâðàùåíèå ðåçóëüòàòà â ñïèñîê
    A[j] = mas[j];
  delete[] mas;
};
void MergeSort(int *A, int first, int last) { //ðåêóðñèâíàÿ ôóíêöèÿ ñîðòèðîâêè
  if (first < last) {
  	counter++;
    MergeSort(A, first, (first + last) / 2);  //ñîðòèðîâêà ëåâîé ÷àñòè
    MergeSort(A, (first + last) / 2 + 1, last);  //ñîðòèðîâêà ïðàâîé ÷àñòè
    Merge(A, first, last);  //ñëèÿíèå äâóõ ÷àñòåé
  }
}


int main()
{
	setlocale(LC_ALL,"Russian"); //ñìåíà ÿçûêà âûâîäà â êîíñîîëü
	long N = 1050; //Êîë-âî ýëåìåíòîâ
	// int a[N] = { 99, 5, 3, 2, 45, 96, 6, 8, 11, 24, 55, 56, 15, 98, 1 }; // ïðÿìîå çàïîëíåíèå ìàññèâà
	int a[N]; cout <<""<< endl;
	int_massiv(N, a); //ïåðåäà¸ì â ôóíêöèþ äëÿ çàïîëíåíèÿ
	DWORD time1 = ::GetTickCount(); //çàïèñûâàåì â ïåðåìåííóþ âðåìÿ íà÷àëà ñîðòèðîâêè
	MergeSort(a, 0, N); // ñîðòèðîâêà ïðîñòûì ñëèÿíèåì
	DWORD time2 = ::GetTickCount() - time1; //çàïèñûâàåì â ïåðåìåííóþ âðåìÿ êîíöà ñîðòèðîâêè
	for (int i = 0; i < N; i++){cout << a[i] << '\t';if(i!=0&&i%11==0){cout << endl;}} // âûâîä îòñîðòèðîâàííîãî ìàññèâà
	cout << endl;
	cout<<"Èòîãî âðåìåííàÿ ñëîæíîñòü ñîðòèðîâêè(áåç âðåìåíè íà âûâîä) ðàâíà: "<<time2<<"ìñ"<<endl<<"Âñåãî îïåðàöèé ñðàâíåíèÿ è ïåðåìåùåíèÿ:"<<counter*counter<<endl;
}
