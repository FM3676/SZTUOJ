#include <iostream>
#include <string>
using namespace std;

struct Bill
{
    string name;
    int Terminal;
    int opreator;
    string CardIssueers;
    string Validity;
    string CardNumber;
    string Teaded;
    float Costs;

    string CardNum() {
        string temp = "";
        int len = CardNumber.length();
        for (int i = 0; i < len; i++) {
            if (i >= 4 && i < 12) temp += '*';
            else temp += CardNumber[i];
        }
        return temp;
    }
};

int main()
{
    int t;
    cin >> t;
    Bill *bill = new Bill[t];
    for (int i = 0; i < t; i++)
    {
        cin >> bill[i].name >> bill[i].Terminal >> bill[i].opreator >> bill[i].CardIssueers >> bill[i].Validity >> bill[i].CardNumber >> bill[i].Teaded >> bill[i].Costs;
    }
    for (int i = 0; i < t; i++)
    {
        cout << "Name: " << bill[i].name << endl;
        printf("Terminal: %05d operator: %02d\n", bill[i].Terminal, bill[i].opreator);
        cout << "Card Issuers: " << bill[i].CardIssueers << " Validity: " << bill[i].Validity << endl;
        cout << "CardNumber: " << bill[i].CardNum() << endl;
        cout << "Traded: " << bill[i].Teaded << endl;
        printf("Costs: $%.2f\n", bill[i].Costs);
        cout << endl;
    }
}