#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include "Driver.hpp"
#include "LicenseTag.hpp"
#include "B1.hpp"
#include "BE.hpp"
#include "B.hpp"
#include "Person.hpp" 
#include "Auto.hpp"
using namespace std;
int s=5; 
class Person;
Person pe;
int so;
int na=0;
int nl;
int Driver::k;
Driver* Driver::arrad[MAXEM];
Driver *driver;
string str="";
char *s2="";
//путь к файлу
void Driver::File() 
{
ifstream fin("config.txt");
getline(fin, str, '\n');
s2 = new char[str.size() + 1];
strcpy(s2, str.c_str());
}

Driver::Driver()    //конструктор без параметров
{
 Code=new char[4];
 strcpy(Code,"B");
 Stage=1;
}

Driver::Driver(char* FN, char* LN, char* Otch, int NAge, char* mCode, int mStage):Person(FN,LN,Otch,NAge) //конструктор с параметрами
{
	 Code=new char[strlen(mCode)+1];
	 strcpy(Code,mCode);
	 Stage=mStage;
}

//GET-методы
char* Driver::GetCode() //получить код
{
	return Code;
}
int Driver::GetStage() // получить стаж водителя
{
	return Stage;
}
//Set-методы
int Driver::SetCode1() //установить значение кода 
{ char  mCode[50]=""; int ch;
	int len_name=4;
	int lenA=50;
	do {
	cout<<"Enter code(Введите код): ";cin>>mCode;lenA = strlen(mCode);
	}while(lenA>=len_name);
if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR code !!!"<< endl; 
}
Code = new char [lenA+1]; 
strcpy(Code, mCode); 
return 0;
} 
int Driver::SetStage()  // установить стаж
{ int mStage;
	char s[50]="";
cout<<"Enter Stage(Введите Стаж): ";	cin>>s;
mStage=atoi(s);
if(Age>19){while((mStage<=0)||(mStage>(Age-18))){cout<<"Error input, try again"<<endl;cin>>s;mStage=atoi(s);};}
else while(mStage!=0){cout<<"Error input, try again"<<endl;cin>>s;mStage=atoi(s);};
Stage=mStage;
return 1;
} 

// метод визуализации состояния объекта
void Driver::print()
{ 
fstream pb(s2, ios::out|ios::app);
if(!pb){cout<<"You can`t\n";}
cout.setf(ios::left);  
Person::print(); 
cout.width(20); cout<<"Code(Код): "<<GetCode();cout<<endl;
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Stage(Стаж): "<<GetStage();cout<<endl;
cout.width(10); cout.precision(2); 
cout<<endl;
for(int j=0;j<nl;j++)
{
	lt[j]->putData();
	//pb<<(lt[j])<<endl;
}
aut->print();
pb<<"Auto: ";
pb<<(*aut)<<"\n";
}
//Set-методы
int Driver::SetDriver()
{
	return SetStage() && SetCode1();
}
void Driver::SetInfo() //установить значения водителя
{	char reply; 
	cout<<"Driver: "<<endl;
	Person::SetInfo();
	Driver::SetDriver();
   	nl=0; 
	cout<<"License Tag(Водительские права):"<<endl;
	lt[nl]=new B;
	lt[nl++]->getData();
		int i=0;
	cout << "Auto(Авто): " << endl; 
	aut=new Auto;SetAuto(*aut);
	}

//деструктор
Driver::~Driver()
{
	delete driver;
	delete Code;
}

//перегрузка унарного оператора ++ 
 void Driver::operator++()//увеличить стаж вождения
	{
		 ++Stage;
		 ++Age;
	}

////////////////////////////////////////////
//GET-методы
char* Driver::GetBrand(Auto a)
{
	return a.Brand;
}
char* Driver::GetColor(Auto a)
{
	return a.Color;
}
char* Driver::GetT(Auto a)
{
	return a.Type;
}
char* Driver::GetLP(Auto a)
{
	return a.Licenseplate;
}
int Driver::GetMax(Auto a)
{
	return a.MaxSpeed;
}
int Driver::GetOil(Auto a)
{
	return a.Oil;
}
int Driver::GetIns(Auto a)
{
	return a.Insurance;
}
long Driver::GetMile(Auto a)
{
	return a.Mile;
}
// SET-методы
int Driver::SetBrand(Auto &a) 
{ char mBrand[50]="";
int len_name=30;
int lenA = 50; 
do {
	cout<<"Enter brand(введите марку): "; cin>>mBrand; lenA = strlen(mBrand);
	}while(lenA>=len_name);
	if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR Brand !!!"<< endl; 
return 0; 
} 
a.Brand = new char [lenA+1]; 
strcpy(a.Brand, mBrand); 
return 1; 
}
int Driver::SetColor(Auto &a) 
{ char mColor[50]=""; 
	int len_name=30;
int lenA = 50; 
do {
	cout<<"Enter color(Введите цвет): ";
	cin>>mColor;lenA = strlen(mColor); 
	}while(lenA>=len_name);
if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR Color !!!"<< endl; 
return 0; 
} 
a.Color = new char [lenA+1]; 
strcpy(a.Color, mColor); 
return 1; 
} 

int Driver::SetT(Auto &a) 
{char mType[50]="";
	int len_name=30;
int lenA = 50;strlen(mType); 
do {
	cout<<"Enter type(Введите тип): ";
	cin>>mType;lenA = strlen(mType); 
	}while(lenA>=len_name);
if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR type !!!"<< endl; 
return 0; 
} 
a.Type = new char [lenA+1]; 
strcpy(a.Type, mType); 
return 1; 
} 

