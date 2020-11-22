#include<iostream>
#include<clocale>
#include<cmath>
#include<string>
#define pi 3.14159265359

using namespace std;


void program1() {
	int a, b;
	cout << "1. ��������� ��������� �������� ����� ���������� A � B: ���� ��� �� ����� - ������ ���������� ������������� �������� ������� �� ���, ���� ��� ����� - ����� ������������� ����.\n" <<
		"������� �������� ��� A: ";
	cin >> a;
	cout << "������� �������� ��� B: ";
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

	cout << "�����: A = " << a << ", B = " << b << ".\n\n";
}

void program2() { //����� ���������� �� ����� � ����� �� ����� ���� ���
	int a, b, c, sum, min;
	sum = 0;
	cout << "2. ��������� ������� ����� ���� ���������� ����� �� ��� ��������.\n" <<
		"������� �������� ��� ������� �����: ";
	cin >> a; sum += a;
	cout << "������� �������� ��� ������� �����: ";
	cin >> b; sum += b;
	cout << "������� �������� ��� �������� �����: ";
	cin >> c; sum += c;
	min = a;
	if (min > b) {
		min = b;
	}
	if (min > c) {
		min = c;
	}
	cout << "������ ���� ���������� �� �������� ����� �������� " << sum - min << ".\n\n";
}

void program3() {
	double ax, ay, bx, by, cx, cy, aLength, bLength, cLength, angleA, angleB, angleC, angleAB, angleAC, abLength, acLength;
	cout << "3. �� ��������� ����� ��� �����: A, B � C. ��������� ���������, ����� �� ���� ��������� ����� ����������� ����� � A � ����� ���������� �� ����� A.\n";
	cout << "������� ���������� ����� A (�� ��� Ox � Oy ����� ������): ";
	cin >> ax >> ay;
	cout << "������� ���������� ����� B (�� ��� Ox � Oy ����� ������): ";
	cin >> bx >> by;
	cout << "������� ���������� ����� C (�� ��� Ox � Oy ����� ������): ";
	cin >> cx >> cy;
	//���� ������������ ������� ���������
	//����� �������� �� ������ ��������� �� A,B,C �� ������� ��������:
	aLength = sqrt(ax * ax + ay * ay);
	bLength = sqrt(bx * bx + by * by);
	cLength = sqrt(cx * cx + cy * cy);
	//����� ���� ���������� ����� A, B, C �� ����, ���������� �� ������ ��������� � ���� ������������� ��� Ox:
	//��� A:
	if (ax > 0) {
		angleA = abs( atan(ay / ax) );
	}
	else if (ax == 0) {
		angleA = pi / 2;
	}
	else if (ax < 0) {
		angleA = pi - abs( atan(ay / ax) );
	}
	//���������� � B:
	if (bx > 0) {
		angleB = abs(atan(by / bx));
	}
	else if (bx == 0) {
		angleB = pi / 2;
	}
	else if (bx < 0) {
		angleB = pi - abs(atan(by / bx));
	}
	//���������� � �:
	if (cx > 0) {
		angleC = abs(atan(cy / cx));
	}
	else if (cx == 0) {
		angleC = pi / 2;
	}
	else if (cx < 0) {
		angleC = pi - abs(atan(cy / cx));
	}
	//����� ���� ����� ���������, ������������ ������ ��������� � A,B,C:
	//���� ����� OA � OB:
	if ( (ay >= 0 && by >= 0) || (ay <= 0 && by <= 0) ) {
		angleAB = abs(angleA - angleB);
	}
	else {
		angleAB = angleA + angleB;
		if (angleAB > pi) {
			angleAB = 2 * pi - angleAB;
		}
	}
	//���� ����� OA � OC:
	if ((ay >= 0 && cy >= 0) || (ay <= 0 && cy <= 0)) {
		angleAC = abs(angleA - angleC);
	}
	else {
		angleAC = angleA + angleC;
		if (angleAC > pi) {
			angleAC = 2 * pi - angleAC;
		}
	}
	//��������� ���������� ���� � �����, �������� ������� ���������:
	abLength = sqrt( aLength * aLength + bLength * bLength - 2 * aLength * bLength * cos(angleAB) ); //������ ����� ������� AB
	acLength = sqrt( aLength * aLength + cLength * cLength - 2 * aLength * cLength * cos(angleAC) ); //������ ����� ������� AC
	if (abLength < acLength) {
		cout << "�����: ����� B ��������� ����� � ����� A, ��� C. ����� ������� AB ����� " << abLength << ".\n\n";
	}
	else if (abLength == acLength) {
		cout << "�����: ����� B � C ������������ �� ����� A. ����� �������� AB � AC ����� " << abLength << ".\n\n";
	}
	else if (abLength > acLength) {
		cout << "�����: ����� C ��������� ����� � ����� A, ��� B. ����� ������� AC �����  " << acLength << ".\n\n";
	}
}

void program4() {
	int x, y;
	cout << "4. �� ���� ��������� �������� ���������� �����, �� ������� �� ���� Ox � Oy (����� - � ���������). ��������� ���������, � ����� �������� ��������� ������ �����.\n";
	cout << "������� ���������� ����� �� ��� Ox: ";
	cin >> x;
	cout << "������� ���������� ����� �� ��� Oy: ";
	cin >> y;
	if (x > 0) {
		if (y > 0) {
			cout << "�������� ����� ��������� � ������ ��������.\n\n";
		}
		else {
			cout << "�������� ����� ��������� � �������� ��������.\n\n";
		}
	}
	else {
		if (y > 0) {
			cout << "�������� ����� ��������� �� ������ ��������.\n\n";
		}
		else {
			cout << "�������� ����� ��������� � ������� ��������.\n\n";
		}
	}
}

void program5() {
	int a;
	string characteristic;
	cout << "5. ��������� ���� �������� �������� ������ �����.\n" <<
		"������� ����� �����: ";
	cin >> a;

	if (a > 0) {
		characteristic += " �������������";
	}
	else if (a == 0) {
		characteristic += " �������";
	}
	else {
		characteristic += " �������������";
	}

	if (a % 2 == 0 && a != 0) {
		characteristic += " ������";
	}
	else if (a != 0) {
		characteristic += " ��������";
	}

	cout << "�����: �������� ����� ��������" << characteristic << ".\n\n";
}

void program6() {
	int a;
	string characteristic;
	cout << "6. ��������� ���� �������� �������� ������ �����, �������� � ��������� �� 1 �� 999 ������������..\n" <<
		"������� ����� �����: ";
	cin >> a;

	if (a % 2 == 0 && a != 0) {
		characteristic += " ������";
	}
	else if (a != 0) {
		characteristic += " ��������";
	}

	if (a <= 9) {
		characteristic += " �����������";
	}
	else if (a <= 99) {
		characteristic += " ����������";
	}
	else {
		characteristic += " ����������";
	}

	cout << "�����: �������� ����� ��������" << characteristic << ".\n\n";
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