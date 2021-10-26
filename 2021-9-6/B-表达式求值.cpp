#include <iostream>
using namespace std;
int main()
{
    int T,num=0;
    cin >> T;
    double a, b, c, s, w[T];
    for (; T > 0; T--){
        cin >> a >> b >> c;
        if(a+b>c&&b==c){
            s = 1;
        }else{
            s = 0;
        }
        w[num++] = s;
    }
    for (int i = 0; i < num; i++){
        cout << w[i] << "\n";
    }
}