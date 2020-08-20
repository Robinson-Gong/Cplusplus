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
	double a[100000];
	double r=0.0;
	double temp= 0.0;
	for(i=0;i<100000;i++){
		r=2.0*erand48(xsubi)-1.0;
	        a[i]=r;
		temp=temp+r;
	}
        double mu = temp/100001.0;
	temp=0.0;
	for(j=0;j<100000;j++){
		temp=temp+pow(a[j]-mu,2);
	}
	double sigma = sqrt(temp/100001.0);
	double    t, z;
        int      num_iter;
        static  double  alpha, sqrt2, erf1, logsqrtpi;
        alpha = 2.0/sqrt(M_PI);
        sqrt2 = sqrt(2.0);
        logsqrtpi = 0.5*log(M_PI);
        erf1 = erf(1.0);
	double b[100000];
        for(int k=0;k<100000;k++){
		t=a[k];
	if (t> erf1)
            z =  sqrt(-logsqrtpi - log(1.0-t));
        else if (t < -erf1)
            z = -sqrt(-logsqrtpi - log(1.0+t));
        else
            z = t/alpha;

        for (num_iter=0; (num_iter<10) && (fabs(t-erf(z))>10e-14); ++num_iter)
        {
            z += (t - erf(z))/(alpha*exp(-z*z));
        }
        b[k]= sqrt2*sigma*z+mu;
	}
	ofstream outFile;
	outFile.open("data.dat",ios::out);
	for(int l=0;l<100000;l++){
		outFile<<b[l]<<endl;
	}
	outFile.close();
	cout<<mu<<","<<sigma<<endl;
	getchar();
        return 0;
}

