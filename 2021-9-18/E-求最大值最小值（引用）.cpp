#include <algorithm>
#include <iostream>
using namespace std;
void find(int *num, int n, int &minIndex, int &maxIndex)
{
    minIndex = min_element(num, num + n) - num;
    maxIndex = max_element(num, num + n) - num;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int *pn = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> pn[i];
        }
        int minIndex = 0, maxIndex = 0;
        find(pn, n, minIndex, maxIndex);
        cout << "min=" << pn[minIndex] << " minindex=" << minIndex << endl;
        cout << "max=" << pn[maxIndex] << " maxindex=" << maxIndex << endl;
        cout << endl;
    }
}