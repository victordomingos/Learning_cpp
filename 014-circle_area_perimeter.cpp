#include <iostream>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

int main()
{
    double radius, area, perimeter;
    
    cout << "Circle radius? ";    cin >> radius;
    
    perimeter = 2 * PI * radius;
    area = PI * pow(radius, 2);
    
    cout << "Circumpherence: " << perimeter << endl;
    cout << "Area of disk: " << area << endl;
    
    return 0;
}
