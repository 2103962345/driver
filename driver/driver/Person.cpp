#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <typeinfo> // typeid()
#include <process.h> // exit()
#include "Person.hpp"
#include "Driver.hpp"
#include "B.hpp"
using namespace std;
class Driver;
Driver dr;
string str1="";
char *s1="";
int Person::n;
int c=0;
Person* Person::arrap[MAXEM]; // array ukazatelei na klass chel
Person* person;
//путь к файлу
void Person::File() 
{
ifstream fin("config.txt");
getline(fin, str1, '\n');
s1 = new char[str1.size() + 1];
strcpy(s1, str1.c_str());
}
//конструкторы
Person::Person()
{
 FirstName=new char[15];
 strcpy(FirstName,"Ivan");
 LastName=new char[30];
 strcpy(LastName,"Ivanov");
 Otchestvo=new char[20];
 strcpy(Otchestvo,"Ivanovich");
 Age=18;
 FIO=new char[100];
 strcpy(FIO,"");
}
Person::Person(char* FN, char* LN, char* Otch, int NAge)
{
	 FirstName=new char[strlen(FN)+1];
	 strcpy(FirstName,FN);
	 LastName=new char[strlen(LN)+1];
	 strcpy(LastName,LN);
	 Otchestvo=new char[strlen(Otch)+1];
	 strcpy(Otchestvo,Otch);
     Age=NAge;
}
//GET-методы
char* Person::GetFN()
{
	return FirstName;
}
char* Person::GetLN()
{
	return LastName;
}
char* Person::GetOtch()
{
	return Otchestvo;
}
int Person::GetAge()
{
	return Age;
}

char* Person::GetFIO() 
{
 strcat(FIO,"FIO: ");
 strcat(FIO,LastName);
 strcat(FIO," ");
 strcat(FIO,FirstName);
 strcat(FIO," ");
 strcat(FIO,Otchestvo);
 return FIO;
}
// SET-методы
int Person::SetFN() 
{ char fn[50]=""; int ch;
int len_name=30;
int lenA=50;
do {
	cout<<"Enter First Name(Введите имя): "; cin>>fn;lenA = strlen(fn);
	}while(lenA>=len_name);

if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR Name !!!"<< endl; 
return 0; 
} 
FirstName = new char[lenA+1]; 
strcpy(FirstName, fn); 
return 1; 
} 
int Person::SetLN() 
{ char LN[50]=""; 
	int len_name=30;
	int lenA;
	do {
	cout<<"Enter Last Name(Введите фамилию): ";cin>>LN;lenA = strlen(LN); 
	}while(lenA>=len_name);

if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR LastName !!!"<< endl; 
return 0; 
} 
LastName = new char[lenA+1]; 
strcpy(LastName, LN); 
return 1; 
} 
int Person::SetOtch() 
{ char otc[50]=""; 
	int len_name=30;
	int lenA =50;  
	do {
	cout<<"Enter Otchestvo(Введите отчество): ";cin>>otc; lenA=strlen(otc);
	}while(lenA>=len_name);

if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR Otchetvo !!!"<< endl; 
return 0; 
} 
Otchestvo = new char[lenA+1]; 
strcpy(Otchestvo, otc); 
return 1; 
} 

int Person::SetAge() 
{int NAge;
	char s[50]="";
cout<<"Enter Age(Введите возраст): ";	cin>>s;
NAge=atoi(s);
while ((NAge<=0)||(NAge>=120)){cout<<"Error input, try again"<<endl;cin>>s;NAge=atoi(s);};
Age=NAge;
return 1;
}
int Person::SetPerson()
{ 
return SetFN() && SetLN() && SetOtch() && SetAge() ; 
}
// метод візуалізації стану об'єкта 
void Person::print() 
{ 
cout.setf(ios::left); 
cout<<endl;
cout.width(20); cout<<"First name(Имя): "<<GetFN(); cout<<endl;//FirstName; 
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Otchestvo(Отчество): "<<GetOtch();cout<<endl;
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Last name(Фамилия): "<<GetLN();cout<<endl; 
cout.width(10); cout.precision(2); 
cout.width(20);cout<<"Age(Возраст): "<<GetAge();cout<<endl; 
cout.width(10); cout.precision(2); 
} 
void Person::SetInfo()
{
cout<<"Person(Человек): "<<endl; 
SetPerson();
}

