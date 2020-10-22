#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>

using namespace std;

void print(int* data, int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(6) << data[i];
	}
	cout << endl;
}


void sorting_by_last_digit(int* data, int size) {
	int min, tmp;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (abs(data[j] % 10) < abs(data[min] % 10) or
				(abs(data[j] % 10) == abs(data[min] % 10) and data[j] > data[min])) {
				min = j;
			}
		}

		tmp = data[i];
		data[i] = data[min];
		data[min] = tmp;
	}
}

void enter_array(int& size, int* data) {
	cout << "Entering the array: " << endl;
	cout << "Enter the size of array." << endl;
	cin >> size;
	if (data != nullptr) {
		delete[] data;
	}
	data = new int[size];

	cout << "Enter elements of the array:" << endl << ">> " << endl;
	for (int i = 0; i < size; i++) {
		cout << "data[" << i << "]: ";
		cin >> data[i];
	}
}

int main() {
	srand(time(NULL));
	system("chcp 1251>nul");
	char comands[6][50] = { "Entering the array", "Fill by random values",
			"Printing", "Sorting by sum of numbers stating on even places",
			"Sorting by increase of last digit and by decrease", "Exit" };
	int cmds = 6;
	int cmd;
	int size;
	int* data = nullptr;
	bool running = true;
	while (running) {
		for (int i = 0; i < cmds; i++) {
			cout << i + 1 << ". " << comands[i] << endl;
		}
		cout << ">> ";
		cin >> cmd;
		cout << endl;
		switch (cmd) {
		case 1:
			enter_array(size, data);
			cout << "Successfully entered!" << endl;
			break;
		case 2:
			cout << "Generation the array: " << endl;
			cout << "Enter the size of array." << endl;
			cin >> size;

			if (data != nullptr) {
				delete[] data;
			}
			data = new int[size];

			for (int i = 0; i < size; i++) {
				data[i] = rand() % 2001 - 1000;
			}
			print(data, size);
			cout << "Successfully filled!" << endl;
			break;
		case 3:
			cout << "Printing the array: " << endl;
			print(data, size);
			cout << "Successfully printed!" << endl;
			break;
		case 4:
			break;
		case 5:
			cout << "Sorting: " << endl;
			sorting_by_last_digit(data, size);
			print(data, size);
			cout << "Successfully sorted!" << endl;
			break;
		default:
			running = false;
			if (data != nullptr) {
				delete[] data;
			}
			break;
		}
		cout << endl;
	}

	cout << "Terminated" << endl;
	system("pause>nul");
	return 0;
}
