#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	vector<int> number1;
	vector<int> number2;
	vector<int> res;
	string I1("456456945699945654699954654654565499999546999999999999999994546456546456");
	string I2("567857856999578999567078090809999995678567876899998679999675999999");
	for(int i = 0; i<I1.size();i++){ //Преобразуем первую строку в первое число
		int temp = (int)(I1[i] -'0');
		number1.push_back(temp);
	}
	for(int i = 0; i<I2.size();i++){ //Преобразуем вторуюю строку во второе число
		int temp = (int)(I2[i] -'0');
		number2.push_back(temp);	
	}
	long size = 0;
	
	if(number1.size()>number2.size()){//Вычисляем размер наибольшего числа
		size = number1.size();
	}else{size = number2.size();}
	
	for(int i = size/2; i>=0;i--){ //Расширяем разрядную сетку нулями перед сравнением
		int temp = 0;
		res.push_back(temp);
	}
	
	for(int i = 0; i<I1.size();i++){ //Колпируем первое число в результирующее
		int temp = (int)(I1[i] -'0');
		res.push_back(temp);
	}
	for(int i = 0; i<I2.size();i++){ //Посимвольно складываем первое число со вторым
		int T1,T2;
		T1 = res[res.size()-i-1];
		T2 = I2[I2.size()-i-1];
		res[res.size()-1-i] = (int)T1+T2-'0';
	}
	for(int i = 0; i<res.size();i++){//Корректируем переполнение разрядов рузультата
		for(int j = 0; j<res.size();j++){
			if(res[j]>9){
				res[j] = res[j] -10;
				res[j-1]++;
			}
		}
	}
	int first = res.size();
	for(int i = 0; i<res.size();i++){//Убираем все не значащие нули
		if(res[i] !=0 ){
			first = i;
			break;
		}
	}
	for(int i = 0; i<I1.size();i++){ //Выводим первое число
		cout<<I1[i]<<" ";
	} cout<<endl;
	
	for(int i = 0; i<I2.size();i++){//Выводим второе число
		cout<<I2[i]<<" ";
	} cout<<endl;
	
	for(int i = first; i<res.size();i++){//Выводим результат
		cout<<res[i]<<" ";
	} cout<<endl;
	return 0;
}

