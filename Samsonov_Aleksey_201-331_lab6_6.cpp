#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, int> m;
	int count = 0;
	string word;
	while (cin >> word and word != "!") {
		m[word]++;
		count++;
	}
	for (pair<string, int> item : m) {
		cout << item.first << ": " << double (item.second) / count *100 << endl;
	}

	return 0;
}