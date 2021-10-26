#include <cmath>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;
class CVector{
    private:
        int *data,n;
        static int sum;

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

        static void addSum(int n){
            sum += n;
        }

        static void printSum(){
        cout << sum << endl;
        };

        static void resetSum(){
            sum = 0;
        };

        ~CVector(){};
};


int CVector::sum = 0;

int main(){
    int t, n, m;
    cin >> t;
    while (t--){
        cin >> m;

        while (m--){
            cin >> n;
            int *a = new int[n];
            for (int i = 0; i < n; i++){
                cin >> a[i];
                CVector::addSum(a[i]);
            };
            CVector V1(n, a);
            V1.show();
        }
        CVector::printSum();
        CVector::resetSum();
    }
    
}