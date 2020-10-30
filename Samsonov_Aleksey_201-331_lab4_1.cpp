 #include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

int my_strlen(const char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

bool isPalindrome(const char* str) {
	int len = my_strlen(str);
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

int find_substring1(const char * str_for_search_in, const char * substring, int start_position) {
	int len = my_strlen(str_for_search_in);
	int len_sub = my_strlen(substring);
	int i = start_position, j;
	while (i < len - len_sub + 1) {
		if (str_for_search_in[i] == substring[0]) {
			j = 0;
			while (j < len_sub and str_for_search_in[i + j] == substring[j]) {
				j++;
			}
			if (j == len_sub) {
				return i;
			}
		}
		i++;
	}
	return -1;
}

int* find_substring2(const char * str_for_search_in, const char * substring) {
	int len = my_strlen(str_for_search_in);
	int len_sub = my_strlen(substring);
	int* positions = new int[len + 1];
	int i = 0, j, pos = 0;
	while (i < len - len_sub + 1) {
		if (str_for_search_in[i] == substring[0]) {
			j = 0;
			while (j < len_sub and str_for_search_in[i + j] == substring[j]) {
				j++;
			}
			if (j == len_sub) {
				positions[pos++] = i;
			}
		}
		i++;
	}
	positions[pos] = -1;
	return positions;
}

void encrypt(char* str_for_encrypt, int key) {
	int len = my_strlen(str_for_encrypt);
	for (int i = 0; i < len; i++) {
		if ('a' <= str_for_encrypt[i] and str_for_encrypt[i] <= 'z') {
			str_for_encrypt[i] = 'a' + (str_for_encrypt[i] + key - 'a') % ('z' - 'a' + 1);
		} else if ('A' <= str_for_encrypt[i] and str_for_encrypt[i] <= 'Z') {
			str_for_encrypt[i] = 'A' + (str_for_encrypt[i] + key - 'A') % ('Z' - 'A' + 1);
		}
	}
}
int main() {
	srand(time(NULL));
	system("chcp 1251>nul");
	char comands[6][50] = {"Checking palindrome", "Substring search",
			"Substring search multiplicity", "Encryption", "Search of names", "Exit"};
	int cmds = 6;
	int cmd;
	char str[256], substr[256];
	int start, result, key;
	int* positions;
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
			cout << "Checking of palindrome" << endl;
			cout << "Enter the string:" << endl << ">> ";
			cin >> str;
			if (isPalindrome(str)) {
				cout << "It's palindrome" << endl;
			} else {
				cout << "It's not palindrome" << endl;
			}
			cout << "Successfully checked!"<< endl;
			break;
		case 2:
			cout << "Enter the string:" << endl << ">> ";
			cin.ignore(1);
			cin.getline(str, 255);
			cout << "Enter the substring:" << endl << ">> ";
			cin.getline(substr, 255);
			cout << "Enter the index of start position:" << endl << ">> ";
			cin >> start;
			result = find_substring1(str, substr, start);
			if (result == -1) {
				cout << "It's not been found" << endl;
			} else {
				cout << "It's been found on position " << result << endl;
			}
			cout << "Successfully searched!"<< endl;
			break;
		case 3:
			cout << "Enter the string:" << endl << ">> ";
			cin.ignore(1);
			cin.getline(str, 255);
			cout << "Enter the substring:" << endl << ">> ";
			cin.getline(substr, 255);
			positions = find_substring2(str, substr);
			if (positions[0] == -1) {
				cout << "It's not been found" << endl;
			} else {
				cout << "It's been found on positions: " << endl;
				for (int i = 0; positions[i] != -1; i++) {
					cout << positions[i] << " ";
				}
				delete[] positions;
				cout << endl;
			}
			cout << "Successfully searched!"<< endl;
			break;
		case 4:
			cout << "Encryption: " << endl;
			cout << "Enter the string:" << endl << ">> ";
			cin.ignore(1);
			cin.getline(str, 255);
			cout << "Enter the key of cipher:" << endl << ">> ";
			cin >> key;
			encrypt(str, key);
			cout << "Encrypted string: " << str << endl;
			cout << "Successfully encrypted!"<< endl;
			break;
		case 5:
			break;
		default:
			running = false;
			break;
		}
		cout << endl;
	}

	cout << "Terminated" << endl;
	system("pause>nul");
	return 0;
}

