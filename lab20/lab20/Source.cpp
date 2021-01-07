#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;


double length(int x1, int y1, int x2, int y2);
double perimeter(int x1, int y1, int x2, int y2, int x3, int y3);

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



double length(int x1, int y1, int x2, int y2) {

	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

}

double perimeter(int x1, int y1, int x2, int y2, int x3, int y3) {

	return length(x1, y1, x2, y2) + length(x2, y2, x3, y3) + length(x3, y3, x1, y1);

}


void program1() {
	int n, sizeB, sizeC, current, i, length;
	cout << "1. Программа получает на вход целочисленный массив A размера N, " <<
		"формирует исходя из этого массива два новых целочисленных массива B и C одинаковой длины. " <<
		"В массиве B заключены длины всех серий в исходном массиве, в массиве C заключены элементы, образующие эти серии " <<
		"(определение серии элементов смотри в условии задания).\n";

	cout << "Задайте размер N массива: ";
	cin >> n;
	int* a = new int[n];

	cout << "Задайте элементы массива A, разделяя их пробелами: ";
	cin >> a[0];
	for (i = 1;i < n;i++) cin >> a[i];

	sizeB = 0;
	sizeC = 0;
	int* b = new int[sizeB];
	int* c = new int[sizeC];

	int headOfSeries = 0;
	while (headOfSeries < n) {
		length = 0;

		for (current = headOfSeries; current < n && a[current] == a[headOfSeries]; current++) {
			length++;
		}

		int* extendedB = new int[sizeB + 1];
		for (i = 0; i < sizeB; i++) extendedB[i] = b[i];
		if (sizeB == 0) extendedB[0] = length;
		else extendedB[i] = length;
		sizeB++;
		delete[] b;
		b = extendedB;

		int* extendedC = new int[sizeC + 1];
		for (i = 0; i < sizeC; i++) extendedC[i] = c[i];
		if (sizeC == 0) extendedC[0] = a[headOfSeries];
		else extendedC[i] = a[headOfSeries];
		sizeC++;
		delete[] c;
		c = extendedC;

		headOfSeries += length;
	}


	cout << "Вывод:\n";

	cout << "массив B (длины серий элементов): ";
	for (i = 0; i < sizeB - 1; i++) cout << b[i] << ", ";
	cout << b[i] << ";\n";

	cout << "массив C (образующие элементы): ";
	for (i = 0; i < sizeC - 1; i++) cout << c[i] << ", ";
	cout << c[i] << ".\n\n";

	delete[] a;
	delete[] b;
	delete[] c;
}


void program2() {
	int n, current, i, length, l;
	cout << "2. Программа получает на вход целочисленный массив размера N и целое число L>0, " <<
		"заменяет каждую серию элементов, длина которой больше L, на один элемент с нулевым значением " <<
		"(если в результате работы алгоритма получится подходящая серия из нулей, эта серия также будет обработана, " <<
		"определение серии элементов смотри в условии задания).\n";

	cout << "Задайте размер N массива: ";
	cin >> n;
	int* a = new int[n];

	cout << "Задайте элементы массива, разделяя их пробелами: ";
	cin >> a[0];
	for (i = 1;i < n;i++) cin >> a[i];

	cout << "Задайте значение числа L: ";
	cin >> l;

	int headOfSeries = 0;
	int sizeOfArr = n;

	for (headOfSeries = 0; headOfSeries < sizeOfArr; headOfSeries++) {

		length = 0;

		for (current = headOfSeries; current < sizeOfArr && a[current] == a[headOfSeries]; current++) {
			length++;
		}

		if (length > l) {
			int headOfDelete = headOfSeries + 1;
			int lengthOfDelete = length - 1;

			for (i = headOfDelete; i + lengthOfDelete < sizeOfArr; i++) {
				a[i] = a[i + lengthOfDelete];
			}

			a[headOfSeries] = 0;

			sizeOfArr -= lengthOfDelete;

			headOfSeries = -1;
		}

	}

	cout << "Вывод: ";
	for (i = 0; i < sizeOfArr - 1; i++) cout << a[i] << ", ";
	cout << a[i] << ".\n\n";


	delete[] a;
}


