#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
    int year;
    int month;
    int day;
};

bool compare(const student &a, const student &b)
{
    int birth1 = a.year * 10000 + a.month * 100 + a.day;
	int birth2 = b.year * 10000 + b.month * 100 + b.day;
	return birth1 < birth2;
}

int main()
{
	int num;
	cin >> num;
	student *stu = new student[num];
    for (int i = 0; i < num; i++)
    {
        cin >> stu[i].year >> stu[i].month >> stu[i].day;
    }
    sort(stu, stu + num, compare);
    cout << stu[1].year << "-" << stu[1].month << "-" << stu[1].day;
    delete stu;
}