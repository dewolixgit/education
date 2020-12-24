#include <iostream>
#include <clocale>

using namespace std;

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
	int i, n, amount;
	cout << "1. ��������� �� ��������� ������ ����� N > 0 ���������� � ������� ������������� ������ ������� N, ���������� N ������ ������������� ������������� �������� �����: 1, 3, 5, ...\n";
	cout << "������� �������� N: ";
	cin >> n;

	//��������:
	for (i = 0, amount = 0; i < n; i++) {
		if (i % 2 != 0) amount++;
	}
	int* a = new int[amount];
	for (i = 0; i < amount; i++) {
		a[i] = i * 2 + 1;
	}

	//������
	cout << "�����: ";
	for (i = 0; i < amount-1; i++) {
		cout << a[i] << ", ";
	}
	cout << a[amount - 1] << ".\n\n";

	delete[] a;
}

void program2() {
	int i, n;
	double a, d;
	cout << "2. ��������� �� ��������� ������ ����� N > 1, ������� ����� A � ����������� D �������������� ���������� ���������� � ������� ������ ������� N, ���������� N ������ ������ ������ ����������: A, A*D, A*D*D, ...\n";
	cout << "������� �������� N: ";
	cin >> n;
	cout << "������� �������� A: ";
	cin >> a;
	cout << "������� �������� D: ";
	cin >> d;

	//��������:
	double* array = new double[n];
	array[0] = a;
	for (i = 1; i < n; i++) {
		array[i] = array[i - 1] * d;
	}

	//������
	cout << "�����: ";
	for (i = 0; i < n - 1; i++) {
		cout << array[i] << ", ";
	}
	cout << array[n - 1] << ".\n\n";

	delete[] array;
}

void program3() {
	int n, i, sum;
	cout << "3. ��������� �� �������� ����� ������ N > 2, A � B ���������� � ������� ������������� ������ ������� N, ��� ������ ������� ����� A, ������ - B, � ������ ����������� ����� ����� ���� ����������.\n";
	cout << "������� �������� N: ";
	cin >> n;
	int* array = new int[n];
	cout << "������� �������� A: ";
	cin >> array[0];
	cout << "������� �������� B: ";
	cin >> array[1];

	//��������� ����������� ������:
	sum = array[0] + array[1];
	for (i = 2; i < n; i++) {
		array[i] = sum;
		sum += array[i];
	}

	//������ ������:
	cout << "�����: ";
	for (i = 0; i < n - 1; i++) {
		cout << array[i] << ", ";
	}
	cout << array[n - 1] << ".\n\n";
}

void program4() {
	int i, n, c;
	cout << "4. ��������� �������� �� ���� ������ A �������� N � ������� ��� �������� � ��������� �������:\n" <<
		"A(1), A(N), A(2), A(N-1), A(3), A(N-2), ...\n";
	cout << "������� �������� N: ";
	cin >> n;
	double* a = new double[n];
	cout << "������� �������� �������, �������� �� ���������:\n";
	cin >> a[0];
	for (i = 1; i < n; i++) cin >> a[i];

	cout << "�����: ";
	cout << "�������������� �������� ������������������: ";
	for (i = 0; i < n - 1; i++) cout << a[i] << ", ";
	cout << a[n - 1] << ";\n";

	cout << "��������������� �������� ������������������: ";

	//����� ���� � ����� �������, �� ����� ���� �������� ���� � ����� ��-���� �������� ���� ������:
	for (i = 0, c = 0; i < n - 1; i++) {
		if (i % 2 == 0) {
			cout << a[i - c] << ", ";
		}
		else {
			cout << a[n - c - 1] << ", ";
			c++;
		}
	}

	if (i % 2 == 0) {
		cout << a[i - c] << ".\n\n";
	}
	else {
		cout << a[n - c - 1] << ".\n\n";
	}

	delete[] a;
}

void program5() {
	int n, i, last;
	cout << "5. ��������� �� ��������� ������� A � ��������� ������� N ������� ������� ��� �������� � ��������� �������� � ������� ����������� �������, ����� - �������� � ������� �������� � ������� �������� �������. ���� ��������� ���������� � �������.\n";
	cout << "������� ������ ������� N: ";
	cin >> n;
	double* a = new double[n + 1];
	cout << "������� �������� �������, �������� �� ���������:\n";
	cin >> a[1];
	for (i = 2; i <= n; i++) cin >> a[i];

	cout << "�����:\n";
	cout << "�������� � ��������� �������� � ������� ����������� �������: ";

	if (n % 2 == 0) last = n - 1;
	else last = n;

	for (i = 1; i < last; i += 2) {
		cout << a[i] << ", ";
	}
	cout << a[last];

	if (n == 1) {
		cout << ".\n";
		cout << "������ ������� �� ������ ��������, ������� �� �� ����� ��������� � ������� ��������.\n\n";
		return;
	}
	cout << ";\n";

	cout << "�������� � ������� �������� � ������� �������� �������: ";

	if (n % 2 == 0) last = n;
	else last = n - 1;

	for (i = last; i > 2; i -= 2) {
		cout << a[i] << ", ";
	}
	cout << a[2] << ".\n";

	delete[] a;
}