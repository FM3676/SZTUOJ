#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int t;
    cin >> t;
    string str1, str2, str3, str;
    int a1, a2, b1, b2, c1, c2;
    while (t--){
        cin >> str1;
        cin >> str2;
        cin >> str3;
        cin >> a1 >> a2;
        cin >> b1 >> b2;
        cin >> c1 >> c2;
        str1 = str1.substr(a1 - 1, a2 - a1 + 1);
        str2 = str2.substr(b1 - 1, b2 - b1 + 1);
        str3 = str3.substr(c1 - 1, c2 - c1 + 1);
        str = str1 + str2 + str3;
        cout << str << endl;
    }
    
}