int Driver::SetLP(Auto &a) 
{ char mLP[50]=""; 
	int len_name=30;
int lenA = 50; 
do {
	cout<<"Enter license plate(Введите гос.номер): ";
	cin>>mLP;lenA = strlen(mLP); 
	}while(lenA>=len_name);

if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR Licensplate !!!"<< endl; 
return 0; 
} 
a.Licenseplate = new char [lenA+1]; 
strcpy(a.Licenseplate, mLP); 
return 1; 
} 
int Driver::SetMax(Auto &a) 
{int mMaxSpeed; char s[50]="";
cout<<"Enter max speed(Введите макс.скорость): ";	cin>>s;
mMaxSpeed=atoi(s);
while ((mMaxSpeed<=0)||(mMaxSpeed>=1000)){cout<<"Error input, try again"<<endl;cin>>s;mMaxSpeed=atoi(s);};
a.MaxSpeed=mMaxSpeed;
return 1;
}
int Driver::SetOil(Auto &a) 
{ int mOil; char s[50]="";
	cout<<"Enter oil(Введите бензин): ";cin>>s;
mOil=atoi(s);
while ((mOil<=0)||(mOil>=1000)){cout<<"Error input, try again"<<endl;cin>>s;mOil=atoi(s);};
a.Oil=mOil;
return 1;
}
int Driver::SetIns(Auto &a) 
{ int mInsurance; char s[50]="";
	cout<<"Enter insurance(Введите количество лет страховки): "; cin>>s;
mInsurance=atoi(s);
while ((mInsurance<=0)||(mInsurance>=1000)){cout<<"Error input, try again"<<endl;cin>>s;mInsurance=atoi(s);};
a.Insurance=mInsurance;
return 1;
}
long Driver::SetMile(Auto &a) 
{long mMile; char s[50]="";
	cout<<"Enter miles(Введите пробег): "; cin>>s;
mMile=atoi(s);
while ((mMile<=0)||(mMile>=10000000)){cout<<"Error input, try again"<<endl;cin>>s;mMile=atoi(s);};//
a.Mile=mMile;
return 1;
} 
//устпновить машину
int Driver::SetAuto(Auto &a)
{
 return SetBrand(a)&&SetColor(a)&&SetMax(a)&&SetT(a)&&SetLP(a)&&SetMile(a)&&SetOil(a)&&SetIns(a);
}

//получить машину
void Driver::GetAuto(Auto a)
{	cout<<"Auto(Машина)"<<endl;
cout<<"Brand(Марка): "<<a.Brand;
cout<<"Color(Цвет): "<<a.Color;
cout<<"MaxSpeed(Макс.скорость): "<<a.MaxSpeed;
cout<<"Type(Тип): "<<a.Type; 
cout<<"Licenseplate(Гос.номер): "<<a.Licenseplate;
cout<<"Mile(Пробег): "<<a.Mile;
cout<<"Oil(Бензин): "<<a.Oil;
cout<<"Insurance(Стаховка на): "<<a.Insurance;
}

/////////////////////////////////////////
//получить объект
void Driver::GetAr(int j)
{
			  arrad[j]->print();
		 ++(*(arrad[j]));
              	  arrad[j]->print();
}
 //добавить инфу
void Driver::Add()
{
	arrad[k] = new Driver(GetFN(),GetLN(),GetOtch(),GetAge(),Code,Stage);
	arrad[k++]->SetInfo();
}
//вывод данных
void Driver::Display()
{
	for(int j = 0; j<k; j++)
	{
		cout <<(j+1)<<endl;
       cout <<" Driver(Водитель) "<<endl; 
	arrad[j]->print();

	}
}
//запись в файл
void Driver::write()
{fstream pb(s2, ios::out|ios::app);
if(!pb){cout<<"You can`t write or read. Error file\n";}
for(int j = 0; j<k; j++)
	{
    pb<<"Driver(Водитель) №"<<j+1<<": ";
	pb<<(*arrad[j]); cout<<endl;
	arrad[j]->print();
}
}
//ввод в файл
ostream& operator<<(ostream &stream, Driver &o)
{
	stream<<o.GetFN() <<" ";
	stream<<o.GetLN() <<" ";
	stream<<o.GetOtch() <<" ";
	stream<<o.GetAge() <<" ";
	stream<<o.Code<<" ";
	stream<<o.Stage<<"\n";
	return stream;
}
//получить объект
void Driver::GetAr1(int j)
{
	cout<<endl;
   cout<<(arrad[j]->GetInfo());
}
//получить инфу
char* Driver::GetInfo()
{   char info[1]="";
	Person::print();
	cout<<"Code: "<<Code<<endl;
	cout<<"Stage: "<<Stage<<endl;
	return info;
}
//получить фио
char* Driver::GetFIO()
{
	return Person::GetFIO();
}
//установить код 
void Driver::sset1(int j)
{
	char mcode[3]="B1";
   arrad[j]->SetCode(mcode);
}
//установить код
void Driver::SetCode(char *mCode)
{	int len_name=30;
int lenA = strlen(mCode); 
if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR code !!!"<< endl; 
} 
Code = new char [lenA+1]; 
strcpy(Code, mCode); 
}
//получить количество объектов
int Driver::Ret()
{
	return k;
}