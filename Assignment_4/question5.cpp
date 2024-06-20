#include <iostream>
#include <string>
using namespace std;

string smallestRotation(string S) {

    int l = S.length();
    string C = S + S;
    
    int m = 0;
    
    for (int i = 1; i < l; ++i) {
        int j = 0;
        while (j < l && C[m + j] == C[i + j]) {
            j++;
        }
        if (j >= l) {
            continue;
        }
        if (C[m + j] > C[i + j]) {
            m = i;
        }
    }
    return C.substr(m, l);
}

int main() {
    string S;
    getline (cin, S);
    string smallest_rotation = smallestRotation(S);
    cout << smallest_rotation << endl;
    return 0;
}