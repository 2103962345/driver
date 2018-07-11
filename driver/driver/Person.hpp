#pragma once
#include <iostream>
#include <fstream>
using namespace std;
	const int MAXEM = 50; //количество объектов
class Person 

{private:
	   static int  n; //количество человек
	         char* FirstName; //имя
	         char* LastName; //фамилия
	         char* Otchestvo; //отчество
	         char* FIO; //ФИО
	       static  Person* arrap[]; // массив указателей
protected:
	          int  Age;//возраст
public:
	               Person(); //конструктор по умолчанию
				   Person(char* FN, char* LN, char* Otch, int NAge); // конструктор с параметрами
 	              ~Person();//деструктор
	         char* GetFIO(); // взять ФИО
	          int  GetAge(); //взять значение возраста
	         void  GetInfo();  //получить информацию о человеке
              int  SetPerson(); //установить поля человека
	 virtual void  SetInfo(); //установить информацию
	          int  SetFN();  //установть имя
              int  SetLN();  //установить фамилию
	          int  SetOtch(); //установить отчество
              int  SetAge();  //установить возраст
	         char* GetOtch(); //получить отчество
   	         char* GetFN(); //получить имя
	         char* GetLN(); //получить фамилию
             void  GetAr(int j); // получить объект
			 void  GetAr2(int j,int k); //получить 2 объекта
     virtual void  print();  //вывод на экран
	         void  read(); //чтение
			 void  write(); //заапись в файл
	          int  MidAge(); //средний возраст
          virtual  void  Add(); // dobavit chela
          virtual void  Display(); //vivod dannih obo vseh
		  int Ret(); //вернуть количество объектов
		  void oper(int j); //изменить данные о человеке
void File(); //путь к файлу
friend bool operator<(const Person &p1,const Person &p2); //сравнить 2 людей
friend bool operator<(const Person &p1,const int p2); //старше 18
friend bool operator<(const int p2,const Person &p1);//старше 18
friend ostream& operator<<(ostream &stream, Person &o); //вывод в файл
friend istream& operator>>(istream &stream, Person &o); //ввод из файла
	};
