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
    Point(const Point& p);
    Point(double x_value, double y_value);
    ~Point();
    double getX();
    double getY();
    void setX(double x_value);
    void setY(double y_value);
    void setXY(double x_value, double y_value) { x = x_value; y = y_value; cout << "Constructor." << endl;}
    double getDisTo(const Point &p);
};

Point::Point()
{
}

Point::Point(double x_value, double y_value)
{
    x = x_value;
    y = y_value;
    cout << "Constructor." << endl;
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

Point::~Point(){
    cout << "Distructor." << endl;
}

double Point::getDisTo(const Point &p) {
    double dx = x - p.x;
    double dy = y - p.y;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Point* ps = new Point[n];
        for (int i = 0; i < n; i++) {
            int tempx, tempy;
            cin >> tempx >> tempy;
            ps[i].setXY(tempx, tempy);
        }

        double maxLen;
        int n1 = 0, n2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double temp = ps[i].getDisTo(ps[j]);
                if (temp > maxLen) {
                    maxLen = temp;
                    n1 = i;
                    n2 = j;
                }
            }
        }
        cout << fixed << setprecision(2)
            << "The longeset distance is " << maxLen << ","
            << "between p[" << n1 << "] and p[" << n2 << "]." << endl;
        delete[] ps;
    }
}