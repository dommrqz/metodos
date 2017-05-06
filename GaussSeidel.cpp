/Método de Gauss-Seidel
//Autor: Dominic Márquez

#include <iostream>
#include <cmath>

using namespace std;

double xVieja, yVieja, zVieja, wVieja, error1, error2, error3, error4;

int iteraciones;

double errorIterativo(double viejo, double nuevo) {
	return abs((nuevo - viejo) / nuevo) * 100; //ERROR PARCIAL2
}

void GaussSeidel(double x, double y, double z, double w,
	double ec1[], double ec2[], double ec3[], double ec4[],
	double error, int grado) {

	if (grado == 2) {
		do {
			xVieja = x;
			yVieja = y;
			x = (ec1[0] + (ec1[1] * y)) / ec1[2];
			y = (ec2[0] + (ec2[1] * x)) / ec2[2];
			error1 = errorIterativo(xVieja, x);
			error2 = errorIterativo(yVieja, y);
			iteraciones++;
		} while (error1 > error && error2 > error);

		cout << "Las raices son:" << endl << "x = " << x << endl
			<< "y = " << y << endl;
		cout << "Iteraciones: " << iteraciones << endl;
	}
	else if (grado == 3) {
		do {
			xVieja = x;
			yVieja = y;
			zVieja = z;
			x = (ec1[0] + (ec1[1] * y) + (ec1[2] * z)) / ec1[3];
			y = (ec2[0] + (ec2[1] * x) + (ec2[2] * z)) / ec2[3];
			z = (ec3[0] + (ec3[1] * x) + (ec3[2] * y)) / ec3[3];
			error1 = errorIterativo(xVieja, x);
			error2 = errorIterativo(yVieja, y);
			error3 = errorIterativo(zVieja, z);
			iteraciones++;
		} while (error1 > error && error2 > error && error3 > error);

		cout << "Las raices son:" << endl << "x = " << x << endl
			<< "y = " << y << endl
			<< "z = " << z << endl;
		cout << "Iteraciones: " << iteraciones << endl;
	}
	else if (grado == 4) {
		do {
			xVieja = x;
			yVieja = y;
			zVieja = z;
			wVieja = w;
			x = (ec1[0] + (ec1[1] * y) + (ec1[2] * z) + (ec1[3] * w)) / ec1[4];
			y = (ec2[0] + (ec2[1] * x) + (ec2[2] * z) + (ec2[3] * w)) / ec2[4];
			z = (ec3[0] + (ec3[1] * x) + (ec3[2] * y) + (ec3[3] * w)) / ec3[4];
			w = (ec4[0] + (ec4[1] * x) + (ec4[2] * y) + (ec4[3] * z)) / ec4[4];
			error1 = errorIterativo(xVieja, x);
			error2 = errorIterativo(yVieja, y);
			error3 = errorIterativo(zVieja, z);
			error4 = errorIterativo(wVieja, w);
			iteraciones++;
		} while (error1 > error && error2 > error && error3 > error && error4 > error);

		cout << "Las raices son:" << endl << "x = " << x << endl
			<< "y = " << y << endl
			<< "z = " << z << endl
			<< "w = " << w << endl;
		cout << "Iteraciones: " << iteraciones << endl;
	}
}

