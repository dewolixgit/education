#include<iostream>
#include<clocale>
#include<cmath>
#include<string>
#define pi 3.14159265359

using namespace std;


void program1() {
	int a, b;
	cout << "1. Программа проверяет заданные целые переменные A и B: если они не равны - каждой переменной присваивается значение большей из них, если они равны - обеим присваивается ноль.\n" <<
		"Задайте значение для A: ";
	cin >> a;
	cout << "Задайте значение для B: ";
	cin >> b;

	if (a == b) {
		a = 0;
		b = 0;
	}
	else {
		if (a > b) {
			b = a;
		}
		else {
			a = b;
		}
	}

	cout << "Вывод: A = " << a << ", B = " << b << ".\n\n";
}

void program2() { //найду наименьшее из чисел и вычту из суммы всех трёх
	int a, b, c, sum, min;
	sum = 0;
	cout << "2. Программа находит сумму двух наибольших чисел из трёх заданных.\n" <<
		"Задайте значение для первого числа: ";
	cin >> a; sum += a;
	cout << "Задайте значение для второго числа: ";
	cin >> b; sum += b;
	cout << "Задайте значение для третьего числа: ";
	cin >> c; sum += c;
	min = a;
	if (min > b) {
		min = b;
	}
	if (min > c) {
		min = c;
	}
	cout << "Суммой двух наибольших из заданных чисел является " << sum - min << ".\n\n";
}

void program3() {
	double ax, ay, bx, by, cx, cy, aLength, bLength, cLength, angleA, angleB, angleC, angleAB, angleAC, abLength, acLength;
	cout << "3. На плоскости лежат три точки: A, B и C. Программа определит, какая из двух последних точек расположена ближе к A и найдёт расстояние до точки A.\n";
	cout << "Задайте координаты точки A (по оси Ox и Oy через пробел): ";
	cin >> ax >> ay;
	cout << "Задайте координаты точки B (по оси Ox и Oy через пробел): ";
	cin >> bx >> by;
	cout << "Задайте координаты точки C (по оси Ox и Oy через пробел): ";
	cin >> cx >> cy;
	//буду использовать теорему косинусов
	//найду величину от начала координат до A,B,C по теореме Пифагора:
	aLength = sqrt(ax * ax + ay * ay);
	bLength = sqrt(bx * bx + by * by);
	cLength = sqrt(cx * cx + cy * cy);
	//найду угол отклонения точек A, B, C от луча, исходящего от начала координат к плюс бесконечности оси Ox:
	//для A:
	if (ax > 0) {
		angleA = abs( atan(ay / ax) );
	}
	else if (ax == 0) {
		angleA = pi / 2;
	}
	else if (ax < 0) {
		angleA = pi - abs( atan(ay / ax) );
	}
	//аналогично с B:
	if (bx > 0) {
		angleB = abs(atan(by / bx));
	}
	else if (bx == 0) {
		angleB = pi / 2;
	}
	else if (bx < 0) {
		angleB = pi - abs(atan(by / bx));
	}
	//аналогично с С:
	if (cx > 0) {
		angleC = abs(atan(cy / cx));
	}
	else if (cx == 0) {
		angleC = pi / 2;
	}
	else if (cx < 0) {
		angleC = pi - abs(atan(cy / cx));
	}
	//найду углы между отрезками, соединяющими начало координат и A,B,C:
	//угол между OA И OB:
	if ( (ay >= 0 && by >= 0) || (ay <= 0 && by <= 0) ) {
		angleAB = abs(angleA - angleB);
	}
	else {
		angleAB = angleA + angleB;
		if (angleAB > pi) {
			angleAB = 2 * pi - angleAB;
		}
	}
	//угол между OA И OC:
	if ((ay >= 0 && cy >= 0) || (ay <= 0 && cy <= 0)) {
		angleAC = abs(angleA - angleC);
	}
	else {
		angleAC = angleA + angleC;
		if (angleAC > pi) {
			angleAC = 2 * pi - angleAC;
		}
	}
	//используя полученные углы и длины, применим теорему косинусов:
	abLength = sqrt( aLength * aLength + bLength * bLength - 2 * aLength * bLength * cos(angleAB) ); //нахожу длину отрезка AB
	acLength = sqrt( aLength * aLength + cLength * cLength - 2 * aLength * cLength * cos(angleAC) ); //нахожу длину отрезка AC
	if (abLength < acLength) {
		cout << "Вывод: точка B находится ближе к точке A, чем C. Длина отрезка AB равна " << abLength << ".\n\n";
	}
	else if (abLength == acLength) {
		cout << "Вывод: точки B и C равноудалены от точки A. Длины отрезков AB и AC равны " << abLength << ".\n\n";
	}
	else if (abLength > acLength) {
		cout << "Вывод: точка C находится ближе к точке A, чем B. Длина отрезка AC равна  " << acLength << ".\n\n";
	}
}

void program4() {
	int x, y;
	cout << "4. На вход программе подаются координаты точки, не лежащей на осях Ox и Oy (точка - в плоскости). Программа определит, в какой четверти находится данная точка.\n";
	cout << "Задайте координаты точки по оси Ox: ";
	cin >> x;
	cout << "Задайте координаты точки по оси Oy: ";
	cin >> y;
	if (x > 0) {
		if (y > 0) {
			cout << "Заданная точка находится в первой четверти.\n\n";
		}
		else {
			cout << "Заданная точка находится в четвёртой четверти.\n\n";
		}
	}
	else {
		if (y > 0) {
			cout << "Заданная точка находится во второй четверти.\n\n";
		}
		else {
			cout << "Заданная точка находится в третьей четверти.\n\n";
		}
	}
}

void program5() {
	int a;
	string characteristic;
	cout << "5. Программа даст описание введёному целому числу.\n" <<
		"Введите целое число: ";
	cin >> a;

	if (a > 0) {
		characteristic += " положительным";
	}
	else if (a == 0) {
		characteristic += " нулевым";
	}
	else {
		characteristic += " отрицательным";
	}

	if (a % 2 == 0 && a != 0) {
		characteristic += " чётным";
	}
	else if (a != 0) {
		characteristic += " нечётным";
	}

	cout << "Вывод: введённое число является" << characteristic << ".\n\n";
}

void program6() {
	int a;
	string characteristic;
	cout << "6. Программа даст описание введёному целому числу, лежащему в диапазоне от 1 до 999 включительно..\n" <<
		"Введите целое число: ";
	cin >> a;

	if (a % 2 == 0 && a != 0) {
		characteristic += " чётным";
	}
	else if (a != 0) {
		characteristic += " нечётным";
	}

	if (a <= 9) {
		characteristic += " однозначным";
	}
	else if (a <= 99) {
		characteristic += " двузначным";
	}
	else {
		characteristic += " трёхзначным";
	}

	cout << "Вывод: введённое число является" << characteristic << ".\n\n";
}

int main() {
	setlocale(LC_ALL, "rus");

	program1();
	program2();
	program3();
	program4();
	program5();
	program6();

	return 0;
}