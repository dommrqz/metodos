#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Variables para las coluciones de los sistemas, errores y
//calculo de discriminante.
double dr, ds, errorDer, errorDes, disc;

//Variables para las iteraciones, cuneta de raíces y el grado.
int iteraciones = 0, raicesR, raicesI, grado;

//Cálculo de discriminante.
double discriminante(double r, double s) {
	return pow(r, 2) + 4 * s;
}

//Regresa la primera raíz del polinomio con la fórmula
//general.
double raiz1(double r, double s, double disc) {
	grado--;
	return (r + sqrt(disc)) / 2;
}

//Regresa la segunda raíz del polinomio con la fórmula
//general.
double raiz2(double r, double s, double disc) {
	grado--;
	return (r - sqrt(disc)) / 2;
}

//Aplica la división sintética y regresa una arreglo con los nuevos
//coeficiente.
double* divSint(double *polinomio, double raiz) {
	double *res = new double[grado];
	res[0] = polinomio[0];
	for (int i = 0; i < grado + 1; i++) {
		res[i] = polinomio[i] + (raiz*res[i - 1]);
	}
	return res;
}

//Método de Bairstow: recibe un valor inicial de r y s, un arreglo con
//los coeficientes originales, el tamaño del arreglo y el error.
void Bairstow(double r, double s, double a[], int tamano, double error) {

	//Se declaran los arreglos para valores de b y c.
	double *b = new double[tamano];
	double *c = new double[tamano - 1];

	//Se define el grado de acuerdo al tamaño.
	grado = tamano - 1;

	//Se define el arreglo para guardar las raíces.
	double *raices = new double[grado];

	//Procedimiento para mientras el grado sea 3 o mayor.
	while (grado >= 2) {
		do {
			//Encontrar valores de b.
			for (int i = 0; i < tamano; i++) {
				if (i == 0) {
					b[i] = a[i];
				}
				else if (i == 1) {
					b[i] = a[i] + r*(b[0]);
				}
				else {
					b[i] = a[i] + r*(b[i - 1]) + s*(b[i - 2]);
				}
			}

			//Encontrar valores de c.
			for (int i = 0; i < tamano - 1; i++) {
				if (i == 0) {
					c[i] = b[i];
				}
				else if (i == 1) {
					c[i] = b[i] + r*(c[0]);
				}
				else {
					c[i] = b[i] + r*(c[i - 1]) + s*(c[i - 2]);
				}
			}

			//Aplicar la regla de Cramer para sacar los valores de 
			//Delta r y Delta s.
			dr = ((-b[tamano - 2] * c[tamano - 3]) - (c[tamano - 4] * -b[tamano - 1]))
				/ ((c[tamano - 3] * c[tamano - 3]) - (c[tamano - 4] * c[tamano - 2]));
			ds = ((c[tamano - 3] * -b[tamano - 1]) - (-b[tamano - 2] * c[tamano - 2]))
				/ ((c[tamano - 3] * c[tamano - 3]) - (c[tamano - 4] * c[tamano - 2]));

			//Nuevos valores de r y s.
			r = r + dr;
			s = s + ds;

			//Cálculo de los nuevos errores.
			errorDer = abs(dr / r); //ERROR PARCIAL2
			errorDes = abs(ds / s); //ERROR PARCIAL2

									//Se suman iteraciones
			iteraciones++;

			//Todo mientras los errores sean mayores al error deseado.
		} while (errorDer > error && errorDes > error); //ERROR PARCIAL2

														//Se busca el discriminante.
		disc = discriminante(r, s);

		//El discriminante es el número que indica si la ecuación tiene
		//2 valores reales, un valor real o dos valores imaginarios.

		//Si es menor a cero, las raíces son imaginarias.
		if (disc < 0) {
			cout << "Raices imaginarias: " << endl;
			cout << r / 2 << " + " << sqrt(abs(disc)) / 2 << "i" << endl;
			cout << r / 2 << " - " << sqrt(abs(disc)) / 2 << "i" << endl;
			raicesI += 2;
			grado -= 2;
		}
		//Si es cero, sólo hay una raíz para esos valores.
		else if (disc == 0) {
			raices[raicesR] = raiz1(r, s, disc);
			raicesR++;
			grado -= 2;
		}
		//Si es mayor a cero, hay dos raíces.
		else if (disc > 0) {
			raices[raicesR] = raiz1(r, s, disc);
			a = divSint(a, raices[raicesR]);
			raicesR++;
			tamano--;
			raices[raicesR] = raiz2(r, s, disc);
			a = divSint(a, raices[raicesR]);
			raicesR++;
			tamano--;

			cout << "Polinomio: " << endl;
			for (int i = 0; i < tamano; i++) {
				cout << a[i] << endl;
			}
		}
	}
	//Si es uno, se usa la última fórmula.
	if (grado == 1) {
		raices[raicesR] = -(b[1] / b[0]);
	}
	//Imprime las raíces.
	cout << "Las raices reales son: " << endl;
	for (int i = 0; i <= raicesR; i++) {
		cout << raices[i] << endl;
	}
	cout << "Iteraciones: " << iteraciones << endl;
}

int main() {
	//Usando un polinomio con los coeficientes ordenados de mayor
	//a menor grado, se guardan en el arreglo a.
	double a[] = { 0.7, -4, 6.2, -2 };
	//LLamada al método.
	Bairstow(-0.5, 0.5, a, sizeof(a) / sizeof(a[0]), 0.001); //ERROR PARCIAL2
	return 0;
}
