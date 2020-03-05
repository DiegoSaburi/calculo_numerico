#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

double simpson_1 (double h, std::vector<double>yi){

	int i;
	double sum = h*(yi.at(0) + yi.at(yi.size()-1))/3;

	for (i = 1; i < yi.size()-1 ; i += 2){
		sum += 4*h* yi.at(i)/3;
	}
	for (i = 2 ; i < yi.size()-1 ; i += 2){
		sum += 2*h*yi.at(i)/3;
	}

	return sum;

}

double erro_simpson (double h,double n, double max){
	return pow(h,5)*max/(180*pow(n,4));
}

int main (){
	double a = 3.0, b = 3.6;
	double n = 6;
	std::cout << "h=" << (b-a)/n << std::endl;
	std::vector<double> yi = {0.333, 0.322581, 0.3125, 0.30303, 0.294118, 0.285714, 0.277778};


	std::cout << "====================== simpson ===============================" << std::endl;
	std::cout << "-> primeira regra de simpson:" << std::endl;
	std::cout << "F[" << a << "," << b << "] = " << simpson_1((b-a)/n,yi) << std::endl;
	std::cout << "Erro = " << erro_simpson((b-a),n,0.33) << std::endl;
	std::cout << "============================================================" << std::endl;
}