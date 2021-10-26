#include <iostream>
#include <iomanip>
#include<math.h>
using namespace std;

class Equation {
    private:
        double a, b, c;
    public:
        Equation(){
            a = 1, b = 1, c = 0;
        }
        Equation(double av, double bv, double cv){
            a = av, b = bv, c = cv;
        }
        void set(double av, double bv, double cv){
            a = av, b = bv, c = cv;
        }
        void getRoot(){
            double x1, x2;
            double delta = b * b - 4 * a * c;
            if(delta > 0){
                x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                cout << fixed << setprecision(2) << "x1=" << x1 << " x2=" << x2 << endl;
            } 
            if (delta == 0){
                x1 = -b / (2 * a);
                cout << "x1=x2=" << fixed << setprecision(2) << x1 << endl;
            }
            if(delta < 0){
                cout << fixed << setprecision(2) << "x1=" << (-b / (2 * a)) << "+" << (sqrt(-(b * b - 4 * a * c)) / (2 * a))
                     << "i x2=" << (-b / (2 * a)) << "-" << (sqrt(-(b * b - 4 * a * c)) / (2 * a)) << "i" << endl;
            }
        }
};

int main(){
    int t;
    cin >> t;
    double a, b, c;
    Equation Fun;
    while (t--)
    {
        cin >> a >> b >> c;
        Fun.set(a, b, c);
        Fun.getRoot();
    }
    
}