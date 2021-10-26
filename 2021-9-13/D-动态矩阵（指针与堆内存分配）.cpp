#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int** matrix = new int*[m];

        int* min = new int[m];
        int* max = new int[m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
            sort(matrix[i], matrix[i] + n);
            min[i] = matrix[i][0];
            max[i] = matrix[i][n - 1];
        }
        sort(min, min + m);
        sort(max, max + m, greater<int>());
        cout << min[0] << ' ' << max[0] << endl;
    }
} 