#include <cmath>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;
class CVector{
private:
    int *data,n;
public:
    CVector(){
        n = 5;
        data = new int[5];
        for (int i = 0; i < 5; i++)
        {
            data[i] = i;
        }
    }
    CVector(int n1,int* a){
        n = n1;
        data = a;
        }
    void show(){
        for (int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    ~CVector(){}
};
int main(){
    CVector cv;
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cv.show();
    CVector c(n, a);
    c.show();
}