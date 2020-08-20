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
	unsigned short xsubi[3];
        int i;
        int j;
        double a[200000];
        double x1=0.0;
	double x2=0.0;
        double temp= 0.0;
        for(i=0;i<100000;i++){
               x1 = erand48(xsubi);
               x2 = erand48(xsubi);
	       temp = temp + x1 + x2;
	       a[i]=x1;
	       a[100000+i]=x2;
	}
	double mu = temp/200000.0;
	temp=0.0;
	for(j=0;j<200000;j++){
		temp = temp+ pow(a[j]-mu,2);
	}
	double sigma=sqrt(temp/200000.0);
	double y;
	ofstream outFile;
	outFile.open("data2.dat",ios::out);
	for(i = 0; i<100000; i++){
	       y = sqrt(-2.0*log(a[i]))*cos(2.0*M_PI*a[100000+i]);
               y = sigma*y + mu; 
	       outFile<<y<<endl;
	}
	outFile.close();
	cout<<mu<<","<<sigma<<endl;
	getchar();
	return 0;
}
