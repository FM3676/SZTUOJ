#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point();
    Point(double x_value, double y_value);
    double getX();
    double getY();
    void setX(double x_value);
    void setY(double y_value);
    double distanceToAnotherPoint(Point p);
};

Point::Point()
{
}

Point::Point(double x_value, double y_value)
{
    x = x_value;
    y = y_value;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

void Point::setX(double x_value)
{
    x = x_value;
}

void Point::setY(double y_value)
{
    y = y_value;
}

double Point::distanceToAnotherPoint(Point p)
{
    double xr = pow(x - p.getX(), 2);
    double yr = pow(y - p.getY(), 2);
    return sqrt(xr + yr);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1);
        Point p2(x2, y2);
        cout << "Distance of Point(" << fixed << setprecision(2) << p1.getX() << "," << p1.getY()
             << ") to Point(" << p2.getX() << "," << p2.getY() << ") is " << p1.distanceToAnotherPoint(p2) << endl;
    }
}