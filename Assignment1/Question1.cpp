#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int k;
        for (k=1; k<=(n+1)/2; k++){
            for(int j=1; j<=i; j++){
                cout << j;
            }
            if(k==(n+1)/2 && n!=2*k)
            break;
            for(int j=i; j<n; j++){
                cout << "  ";
            }
            for(int j=i; j>=1; j--){
                cout << j;
            }
        }
        cout << endl;
    }
    return 0;
}