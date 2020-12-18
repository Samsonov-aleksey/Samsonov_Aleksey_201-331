#include <iostream>
#include <stack>
using namespace std;

int main() {
	string a;
	cin >>a;
	stack<char> s;
	for (int i = 0; i <a.length(); i++) {
		if (a[i] == '{' or a[i] == '(' or a[i] == '[') {
			s.push(a[i]);
		}
		else if ((a[i] == '}' and s.top() == '{') or (a[i] == ']' and s.top() == '[') or (a[i] == ')' and s.top() == '(')) {
			s.pop();
		}
	}
	if (s.empty()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}