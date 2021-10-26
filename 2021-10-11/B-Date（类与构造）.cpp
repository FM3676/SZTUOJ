#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    Date();
    Date(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);
    void print();
    void addOneDay();
    bool isLeap(int year);
};

Date::Date(){
}

Date::Date(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

int Date::getYear(){
    return year;
}

int Date::getMonth(){
    return month;
}

int Date::getDay(){
    return day;
}

void Date::setDate(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

void Date::print(){
    cout << setfill('0') <<year << "/" <<setw(2) <<month << "/" << setw(2)<< day << endl;
}

bool Date::isLeap(int year) {
	return year % 100 == 0 ? year % 400 == 0: year % 4 == 0;
}

void Date::addOneDay() {
	int monthDays[] = { 0,31,isLeap(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };
	++day;
	if (day > monthDays[month]){
		++month;
		day = 1;
	}
	if (month > 12){
		++year;
		month = 1;
	}
}

int main()
{
	int t, year, month, day;
	cin >> t;
	while (t--){
		cin >> year >> month >> day;
		Date date(year, month, day);
		cout << "Today is ";
		date.print();
		date.addOneDay();
		cout << "Tomorrow is ";
		date.print();
	}
	return 0;
}