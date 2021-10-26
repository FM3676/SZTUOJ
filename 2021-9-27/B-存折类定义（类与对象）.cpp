#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class CAccount
{
private:
    long account;
    string name;
    float balance;

public:
    CAccount()
    {
        account = 0;
        name = "<name>";
        balance = 0;
    }
    CAccount(long _account, string _name, float _balance)
    {
        account = _account;
        name = _name;
        balance = _balance;
        check();
    }
    void deposit(float d)
    {
        balance += d;
        cout << "saving ok!" << endl;
        check();
    }
    void withdraw(float w)
    {
        if (balance >= w)
        {
            balance -= w;
            cout << "withdraw ok!" << endl;
            check();
        }
        else
        {
            cout << "sorry! over limit!" << endl;
            check();
        }
    }
    void check()
    {
        cout << name << "'s balance is " << balance << endl;
    }
};
int main()
{
    for (int i = 0; i < 2; i++)
    {
        long account;
        string name;
        float balance;
        CAccount temp;
        cin >> account >> name >> balance;
        temp = { account, name, balance };
        int _b;
        cin >> _b;
        temp.deposit(_b);
        cin >> _b;
        temp.withdraw(_b);
    }

    return 0;
}