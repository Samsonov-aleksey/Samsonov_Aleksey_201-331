#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
private:
	int rows, columns;
	double** data;//указатель на массив указателей(указатель на каждую строчку матрицы)
public:	
	
	Matrix(int rows_, int columns_) : rows(rows_), columns(columns_) {
		if (data != nullptr) {
			for (int i = 0; i < rows; i++) {
				delete[] data[i];
			}
			delete[] data;
		}
		data = new double* [rows];//выделили память под роуз штук указателй
		for (int i = 0; i < rows; i++) {
			data[i] = new double[columns];
		}
	}

	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}

	Matrix* sum(const Matrix* m) {
		if (rows != m->rows or columns != m->columns) {
			return nullptr;
		}
		Matrix* result = new Matrix(rows, columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				result->data[i][j] = data[i][j] + m->data[i][j];
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
		if (rows != columns) {
			return 0;
		}
		double h = 0;
		for (int i = 0; i < rows; i++) {
			h += data[i][i];// сумма диагональных элементов
		}
		return h;
	}


	Matrix* removeRowColumn(int I, int J) {
		if (I < 0 or I >= rows or J < 0 or J >= columns) {
			return nullptr;
		}
		Matrix* M = new Matrix(rows - 1, columns - 1);
		for (int i = 0; i < I; i++) {
			for (int j = 0; j < J; j++) {
				M->data[i][j] = data[i][j];
			}
		}
		for (int i = I; i < rows - 1; i++) {
			for (int j = 0; j < J; j++) {
				M->data[i][j] = data[i + 1][j];
			}
		}
		for (int j = J; j < columns - 1; j++) {
			for (int i = 0; i < I; i++) {
				M->data[i][j] = data[i][j + 1];
			}
		}
		for (int j = J; j < columns - 1; j++) {
			for (int i = I; i < rows - 1; i++) {
				M->data[i][j] = data[i + 1][j + 1];
			}
		}

		return M;
	}

	double det() {
		if (rows != columns) {
			return 0;
		}
		if (rows == 1) {
			return data[0][0];
		}
		if (columns == 2) {
			return data[0][0] * data[1][1] - (data[1][0] * data[0][1]);// определитель матрицы 2Х2
		}
		double d = 0;
		int sign = 1;
		for (int i = 0; i < columns; i++) {// рекурсивная функция детерминант считается через детерминант меньших матриц
			Matrix* M = removeRowColumn(i, 0);
			d += sign * data[i][0] * M->det();
			delete M;
			sign *= -1;
		}
		return d;
	}

	Matrix* mult_by_num(double num) {
		Matrix* result = new Matrix(rows, columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				result->data[i][j] = data[i][j] * num;
			}
		}
		return result;
	}

	void input() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << "data[" << i << "][" << j << "]: ";
				cin >> data[i][j];
			}
		}
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << setw(7) << fixed << setprecision(1) << data[i][j];// фиксированное количество знаков после запятой(1)
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
		return data[i][j];
	}
};

int main() {
	Matrix* matrix = nullptr;// не выделяем память
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