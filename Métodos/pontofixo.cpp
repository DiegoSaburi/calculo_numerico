#include <iostream>
#include <cmath>
#include <iomanip>

float function (float x){
	// Aqui vc deverá colocar a função a ser utilizada
	return  x*x*x-9.0*x+3.0;
}

float qx (float x){
	// Aqui vc deverá colocar a função q(x) referente 
	// a função q vc usará em "function" para o método
	// do ponto fixo

	return x*x*x/9.0+1.0/3.0;
}

float pontofixo(float x0, float erro){

	std::cout << "=============== METODO DO PONTO FIXO ====================="<<std::endl;

	float x1 = qx(x0);
	int k = 0;
	while (fabs(x0-x1) >= erro && fabs(function(x0)) >= erro )
	{	
		std::cout << "X[" << k <<"] = " << x0 << std::endl;
		std::cout << "X[" << k+1<<"] = " << x1 << std::endl;
		std::cout << "Erro: " << fabs(x0-x1) << std::endl;

		x0 = x1;
		x1 = qx(x1);

		k++;
	}

	std::cout << "X[" << k <<"] = " << x0 << std::endl;
	std::cout << "X[" << k+1<<"] = " << x1 << std::endl;
	std::cout << "Erro: " << fabs(x0-x1) << std::endl;
		
	std::cout << "=========================================================="<<std::endl;

	return x1;
}

int main (){
	pontofixo(0.5,0.0005);
}