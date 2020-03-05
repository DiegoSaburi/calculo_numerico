#include <iostream>
#include <cmath>
#include <iomanip>

float function (float x){
	// Aqui vc deverá colocar a função a ser utilizada
	return  x*x*x-9.0*x+3.0;
}

float newton (float x){
	return x-(function(x)/(3.0*powf(x,2.0)-9.0));
}

float metodonewton (float x0, float erro){
	std::cout << "================== METODO DE NEWTON ======================="<<std::endl;
	float x1 = newton(x0);
	int k = 0;

	while (fabs(x0-x1) >= erro && function(x0)>= erro)
	{
		std::cout << "X[" << k << "] = " << x0 << std::endl;
		std::cout << "X[" << k+1 << "] = " << x1 << std::endl;
		std::cout << "Erro = " << fabs(x0 - x1) << std::endl;

		x0 = x1;
		x1 = newton(x0);

		k++;
	}

	std::cout << "X[" << k << "] = " << x0 << std::endl;
	std::cout << "X[" << k+1 << "] = " << x1 << std::endl;
	std::cout << "Erro = " << fabs(x0 - x1) << std::endl;

	std::cout << "=========================================================="<<std::endl;
	return x1;
}

int main (){
	metodonewton(0.3,0.001);
}