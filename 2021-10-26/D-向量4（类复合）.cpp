#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class vector {
		int *data;
		int n;
	public:
		vector() {
			n = 5;
			data = new int[n];
			for (int i = 0; i < n; i++) {
				data[i] = i;
			}
		}
		vector(int n1, int *a) {
			data = new int[n1];
			n = n1;
			for (int i = 0; i < n; i++) {
				data[i] = a[i];
			}
		}
		void out() {
			for (int i = 0; i < n; i++) {
				cout << data[i] << ' ';
			}

		}
		float avg(){
			float sum=0;
			for(int i=0;i<n;i++){
				sum+=data[i];
			}
			return sum/n;
		}
};
class student{
	string name;
	vector grade;
	public:
		student();
		student(string name1,int *a1,int n2){
			name=name1;
			vector temp(n2,a1);
			grade=temp;
		}
		void show(){
			cout<<name<<" ";
			grade.out();
			cout<<fixed<<setprecision(2)<<grade.avg()<<endl;
		}
};
int main(){
	string name;
	while(cin>>name){
		int n;
		cin>>n;
		int *a1=new int[n];
		for(int i=0;i<n;i++){
			cin>>a1[i];
		}
		student q(name,a1,n);
		q.show();
	}
	return 0;
}
