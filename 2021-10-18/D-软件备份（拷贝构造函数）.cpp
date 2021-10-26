#include <cstring>
#include <iostream>
using namespace std;

class CDate
{
private:
    int year, month, day;

public:
    CDate()
    {
    }
    CDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void set(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    bool isLeapYear() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear() //计算日期从当年1月1日算起的天数
    {
        int i, sum = day;
        int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeapYear())
            for (i = 0; i < month; i++)
                sum += b[i];
        else
            for (i = 0; i < month; i++)
                sum += a[i];

        return sum;
    }
};

class Software
{
private:
    char *name;
    char type;
    CDate useful_day;
    char media;

public:
    Software(char *n, char t, char med, int y, int m, int d)
    {
        int len = strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
        type = t;
        media = med;
        useful_day.set(y, m, d);
    }
    void print()
    {
        cout << "name:" << name << endl;
        switch (type)
        {
        case 'O':
            cout << "type:original" << endl;
            break;
        case 'T':
            cout << "type:trial" << endl;
            break;
        case 'B':
            cout << "type:backup" << endl;
            break;
        }
        switch (media)
        {
        case 'D':
            cout << "media:optical disk" << endl;
            break;
        case 'H':
            cout << "media:hard disk" << endl;
            break;
        case 'U':
            cout << "media:USB disk" << endl;
            break;
        }
        if (useful_day.getDay() == 0 && useful_day.getMonth() == 0 && useful_day.getYear() == 0)
            cout << "this software has unlimited use" << endl;
        else if ((useful_day.getYear() >= 2015 && useful_day.getMonth() >= 4 && useful_day.getDay() >= 7) || (useful_day.getYear() >= 2015 && useful_day.getMonth() > 4))
        {                                                                                                            //其实这里只考虑了年份为2015年的情况，不完整
            cout << "this software is going to be expired in " << useful_day.getDayofYear() - 97 << " days" << endl; //计算的天数-97（即四月7日的天数）
        }
        else
        {
            cout << "this software has expired" << endl;
        }
    }
    Software(Software &s)
    {
        int len = strlen(s.name);
        name = new char[len + 1];
        strcpy(name, s.name);
        type = 'B';
        media = 'H';
        CDate temp(s.useful_day);
        useful_day = temp;
    }
    ~Software()
    {
        delete name;
    }
};

int main()
{
    int t, y, d, m;
    char name[30], type, media;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> name >> type >> media >> y >> m >> d;
        Software s1(name, type, media, y, m, d);
        s1.print();
        cout << endl;
        Software s2(s1);
        s2.print();
        cout << endl;
    }
}