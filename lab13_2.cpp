#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool x[][M]){
    cout << "------------------------------------------------------------------------" << endl;
    for(int i = 0; i < 30; i++){
        cout << "|";
        for(int j = 0; j < 70; j++){
            if(x[i][j] == 0) cout << " ";
            else cout << "*";
        }
        cout << "|";
        cout << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
}

void updateImage(bool a[N][M],int s,int x,int y){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if((sqrt(pow(i-x,2) + pow(j-y,2))) <= (s-1)) {a[i][j] = 1;}
        }
    }
}