void Jacobi(double x, double y, double z, double w,
	double ec1[], double ec2[], double ec3[], double ec4[],
	double error, int grado) {

	if (grado == 2) {
		do {
			xVieja = x;
			yVieja = y;
			x = (ec1[0] + (ec1[1] * yVieja)) / ec1[2];
			y = (ec2[0] + (ec2[1] * xVieja)) / ec2[2];
			error1 = errorIterativo(xVieja, x);
			error2 = errorIterativo(yVieja, y);
			iteraciones++;
		} while (error1 > error && error2 > error);

		cout << "Las raices son:" << endl << "x = " << x << endl
			<< "y = " << y << endl;
		cout << "Iteraciones: " << iteraciones << endl;
	}
	else if (grado == 3) {
		do {
			xVieja = x;
			yVieja = y;
			zVieja = z;
			x = (ec1[0] + (ec1[1] * yVieja) + (ec1[2] * zVieja)) / ec1[3];
			y = (ec2[0] + (ec2[1] * xVieja) + (ec2[2] * zVieja)) / ec2[3];
			z = (ec3[0] + (ec3[1] * xVieja) + (ec3[2] * yVieja)) / ec3[3];
			error1 = errorIterativo(xVieja, x);
			error2 = errorIterativo(yVieja, y);
			error3 = errorIterativo(zVieja, z);
			iteraciones++;
		} while (error1 > error && error2 > error && error3 > error);

		cout << "Las raices son:" << endl << "x = " << x << endl
			<< "y = " << y << endl
			<< "z = " << z << endl;
		cout << "Iteraciones: " << iteraciones << endl;
	}
	else if (grado == 4) {
		do {
			xVieja = x;
			yVieja = y;
			zVieja = z;
			wVieja = w;
			x = (ec1[0] + (ec1[1] * yVieja) + (ec1[2] * zVieja) + (ec1[3] * wVieja)) / ec1[4];
			y = (ec2[0] + (ec2[1] * xVieja) + (ec2[2] * zVieja) + (ec2[3] * wVieja)) / ec2[4];
			z = (ec3[0] + (ec3[1] * xVieja) + (ec3[2] * yVieja) + (ec3[3] * wVieja)) / ec3[4];
			w = (ec4[0] + (ec4[1] * xVieja) + (ec4[2] * yVieja) + (ec4[3] * zVieja)) / ec4[4];
			error1 = errorIterativo(xVieja, x);
			error2 = errorIterativo(yVieja, y);
			error3 = errorIterativo(zVieja, z);
			error4 = errorIterativo(wVieja, w);
			iteraciones++;
		} while (error1 > error && error2 > error && error3 > error && error4 > error);

		cout << "Las raices son:" << endl << "x = " << x << endl
			<< "y = " << y << endl
			<< "z = " << z << endl
			<< "w = " << w << endl;
		cout << "Iteraciones: " << iteraciones << endl;
	}	
}

int main() {

	//Caso de falla:
	//double ec1[] = { 286,-13,11 };
	//double ec2[] = { 99,-11,-9 };

	//Caso de éxito
	//double ec1[] = { 99,9,11 };
	//double ec2[] = { 286,-11,13 };

	/* Gauss-Seidel y Jacobi de dos incógnitas
	cout << "Gauss-Seidel: " << endl;
	GaussSeidel(0, 0, 0, 0, ec1, ec2, NULL, NULL, 0.00001, 2);
	cout << endl << "Jacobi: " << endl;
	Jacobi(0, 0, 0, 0, ec1, ec2, NULL, NULL, 0.00001, 2);
	*/

	//double ec1[] = { 7, 1, -1, 2 };
	//double ec2[] = { 6, -1, 1, 2 };
	//double ec3[] = { 12, -1, -1, 1 };

	/* Gauss-Seidel y Jacobi de tres incógnitas
	double ec1[] = { 7.85,0.1,0.2,3};
	double ec2[] = { -19.3,-0.1,0.3,7 };
	double ec3[] = { 71.4,-0.3,0.2,10 };
	cout << "Gauss-Seidel: " << endl;
	GaussSeidel(0, 0, 0, 0, ec1, ec2, ec3, NULL, 0.00001, 3);
	cout << endl << "Jacobi: " << endl;
	Jacobi(0, 0, 0, 0, ec1, ec2, ec3, NULL, 0.00001, 3);
	*/
	
	/* Gauss-Seidel y Jacobi de cuatro incógnitas
	double ec1[] = { 6,1,-2,0,10 };
	double ec2[] = { 25,1,1,-3,11 };
	double ec3[] = { -11,-2,1,1,10 };
	double ec4[] = { 15,0,-3,2,8 };
	cout << "Gauss-Seidel: " << endl;
	GaussSeidel(0, 0, 0, 0, ec1, ec2, ec3, ec4, 0.0000000001, 4);
	cout << endl << "Jacobi: " << endl;
	Jacobi(0, 0, 0, 0, ec1, ec2, ec3, ec4, 0.0000000001, 4);
	*/

	double ec1[] = { 3, 1, 1, 6 };
	double ec2[] = { 40, -6, -1, 9 };
	double ec3[] = { 50, 3, -1, -12 };
	GaussSeidel(0, 0, 0, 0, ec1, ec2, ec3, NULL, 5, 3); //ERROR PARCIAL2

	return 0;
}
