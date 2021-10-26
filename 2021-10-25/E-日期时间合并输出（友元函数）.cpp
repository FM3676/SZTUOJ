#include <cmath>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;
class Time;
class Date
{
    private:
        int year;
        int month;
        int day;

    public:
        Date(int y, int m, int d)
        {
            year = y;
            month = m;
            day = d;
        }
        friend void Display(Date D ,Time T);
};

class Time
{
    private:
		int hour;
		int minute;
		int second;	
    
	public:
		Time(int h,int m,int s)
		{
			hour=h;
			minute=m;
			second=s;
		}
		friend void Display(Date D ,Time T);	
};

void Display(Date D,Time T)//定义的全局函数同时作为两个类的友元函数
{
	cout<<D.year<<"-"<<setfill('0')<<setw(2)<<D.month<<"-"<<setfill('0')
    <<setw(2)<<D.day<<" "<<setfill('0')<<setw(2)<<T.hour<<":"<<setfill('0')<<setw(2)
    <<T.minute<<":"<<setfill('0')<<setw(2)<<T.second<<endl;
}

int main()
{
	int i,t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int y,month,d,h,min,s;
		cin>>y>>month>>d>>h>>min>>s;
		Date Date1(y,month,d);
		Time Time1(h,min,s);
		Display(Date1,Time1);
	}
	return 0;
}
