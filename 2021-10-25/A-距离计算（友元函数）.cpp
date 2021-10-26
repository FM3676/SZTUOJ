#include <cmath>
#include <iostream>
using namespace std;

class Point {
    private:
        double x, y;

    public:
        Point(double xx, double yy){
            x = xx;
            y = yy;
        };
        friend double Distance(Point &a, Point &b);
};


double Distance(Point &a, Point &b) {
    double s;
    s = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    return s;
};

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        double x, y;
        cin >> x >> y;
        Point a(x, y);
        cin >> x >> y;
        Point b(x, y);

        double s;
        s = Distance(a, b);
        cout << int(s) << endl;
    }
    
}