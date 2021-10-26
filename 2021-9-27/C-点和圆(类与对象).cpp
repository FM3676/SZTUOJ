#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point{
    private:
        float x;
        float y;
    public:
        Point() {
            x = 0;
            y = 0;
        }
        Point(float _x, float _y) {
            x = _x;
            y = _y;
        }
        void setPoint(float _x, float _y) {
            x = _x;
            y = _y;
        }
        float getX() {
            return x;
        }
        float getY() {
            return y;
        }
};
class Circle {
    private:
        Point o;
        float r;
    public:
        Circle(Point _o, float _r) {
            o = _o;
            r = _r;
        }
        Circle(float _ox, float _oy, float _r) {
            o = { _ox, _oy };
            r = _r;
        }
        void setCenter(float _ox, float _oy) {
            o = { _ox, _oy };
        }
        void setRadius(float _r) {
            r = _r;
        }
        float getArea() {
            return 3.14 * r * r;
        }
        float getLength() {
            return 2 * 3.14 * r;
        }
        string isContain(Point _o) {
            float x = o.getX();
            float y = o.getY();
            float _x = _o.getX();
            float _y = _o.getY();
            float l = sqrt((x - _x) * (x - _x) + (y - _y) * (y - _y));
            if (l <= r) return "yes";
            else return "no";
        }
};

int main() {
    float ox, oy, r, x, y;
    cin >> ox >> oy >> r
        >> x >> y;
    Point p = { x, y };
    Circle c = { {ox, oy}, r };

    cout << c.getArea() << " " << c.getLength() << endl
        << c.isContain(p) << endl;

    return 0;
} 

