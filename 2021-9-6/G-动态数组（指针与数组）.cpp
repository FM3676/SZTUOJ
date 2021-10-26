#include <iostream>
#include <algorithm>
using namespace std;

void sortchar( char *s, int len)
{
    char temp;
    int i,j;
    for(i=0; i<len; i++) {
        for(j=i+1; j<len; j++) {
            if(s[i] < s[j]) {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--){ 
        char type;
        int n;
        cin >> type >> n;

        if (type == 'I'){
            int *p = new int[n];
            double sum;
            for (int i = 0; i < n; i++){
                cin >> p[i];
                sum += p[i];
            }
            cout << sum / n << endl;
        }

        if (type == 'C'){
            char *p = new char[n];
            for (int i = 0; i < n; i++) cin >> *(p + i);
            sort(p, p + n, greater<char>());
            cout << *p << endl;
        }

        if (type ==  'F')
        {
            float *p = new float[n];
            for (int i = 0; i < n; i++){
                cin >> p[i];
            }
            sort(p, p + n);
            cout << *p << endl;
        }
        
    }
}


