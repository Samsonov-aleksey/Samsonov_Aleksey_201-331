
#include <bitset>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	cout << "№1" << endl;
 cout << "SAMSONOV ALEKSEY DMITRIEVICH 201-331!"<<endl;
 cout << "№2" << endl;
 // Данные были взяты из лабораторной работы и переведены с помощью интернета.
 int minInt = 0b10000000000000000000000000000000;
	 int maxInt = 0b01111111111111111111111111111111;
	 cout << "min int=" << minInt << "max int=" << maxInt << "size of int=" << sizeof(minInt) << endl;
	 unsigned int minUint = 0b00000000000000000000000000000000;
	 unsigned int maxUint = 0b11111111111111111111111111111111;
	 cout << "min unsigned int = " << minUint << " max unsigned int = " << maxUint << " size of unsigned int = " << sizeof(minUint) << endl;
	 short mins = 0b1000000000000000;
	 short maxs = 0b0111111111111111;
	 cout << "min short = " << mins << " max short = " << maxs << " size of short = " << sizeof(mins) << endl;
	 unsigned short minus = 0b0000000000000000;
	 unsigned short maxus = 0b1111111111111111;
	 cout << "min unsigned short = " << minus << " max unsigned short = " << maxus << " size of unsigned short = " << sizeof(minus) << endl;
	 long minl = 0b10000000000000000000000000000000;
	 long maxl = 0b01111111111111111111111111111111;
	 cout << "min long = " << minl << ", max long = " << maxl << ", size of long = " << sizeof(minl) << endl;
	 long long minll = 0b1000000000000000000000000000000000000000000000000000000000000000;
	 long long maxll = 0b0111111111111111111111111111111111111111111111111111111111111111;
	 cout << "min long long = " << minll << ", max long long = " << maxll << ", size of long long = " << sizeof(minll) << endl;
	 float minf = 0b10000000000000000000000000000000;
	 float maxf = 0b01111111111111111111111111111111;
	 cout << "min float = " << minf << ", max float = " << maxf << ", size of float = " << sizeof(minf) << endl;
	 double mind = 0b1000000000000000000000000000000000000000000000000000000000000000;
	 double maxd = 0b0111111111111111111111111111111111111111111111111111111111111111;
	 cout << "min double = " << mind << ", max double = " << maxd << ", size of double = " << sizeof(mind) << endl;
	 char minc = 0b10000000;
	 char maxc = 0b01111111;
	 cout << "min char = " << minc << ", max char = " << maxc << ", size of char = " << sizeof(minc) << endl;
	 bool minb = 0b00000000;
	 bool maxb = 0b11111111;
	 cout << "min bool = " << minb << ", max bool = " << maxb << ", size of bool = " << sizeof(minb) << endl;
	 cout << "№3" << endl;
	 cout << "Введите число";
	 int num;
	 cin>>num;
	 cout <<"в бинарном виде" <<bitset<32>(num)<< endl;
	 cout << "в шестнадцатиричном виде" << hex << num << endl;
	 cout << "bool" << bool(num) << endl;
	 cout << "double" << double(num) << endl;
	 cout << "char" << char(num) << endl;
	 cout << "№4" << endl;
	 cout << "Введите коэфиценты a,b" << endl;
	 int a, b;
	 cin >> a >> b;
	 cout << "a*x=b" << a << "*x=" << b << endl;
	 cout << "x=" << b << "/" << a
	 cout <<"Ответ:"<<"x="<< double((b) / a )<< endl;
	 cout << "№5" << endl;
	 cout << "Введите координаты отрезка" << endl;
	 int n, k;
	 cin >> n >> k;
	 cout << "Середина отрезка находится в" << double((k + n) / 2;
	 system("pause>nul");
	 return 0;
}

