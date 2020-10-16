#include <iostream>
#include <cstdlib>
using namespace std;

void bubble_sort(int* data, int n) {
	int tmp;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (data[j] > data[j + 1]) {
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}

void counting_sort(char* data, int n) {
	int count_alphas[26] = { 0 };
	for (int i = 0; i < n; i++) {
		count_alphas[data[i] - 'a']++;
	}
	int pos = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < count_alphas[i]; j++) {
			data[pos++] = i + 'a';
		}
	}
}


int main() {
	system("chcp 1251>nul");
	char comands[3][20] = { "Bubble Sort", "Counting Sort", "Exit" };
	int cmds = 3;
	int cmd;
	const int n = 1000;
	int data_int[n];
	char str[n];
	int size;
	bool running = true;
	while (running) {
		for (int i = 0; i < cmds; i++) {
			cout << i + 1 << ". " << comands[i] << endl;
		}
		cout << ">> ";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cout << "Enter the size of array:" << endl;
			cout << ">> ";
			cin >> size;
			cout << "Enter elements of the array:" << endl << ">> ";
			for (int i = 0; i < size; i++) {
				cin >> data_int[i];
			}
			bubble_sort(data_int, size);
			for (int i = 0; i < size; i++) {
				cout << data_int[i] << " ";
			}
			cout << endl;
			break;
		case 2:
			cout << "Enter string:" << endl << ">> ";
			cin >> str;
			counting_sort(str, size);
			cout << str << endl;
			break;
		case 3:
		default:
			running = false;
			break;
		}
	}

	cout << "Terminated" << endl;
	system("pause>nul");
}