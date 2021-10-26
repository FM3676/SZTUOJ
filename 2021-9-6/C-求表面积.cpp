#include <iostream>
using namespace std;
int main(){
    int T,num;
    cin >> T;
    int result[T];
    for (; T > 0; T--){
        int a, b, c;
        cin >> a >> b >> c;
        result[num++] = 2 * a * b + 2 * b * c + 2 * c * a;
    }
    for (int i = 0; i < num; i++){
        cout << result[i] << "\n";
    }
}