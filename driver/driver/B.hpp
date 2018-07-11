#pragma once
#include "B1.hpp"
#include "BE.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class B: public B1, public BE
{
private:
bool Car;
bool b;
bool b1;
bool be;
int Year;
public:
virtual void B::getData() //получить данные
	{   char cr1,c,s[50]="";
fstream pb("driver.txt",ios::out|ios::app);
if(!pb)cout<<"Error";
cout<<" Do you have category B1?(for yes:1): "<<endl; cin>>cr1;
if(cr1=='1'){B1::getData();b1=1;} else b1=0;
cout<<" Do you have category BE?(for yes:1): "<<endl; cin>>cr1;
if(cr1=='1'){BE::getData();be=1;}else be=0;
		cout<<" Do you have category B?(for yes:1): "<<endl; cin>>cr1;
		if(cr1=='1'){
		cout<<" Category B: "<<endl;
		cout<<" Enter year: "; 
		cin>>s;
Year=atoi(s);
while ((Year<=1908)||(Year>=2500)){cout<<"Error input, try again"<<endl;cin>>s;Year=atoi(s);};
pb<<"Category B:\n"<<"Year "<<Year<<"\n";
		cout<<"Enter Car:";cin>>c;
		if(c=='1'){Car=1;pb<<"You have car\n";}else {Car=0;b=1;pb<<"You haven`t car\n";}}else b=0;
}
virtual void putData()//вывод данных
	{
		if(b1)B1::putData();
		if(be)BE::putData();
		if(b){
		cout<<" Category B: "<<endl;
		cout<<"Year: "<<Year<<endl;
		cout<<"Car:"<<Car<<endl;
		}
}
friend ostream& operator<<(ostream &stream, B o)
{return stream;}
friend istream& operator>>(istream &stream, B &o);
};
