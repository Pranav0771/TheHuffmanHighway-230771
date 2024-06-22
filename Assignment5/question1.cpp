#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout << "Enter number of Trains coming at the station in a day: ";
    cin >> n;

    vector<int> arrv;
    cout << "Enter arrival timings of each train: ";
    for(int i=1; i<n; i++){
        int input;
        cin >> input;
        arrv.push_back(input);
    }

    vector<int> dept;
    cout << "Enter departure timings of each train: ";
    for(int i=1; i<n; i++){
        int input;
        cin >> input;
        dept.push_back(input);
    }

    int min_pf = 0;
    for(int i=1; i<n; i++){
        int pf = 0;
        for(int j=0; j<i; j++){
            if(arrv[i]<dept[j]){
                pf++;
            }
            if(min_pf < pf){
                min_pf = pf;
            }
        }
    }
    cout << min_pf + 1;
}
