//Método de la secante
//Autor: Dominic Márquez

#include <iostream>
#include <cmath>

using namespace std;

double x0, x1, xi, error;

//Variable que guarda las iteraciones.
int iteraciones = 0;

//Método que representa la evaluación de la función.
double funcion(double x) {
	return pow(x, 3) + 2 * pow(x, 2) + 10 * x - 20;
}

//Función que calcula el error
double errorAbsoluto(double viejo, double nuevo) {
	return abs((nuevo - viejo) / nuevo) * 100;
}

//Método de la secante: acepta dos valores iniciales y un error.
double Secante(double x0, double x1, double exactitud) {

	do {
		//Calcula el nuevo punto y el error.
		xi = x1 - ((funcion(x1)*(x0-x1)) / (funcion(x0)-funcion(x1)));
		error = errorAbsoluto(x1, xi);

		x0 = x1;
		x1 = xi;

		//Se suma una iteración.
		iteraciones++;

		//Todo lo hace mientras el error deseado no haya sido
		//alcanzado todavía.
	} while (error > exactitud); //ERROR PARCIAL2

	//Regresa el último valor calculado.
	return x1;
}

int main() {

	double res = Secante(0, 1, 0.1);
	cout << "La raiz es: " << res << "\n";
	cout << "Iteraciones: " << iteraciones;
	return 0;
}
