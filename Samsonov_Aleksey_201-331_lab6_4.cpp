#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
	int n;
	int id;
	string answer;
	cin >> n;
	unordered_set<int> u;
	for (int i = 0; i < n; i++) {
		cin >> id >> answer;
		if (u.count(id) != 1) {
			u.insert(id);
			cout << "The answer is counted" << endl;
		}
		else {
			cout << "The answer isn't counted" << endl;
		}
	}

	return 0;
}