//dlya faila
 //dobavit hel v spisok (OP)
void Person::Add()
{
	arrap[n] = new Person;
	arrap[n++]->SetInfo();
}

//vivod dannih
void Person::Display()
{	for(int j = 0; j<n; j++)
	{
		cout <<(j+1)<<endl;
       cout <<" Person(Человек) "<<endl; 
		arrap[j]->print();
		cout<<endl;
 	}
}
//записать в файл
void Person::write()
{fstream pb(s1, ios::out|ios::app);
if(!pb){cout<<"You can`t write or read. Error file\n";}
for(int j = 0; j<n; j++)
	{
		arrap[j]->print();
    pb<<"Person(Человек) №"<<j+1<<": ";
	pb<<(*arrap[j]); cout<<endl;
	c=j;
}

}
//чтение из файла
void Person::read()
{char ch;
	fstream pb(s1, ios::in);
if(!pb){cout<<"You can`t write or read. Error file\n\n";}
pb.seekg(0,ios::beg);
	while(!pb.eof()){
		pb.get(ch);
		if(!pb.eof())cout<<ch;
	}
	pb.clear(); 
    cout<<endl;
}
//доступ к объекту человек
void Person::GetAr2(int j,int k)
{
	arrap[j]->print();
	arrap[k]->print();
	if(*(arrap[j])<*(arrap[k])){cout<<"2 Person is older than 1"<<endl;cout<<"2 Человек старше 1"<<endl;}
	else {cout<<"1 Person is older than 2"<<endl;cout<<"1 Человек старше 2"<<endl;}
	if(*(arrap[j])<17){cout<<"You cant get license tag"<<endl;cout<<"Вы не можете получить водительские права"<<endl;}
	else {cout<<"You can get license tag and drive"<<endl;cout<<"Вы можете получить водительские права и водить"<<endl;}
	if(17<*(arrap[k])){cout<<"You can get license tag and drive"<<endl;cout<<"Вы можете получить водительские права и водить"<<endl;}
	else {cout<<"You cant get license tag"<<endl;cout<<"Вы не можете получить водительские права"<<endl;}
}
//доступ к объекту человек
void Person::GetAr(int j)
{
   cout<<(arrap[j]->GetFIO());
}
//ернуть количество объектов
int Person::Ret()
{
	return n;
}

//деструктор
Person::~Person(void)
{
	delete FirstName;
	delete LastName;
	delete Otchestvo;
	delete FIO;
}
//операто <
bool operator<(const Person &p1,const Person &p2)
{
	return (p1.Age < p2.Age);
}
//операто <
bool operator<(const Person &p1,const int p2)
{
	return (p1.Age < p2);
}
//операто <
bool operator<(const int p2,const Person &p1)
{
	return (p1.Age > p2);
}
//средний возраст
int Person::MidAge()
{int j;
	int ma=0,ma1=0,k=0; 
	if(n==0)cout<<"Error"<<endl; 
	else{
	for(j=0;j<n;j++)
	{
		ma+=(*(arrap[j])).GetAge();
	}
	cout<<"Middle age(Средний возраст)="<<(ma/n)<<endl;}
	return 1;
}
//оператор <<
ostream& operator<<(ostream &stream, Person &o)
{
	stream<<o.FirstName<<" ";
	stream<<o.LastName <<" ";
	stream<<o.Otchestvo <<" ";
	stream<<o.Age <<"\n";
	return stream;
}
void Person::oper(int j){
 cin>>*arrap[j];
}
//оператор >>
istream &operator>>(istream &stream, Person &o)
{
	cout<<"Enter FirstName ";
	stream>>o.FirstName;
	cout<<"Enter LastName ";
	stream>>o.LastName;
	cout<<"Enter Otchestvo ";
	stream>>o.Otchestvo;
	cout<<"Enter Age ";
	stream>>o.Age;
	cout<<"\n";
	return stream;
}