#include <iostream>
#include <list>
#include <map>
using namespace std;
int main() {
	map<int, list<string>> m;
	int n;
	int number;
	string surname;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number >> surname;
		m[number].push_back(surname);
	}
	for (pair<int, list<string>> item : m) {// проходимся по каждому элементу словаря
		cout << item.first << ": ";
		for (string name : item.second) {
			cout << name << " ";
		}
		cout << endl;
	}


	return 0;
}