#include <iostream>
using namespace std;

class AC{
    private:
        int theInt;
    public:
        AC(){
            theInt = 0;
            cout << "Constructed by default, value = 0" << endl;
        }
        AC(int value){
            theInt = value;
            cout << "Constructed using one argument constructor, value = " << theInt << endl;
        }
        AC(const AC& c){
            theInt = c.theInt;
            cout << "Constructed using copy constructor, value = " << c.theInt << endl;
        }
};

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int tcase;
        cin >> tcase;
        if (tcase == 0)
        {
            AC aClass;
        }
        if (tcase == 1)
        {
            int intNum;
            cin >> intNum;
            AC aClass(intNum);
        }
        if (tcase == 2){
            int intNum;
            cin >> intNum;
            AC bClass(intNum);
            AC anotherClass(bClass);
        }
    }
    
}