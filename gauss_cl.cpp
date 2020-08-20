#include<iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main(){
	unsigned short int xsubi[3];
	double mu;
	double sigma;
	double x;
	double temp=0.0;
	int i;
	int j;
	double a[120000];
	for (i=0;i<120000;i++){
		a[i] = erand48(xsubi);
		temp = temp + a[i];
	}
	mu = temp/120001.0;
	temp = 0.0;
	for (i = 0; i<120000; i++){
		temp = temp + pow (a[i]-mu,2);
	}
	sigma = sqrt(temp/120001.0);
	ofstream outFile;
        outFile.open("data3.dat",ios::out);
	for (j = 0; j<9999; j++){
	for (i = 0, x = 0.0; i < 12; i++){
            x += a[12*j+i];
	}
            x -= 6.0;
            x = sigma*x + mu;
	    outFile<<x<<endl;
	}
	outFile.close();
	cout<<mu<<","<<sigma<<endl;
	getchar();
	return 0;
}


