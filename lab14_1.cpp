#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0, mean = 0, sd = 0, gm = 0, hm = 0, max = A[0], min = A[0];
    for(int i = 0; i < N; i++){
        sum += A[i];
        gm += log10(A[i]);
        hm += (1/A[i]);
        if (A[i] > max) max = A[i];
        if (min > A[i]) min = A[i];
    }
    mean = sum/N;
    gm /= N;
    gm = pow(10,gm);
    hm = N/hm;
    for(int i = 0; i < N; i++) sd += pow((A[i]-mean),2);
    sd = sqrt(sd/(N));
    B[0] = mean;
    B[1] = sd;
    B[2] = gm;
    B[3] = hm;
    B[4] = max;
    B[5] = min;
}