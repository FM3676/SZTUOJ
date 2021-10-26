#include <iostream>
#include <iomanip>
using namespace std;
class bodyHealth{
    private:
        string name;
        float height, weight, waist;
    public:
        bodyHealth() {
            name = "<name>";
            height = 0;
            weight = 0;
            waist = 0;
        }
        bodyHealth(string _n, float _h, float _w, float _wa) {
            name = _n;
            height = _h;
            weight = _w;
            waist = _wa;
        }
        float getBMI() {
            return weight / height / height;
        }
        float getBFR() {
            float a = waist * 0.74;
            float b = weight * 0.082 + 34.89;
            return (a - b) / weight;
        }
        void print() {
            cout << fixed << setprecision(0)
                << name << "的BMI指数为" << getBMI() 
                << fixed << setprecision(2)
                << "--体脂率为" << getBFR() << endl;
        }
};

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string _name;
        float _height, _weight, _waist;
        bodyHealth temp;
        cin >> _name >>_height >> _weight >> _waist;
        temp = {_name, _height, _weight, _waist};
        temp.print();
    }
    return 0;
}