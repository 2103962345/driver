#pragma once
#include <iostream>
#include <fstream>
#include "Driver.hpp" 
using namespace std;
class Driver;
class Auto
{
private: 
	     char* Brand; //марка
		 char* Color; //цвет
		  int  MaxSpeed; //макс.скорость
		 char* Type; //тип
		 char* Licenseplate; //гос.номер
         long  Mile;  //пробег
          int  Oil; //бензин
       friend  Driver;// дружественный класс Водитель
	      int  Insurance; //страховка
		
public:
	      Auto(); //конструктор без параметров
	      Auto(char* mBrand, char* mColor, int mMaxSpeed, char* mType, char* mLP, long mMile,int mOil,int mInsuranse);//конструктор с параметрами
	     ~Auto(); //деструктор
	void  print(); ///вывод на экран
	 friend ostream& operator<<(ostream &stream, Auto &o);//ввод в файл
};
