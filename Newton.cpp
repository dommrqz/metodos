#include <iostream>
#include <cmath>

using namespace std;

double diferenciaDivFinita(int i0, int i1, double x[], double y[]) {

	if (i1 - i0 == 0) {
		return y[i0];
	}
	else {
		return (diferenciaDivFinita(i0 + 1, i1, x, y) - 
			diferenciaDivFinita(i0, i1 - 1, x, y)) / (x[i1] - x[i0]);
	}
}

void Newton(double x[], double y[], int tamaño, double valor) {

	double aproximacion = 0;
	double *divisiones = new double[tamaño];

	cout << "Coeficientes: " << endl;

	for (int i = 0; i < tamaño; i++) {
		divisiones[i] = diferenciaDivFinita(0, i, x, y);
		cout << divisiones[i] << endl;
	}


	for (int i = 0; i < tamaño; i++) {
		double aprox = divisiones[i];

		for (int j = 0; j < i; j++) {
			aprox *= (valor - x[j]);
		}

		aproximacion += aprox;
	}

	cout << "Valor aproximado: " << aproximacion;
}

int main() {

	double x[] = { 2, 3, 4 };
	double y[] = { 0.5, 0.3333, 0.25 };

	Newton(x, y, sizeof(x)/sizeof(x[0]), 2);

}
