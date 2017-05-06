#include <iostream>

using namespace std;

double mult(double x[], int i, int n, double numero) {
	double res = 1;
	for (int j = 0; j < n; j++) {
		if (i != j)
			res *= (numero - x[j]) / (x[i] - x[j]);
	}
	return res;
}

void Lagrange(double x[], double y[], double n, int numero) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += mult(x, i, n, numero) * y[i];
	}
	cout << "Valor aproximado: " << sum << endl;
}

int main() {
	double x[] = { 1, 4, 6 };
	double y[] = { 0, 1.386294, 1.791760 };

	Lagrange(x, y, sizeof(x)/sizeof(x[0]), 2);
}
