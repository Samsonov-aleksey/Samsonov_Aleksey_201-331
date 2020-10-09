#include <iostream>
#include <stdlib.h>
using namespace std;

long double fakt(long double x) {
	long double s = 1;
	for (long double i = 1; i <= x; i++) {
		s *= i;
	}
	return s;
}
void zad1() {
	cout << "Введите n" << endl;
	int n, l = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << j;
		}
		cout << endl;
	}
}
void zad2() {
	long double x;
	cout << "Введите n" << endl;
	cin >> x;
	for (long double i = 0; i <= x; i++) {
		cout << fakt(x) / (fakt(x - i) * fakt(i));
		cout << " ";
	}
	cout << endl;

}
}
int main()
{
	system("chcp 1251>nul");
	int keys;
	while (true) {
		cout << "Что вы хотите выполнить?" << endl;
		cout << "1.Числовой треугольник" << endl;
		cout << "2.Биоминальые коэффициенты" << endl;
		cout << "3.Среднее арифметическое" << endl;
		cout << "4.Выход" << endl;
		cin >> keys;
		switch (keys)
		{
		case 1:
			zad1();
			break;
		case 2:
			zad2();
			break;
		case 3:
			zad3();
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}
	system("pause>nul");
}

