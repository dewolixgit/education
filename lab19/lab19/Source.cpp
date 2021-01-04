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
	int i, j, k, flag, n, del;
	cout << "1. Программа получает на вход целочисленный массив размера N и удаляет из массива все соседние одинаковые элементы, оставляя их первые вхождения.\n";
	cout << "Задайте размер массива N: ";
	cin >> n;
	int* a = new int[n];
	cout << "Задайте элементы массива, разделяя их пробелами: ";
	cin >> a[0];
	for (i = 1; i < n; i++) cin >> a[i];

	if (n == 1) {
		cout << "В заданном массиве лишь один элемент, поэтому никаких манипуляций не должно быть; вывод: " << a[0] << ".\n\n";
		return;
	}

	del = 0;
	flag = 0;
	for (i = 1; i < n - del; i++) {
		if (a[i] == a[i - 1]) {
			flag++;
		}

		if (flag == 1) {
			j = i + 1;
			while (a[j] == a[j - 1] && j < n) {
				flag++;
				j++;
			}
			del += flag;
			for (k = j; k < n; k++) {
				a[k - flag] = a[k];
			}
			flag = 0;
		}
	}

	cout << "Вывод: преобразованный массив: ";

	for (i = 0; i < n - del - 1; i++) cout << a[i] << ", ";
	cout << a[n - del - 1] << ".\n\n";

	delete[] a;
}


void program2() {
	int n, flag, i, j, k, buf, del, newSize;
	cout << "2. Программа получает на вход целочисленный массив размера N, удаляет из массива все элементы, встречающиеся ровно два раза, выводит получившийся массив и его размер.\n";
	cout << "Задайте размер массива N: ";
	cin >> n;
	int* a = new int[n];
	cout << "Задайте элементы массива, разделяя их пробелами: ";
	cin >> a[0];
	for (i = 1; i < n; i++) cin >> a[i];

	if (n == 1) cout << "Заданный массив имеет лишь один элемент, поэтому вывод: " << a[0] << ".\n\n";

	del = 0;
	for (i = 0; i < n - del; i++) {
		flag = 0;
		for (j = 0; j < n - del; j++) {
			if (j == i) continue;
			if (a[i] == a[j]) {
				flag++;
				buf = j;
			}

			if (flag > 1) {
				break;
			}
		}

		if (flag == 1) {
			del += 2;
			if (buf > i) {
				for (k = buf; k < n - 1; k++) a[k] = a[k + 1];
				for (k = i; k < n - 2; k++) a[k] = a[k + 1];
			}
			else {
				for (k = i; k < n - 1; k++) a[k] = a[k + 1];
				for (k = buf; k < n - 2; k++) a[k] = a[k + 1];
			}
			i--;
		}
	}

	newSize = n - del;
	if (newSize == 0) {
		cout << "В данном массиве в результате обработки не осталось элементов.\n\n";
	}
	else {
		cout << "Вывод: преобразованный массив: ";
		for (i = 0; i < newSize - 1; i++) cout << a[i] << ", ";
		cout << a[i] << ";\n";

		cout << "размер преобразованного массива составляет " << newSize << ".\n\n";
	}

	delete[] a;
}


void program3() {
	int i, n, min, max, flag, newSize;
	cout << "3. Программа получает на вход массив размера N, вставляет элемент с нулевым значением перед минимальным элементом массива и после максимального элемента массива (то есть элемент с нулевым значением встаёт между минимальныи элементом и предшествущим ему и максимальным элементом и следующим за ним).\n";
	cout << "Задайте размер массива N: ";
	cin >> n;
	double* a = new double[n];
	cout << "Задайте элементы массива, разделяя их пробелами: ";
	cin >> a[0];
	for (i = 1; i < n; i++) cin >> a[i];

	min = 0;
	max = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > a[max]) max = i;
		if (a[i] < a[min]) min = i;
	}

	flag = 0;
	newSize = n + 2;
	double* b = new double[newSize];
	for (i = 0; i < n; i++) b[i] = a[i];
	if (min < max) {
		flag = 1;
		for (i = newSize - 2; i > max; i--) b[i] = b[i - 1];
		b[max + 1] = 0;
		for (i = newSize - 1; i > min - 1; i--) b[i] = b[i - 1];
		b[min] = 0;
	}
	else if (min > max) {
		flag = 1;
		for (i = newSize - 2; i > min - 1; i--) b[i] = b[i - 1];
		b[min] = 0;
		for (i = newSize - 1; i > max; i--) b[i] = b[i - 1];
		b[max + 1] = 0;
	}


	if (flag == 1) {
		cout << "Вывод: преобразованный массив: ";
		for (i = 0; i < newSize - 1; i++) cout << b[i] << ", ";
		cout << b[i] << ".\n\n";
	}
	else {
		cout << "Задан массив, состоящий из одинаковых элементов, поэтому в нём нельзя выделить минимальный и максимальный элементы.\n\n";
	}

	delete[] a;
	delete[] b;
}


void program4() {
	int i, j, n, newSize, add;
	cout << "4. Программа получает на вход массив размера N и после каждого отрицательного элемента вставляет элемент с нулевым значением (то есть элемент с нулевым значением вставляется между отрицательным элементом и идущим за ним).\n";
	cout << "Задайте размер массива N: ";
	cin >> n;
	double* a = new double[n];
	cout << "Задайте элементы массива, разделяя их пробелами: ";
	cin >> a[0];
	for (i = 1; i < n; i++) cin >> a[i];

	add = 0;
	for (i = 0; i < n; i++) {
		if (a[i] < 0) add++;
	}

	newSize = n + add;
	double* b = new double[newSize];
	for (i = 0;i < n;i++) b[i] = a[i];

	for (i = n - 1; i >= 0 && add != 0; i--) {
		if (b[i] < 0) {
			for (j = newSize - 1; j > i + 1; j--) {
				b[j] = b[j - 1];
			}
			b[i + 1] = 0;
		}
	}

	cout << "Вывод массива: ";
	for (i = 0; i < newSize - 1; i++) cout << b[i] << ", ";
	cout << b[i] << ".\n\n";

	delete[] a;
	delete[] b;
}


void program5() {
	int i, j, n, newSize, add;
	cout << "5. Программа получает на вход массив размера N и после каждого положительного элемента вставляет элемент с нулевым значением (то есть элемент с нулевым значением вставляется между положительным элементом и идущим за ним).\n";
	cout << "Задайте размер массива N: ";
	cin >> n;
	double* a = new double[n];
	cout << "Задайте элементы массива, разделяя их пробелами: ";
	cin >> a[0];
	for (i = 1; i < n; i++) cin >> a[i];

	add = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > 0) add++;
	}

	newSize = n + add;
	double* b = new double[newSize];
	for (i = 0;i < n;i++) b[i] = a[i];

	for (i = n - 1; i >= 0 && add != 0; i--) {
		if (b[i] > 0) {
			for (j = newSize - 1; j > i + 1; j--) {
				b[j] = b[j - 1];
			}
			b[i + 1] = 0;
		}
	}

	cout << "Вывод массива: ";
	for (i = 0; i < newSize - 1; i++) cout << b[i] << ", ";
	cout << b[i] << ".\n\n";

	delete[] a;
	delete[] b;
}