#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
private:
	int rows;
	double* main_diag, *top_diag, *bot_diag;
public:
	Matrix(int rows_) : rows(rows_) {
		main_diag = new double*[rows];
		top_diag = new double*[rows - 1];
		bot_diag = new double*[rows - 1];
	}

	~Matrix() {
		delete[] main_diag;
		delete[] top_diag;
		delete[] bot_diag;
	}

	Matrix operator+(const Matrix& m) {
		if (rows != m.rows) {
			return Matrix(1);
		}
		Matrix result(rows);
		for (int i = 0; i < rows; i++) {
			result.main_diag[i] = main_diag[i] + m.main_diag[i];
		}
		for (int i = 0; i < rows - 1; i++) {
			result.top_diag[i] = top_diag[i] + m.top_diag[i];
		}
		for (int i = 0; i < rows - 1; i++) {
			result.bot_diag[i] = bot_diag[i] + m.bot_diag[i];
		}
		return result;
	}

	Matrix operator-(const Matrix& m) {
		if (rows != m.rows) {
			return Matrix(1);
		}
		Matrix result(rows);
		for (int i = 0; i < rows; i++) {
			result.main_diag[i] = main_diag[i] - m.main_diag[i];
		}
		for (int i = 0; i < rows - 1; i++) {
			result.top_diag[i] = top_diag[i] - m.top_diag[i];
		}
		for (int i = 0; i < rows - 1; i++) {
			result.bot_diag[i] = bot_diag[i] - m.bot_diag[i];
		}
		return result;
	}

	Matrix operator*(const Matrix& m) {
		if (rows != m.rows) {
			return Matrix(1);
		}
		Matrix result(rows);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				result->data[i][j] = 0;
				for (int k = 0; k < columns; k++) {
					result->data[i][j] += data[i][k] * m->data[k][j];
				}
			}
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
				result->data[i][j] = 0;
				for (int k = 0; k < columns; k++) {
					result->data[i][j] += data[i][k] * m->data[k][j];
				}
			}
		}
		return result;
	}

	double trace() {
		double h = 0;
		for (int i = 0; i < rows; i++) {
			h += main_diag[i];
		}
		return h;
	}

	double det(int n) {
		if (n == -1) {
			return 0;
		} else if (n == 0) {
			return 1;
		} else if (n == 1) {
			return main_diag[0];
		} else {
			return main_diag[n-1]*det(n-1) - bot_diag[n-2]*top_diag[n-2]*det(n-2);
		}
	}

	Matrix operator*(int n) {
		Matrix result(rows);
		for (int i = 0; i < rows; i++) {
			result.main_diag[i] = main_diag[i] * n;
		}
		for (int i = 0; i < rows - 1; i++) {
			result.top_diag[i] = top_diag[i] * n;
		}
		for (int i = 0; i < rows - 1; i++) {
			result.bot_diag[i] = bot_diag[i] * n;
		}
		return result;
	}

	void input() {

	}

	int get_rows() {
		return rows;
	}

	int get_columns() {
		return rows;
	}

	double get_elem(int i, int j) {
		if (i == j) {
			return main_diag[i];
		} else if (i == j - 1) {
			return top_diag[i];
		} else if (i == j + 1) {
			return bot_diag[j];
		} else {
			return 0;
		}
	}

	friend ostream& operator<<(ostream& os, const Matrix& m);
	friend istream& operator>>(ostream& is, Matrix& m);
};

ostream& operator<<(ostream& os, const Matrix& m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.rows; j++) {
			os << setw(7) << fixed << setprecision(1);
			if (i == j) {
				os << m.main_diag[i];
			} else if (i == j - 1) {
				os << m.top_diag[i];
			} else if (i == j + 1) {
				os << m.bot_diag[j];
			} else {
				os << 0;
			}
		}
		os << endl;
	}
	return os;
}

istream& operator>>(ostream& is, Matrix& m) {
	cout << "Enter elements of main diagonal: " << endl;
	for (int i = 0; i < m.rows; i++) {
		cout << "matrix[" << i << "][" << i << "]: ";
		is >> m.main_diag[i];
	}
	cout << "Enter elements of top diagonal: " << endl;
	for (int i = 0; i < m.rows - 1; i++) {
		cout << "matrix[" << i << "][" << i + 1 << "]: ";
		is >> m.top_diag[i];
	}
	cout << "Enter elements of bot diagonal: " << endl;
	for (int i = 1; i < m.rows; i++) {
		cout << "matrix[" << i << "][" << i - 1 << "]: ";
		is >> m.bot_diag[i];
	}
	return is;
}

int main() {
	Matrix* matrix = nullptr;
	char comands[8][250] = { "Create Matrix","Print Matrix","Sum Matrix","Multiply Matrix","Multiply by number","Trace",
							 "Determinant","Exit" };
	int num;
	Matrix* tmp, *result;
	int rows, columns;
	int cmd = 0;
	int cmds = 8;
	bool running = true;
	while (running) {
		for (int i = 0; i < cmds; i++) {
			cout << i + 1 << ". " << comands[i] << endl;
		}
		cout << ">> ";
		cin >> cmd;
		cout << endl;
		if (cmd != 1 and cmd != 8 and matrix == nullptr) {
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
			matrix->input();
			cout << "Successfully entered!" << endl;
			break;
		case 2:
			cout << "Printing the Matrix: " << endl;
			matrix->print();
			cout << "Successfully printed!" << endl;
			break;
		case 3:
			cout << "Sum of Matrixes: " << endl;
			cout << "Entering the Matrix: " << endl;
			cout << "Enter the size of Matrix." << endl;
			cout << "Rows    >> ";
			cin >> rows;
			cout << "Columns >> ";
			cin >> columns;
			tmp = new Matrix(rows, columns);

			cout << "Enter elements of the Matrix:" << endl;
			tmp->input();
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
		case 4:
			cout << "Multiply of Matrixes: " << endl;
			cout << "Entering the Matrix: " << endl;
			cout << "Enter the size of Matrix." << endl;
			cout << "Rows    >> ";
			cin >> rows;
			cout << "Columns >> ";
			cin >> columns;
			tmp = new Matrix(rows, columns);

			cout << "Enter elements of the Matrix:" << endl;
			tmp->input();
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

		case 5:
			cout << "Multiply by number: " << endl;
			cout << "Enter a number:" << endl << ">> ";
			cin >> num;
			result = matrix->mult_by_num(num);
			cout << "Result:" << endl;
			result->print();
			delete result;
			cout << "Successfully calculated!" << endl;
			break;
		case 6:
			cout << "Calculating trace:" << endl;
			cout << "Trace: " << matrix->trace() << endl;
			cout << "Successfully calculated";
			break;
		case 7:
			cout << "Calculating determinate:" << endl;
			cout << "Determinate: " << matrix->det() << endl;
			cout << "Successfully calculated";
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
