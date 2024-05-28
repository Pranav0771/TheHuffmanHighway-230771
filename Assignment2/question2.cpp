#include<iostream>
#include<vector>
using namespace std; 

class Matrix {
private:  
    int r,c;
    vector<vector<double>> element;

public:
    Matrix(int a, int b) : element(a, vector<double>(b, 0)) {
        r=a;
        c=b;
    }

    void input(){
        cout << "Enter elements of mat: ";
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){    
                cin >> element[i][j];
            }
        }
    }

    Matrix operator*(Matrix& other) {

        Matrix prod(r, other.c);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < other.c; j++) {
                for (int k = 0; k < c; k++) {
                    prod.element[i][j] += element[i][k] * other.element[k][j];
                }
            }
        }
        return prod;
    }

    void print(){
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                cout << element[i][j] << " ";
            }
            cout<< endl;
        }
    }
};


int main(){
    int m,n;
    cout<<"Enter the no.: ";
    cin>>m;
    cout<<"Enter the no.: ";
    cin>>n;
    Matrix matA(m,n), matB(n,m), matC(m,m);
    matA.input();
    matB.input();
    matC = matA * matB;
    matA.print();
    cout<<endl;
    matB.print();
    cout<<endl;
    matC.print();
    return 0;
}