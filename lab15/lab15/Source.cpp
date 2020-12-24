#include <iostream>
#include <clocale>
#define pi 3.1415926535

using namespace std;

void PowerA3(double &a, double &b);
int Sign(double& x);
double RingS(double &r1, double &r2);
int Quarter(double &x, double &y);
double Fact2(int &n);
void program1();
void program2();
void program3();
void program4();
void program5();



int main() {
	setlocale(LC_ALL, "rus");

	program1();
	program2();
	program3();
	program4();
	program5();

	return 0;
}

void program1() {
	double a, b;
	cout << "1. Программа вычислит третьи степени пяти заданных чисел с помощью функции.\n";

	cout << "Задайте первое число: ";
	cin >> a;
	PowerA3(a, b);
	cout << "Вывод: третья степень числа равна " << b << ";\n";

	cout << "Задайте второе число: ";
	cin >> a;
	PowerA3(a, b);
	cout << "Вывод: третья степень числа равна " << b << ";\n";

	cout << "Задайте третье число: ";
	cin >> a;
	PowerA3(a, b);
	cout << "Вывод: третья степень числа равна " << b << ";\n";

	cout << "Задайте четвёртое число: ";
	cin >> a;
	PowerA3(a, b);
	cout << "Вывод: третья степень числа равна " << b << ";\n";

	cout << "Задайте пятое число: ";
	cin >> a;
	PowerA3(a, b);
	cout << "Вывод: третья степень числа равна " << b << ".\n\n";
}

void program2() {
	double a, b;
	cout << "2. Программа в зависимости от знака числа преобразует его в определённое значение (-1 для X<0, 0 для X=0, 1 для X>0) с помощью функции Sign(X), затем вычисляет Sign(A)+Sign(B).\n";
	cout << "Задайте значение вещественного числа A: ";
	cin >> a;
	cout << "Задайте значение вещественного числа B: ";
	cin >> b;
	cout << "Вывод: Sign(A) + Sign(B) = " << Sign(a) + Sign(b) << ".\n\n";
}

void program3() {
	double r1, r2;
	cout << "3. Программа с помощью функции RingS(R1,R2) находит площадь кольца, заключённого между двумя окружностями с общим центром и радиусами R1 и R2, где R1 > R2, R1 и R2 - вещественные числа.\n";
	cout << "Программа найдёт площади трех колец по заданным внешним и внутренним радиусам.\n";

	cout << "Задайте R1 и R2 первого кольца (два значения через пробел): ";
	cin >> r1 >> r2;
	cout << "Вывод: площадь заданного кольца составляет " << RingS(r1, r2) << ".\n";

	cout << "Задайте R1 и R2 второго кольца (два значения через пробел): ";
	cin >> r1 >> r2;
	cout << "Вывод: площадь заданного кольца составляет " << RingS(r1, r2) << ".\n";

	cout << "Задайте R1 и R2 третьего кольца (два значения через пробел): ";
	cin >> r1 >> r2;
	cout << "Вывод: площадь заданного кольца составляет " << RingS(r1, r2) << ".\n\n";
}

void program4() {
	double x, y;
	cout << "4. Программа по заданным ненулевым вещественным координатам (x, y) с помощью функции Quarter(x, y) определит номер координатной четверти, в которой находится точка с этими координатами.\n";
	cout << "Программа определит расположение трёх заданных точек.\n";
	cout << "Задайте координаты первой точки (\"x\", затем \"y\" через пробел): ";
	cin >> x >> y;
	cout << "Заданная точка находится в " << Quarter(x, y) << " четверти.\n";

	cout << "Задайте координаты второй точки (\"x\", затем \"y\" через пробел): ";
	cin >> x >> y;
	cout << "Заданная точка находится в " << Quarter(x, y) << " четверти.\n";

	cout << "Задайте координаты третьей точки (\"x\", затем \"y\" через пробел): ";
	cin >> x >> y;
	cout << "Заданная точка находится в " << Quarter(x, y) << " четверти.\n\n";
}

void program5() {
	int n;

	cout << "5. Программа по заданному целому числу N > 0 с помощью функции Fact2(N) вычислит двойной факториал:\n" <<
		"N!!= 1 * 3 * 5*...*N, если N - нечётное;\n" <<
		"N!!= 2 * 4 * 6*...*N, если N - чётное.\n";
	cout << "Задайте N: ";
	cin >> n;
	cout << "Вывод: двойной факториал N!! равен " << Fact2(n) << ".\n\n";
}

void PowerA3(double &a, double &b) {
	b = a * a * a;
}

int Sign(double &x) {
	if (x == 0) return 0;
	return abs(x) / x;
}

double RingS(double &r1, double &r2) {
	return pi * r1 * r1 - pi * r2 * r2;
}

int Quarter(double &x, double &y) {
	if (x > 0 && y > 0) return 1;
	else if (x < 0 && y > 0) return 2;
	else if (x < 0 && y < 0) return 3;
	else return 4;
}

double Fact2(int &n) {
	double i;
	double fact = 1;

	if (n % 2 == 0) {
		i = 1;
		while (2 * i <= n) {
			fact *= 2 * i;
			i++;
		}
	}
	else {
		i = 0;
		while (2 * i + 1 <= n) {
			fact *= 2 * i + 1;
			i++;
		}
	}

	return fact;
}