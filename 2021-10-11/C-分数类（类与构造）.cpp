#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class CFraction
{
private:
    int fz, fm;

public:
    CFraction(){
    }

    CFraction(int fz_val, int fm_val)
    {
        fz = fz_val;
        fm = fm_val;
    };

    CFraction add(const CFraction &r){
        CFraction result;
        int GCD;
        result.fz = fz * r.fm + fm * r.fz;
        result.fm = fm * r.fm;
        GCD = result.getGCD();
        result.fz = result.fz / GCD;
        result.fm = result.fm / GCD;
        return result;
    };

    CFraction sub(const CFraction &r){
        CFraction result;
        int GCD;
        result.fz = fz * r.fm - fm * r.fz;
        result.fm = fm * r.fm;
        GCD = result.getGCD();
        result.fz = result.fz / GCD;
        result.fm = result.fm / GCD;
        return result;

    };

    CFraction mul(const CFraction &r){
        CFraction result;
        int GCD;
        result.fz = fz * r.fz;
        result.fm = fm * r.fm;
        GCD = result.getGCD();
        result.fz = result.fz / GCD;
        result.fm = result.fm / GCD;
        return result;
    };
    
    CFraction div(const CFraction &r){
        CFraction result;
        int GCD;
        result.fz = fz * r.fm;
        result.fm = fm * r.fz;
        GCD = result.getGCD();
        result.fz = result.fz / GCD;
        result.fm = result.fm / GCD;
        return result;
    };
    
    int getGCD()
    {
        int a, b, r, temp;
        a = fz;
        b = fm;
        if (a < 0)
        {
            a = -a;
        }

        if (b < 0)
        {
            b = -b;
        }

        if (b > a)
        {
            temp = a;
            a = b;
            b = temp;
        }
        for (;;)
        {
            r = a % b;
            if (r == 0)
                return b;
            a = b;
            b = r;
        }
    }; // 求对象的分子和分母的最大公约数
    
    void print(){
        cout<<fz<<"/"<<fm<<endl;
    };
};

int main(){
    int t, fz1, fm1, fz2, fm2;
    char temp;
    cin >> t;
    while (t--)
    {
        cin >> fz1 >> temp >> fm1 >> fz2 >> temp >> fm2;
        CFraction CF1(fz1, fm1);
        CFraction CF2(fz2, fm2);
        CF1.add(CF2).print();
        CF1.sub(CF2).print();
        CF1.mul(CF2).print();
        CF1.div(CF2).print();
        cout << endl;
    }
    
}