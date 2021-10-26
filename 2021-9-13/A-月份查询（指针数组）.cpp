#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int t, n;
    string month[] = {" ", "January", "Febuary", "March", "April", "May", "June", "July", "Aguest", "September", "October", "November", "December"};
    string *p = month;
    cin >> t;
    int *num = new int[t];
    for (int i = 0; i < t; i++){
        cin >> num[i];
    }
    for ( int i = 0; i < t; i++){
        if(num[i] < 0 || num[i] > 12){
            cout << "error" << endl;
        }else{
            cout << *(p + num[i]) << endl;
        }
    }
}