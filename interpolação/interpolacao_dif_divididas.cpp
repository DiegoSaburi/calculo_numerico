#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;

double inter_difDivididas(vector <double> xi,vector<double> yi,double x){
	int i, j,tam;
	double sum = yi.at(0), prod = 1;
	vector <double> delta_y0,aux_delta_y;

	delta_y0.push_back((yi.at(1) - yi.at(0))/(xi.at(1) - xi.at(0)));
	cout << "========== p/ k = 1: =========" << endl;
	for (i = 0; i < yi.size()-1 ; i++){
		aux_delta_y.push_back((yi.at(i+1) - yi.at(i))/(xi.at(i+1) - xi.at(i)));
		cout << "\tdY = " << i << " = " << aux_delta_y.at(i) << endl;
	}

	tam = aux_delta_y.size();

	for (i = 2 ; i < yi.size() ; i++ ){

		cout << "========= P/ k = " << i << " =========" << endl;

		for (j = 0; j < tam - 1; j++){
			aux_delta_y.at(j) = ((aux_delta_y.at(j+1) - aux_delta_y.at(j))/(xi.at(i+j) - xi.at(j)));
			cout << "\tdy" << j << " = " << aux_delta_y.at(j) << endl;

			if(j == 0)
				delta_y0.push_back(aux_delta_y.at(0));
		}

		tam--;
	}

	for (i = 0 ; i < delta_y0.size() ; i++){
		prod = 1;

		for (j = 0; j <= i;j++){
			prod *= x - xi.at(j);
		}
		sum += delta_y0.at(i)*prod;
	}

	return sum;
}

int main(){
	vector <double> xi = {0,0.2,0.3,0.5,0.6};
	vector <double> yi = {1.008,1.064,1.125,1.343,1.512};
	double x = 0.35;

	cout<<"f("<<x<<") = "<<inter_difDivididas(xi,yi,x)<<endl;
	
}