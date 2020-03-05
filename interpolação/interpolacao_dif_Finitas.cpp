#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;

int f(int i){

	if(i == 0)
		return 1;
	else
		return i*f(i-1);	
}

double inter_difFinitas(vector <double> xi,vector <double> yi,double x,double h){
	int i, j, tam, z = (x - xi.at(0))/h;
	double sum = yi.at(0), prod = 1;
	vector <double> delta_y0,aux_delta_y;

	delta_y0.push_back(yi.at(1) - yi.at(0));

	cout << "========== p/ k = 1: =========" << endl;

	for (i = 0; i < yi.size() -1 ; i++){

		aux_delta_y.push_back(yi.at(i+1) - yi.at(i));
		cout << "\tdY = " << i << " = " << aux_delta_y.at(i) << endl;
	}

	tam = aux_delta_y.size();

	for (i = 2 ; i < yi.size() ; i++ ){

		cout << "========= P/ k = " << i << " =========" << endl;

		for (j = 0; j < tam - 1; j++){
			aux_delta_y.at(j) = (aux_delta_y.at(j+1) - aux_delta_y.at(j));
			cout << "\tdy" << j << " = " << aux_delta_y.at(j) << endl;

			if(j == 0)
				delta_y0.push_back(aux_delta_y.at(0));
		}

		tam--;
	}

	for (i = 0 ; i < delta_y0.size() ; i++){
		prod = 1;

		for (j = 0; j <= i;j++){
			prod *= z - j;
		}

		sum += delta_y0.at(i)*prod/f(i+1);
	}

	return sum;
}

int main(){
	vector <double> xi = {3.5 , 4.0 , 4.5 , 5.0 , 5.5};
	vector <double> yi = {9.82, 10.91 , 12.05 , 13.14 , 16.19};
	double x = 6.0;
	double h = 0.5;
	int tam = 4;
	
	cout<<"f("<<x<<") = "<<inter_difFinitas(xi,yi,x,h)<<endl;

}