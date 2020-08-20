#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;
int main(){
        unsigned short int xsubi[3];
        double x;
        int j;
        int i;
        double y;
        double mu;
        double sigma;
        double temp = 0.0;
        cout<< " please enter the initial price of the stock" <<endl;
        cin>>y;
	cout<< " please enter the mean " <<endl;
	cin>>mu;
	cout<< " please enter the sigma" <<endl;
	cin>>sigma;
        ofstream outFile;
        ofstream outFile2;
        outFile.open("data.dat",ios::out);
        outFile2.open("data2.dat",ios::out);
        double a[120000];
        for (i=0;i<120000;i++){
                a[i] = erand48(xsubi);
        }
        for (j = 0; j<9999; j++){
        for (i = 0, x = 0.0; i < 12; i++){
            x += a[12*j+i];
        }
            x -= 6.0;
            x = sigma*x + mu;
            outFile<<i<<" "<<x<<endl;
            y = y * (1+x);
            outFile2<<i<<" "<<y<<endl;
	}
        outFile.close();
        outFile2.close();
        return 0;
}

                           
