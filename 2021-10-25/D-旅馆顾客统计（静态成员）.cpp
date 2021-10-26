#include <cmath>
#include <iostream>
#include <string.h>
#include<iomanip>
using namespace std;
class Hotel{
	private:
		static int m_TotalCusNum;		//顾客总人数 
		static	float m_TotalEearning;	//旅店总收入 
		static float m_Rent;			//每一个顾客的房租 
		char* m_CustomerName;			//顾客名字 
		int m_CustomerID;				//顾客编号 
	public:
		Hotel(char *a_Customer){
			m_CustomerName=new char[strlen(a_Customer)+1];
			strcpy(m_CustomerName,a_Customer);
			m_TotalCusNum++;
			m_CustomerID=m_TotalCusNum;
			m_TotalEearning=m_TotalCusNum*m_Rent;
		}
		~Hotel(){
			delete m_CustomerName;
		}
		static void setRent(float r){
			m_Rent=r;
		}
		void Display(){
			cout<<m_CustomerName<<" 2015"<<setfill('0')<<setw(4)<<m_CustomerID;
			cout<<" "<<m_CustomerID<<" "<<m_TotalEearning<<endl;
		} 		
};

float Hotel::m_Rent=0;
int Hotel::m_TotalCusNum=0;
float Hotel::m_TotalEearning=0;

int main(){
	float rent;
	char name[50];
	cin>>rent;
	Hotel::setRent (rent);
	while(1){
		cin>>name;
		if(name[0]=='0'){
            break;
        }
		Hotel h1(name);
		h1.Display();
	}
}