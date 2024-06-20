#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;    
    Node(int v) : value(v), next(nullptr), prev(nullptr){}
};

bool isPalindrome(Node* head) {
    
    if (head->next == nullptr) {
        return true;
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    Node* front = head;
    Node* back = tail;
    while (front != back && back->next != front) {
        if (front->value != back->value) {
            return false;
        }
        front = front->next;
        back = back->prev;
    }
    return true;
}

int main(){
    
    int n;
    cout << "Enter number of integer inputs: ";
    cin >> n;
    int arr[n];
    cout << "Enter numbers separated by space: ";
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    if(isPalindrome(head)){
        cout << "Linked list is a palindrome";
    }
    else{
        cout << "Linked list isn't a palindrome";
    }
}