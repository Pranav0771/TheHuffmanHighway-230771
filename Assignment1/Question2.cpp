#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error: Division by zero\n";
        return NAN;
    }
}

double mod(double a, double b) {
    return fmod(a, b);
}

double remainder(double a, double b) {
    return remainder(a, b);
}

double trigFunction(string func, double x) {
    if (func == "sin") return sin(x);
    if (func == "cos") return cos(x);
    if (func == "tan") return tan(x);
    if (func == "sininverse") return asin(x);
    if (func == "cosinverse") return acos(x);
    if (func == "taninverse") return atan(x);
    else {
        cout << "Error: Unsupported trigonometric function\n";
        return NAN;
    }
}

double exponentialFunction(string func, double x) {
    if (func == "ln") return log(x);
    if (func == "exp") return exp(x);
    else {
        cout << "Error: Unsupported exponential function\n";
        return NAN;
    }
}

int main() {
    
    string operators;
    string values;
    
    cout << "Enter operators separated by spaces: ";
    getline(cin, operators);
    
    cout << "Enter values separated by spaces: ";
    getline(cin, values);
    
    
    return 0;
}
