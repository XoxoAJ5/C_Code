#include <iostream>
#include <cmath>

using namespace std;

void second() {
    cout << "does this work?" << endl;
    string input;
    cin >> input;
    cout << "here's your input" << endl << input;
}

int main() {
    const double pi = 3.14;
    cout << "Enter the radius: ";
    double radius;
    cin >> radius;
    double area = pi*pow(radius, 2);
    cout <<area<< endl;
    second();
    return 0;
}