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
	cout << "1. ��������� �������� ������ ������� ���� �������� ����� � ������� �������.\n";

	cout << "������� ������ �����: ";
	cin >> a;
	PowerA3(a, b);
	cout << "�����: ������ ������� ����� ����� " << b << ";\n";

	cout << "������� ������ �����: ";
	cin >> a;
	PowerA3(a, b);
	cout << "�����: ������ ������� ����� ����� " << b << ";\n";

	cout << "������� ������ �����: ";
	cin >> a;
	PowerA3(a, b);
	cout << "�����: ������ ������� ����� ����� " << b << ";\n";

	cout << "������� �������� �����: ";
	cin >> a;
	PowerA3(a, b);
	cout << "�����: ������ ������� ����� ����� " << b << ";\n";

	cout << "������� ����� �����: ";
	cin >> a;
	PowerA3(a, b);
	cout << "�����: ������ ������� ����� ����� " << b << ".\n\n";
}

void program2() {
	double a, b;
	cout << "2. ��������� � ����������� �� ����� ����� ����������� ��� � ����������� �������� (-1 ��� X<0, 0 ��� X=0, 1 ��� X>0) � ������� ������� Sign(X), ����� ��������� Sign(A)+Sign(B).\n";
	cout << "������� �������� ������������� ����� A: ";
	cin >> a;
	cout << "������� �������� ������������� ����� B: ";
	cin >> b;
	cout << "�����: Sign(A) + Sign(B) = " << Sign(a) + Sign(b) << ".\n\n";
}

void program3() {
	double r1, r2;
	cout << "3. ��������� � ������� ������� RingS(R1,R2) ������� ������� ������, ������������ ����� ����� ������������ � ����� ������� � ��������� R1 � R2, ��� R1 > R2, R1 � R2 - ������������ �����.\n";
	cout << "��������� ����� ������� ���� ����� �� �������� ������� � ���������� ��������.\n";

	cout << "������� R1 � R2 ������� ������ (��� �������� ����� ������): ";
	cin >> r1 >> r2;
	cout << "�����: ������� ��������� ������ ���������� " << RingS(r1, r2) << ".\n";

	cout << "������� R1 � R2 ������� ������ (��� �������� ����� ������): ";
	cin >> r1 >> r2;
	cout << "�����: ������� ��������� ������ ���������� " << RingS(r1, r2) << ".\n";

	cout << "������� R1 � R2 �������� ������ (��� �������� ����� ������): ";
	cin >> r1 >> r2;
	cout << "�����: ������� ��������� ������ ���������� " << RingS(r1, r2) << ".\n\n";
}

void program4() {
	double x, y;
	cout << "4. ��������� �� �������� ��������� ������������ ����������� (x, y) � ������� ������� Quarter(x, y) ��������� ����� ������������ ��������, � ������� ��������� ����� � ����� ������������.\n";
	cout << "��������� ��������� ������������ ��� �������� �����.\n";
	cout << "������� ���������� ������ ����� (\"x\", ����� \"y\" ����� ������): ";
	cin >> x >> y;
	cout << "�������� ����� ��������� � " << Quarter(x, y) << " ��������.\n";

	cout << "������� ���������� ������ ����� (\"x\", ����� \"y\" ����� ������): ";
	cin >> x >> y;
	cout << "�������� ����� ��������� � " << Quarter(x, y) << " ��������.\n";

	cout << "������� ���������� ������� ����� (\"x\", ����� \"y\" ����� ������): ";
	cin >> x >> y;
	cout << "�������� ����� ��������� � " << Quarter(x, y) << " ��������.\n\n";
}

void program5() {
	int n;

	cout << "5. ��������� �� ��������� ������ ����� N > 0 � ������� ������� Fact2(N) �������� ������� ���������:\n" <<
		"N!!= 1 * 3 * 5*...*N, ���� N - ��������;\n" <<
		"N!!= 2 * 4 * 6*...*N, ���� N - ������.\n";
	cout << "������� N: ";
	cin >> n;
	cout << "�����: ������� ��������� N!! ����� " << Fact2(n) << ".\n\n";
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