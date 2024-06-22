#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int merge(vector<int>& file_sizes) {
    
    priority_queue<int, vector<int>, greater<int>> minHeap(file_sizes.begin(), file_sizes.end());

    int cost = 0;
    while (minHeap.size()>1){
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        int pairCost = first + second;
        cost += pairCost;

        minHeap.push(pairCost);
    }
    return cost;
}

int main() {
    int n;
    vector<int> file_sizes;
    cout << "Enter the number of files: ";
    cin >> n;
    cout << "Enter the array of file sizes: ";
    for (int i=0; i<n; i++){
        int input;
        cin >> input ;
        file_sizes.push_back(input);
    }
    cout << "Minimum Cost = " << merge(file_sizes);
    return 0;
}
