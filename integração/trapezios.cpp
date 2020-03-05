#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

double trapezios (double h, std::vector <double> yi){
	int i;
	double sum = h*(yi.at(0) + yi.at(yi.size()-1))/2;

	for (i = 1 ; i < yi.size()-1 ; i++){
		sum += h*(yi.at(i));
	}

	return sum;

}

double erro_trapezios(double h, double n, double max){
	return -pow(h,3)* max/(12*n);
}

int main (){
	double a = 3.0, b = 3.6;
	double n = 6;
	std::cout << "h=" << (b-a)/n << std::endl;
	std::vector<double> yi = {0.333, 0.322581, 0.3125, 0.30303, 0.294118, 0.285714, 0.277778};

	std::cout << "====================== trapezios ==========================" << std::endl;
	std::cout << "F[" << a << "," << b << "] = " << trapezios((b-a)/n,yi) << std::endl;
	std::cout << "Erro = " << erro_trapezios((b-a),n,0.33) << std::endl;
	std::cout << "============================================================" << std::endl;
}