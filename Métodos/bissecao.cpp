#include <iostream>
#include <cmath>
#include <iomanip>

float function (float x){
	// Aqui vc deverá colocar a função a ser utilizada
	return  x*x*x-9.0*x+3.0;
}

float bissecao(float a, float b, float erro){
	std::cout << "=============== METODO DA BISSECAO ====================="<<std::endl;
	float x, fx, fa,k = 0;

	do
	{
		x = (a+b)/2;
		std::cout << "X["<<k<<"] = "<< x << std::endl;
		std::cout << "Erro :" << fabs(b-a) << std::endl;

		fx = function(x);
		fa = function(a);

		if (fa*fx > 0)
			a = x;
		else
			b = x;
		k++;		

	}while (fabs(b-a) >= erro);

	std::cout << "=========================================================="<<std::endl;

	return x;
}

int main (){
	bissecao(0.0,1.0,0.001);
}