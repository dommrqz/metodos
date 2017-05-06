// Regresión lineal
// Autor: Dominic Márquez

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

// Lista de las variables que se usarán.
double sum, sumx, sumx2, sumy, sumxy, promx, promy, a0, a1, sr, st, desvest, s, r, alfa, beta;

// Método que hace una sumatoria.
double sumatoria(double valores[], int modo, int n) {
	sum = 0;
	// Sumatoria normal de los valores del arreglo.
	if (modo == 0) {
		for (int i = 0; i < n; i++) {
			sum += valores[i];
		}
	}
	// Sumatoria de los cuadrados de los valores del arreglo.
	else if (modo == 1) {
		for (int i = 0; i < n; i++) {
			sum += pow(valores[i], 2);
		}
	}
	return sum;
}

// Método que efectúa la sumatoria de los productos de los valores 
// de ambos arreglos.
double sumatoriaMult(double x[], double y[], int n) {
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (x[i] * y[i]);
	}
	return sum;
}
 
double getSt(double y[], double promy, int n) {
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pow((y[i] - promy), 2);
	}
	return sum;
}

double getSr(double x[], double y[], double a0, double a1, int n) {
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pow((y[i] - a0 - a1*x[i]), 2);
	}
	return sum;
}

// Método de regresión lineal. Recibe dos arreglos que
// representan los valores de x y y, el número de 
// datos.
void regresionLineal(double x[], double y[], int n, int modo) {

	// Se sacan los valores necesarios para la fórmula de
	// la regresión lineal.
	sumx = sumatoria(x, 0, n);
	sumy = sumatoria(y, 0, n);
	sumx2 = sumatoria(x, 1, n);
	sumxy = sumatoriaMult(x, y, n);
	promx = sumx / n;
	promy = sumy / n;

	// Se aplican las fórmulas de a1 y a0 con los datos
	// obtenidos previamente.
	a1 = ((n*sumxy) - (sumx*sumy)) / ((n*sumx2) - pow(sumx, 2));
	a0 = promy - a1*promx;

	if (modo == 0) {
		alfa = exp(a0);
		beta = a1;
		cout << "y = " << alfa << " * e^(" << beta << "x)\n";
	}
	else if (modo == 1) {
		alfa = pow(10, a0);
		beta = a1;
		cout << "y = " << alfa << " * x^(" << beta << ")\n";
	}else if (modo == 2) {
		// Imprime la ecuación de la recta ajustada.
		cout << "La recta es: y = " << a0 << " + " << a1 << "x" << endl;
	}
	
	// Obtiene sr y st para la cuantificación del error.
	sr = getSr(x, y, a0, a1, n);
	st = getSt(y, promy, n);

	// Obtiene la desviación estándar y el error estándar de la
	// estimación.
	desvest = sqrt(st / (n - 1));
	s = sqrt(sr / (n - 2));

	// Determina si la desviación mejoro, y por tanto el ajuste
	// fue bueno.
	cout << "Desviacion estandar: " << desvest << endl;
	cout << "Error estandar de la estimacion: " << s << endl;

	// Obtiene el coeficiente de determinación y el coeficiente
	// de correlación.
	r = (st - sr) / st;
	cout << "Coeficiente de determinacion: " << r << endl;
	cout << "Coeficiente de correlacion: " << sqrt(r) << endl;


}

void linealizacion(double x[], double y[], int n, int modo) {

	double *logx = new double[n];
	double *logy = new double[n];

	//Modelo exponencial: aplica logaritmo natural a los valores del
	//eje de las ordenadas.
	if (modo == 0) {
		for (int i = 0; i < n; i++) {
			logy[i] = log(y[i]);
		}
		regresionLineal(x, logy, n, modo);
	}else if (modo == 1) {
	for (int i = 0; i < n; i++) {
		logx[i] = log10(x[i]);
		logy[i] = log10(y[i]);
	}
	regresionLineal(logx, logy, n, modo);
	}
	else if(modo == 2) {
		regresionLineal(x, y, n, modo);
	}
}

int main() {
	// Arreglos de valores de x y y.

	double x[] = { 0.75, 2, 3, 4, 6, 8, 8.5 };
	double y[] = { 1.2, 1.95, 2, 2.4, 2.4, 2.7, 2.6 };

	linealizacion(x, y, (sizeof(x) / sizeof(x[0])), 1);

	//0 para exponencial, 1 para potencial, 2 para lineal

	return 0;
}
