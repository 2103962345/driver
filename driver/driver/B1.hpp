#pragma once
#include "LicenseTag.hpp"
#include <iostream>
#include <fstream>
using namespace std;
class B1: virtual public LicenseTag
{
	private:
bool Tricycle; 

protected: int Year;
public:
virtual void getData() //получить данные
{char s[50]=""; char c;
fstream pb("driver.txt",ios::out|ios::app);
	cout<<" Category B1: "<<endl;
	cout<<" Enter year: "; 	cin>>s;
Year=atoi(s);
while ((Year<=1908)||(Year>=2500)){cout<<"Error input, try again"<<endl;cin>>s;Year=atoi(s);};
pb<<"Category B1:\n"<<"Year "<<Year<<"\n";
cout<<"do you have tricycle?";cin>>c;
if(c=='1'){Tricycle=1;pb<<"You have tricycles\n";}else {Tricycle=0;pb<<"You haven`t tricycle\n";}
}

virtual void putData()//вывод данных
{
 cout<<" Category B1: "<<endl;
cout<<"Year: "<<Year<<endl;
cout<<"You ";  if(Tricycle)cout<<"have tricycle "<<endl;else cout<<"haven`t tricycle "<<endl;
}
friend ostream& operator<<(ostream &stream, B1 o)
{//stream<<B1;
//stream<<B1::Tricycle;
return stream;}
friend istream& operator>>(istream &stream, B1 &o);
};
