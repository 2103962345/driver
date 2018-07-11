#pragma once
#include "LicenseTag.hpp"
#include <iostream>
#include <fstream>
using namespace std;
class BE:virtual public LicenseTag
{
private: bool trailer; 
protected: int Year;
public: 
	virtual void getData() //получить данные
	{char s[50]=""; char c;
	fstream pb("driver.txt",ios::out|ios::app);
		cout<<" Category BE: "<<endl;
		cout<<" Enter year: ";cin>>s;
	Year=atoi(s);
while ((Year<=1908)||(Year>=2500)){cout<<"Error input, try again"<<endl;cin>>s;Year=atoi(s);};
pb<<"Category BE:\n"<<"Year "<<Year<<"\n";
cout<<"Do you have trailer? ";cin>>c;
if(c=='1'){trailer=1;pb<<"You have trailer\n";}else {trailer=0;pb<<"You haven`t trailer\n";}
} 
 virtual void putData() //вывод данных
	{
		cout<<" Category BE: "<<endl;
		cout<<"Year: "<<Year<<endl;
cout<<"have ";if(trailer)cout<<"have trailer "<<endl;else cout<<"haven`t trailer "<<endl;
}
  friend ostream& operator<<(ostream &stream, BE o)
  {//stream<<BE;
  //stream<<BE::trailer;
return stream;}
	 friend istream& operator>>(istream &stream, BE &o);
};
