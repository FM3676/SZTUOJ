#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        int len1 = s1.length(), len2 = s2.length();
        if (len1 == len2) {
            int count = 0;
            for (int i = 0; i < len1; i++) {
                s1[i] > s2[i] ? count++ : count--;
            }
            cout << ((count == 0)  ? 0
                     : (count > 0) ? 1
                                   : -1)
                 << endl;
        }
        else {
            cout << (len1 > len2 ? 1 : -1) << endl;
        }
    }
}