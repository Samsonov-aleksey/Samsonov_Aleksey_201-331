#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string file_format(const string file_path_full) {
	int len = file_path_full.length();
	int i = len - 1;//konec stroki
	while (i >= 0 and file_path_full[i] != '.') {
		i--;
	}
	if (i == -1) {
		return "";
	}
	return file_path_full.substr(i + 1);
}
string file_name(const string file_path_full) {
	int len = file_path_full.length();//
	int i = 0;
	while (i < len and file_path_full[i] != '.') {//
		i++;
	}
	if (i == len + 1) {
		return "";
	}
	int j = i - 1;
	while (j >= 0 and file_path_full[j] != '\\') {//
		j--;
	}
	if (j == -1) {
		return "";
	}
	return file_path_full.substr(j + 1, i - j - 1);//	
}
string file_path(const string file_path_full) {
	int len = file_path_full.length();
	int i = len - 1;
	while (i >= 0 and file_path_full[i] != '\\') {
		i--;
	}
	if (i == -1) {
		return "";
	}
	return file_path_full.substr(0, i+1);
}
char file_disk(const string file_path_full)
{
	int len = file_path_full.length();
	int i = 0;
	while (i < len and file_path_full[i] != ':') {
		i++;
	}
	if (i == len + 1) {
		return ' ';
	}
	return file_path_full[i - 1];
}
bool file_rename(string* file_path_full, string new_name) {
	int len = (*file_path_full).length();
	int i = 0;
	while (i < len and (*file_path_full)[i] != '.') {
		i++;
	}
	if (i == len + 1) {
		return false;
	}
	int j = i - 1;
	while (j >= 0 and (*file_path_full)[j] != '\\') {
		j--;
	}
	if (j == -1)
	{
		return false;
	}
	*file_path_full = file_path_full->substr(0, j+1) + new_name;
}
bool file_copy(const string file_path_full) {
	ifstream input(file_path_full);
	if (not input.is_open())
		return false;
	string b(file_path_full);
	file_rename(&b, file_name(b) + "_copy."+file_format(b));
	ofstream output(b);
	char buffer[256];
	input.getline(buffer, 255);
	while (not input.eof()) {
		output << buffer << endl;
		input.getline(buffer, 255);
	}
	input.close();
	output.close();
	return true;
}
int main() {
	char comands[8][250] = { "file_format","file_name","file_path","file_disk","file_rename","file_copy" };
	int cmd=0;
	int cmds = 6;
	bool running = true;
	string a;
	string n;
	cout << "Enter name of file" << endl;
	cin >> a;
	while (running) {
		for (int i = 0; i < cmds; i++) {
			cout << i + 1 << ". " << comands[i] << endl;
		}
		cout << ">> ";
		cin >> cmd;
		cout << endl;
		switch (cmd) {
		case 1:
			cout << file_format(a) << endl;
			break;
		case 2:
			cout << file_name(a) << endl;
			break;
		case 3:
			cout << file_path(a) << endl;
			break;
		case 4:
			cout << file_disk(a) << endl;
			break;
		case 5:
			cout << "Enter new name" << endl;
			cin >> n;
			file_rename(&a, n);
			cout << a << endl;
			break;
		case 6:
			file_copy("C:\\new\\abc.txt");
			break;
		default:
			running = false;
		}
	}
	
	
	

	return 0;
}
