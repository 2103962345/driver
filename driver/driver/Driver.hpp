#pragma once
#include "Person.hpp"
#include "LicenseTag.hpp"
#include "Auto.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class LicenseTag;
class Auto;
class Driver : public Person
{private: 
	      static int  k;   //количество водителей в системе
	    unsigned int  Stage; //стаж вождения
		        char* Code;  //код      
		  LicenseTag* lt[10]; //водительские права
		  	    Auto* aut;   // машина 
	  static  Driver* arrad[]; // массив объектов  
public:
	      Driver(); //конструктор по умолчанию
          Driver(char* FN, char* LN, char* Otch, int NAge, char* mCode, int mStage); //конструктор с параметрами
	     ~Driver(); //деструктор
	void  SetInfo(); //установить информацию
	char* GetCode(); // получить код
   	 int  GetStage(); //получить стаж
	void  SetLI();  //установить данные о водительских правах
	void  GetLI(); //получить водительские права
	 void SetCode(char *mCode);//«присвоить категорию»
	 int  SetStage(); //получить стаж
	 friend ostream& operator<<(ostream &stream, Driver &o);//ввод в файл
	 int  SetDriver(); // добавить данные
    void  print();  //вывод на экран
	void  GetA(int i); //получить данные о машине
	void  SetA(); //установить данные о машине
	/////////////////////////////////////////////////////
	void  GetAuto(Auto);  
	char* GetInfo();//информации о водителе (ФИО+категория+стаж вождения)
	int  SetCode1();//«присвоить категорию» v uslovii void
	char* GetFIO();  //получить фио
     int  SetAuto(Auto &);  //установить машину
	char* GetColor(Auto); //получить цвет
	char* GetBrand(Auto); //получить марку
	char* GetT(Auto); //получить тип
	char* GetLP(Auto); //получить гос.номер
	 int  GetIns(Auto); //получить страховку
	 int  GetMax(Auto); //получить макс.скорость
	 int  GetOil(Auto); //получить бензин
	long  GetMile(Auto); //получить пробег
	 int  SetBrand(Auto &); //установить марку
	 int  SetColor(Auto &); //установить цвет
	 int  SetMax(Auto &); //установить макс.скорость
	 int  SetOil(Auto &); //установить бензин
	long  SetMile(Auto &); //установить пробег
	 int  SetT(Auto &); //установить тип
	 int  SetLP(Auto &); //установить гос.номер
	 int  SetIns(Auto &);//установить старховку
		 /////////////////////////////////////////////
	 void operator++(); ///увеличить стаж+возраст
	 void  GetAr(int j); //получить объект
	 void Driver::GetAr1(int j); //получить объект
	 void Add(); //добавить информацию
	 void Display(); //вывод на экран
	 void File(); //путь к файлу
	 void sset1(int j); //установить код
	 void write();	 //запись в файл
	 int Ret();//вернуть количество объектов
};
