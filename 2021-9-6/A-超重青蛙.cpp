#include <iostream>
using namespace std;
int main(){
    int T, n, num=0;
    int nummer = 0;
    double avgw=0;
    cin >> T;
    double c[T];
    for (; T > 0;T--){
        cin >> n;
        int *pw = new int[n];
        for (int i = 0; i < n;i++){
            cin >> pw[i];
            avgw+= pw[i];
        }
        avgw = avgw / n;
        for (int i = 0; i < n;i++){
            if(pw[i]>avgw){
                num += 1;
            }
        }
        c[nummer++] = num;
        num = 0;
        delete []pw;
    }
    for (int i = 0; i < nummer;i++){
        cout << c[i] << "\n";
    }
        return 0;
}