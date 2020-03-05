#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;
int fatorial (int i){
	if (i == 0)
		return 1;
	return i*fatorial(i-1);
}

double derivada (vector <double> fx, double ordem, double valor){

	int i, j, sum = 0;

	for (j = 0; j < ordem; j++){
		for (i = 0; i < fx.size()-1;i++){
			fx.at(i) = (i+1)*fx.at(i+1);
		}
		fx.pop_back();
	}

	for (i = 0 ; i < fx.size(); i++){
		sum += fx.at(i)*pow(valor,i);
	}

	return sum;
}

double erro (double x, double max, vector<double> yi,vector<double>xi){
	int i;
	double prod = derivada(yi,yi.size(),max)/fatorial(yi.size());

	for (i = 0 ; i < yi.size() ;i++ ){
		prod *= (x - xi.at(i));
	}

	return prod;
}

double lagrange(vector <double> xi, vector <double> yi,double x){
	
	int i,j;
	double sum = 0, prod = 1;
	
	for (i = 0; i < yi.size(); i++){

		prod = 1;

		for(j= 0; j < yi.size(); j ++){

			if (i != j){
				prod *= (x - xi.at(j))/(xi.at(i) - xi.at(j));
			}
		}
		cout << "L" << i << "(x) = " << prod << endl;
		cout << "y" << i << " = " << yi.at(i) << endl<<endl;
		sum += yi.at(i)*prod;
	}

	cout << endl << endl;
	
	return sum;
}


int main(){

	vector <double> xi = {0.0 , 0.5 , 1.0};
	vector <double> yi= {0.15 , 0.328 , 0.560};
	double x = 0.3;
	int tam = 5;

	cout<<"f("<<x<<") = "<< lagrange(xi,yi,x)<<endl;
	
}