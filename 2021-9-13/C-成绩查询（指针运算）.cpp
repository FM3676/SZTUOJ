#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, num;
        cin >> n;
        int *grade = new int[n];
        for (int i = 0; i < n; i++){
            cin >> grade[i];
        }
        cin >> num;
        cout << *(grade + (n / 2) - 1) << " " << *(grade + (n / 2) + 1) << endl
             << *(grade + num - 1) << endl;
    }
}