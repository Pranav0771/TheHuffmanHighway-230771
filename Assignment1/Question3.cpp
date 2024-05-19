#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int examScores[10];
    for (int i = 0; i < 10; i++) { 
        cout << "Enter the examScores: "; 
        cin >> examScores[i]; 
    } 
    
    float avg=0;
    for (int i = 0; i < 10; i++){
        avg += examScores[i];
    }
    avg = avg/10;

    int max = examScores[0];
    int min = examScores[0];
    int count=0;
    int avgScorers=0;
    
    if (examScores[0] > avg)
            count++;

    for (int i = 1; i < 10; i++){
        if (examScores[i] > max) 
            max = examScores[i];
        if (examScores[i] < min) 
            min = examScores[i];
        if (examScores[i] > avg)
            count++;
        if (examScores[i] == avg)
            avgScorers++;
    }
    
    cout << "Average exam score : " << avg << endl;
    cout << "Highest exam score : " << max << endl;
    cout << "Lowest exam score : " << min << endl;
    cout << "Number of exam scores above the average : " << count << endl;
    cout << "Number of exam scores below the average : " << 10-avgScorers-count << endl;
    return 0;
}