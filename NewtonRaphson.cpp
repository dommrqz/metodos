/Método de Newton-Raphson
//Autor: Dominic Márquez

#include <iostream>
#include <cmath>

using namespace std;

//Variables que representarán el valor evualuado
//en la función, la evaluación en la derivada, el valor del
//cruce de la tangente y el error porcentual
double fx, fdx, xn, error;

//Variable que guarda las iteraciones.
int iteraciones = 0;

//Método que representa la evaluación de la función.
double funcion(double x) {
	return pow(x,3) - 2;
}

//Método que representa la evaluación de la derivada.
double derivada(double x) {
	return 3 * pow(x, 2);
}

//Método para obtener el error iterativo.
double errorAbsoluto(double nuevo, double viejo) {
	return abs((nuevo - viejo)/nuevo)*100;
}

//Método de Newton-Raphson, recibe dos valores, el punto
//inicial para el método y la exactitud para el criterio de
//detención.
double NewtonRaphson(double x, double exactitud) {

	do {
		//Evalúa x en la función y su
		//derivada.
		fx = funcion(x);
		fdx = derivada(x);

		//Calcula el nuevo punto y el error.
		xn = x - (fx / fdx);
		error = errorAbsoluto(xn, x);

		//Se reajustan las variables para que se repita el
		//proceso con xn.
		x = xn;

		//Se suma una iteración.
		iteraciones++;

		//Todo lo hace mientras el error deseado no haya sido
		//alcanzado todavía.
	} while (error > exactitud);

	//Regresa el último valor calculado.
	return x;
}

int main() {

	double res = NewtonRaphson(10, 0.00001);
	cout << "La raiz es: " << res << "\n";
	cout << "Iteraciones: " << iteraciones;

	return 0;
}
