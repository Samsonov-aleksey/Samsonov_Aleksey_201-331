#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
private:
	int rows, columns;
	double* data;
public:
	Matrix(int rows_, int columns_, const double* arr = nullptr) : rows(rows_), columns(columns_) {
		data = new double[rows*columns];
			for (int i = 0; i < rows*columns; i++) {
				data[i] = arr[i];
			}
		}
	}

	~Matrix() {
		delete[] data;
	}

	Matrix* sum(const Matrix* m) {
		if (rows != m->rows or columns != m->columns) {
			return nullptr;
		}
		Matrix* result = new Matrix(rows, columns);
		for (int i = 0; i < rows*columns; i++) {
				result->data[i] = data[i] + m->data[i];
		}
		return result;
	}

	Matrix* mult(const Matrix* m) {
		if (columns != m->rows) {
			return nullptr;
		}
		Matrix* result = new Matrix(rows, m->columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < m->columns; j++) {
				result->data[i*columns + j] = 0;
				for (int k = 0; k < columns; k++) {
					result->data[i*columns + j] += data[i*columns + k] * m->data[k*columns + j];
				}
			}
		}
		return result;
	}

	void input(int rows_, int columns_) {
		rows = rows_;
		columns = columns_;
		delete[] data;
		data = new double[rows*columns];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << "data[" << i << "][" << j << "]: ";
				cin >> data[i*columns + j];
			}
		}
	}

	void input(int rows_, int columns_, const double* arr) {
		rows = rows_;
		columns = columns_;
		delete[] data;
		data = new double[rows*columns];
		for (int i = 0; i < rows*columns; i++) {
			data[i] = arr[i];
		}
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << setw(7) << fixed << setprecision(1) << data[i*columns + j];
			}
			cout << endl;
		}
	}

	int get_columns() {
		return columns;
	}

	int get_rows() {
		return rows;
	}

	double get_elem(int i, int j) {
		return data[i*columns + j];
	}
};

int main() {
	Matrix* matrix = nullptr;
	char comands[6][250] = {"Create Matrix", "Create Matrix by array", "Print Matrix", "Sum Matrix", "Multiply Matrix", "Exit" };
	Matrix* tmp, *result;
	int rows, columns;
	int cmd = 0;
	int cmds = 6;
	bool running = true;
	double* arr = nullptr;
	while (running) {
		for (int i = 0; i < cmds; i++) {
			cout << i + 1 << ". " << comands[i] << endl;
		}
		cout << ">> ";
		cin >> cmd;
		cout << endl;
		if (cmd != 1 and cmd != 6 and matrix == nullptr) {
			cout << "Matrix doesn't exist" << endl;
			continue;
		}
		switch (cmd) {
		case 1:
			cout << "Entering the Matrix: " << endl;
			cout << "Enter the size of Matrix." << endl;
			cout << "Rows    >> ";
			cin >> rows;
			cout << "Columns >> ";
			cin >> columns;
			if (matrix != nullptr) {
				delete matrix;
			}
			matrix = new Matrix(rows, columns);

			cout << "Enter elements of the Matrix:" << endl;
			matrix->input(rows, columns);
			cout << "Successfully entered!" << endl;
			break;
		case 2:
			cout << "Entering the Matrix: " << endl;
			cout << "Enter the size of Matrix." << endl;
			cout << "Rows    >> ";
			cin >> rows;
			cout << "Columns >> ";
			cin >> columns;
			if (matrix != nullptr) {
				delete matrix;
			}
			arr = new double[rows*columns];
			cout << "Entering the array: " << endl;
			for (int i = 0; i < rows*columns; i++) {
				cout << "arr[" << i << "]: ";
				cin >> arr[i];
			}
			matrix = new Matrix(rows, columns);
			matrix->input(rows, columns, arr);
			delete[] arr;
			cout << "Successfully entered!" << endl;
			break;
		case 3:
			cout << "Printing the Matrix: " << endl;
			matrix->print();
			cout << "Successfully printed!" << endl;
			break;
		case 4:
			cout << "Sum of Matrixes: " << endl;
			cout << "Entering the Matrix: " << endl;
			cout << "Enter the size of Matrix." << endl;
			cout << "Rows    >> ";
			cin >> rows;
			cout << "Columns >> ";
			cin >> columns;
			tmp = new Matrix(rows, columns);

			cout << "Enter elements of the Matrix:" << endl;
			tmp->input(rows, columns);
		    result = matrix->sum(tmp);
			if (result == nullptr) {
				cout << "Matrixes cannot be sum" << endl;
			}
			else {
				cout << "Result:" << endl;
				result->print();
				delete result;
			}
			delete tmp;
			cout << "Successfully calculated!" << endl;

			break;
		case 5:
			cout << "Multiply of Matrixes: " << endl;
			cout << "Entering the Matrix: " << endl;
			cout << "Enter the size of Matrix." << endl;
			cout << "Rows    >> ";
			cin >> rows;
			cout << "Columns >> ";
			cin >> columns;
			tmp = new Matrix(rows, columns);

			cout << "Enter elements of the Matrix:" << endl;
			tmp->input(rows, columns);
			result = matrix->mult(tmp);
			if (result == nullptr) {
				cout << "Matrixes cannot be multiplied" << endl;
			}
			else {
				cout << "Result:" << endl;
				result->print();
				delete result;
			}
			delete tmp;
			cout << "Successfully calculated!" << endl;

			break;
		default:
			running = false;
			if (matrix != nullptr) {
				delete matrix;
			}
			break;
		}
		cout << endl;
	}

	cout << "Terminated" << endl;
	system("pause>nul");

	return 0;
}
