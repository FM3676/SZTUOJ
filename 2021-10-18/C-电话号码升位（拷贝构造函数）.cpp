#include <cstring>
#include <iostream>
using namespace std;
class CTelNumber
{
private:
    char *phoneNumber;

public:
    CTelNumber()
    {
        phoneNumber = new char[8];
    }
    CTelNumber(char *q)
    {
        phoneNumber = new char[8];
        strcpy(phoneNumber, q);
    }
    CTelNumber(CTelNumber &q)
    {
        phoneNumber = new char[9];
        if (q.phoneNumber[0] == '2' || q.phoneNumber[0] == '3' || q.phoneNumber[0] == '4')
        {
            phoneNumber[0] = '8';
        }
        else
            phoneNumber[0] = '2';
        for (int i = 0; i < 7; i++)
        {
            phoneNumber[i + 1] = q.phoneNumber[i];
        }
    }
    void phoneNumberrint()
    {
        for (int i = 0; i < 8; i++)
            cout << phoneNumber[i];
        cout << endl;
    }
    void print()
    {
        for (int i = 0; i < 8; i++)
            cout << phoneNumber[i];
        cout << endl;
    }
    ~CTelNumber()
    {
        delete phoneNumber;
    }
};

int main()
{
    int t, isNum = 1;
    char *q;
    cin >> t;
    while (t--)
    {
        q = new char[8];
        cin >> q;
        for (int i = 1; i < 7; i++)
        {
            if (q[i] > '9' || q[i] < '0')
            {
                isNum = 0;
                break;
            }
        }
        if (isNum)
        {
            if (strlen(q) == 7)
            {
                if (q[0] >= '2' && q[0] <= '8')
                {
                    CTelNumber m(q);
                    CTelNumber n(m);
                    n.print();
                }
                else
                    cout << "Illegal phone number" << endl;
            }
        }
        else
            cout << "Illegal phone number" << endl;
    }
}
