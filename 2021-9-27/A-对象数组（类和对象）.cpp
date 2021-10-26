#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string name, id, sex, college, telnum;

public:
    void input(string n, string d, string s, string c, string t)
    {
        name = n;
        id = d;
        sex = s;
        college = c;
        telnum = t;
    }
    void showName()
    {
        cout << name << endl;
    }
};

int main()
{
    int t;
    string name, id, sex, college, telnum;
    cin >> t;
    Student *students = new Student[t];
    for (int i = 0; i < t; i++)
    {
        cin >> name >> id >> sex >> college >> telnum;
        students[i].input(name, id, sex, college, telnum);
    }
    for (int i = 0; i < t; i++)
    {
        students[i].showName();
    }
}