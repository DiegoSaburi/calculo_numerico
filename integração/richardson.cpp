#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

double richardson (double I1, double I2, double n1,double n2, double p){
	return I2 +pow(n1,p)*(I2-I1)/(pow(n2,p)-pow(n1,p));
}