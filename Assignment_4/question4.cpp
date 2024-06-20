#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;    
    Node(int v) : value(v), next(nullptr), prev(nullptr){}
};

int main(){
    int n;
    cout << "Enter number of integer inputs: ";
    cin >> n;
    int k;
    cout << "Enter number of rotations: ";
    cin >> k;
    int arr[n];
    cout << "Enter numbers separated by space: ";
    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for(int i = 1; i < n; i++){
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        if(i==n-1){
            current->next = head;
            head->prev = current;
        }
    }

    Node* temp = head;
    for(int i = 0; i<n-k ; i++){
        temp = temp->next;
    }
    for(int i = 0; i<n ; i++){
        cout << temp->value << " ";
        temp = temp->next;
    }
}