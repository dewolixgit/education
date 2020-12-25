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
	cout << "1. Программа по заданному целому числу N > 0 сформирует и выведет целочисленный массив размера N, содержащий N первых целочисленных положительных нечётных чисел: 1, 3, 5, ...\n";
	cout << "Задайте значение N: ";
	cin >> n;

	//формирую:
	for (i = 0, amount = 0; i < n; i++) {
		if (i % 2 != 0) amount++;
	}
	int* a = new int[amount];
	for (i = 0; i < amount; i++) {
		a[i] = i * 2 + 1;
	}

	//вывожу
	cout << "Вывод: ";
	for (i = 0; i < amount - 1; i++) {
		cout << a[i] << ", ";
	}
	cout << a[amount - 1] << ".\n\n";

	delete[] a;
}

void program2() {
	int i, n;
	double a, d;
	cout << "2. Программа по заданному целому числу N > 1, первому члену A и знаменателю D геометрической прогрессии сформирует и выведет массив размера N, содержащий N первых членов данной прогрессии: A, A*D, A*D*D, ...\n";
	cout << "Задайте значение N: ";
	cin >> n;
	cout << "Задайте значение A: ";
	cin >> a;
	cout << "Задайте значение D: ";
	cin >> d;

	//формирую:
	double* array = new double[n];
	array[0] = a;
	for (i = 1; i < n; i++) {
		array[i] = array[i - 1] * d;
	}

	//вывожу
	cout << "Вывод: ";
	for (i = 0; i < n - 1; i++) {
		cout << array[i] << ", ";
	}
	cout << array[n - 1] << ".\n\n";

	delete[] array;
}

void program3() {
	int n, i, sum;
	cout << "3. Программа по заданным целым числам N > 2, A и B сформирует и выведет целочисленный массив размера N, где первый элемент равен A, второй - B, а каждый последующий равен сумме всех предыдущих.\n";
	cout << "Задайте значение N: ";
	cin >> n;
	int* array = new int[n];
	cout << "Задайте значение A: ";
	cin >> array[0];
	cout << "Задайте значение B: ";
	cin >> array[1];

	//продолжаю формировать массив:
	sum = array[0] + array[1];
	for (i = 2; i < n; i++) {
		array[i] = sum;
		sum += array[i];
	}

	//вывожу массив:
	cout << "Вывод: ";
	for (i = 0; i < n - 1; i++) {
		cout << array[i] << ", ";
	}
	cout << array[n - 1] << ".\n\n";
}

void program4() {
	int i, n, c;
	cout << "4. Программа получает на вход массив A размером N и выводит его элемента в следующем порядке:\n" <<
		"A(1), A(N), A(2), A(N-1), A(3), A(N-2), ...\n";
	cout << "Задайте значение N: ";
	cin >> n;
	double* a = new double[n];
	cout << "Задайте элементы массива, разделяя их пробелами:\n";
	cin >> a[0];
	for (i = 1; i < n; i++) cin >> a[i];

	cout << "Вывод: ";
	cout << "первоначальная числовая последовательность: ";
	for (i = 0; i < n - 1; i++) cout << a[i] << ", ";
	cout << a[n - 1] << ";\n";

	cout << "преобразованная числовая последовательность: ";

	//можно было и легче сделать, но начал идти окольным путём и решил всё-таки доделать этот способ:
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
	cout << "5. Программа по заданному массиву A и заданному размеру N выводит сначала его элементы с нечётными номерами в порядке возрастания номеров, затем - элементы с чётными номерами в порядке убывания номеров. Счёт элементов начинается с единицы.\n";
	cout << "Задайте размер массива N: ";
	cin >> n;
	double* a = new double[n + 1];
	cout << "Задайте элементы массива, разделяя их пробелами:\n";
	cin >> a[1];
	for (i = 2; i <= n; i++) cin >> a[i];

	cout << "Вывод:\n";
	cout << "элементы с нечётными номерами в порядке возрастания номеров: ";

	if (n % 2 == 0) last = n - 1;
	else last = n;

	for (i = 1; i < last; i += 2) {
		cout << a[i] << ", ";
	}
	cout << a[last];

	if (n == 1) {
		cout << ".\n";
		cout << "Массив состоит из одного элемента, поэтому он не имеет элементов с чётными номерами.\n\n";
		return;
	}
	cout << ";\n";

	cout << "элементы с чётными номерами в порядке убывания номеров: ";

	if (n % 2 == 0) last = n;
	else last = n - 1;

	for (i = last; i > 2; i -= 2) {
		cout << a[i] << ", ";
	}
	cout << a[2] << ".\n";

	delete[] a;
}