#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Complex {
    private:
        double real, imag;
    public:
        Complex();
        Complex(double r, double i){
            real = r;
            imag = i;
        };
        friend Complex addCom(Complex c1, Complex c2);
        friend Complex minusCom(Complex c1, Complex c2);
        friend void outCom(Complex c);
};

Complex addCom(Complex c1, Complex c2){
    c1.real = c1.real + c2.real;
    c1.imag = c1.imag + c2.imag;
    return c1;
}

Complex minusCom(Complex c1, Complex c2) {
    c1.real = c1.real - c2.real;
    c1.imag = c1.imag - c2.imag;
    return c1;
}

void outCom(Complex c) {
    cout << "(" << c.real << "," << c.imag << ")" << endl;
}

int main(){
    double real, imag;
    cin >> real >> imag;
    Complex a(real, imag);
    int t;
    cin >> t;
    while (t--)
    {
        char s;
        cin >> s;
        if(s == '-') {
            cin >> real >> imag;
            Complex b(real, imag);
            a = minusCom(a, b);
            outCom(a);
        }
        else if(s == '+'){
            cin >> real >> imag;
            Complex b(real, imag);
            a = addCom(a, b);
            outCom(a);
        }
    }
}