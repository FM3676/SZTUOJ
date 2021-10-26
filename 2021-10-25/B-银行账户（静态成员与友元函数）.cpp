#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Account{
    private:
        float InterestRate;
        string _accno, _accname;
        float _balance;
    public:
        Account(string accno, string name, float balance){
            _accno = accno;
            _accname = name;
            _balance = balance;
        };
        ~Account(){};
        void Deposite(float amount){
            _balance += amount;
        };
        void Withdraw(float amount){
            _balance -= amount;
        };
        float GetBalance(){
            return _balance;
        };
        void Show(){
            cout << _accno << " " << _accname << " ";
        };
        void GetInterestRate(float i)
        {
            InterestRate = i;
        };
        friend void Update(Account &a);
};

void Update(Account& a){
	a._balance=a._balance+a._balance*a.InterestRate;
}

int main(){
    float interestrate,balance,withdraw,deposit,sum=0;
	int t;
	string accno,accname;
	cin>>interestrate;
	cin>>t;
    while (t--)
    {
        cin >> accno >> accname >> balance >> deposit >> withdraw;
        Account a(accno, accname, balance);
        a.GetInterestRate(interestrate);
        a.Show();
        cout << a.GetBalance() + deposit << " ";//存后余额
        a.Deposite(deposit);
        Update(a);
        cout << a.GetBalance() << " " << a.GetBalance() - withdraw << endl;
        sum += (a.GetBalance() - withdraw);
    }
    cout << sum;
}