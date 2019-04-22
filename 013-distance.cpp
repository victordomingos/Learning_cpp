#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double ax, ay;
    double bx, by;
    double d;
    
    cout << "Point A - X: ";  cin >> ax;
    cout << "Point A - Y: ";  cin >> ay;
    cout << "Point B - X: ";  cin >> bx;
    cout << "Point B - Y: ";  cin >> by;
    
    d = sqrt(pow(bx-ax, 2) + pow(by-ay, 2));
    cout << "Distance: " << d << endl;
    return 0;
}
