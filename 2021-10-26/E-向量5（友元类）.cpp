#include <iostream>
#include <iomanip>

using namespace std;

class CVector {
		int *data;
		int n;
	public:
		CVector() {
			n = 5;
			data = new int[n];
			for (int i = 0; i < n; i++) {
				data[i] = i;
			}
		}

		CVector(int nn, int *a) {
			n = nn;
			data = new int[n];
			for (int i = 0; i < n; i++) {
				data[i] = a[i];
			}
		}

		~CVector() {
			delete[] data;
		}

		CVector(const CVector &c) {
			n = c.n;
			data = new int[n];
			for (int i = 0; i < n; i++) {
				data[i] = c.data[i];
			}
		}

		void print() {
			for (int i = 0; i < n; i++) {
				cout << data[i] << " ";
			}
			cout << endl;
		}

		float Average() {
			float sum = 0;
			for (int i = 0; i < n; i++) {
				sum += data[i];
			}
			return sum / n;
		}

		int *getData() {
			return data;
		}

		int getN() {
			return n;
		}

		friend class CMatrix;
};

class CMatrix {
		int **M;
		int n;
	public:

		CMatrix(int n1, int **M1) {
			n = n1;
			M = new int *[n];
			for (int i = 0; i < n; i++) {
				M[i] = new int[n];
				for (int j = 0; j < n; j++) {
					M[i][j] = M1[i][j];
				}
			}
		}

		~CMatrix() {
			for (int i = 0; i < n; i++) {
				delete[] M[i];
			}
			delete[] M;
		}

		bool canM(const CVector &V1) {
			if (n != V1.n)
				return false;
			return true;
		}

		CVector Multi(const CVector &V1) {
			CVector res = V1;
			for (int i = 0; i < n; i++) {
				res.data[i] = 0;
				for (int j = 0; j < n; j++) {
					res.data[i] += M[i][j] * V1.data[j];
				}
			}
			return res;
		}
};
int main() {
	int t;
	cin >> t;

	while (t--) {
		int m, n;
		cin >> n;
		int **dd = new int *[n];
		for (int i = 0; i < n; i++) {
			dd[i] = new int[n];
			for (int j = 0; j < n; j++) {
				cin >> dd[i][j];
			}
		}
		CMatrix mat(n, dd);

		cin >> m;
		int *d = new int[m];
		for (int i = 0; i < m; i++) {
			cin >> d[i];
		}
		CVector vec(m, d);

		if (!mat.canM(vec)) {
			cout << "error" << endl;
		} else {
			mat.Multi(vec).print();
		}

		delete[] d;
		for (int i = 0; i < n; i++) {
			delete[] dd[i];
		}
		delete[] dd;
	}
	return 0;
}