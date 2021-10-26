#include<iostream>
#include <cstring>
using namespace std;
class Date{
private:
    int year, month, day;
public:
    Date(int y, int m, int d) { year = y; month = m; day = d; }
    void set(int y, int m, int d) { year = y; month = m; day = d; }
    Date(){}
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
};
class phone{
 private:
  char type;
  char *num;
  int state;
  Date *stopdate; 
 public:
  phone(char t,char *n,int s){
   stopdate=NULL;//由题目要求一开始指针指向空
   type=t;
   num=n;
   state=s;
   cout<<"Construct a new phone "<<num<<endl;  
  } 
  void print(){
   switch (type){
    case 'A':cout<<"类型=机构";break; 
    case 'B':cout<<"类型=企业";break;
    case 'C':cout<<"类型=个人";break;
    case 'D':cout<<"类型=备份";break;
   }
   cout<<"||号码="<<num;
   switch (state){
    case 1:cout<<"||State=在用"<<endl;break; 
    case 2:cout<<"||State=未用"<<endl;break;
    case 3:cout<<"||State=停用 ||停机日期="<<stopdate->getYear()<<"."<<stopdate->getMonth()<<"."<<stopdate->getDay()<<endl;break;
   }
  }
  phone(const phone &p){
    stopdate=NULL;
   type='D';
   num=new char[strlen(p.num)+1];//将号码复制
   strcpy(num,p.num);
   state=p.state;
   cout<<"Construct a copy of phone "<<num<<endl;
   char *X="X";
   strcat(num,X); 
  }
  void stop(Date &d1){
   state=3;
   stopdate=new Date(d1.getYear(),d1.getMonth(),d1.getDay());
   cout<<"Stop the phone "<<num<<endl;  
  }
  ~phone(){
   if(stopdate!=NULL)
   delete stopdate;
  } 
};
int main(){
 int t,y,m,d,s;
 char number[12];//数组要比存放的字符+1,最后一位存放结束符
 char type;
 cin>>t;
 while(t--){
  cin>>type>>number>>s>>y>>m>>d;
  phone p1(type,number,s);//一开始日期类对象为NULL
  Date s_d(y,m,d);
  p1.print();
  phone p2(p1);
  p2.print();
  p1.stop(s_d);//停机功能需要一个日期类对象，这时用上刚才创建的日期类对象
  p1.print();
  cout<<"----"<<endl;
 }
}