void program3() {
	int n, current, i, length, k, j;
	cout << "3. Программа получает на вход целочисленный массив размера N и целое число K>0, " <<
		"меняет местами последнюю серию элементов с серией с номером K " <<
		"(определение серии элементов смотри в условии задания).\n";

	cout << "Задайте размер N массива: ";
	cin >> n;
	int* a = new int[n];

	cout << "Задайте элементы массива, разделяя их пробелами: ";
	cin >> a[0];
	for (i = 1;i < n;i++) cin >> a[i];

	cout << "Задайте значение числа K: ";
	cin >> k;


	/* Нахожу k-ую серию */
	int headOfSeries = 0;
	int sizeOfArr = n;
	int numOfSeries = 0;

	for (headOfSeries = 0; headOfSeries < sizeOfArr && numOfSeries != k; ) {

		length = 0;

		for (current = headOfSeries; current < sizeOfArr && a[current] == a[headOfSeries]; current++) {
			length++;
		}

		numOfSeries++;
		headOfSeries += length;

	}

	/* Определяю k-ую серию: номер головного элемента, длину, массив с элементами */
	int headKSeries = headOfSeries - length;
	int lengthKSeries = length;
	int* kSeries = new int[lengthKSeries];
	for (i = 0; i < lengthKSeries; i++) kSeries[i] = a[i + headKSeries];

	/* Определяю последнюю серию: номер головного элемента, длину, массив с элементами*/
	int lengthLastSeries = 0;

	for (j = n - 1; j >= 0 && a[j] == a[n - 1]; j--) {
		lengthLastSeries++;
	}
	int headLastSeries = j + 1;

	int* lastSeries = new int[lengthLastSeries];
	for (i = 0; i < lengthLastSeries; i++) lastSeries[i] = a[i + headLastSeries];

	/* Удаляю из исходного массива последнюю серию уменьшением размера массива */
	sizeOfArr -= lengthLastSeries;

	/* Удаляю из исходного массива k-ую серию свигом элементов массива влево и уменьшением размера массива */
	for (i = headKSeries; i + lengthKSeries < sizeOfArr; i++) a[i] = a[i + lengthKSeries];
	sizeOfArr -= lengthKSeries;

	/* Расширяю массив и освобождаю место (свигом элементов вправо) для вставки последней серии на место k-ой серии */
	sizeOfArr += lengthLastSeries;
	for (i = sizeOfArr - 1; i >= headKSeries + lengthLastSeries; i--) a[i] = a[i - lengthLastSeries];

	/* Вставляю последнюю серию в освобождеённое место */
	for (i = headKSeries; i < lengthLastSeries + headKSeries; i++) a[i] = lastSeries[i - headKSeries];

	/* Вставляю k-ю серию в конец массива*/
	headLastSeries = sizeOfArr;
	for (i = headLastSeries; i < lengthKSeries + headLastSeries; i++) a[i] = kSeries[i - headLastSeries];

	sizeOfArr += lengthKSeries;


	cout << "Вывод: ";
	for (i = 0; i < n - 1; i++) cout << a[i] << ", ";
	cout << a[i] << ".\n\n";


	delete[] a;
	delete[] lastSeries;
	delete[] kSeries;
}


void program4() {
	int n, i, x, y, number;
	cout << "4. Программа получает на вход множество A из N точек, " <<
		"по заданным координатам точек находит и выводит точку, " <<
		"наиболее удалённую от начала координат и лежащую во второй четверти.\n";

	cout << "Задайте количество N точек: ";
	cin >> n;
	int* a = new int[n * 2 + 2]; /* "сплющил" двумерный массив, прибавил двойку для удобства */

	cout << "Задайте координаты точек (x и y - через пробел):\n";
	for (i = 1; i <= n; i++) {
		cout << "Координаты точки № " << i << ": ";
		cin >> a[i * 2] >> a[i * 2 + 1];
	}

	double maxDistance = 0;

	for (i = 1; i <= n && a[i * 2] < 0 && a[i * 2 + 1] > 0; i++) {

		double currentDistance = sqrt(a[i * 2] * a[i * 2] + a[i * 2 + 1] * a[i * 2 + 1]);

		if (currentDistance > maxDistance) {
			maxDistance = currentDistance;
			x = a[i * 2];
			y = a[i * 2 + 1];
			number = i;
		}

	}


	if (maxDistance != 0) {
		cout << "Вывод: точка № " << number << " является самой удалённой точкой от начала координат и имеет координаты (" << x << "; " << y << ").\n\n";
	}
	else {
		cout << "Вывод: (0; 0).\n\n";
	}


	delete[] a;
}


void program5() {
	int dot1, dot2, dot3, n, i;
	cout << "5. Программа получает на вход множество A из N точек (N>2), " <<
		"находит наибольший периметр трегольника, вершины которого принадлежат точкам заданного множества A, " <<
		"и сами эти точки (точки выводятся в том же порядке, в котором они вводились)\n";

	cout << "Задайте количество N точек: ";
	cin >> n;
	int* a = new int[n * 2 + 2]; /* "сплющил" двумерный массив, прибавил двойку для удобства */

	cout << "Задайте координаты точек (x и y - через пробел):\n";
	for (i = 1; i <= n; i++) {
		cout << "Координаты точки № " << i << ": ";
		cin >> a[i * 2] >> a[i * 2 + 1];
	}

	double maxPerimeter = 0;
	int number1 = 0;
	int number2 = 0;
	int number3 = 0;

	for (dot1 = 1;dot1 <= n;dot1++) {
		int dot1X = a[dot1 * 2];
		int dot1Y = a[dot1 * 2 + 1];
		for (dot2 = dot1 + 1; dot2 <= n; dot2++) {
			int dot2X = a[dot2 * 2];
			int dot2Y = a[dot2 * 2 + 1];
			for (dot3 = dot2 + 1; dot3 <= n; dot3++) {
				int dot3X = a[dot3 * 2];
				int dot3Y = a[dot3 * 2 + 1];

				double currentPerimeter = perimeter(dot1X, dot1Y, dot2X, dot2Y, dot3X, dot3Y);

				if (currentPerimeter > maxPerimeter) {

					maxPerimeter = currentPerimeter;

					number1 = dot1;
					number2 = dot2;
					number3 = dot3;

				}

			}
		}
	}


	cout << "Вывод: наибольший периметр из возможных треугольников составляет " << maxPerimeter << "; такой треугольник построен на точках №" <<
		number1 << ", №" << number2 << ", №" << number3 << ".\n\n";


	delete[] a;
}