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
        };

        CVector(int n1,int* a){
            n = n1;
            data = a;
        };

        friend CVector Add(const CVector V1, const CVector V2);

        void show()
        {
            for (int i = 0; i < n; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        };

        void print(){
            cout << data[0];
            for (int i = 1; i < n; i++){
                cout << " " << data[i];
            }
            cout << endl;
        };

        ~CVector(){};
};

CVector Add(const CVector V1, const CVector V2){
    int *temp = new int[V1.n];
    for(int i =0;i<V1.n;i++){
        temp[i] = V1.data[i] + V2.data[i];
    };
    CVector tempCV(V1.n, temp);
    return tempCV;
};

int main(){
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        };
        CVector V1(n, a);
        int *b = new int[n];
        for (int i = 0; i < n; i++){
            cin >> b[i];
        };
        CVector V2(n, b);
        V1.show();
        V2.show();
        Add(V1, V2).print();
    }
    
}