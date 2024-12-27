#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}


void stat(const double a[],int N,double c[]){
    double sum = 0, Gsum = 1, Hsum = 0, max = a[0], min = a[0];
    int i = 0;
    while(i < N){
        sum += a[i];
        Gsum *= a[i];
        Hsum += 1/a[i];
        if(max < a[i]) max = a[i];
        if(min > a[i]) min = a[i];
        i ++;
    }
    c[0] = sum/N;
    c[2] = pow(Gsum, 1.0/N);
    c[3] = N/Hsum;
    c[4] = max;
    c[5] = min;
    
    double sum2 = 0;
    int j = 0;
    while(j < N){
        sum2 += pow(a[j] - c[0], 2);
        j ++;
    }
    c[1] = sqrt(sum2/N);
    
    
}