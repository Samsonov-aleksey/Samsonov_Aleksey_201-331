#include <iostream>
#include <deque>

using namespace std;

struct Point {
	double x, y;
};
bool func(Point &A, Point &B, Point &C) {
	return ((B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x)>0);
}




int main() {
	deque<int> d;
	int min = 0;
	 int size;
	cin >> size;
	Point arr[100];
	for (int i = 0; i < size; i++) {
		cin >> arr[i].x>>arr[i].y;
	}
	for (int i = 1; i < size; i++) {
		if (arr[i].x < arr[min].x) {
			min = i;
		}
	}
	Point tmp;
	tmp =arr[min];
	arr[min] = arr[0];
	arr[0] = tmp;

	d.push_back(0);
	for (int i = 1; i < size; i++) {
		min = i;
		for (int j = i + 1;j < size; j++) {
			if (func(arr[0],arr[j],arr[min])){
				min = j;
			}
		}
		tmp = arr[min];
		arr[min] = arr[i];
		arr[i] = tmp;
	}
	d.push_back(1);
	for (int i = 2; i < size; i++) {
		if (d.size() == 1) {
			d.push_back(i);
		}
		else {
			while (d.size() > 1 and !func(arr[d[d.size() - 2]], arr[d[d.size() - 1]], arr[i])) {
				d.pop_back();
			}
			d.push_back(i);
		}
	}
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << arr[d[i]].x << "  " << arr[d[i]].y<<endl;
	}
	return 0;
}