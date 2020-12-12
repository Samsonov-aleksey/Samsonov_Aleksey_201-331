#include <iostream>

using namespace std;

class Position {
protected: // пользоваться переменными в классах наследниках
	double x, y;
public:
	Position (){}
	Position(double x,double y) {
		this->x = x;
		this->y=y;
	}
	friend ostream& operator<<(ostream& os,const Position &p);
};
ostream& operator<<(ostream& os, const Position& p) {// ос это поток вывода
	os << p.x <<" "<< p.y;
	return os;
}
class Square :public virtual Position {//наследование виртуаль это костыль для того чтобы избежать ошибок при множественном наследовании для того тобы икс и игрик были одними и теже в самом последнем классе
protected:
	double side;
public:
	Square(double x, double y,double side):Position(x,y) {//вызвали конструктор позишена и свой сделали
		this->side = side;
	}
	friend ostream& operator<<(ostream& os, const Square& s);
};
ostream& operator<<(ostream& os, const Square& s) {// ос это поток вывода
	os << s.x << " " << s.y;
	return os;
}
class Circle : public virtual Position {
protected:
	double radius;
public:
	Circle(double x, double y, double radius) :Position(x, y) {
		this->radius = radius;
	}
	friend ostream& operator<<(ostream& os, const Circle& c);
};
ostream& operator<<(ostream& os, const Circle& c) {// ос это поток вывода
	os << c.x << " " << c.y;
	return os;
}
class CircleInSquare :public  Circle, public Square {
private:
public:
	CircleInSquare(double x, double y, double side, double radius) :Circle(x, y, radius), Square(x, y, side) {
		this->x=x;
		this->y = y;
		this->side = side;
		this->radius = radius;
	}
	friend ostream& operator<<(ostream& os, const CircleInSquare& cis);
};
ostream& operator<<(ostream& os, const CircleInSquare& cis) {
	os << cis.x << " " << cis.y;
	return os;
}


int main() {
	double x, y,x1,x2,y1,y2,x3,y3,side,radius,side1,radius1;
	cout << "Enter coordinates of Figure" << endl;
	cin >> x >> y;
	Position p(x, y);
	cout << "Enter coordinates of Square" << endl;
	cin >> x1 >> y1;
	cout << "Enter side length" << endl;
	cin >> side;
	Square s(x1, y1,side);
	cout << "Enter coordinates of Circle" << endl;
	cin >> x2 >> y2;
	cout << "Enter radius" << endl;
	cin >> radius;
	Circle c(x2, y2, radius);
	cout << "Enter coordinates of Circle in Square" << endl;
	cin >> x3 >> y3;
	cout << "Enter side length" << endl;
	cin >> side1;
	cout << "Enter radius" << endl;
	cin >> radius1;
	CircleInSquare cis(x3, y3, radius1, side1);
	cout <<"======================================================================="<<endl;
	cout << "Coordinates of Figure" <<p<< endl;
	cout << "Coordinates of Square" << s << endl;
	cout << "Coordinates of Circle" << c << endl;
	cout << "Coordinates of CircleInSquare" << cis << endl;
		return 0;
}
