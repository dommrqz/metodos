//Método de bisección
//Autor: Dominic Márquez

#include <iostream>
#include <cmath>

//#define Y pow(x, 3) - 4*pow(x,2) + x + 6

using namespace std;

//Variables que representan los límites, punto
//medio y error.
double lim0, lim1, xm, error;

//Variable que representa las iteraciones.
int it=1;

//Método para obtener el error iterativo.
double errorAbsoluto(double nuevo, double viejo) {
	return abs((nuevo - viejo)/nuevo)*100;
}

//Método que representa la función.
double funcion(double x) {
	//return (667.38/x)*(1-exp(-0.146843*x))-40;
	return pow(x, 4) + 3 * pow(x, 3) - 2;
}

//Método de bisección, recibe los valores extremos del intervalo
//y el grado de exactitud para el criterio de detención.
void Biseccion(double x0, double x1, double exactitud) {

	lim0 = funcion(x0);

	lim1 = funcion(x1);
	
	//Verifica si existe una raíz en el intervalo.
	if (lim0 * lim1 < 0) {

		//Obtiene el primer valor medio.
		xm = (x0 + x1) / 2;
		lim1 = funcion(xm);

		//Mientras el error sea mayor que la exactitud 
		//deseada.
		do {
			//Se verifica si la raíz está a la derecha o
			//izquierda del punto medio. Se calcula un
			//nuevo punto medio y un nuevo error.

			if (lim0 * lim1 < 0) {
				x1 = xm;
				xm = (x0 + x1) / 2;
				lim1 = funcion(xm);
				error = errorAbsoluto(xm, x1);
				it++;
			}

			if (lim0 * lim1 > 0) {
				x0 = xm;
				xm = (x0 + x1) / 2;
				lim1 = funcion(xm);
				error = errorAbsoluto(xm, x0);
				it++;
			}

			//Todo mientras el error sea mayor al que
			//se desea llegar.
		} while (error > exactitud);
		cout << "La raiz es: " << xm << endl;
		cout << "Iteraciones: " << it;
	}
	//Si no existe raíz en el intervalo se imprime 
	//un mensaje.
	else if (lim0 == 0) {
		cout << "La raiz es: " << lim0 << endl;
		cout << "Iteraciones: " << it;
	}
	else if (lim1 == 0) {
		cout << "La raiz es: " << lim1 << endl;
		cout << "Iteraciones: " << it;
	}
	else {
		cout << "La raiz no esta en el intervalo.";
	}
	//Regresa el último punto medio.
	
}

int main() {
	
	Biseccion(0, 1, 0.0001);	

	return 0;

}
