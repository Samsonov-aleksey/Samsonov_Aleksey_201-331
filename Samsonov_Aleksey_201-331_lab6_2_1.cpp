#include <iostream>
#include <deque>
using namespace std;
int main() {
	
	string a;
	cin >> a;
	deque<char> d;
	for (int i = 0; i < a.length(); i++) {
		d.push_back(a[i]);
	}
	while (not d.empty() and d.front() == d.back()) {
		d.pop_back();
		d.pop_front();
	}
	if (d.empty()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}