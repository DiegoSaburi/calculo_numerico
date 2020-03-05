#include <iostream>
#include <cmath>
#include <iomanip>

float function (float x){
	// Aqui vc deverá colocar a função a ser utilizada
	return  x*x*x-9.0*x+3.0;
}

float secante (float x0, float x1){
	return x1-function(x1)*(x1-x0)/(function(x1)-function(x0));
}

float metodosecante (float x0, float x1, float erro){

	std::cout << "================== METODO DA SECANTE ======================="<<std::endl;

	float x2 = secante(x0,x1);
	int k = 0;

	while (fabs(x2-x1) >= erro && fabs(x2) >= erro)
	{
		std::cout << "X[" << k << "] = " << x1 << std::endl;
		std::cout << "X[" << k+1 << "] = " << x2 << std::endl;
		std::cout << "Erro = " << fabs(x2 - x1) << std::endl;
		
		x0 = x1;
		x1 = x2;
		x2 = secante(x0,x1);

		k++;
	}
	std::cout << "X[" << k << "] = " << x1 << std::endl;
	std::cout << "X[" << k +1<< "] = " << x2 << std::endl;
	std::cout << "Erro = " << fabs(x2 - x1) << std::endl;

	std::cout << "=========================================================="<<std::endl;
	return x2;
}

int main (){
	metodosecante(0.0,1.0,0.001);
}
