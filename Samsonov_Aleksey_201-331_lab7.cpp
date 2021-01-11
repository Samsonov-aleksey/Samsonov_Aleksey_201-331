#include <iostream>

using namespace std;
bool operator<(const pair<string, int> left, const pair<string, int> right) {/////////// струкртура пар два поля фёрст и секонд
	return left.first < right.first;
}
bool operator==(const pair<string, int> left, const pair<string, int> right) {/////////// струкртура пар два поля фёрст и секонд
	return left.first == right.first and left.second==right.second;
}
bool operator<=(const pair<string, int> left, const pair<string, int> right) {/////////// струкртура пар два поля фёрст и секонд
	return left < right or left==right;
}
//struct- тоже самое что class но все поля public
template <typename T>
void quick_sort(T* data, int n) {
	T pivot = data[0];
	int l = 0, r = n - 1;
	while (l < r) {
		while (l < r && data[r] >= pivot) {
			r--;
		}
		if (l != r) {
			data[l] = data[r];
			l++;
		}
		while (l < r && data[l] <= pivot) {
			l++;
		}
		if (l != r) {
			data[r] = data[l];
			r--;
		}
	}
	data[l] = pivot;
	if (0 < l) {
		quick_sort(data, l);
	}
	if (l < n - 1) {
		quick_sort(data + l + 1, n - l - 1);
	}
}



int main() {
	pair<string, int> arr[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	quick_sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		cout << arr[i].first << "   " << arr[i].second << endl;
	}
	return 0;
}