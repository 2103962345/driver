#include "Auto.hpp"
#include "LicenseTag.hpp"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <process.h>
using namespace std;
//конструкторы
Auto::Auto()
{
 Brand=new char[30];
 strcpy(Brand,"new");
 Color=new char[30];
 strcpy(Color,"new");
 Type=new char[30];
 strcpy(Type,"new");
 MaxSpeed=200;
 Licenseplate=new char[30];
 strcpy(Licenseplate,"new");
 Mile=1000;
 Oil=1;
 Insurance=5;
}

Auto::Auto(char* mBrand, char* mColor, int mMaxSpeed, char* mType,char* mLP,long mMile,int mOil,int mInsurance)
{
   	 Brand=new char[strlen(mBrand)+1];
	 strcpy(Brand,mBrand);
	 Color=new char[strlen(mColor)+1];
	 strcpy(Color,mColor);
	 MaxSpeed=mMaxSpeed;
	 Type=new char[strlen(mType)+1];
	 strcpy(Type,mType);
     Licenseplate=new char[strlen(mLP)+1];
	 strcpy(Licenseplate,mLP);
	 Mile=mMile;
	 Oil=mOil;
     Insurance=mInsurance;  
}
//ввод в файл
ostream& operator<<(ostream &stream, Auto &o)
{stream<<o.Brand<<" ";
stream<<o.Color<<" ";
stream<<o.MaxSpeed<<" ";
stream<<o.Type<<" ";
stream<<o.Licenseplate<<" ";
stream<<o.Mile<<" ";
stream<<o.Oil<<" ";
stream<<o.Insurance<<" ";
return stream;}

// метод визуализации состояния объекта 
void Auto::print() 
{ 
cout.setf(ios::left); 
cout.width(10); cout<<"Auto(Машина): "<<endl; 
cout.width(20); cout<<"Brand(Марка): "<< Brand<<endl; 
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Color(Цвет): "<< Color<<endl; 
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Type(Тип): "<< Type<<endl; 
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"License plate(Гос.номер): "<<Licenseplate<<endl; 
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Max speed(Макс.скорость): "<<MaxSpeed<<"km/h"<<endl; 
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Miles(Пробег): "<<Mile<<"km"<<endl; 
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Oil(Бензин): "<<Oil<<endl; 
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Insurance(Страховка на): "<<Insurance<<endl; 
cout.width(10); cout.precision(2); 
} 
//деструктор
Auto::~Auto(void)
{
	delete Brand;
	delete Color;
	delete Type;
	delete Licenseplate;
}
