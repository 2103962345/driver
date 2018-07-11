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
//���� � �����
void Driver::File() 
{
ifstream fin("config.txt");
getline(fin, str, '\n');
s2 = new char[str.size() + 1];
strcpy(s2, str.c_str());
}

Driver::Driver()    //����������� ��� ����������
{
 Code=new char[4];
 strcpy(Code,"B");
 Stage=1;
}

Driver::Driver(char* FN, char* LN, char* Otch, int NAge, char* mCode, int mStage):Person(FN,LN,Otch,NAge) //����������� � �����������
{
	 Code=new char[strlen(mCode)+1];
	 strcpy(Code,mCode);
	 Stage=mStage;
}

//GET-������
char* Driver::GetCode() //�������� ���
{
	return Code;
}
int Driver::GetStage() // �������� ���� ��������
{
	return Stage;
}
//Set-������
int Driver::SetCode1() //���������� �������� ���� 
{ char  mCode[50]=""; int ch;
	int len_name=4;
	int lenA=50;
	do {
	cout<<"Enter code(������� ���): ";cin>>mCode;lenA = strlen(mCode);
	}while(lenA>=len_name);
if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR code !!!"<< endl; 
}
Code = new char [lenA+1]; 
strcpy(Code, mCode); 
return 0;
} 
int Driver::SetStage()  // ���������� ����
{ int mStage;
	char s[50]="";
cout<<"Enter Stage(������� ����): ";	cin>>s;
mStage=atoi(s);
if(Age>19){while((mStage<=0)||(mStage>(Age-18))){cout<<"Error input, try again"<<endl;cin>>s;mStage=atoi(s);};}
else while(mStage!=0){cout<<"Error input, try again"<<endl;cin>>s;mStage=atoi(s);};
Stage=mStage;
return 1;
} 

// ����� ������������ ��������� �������
void Driver::print()
{ 
fstream pb(s2, ios::out|ios::app);
if(!pb){cout<<"You can`t\n";}
cout.setf(ios::left);  
Person::print(); 
cout.width(20); cout<<"Code(���): "<<GetCode();cout<<endl;
cout.width(10); cout.precision(2); 
cout.width(20); cout<<"Stage(����): "<<GetStage();cout<<endl;
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
//Set-������
int Driver::SetDriver()
{
	return SetStage() && SetCode1();
}
void Driver::SetInfo() //���������� �������� ��������
{	char reply; 
	cout<<"Driver: "<<endl;
	Person::SetInfo();
	Driver::SetDriver();
   	nl=0; 
	cout<<"License Tag(������������ �����):"<<endl;
	lt[nl]=new B;
	lt[nl++]->getData();
		int i=0;
	cout << "Auto(����): " << endl; 
	aut=new Auto;SetAuto(*aut);
	}

//����������
Driver::~Driver()
{
	delete driver;
	delete Code;
}

//���������� �������� ��������� ++ 
 void Driver::operator++()//��������� ���� ��������
	{
		 ++Stage;
		 ++Age;
	}

////////////////////////////////////////////
//GET-������
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
// SET-������
int Driver::SetBrand(Auto &a) 
{ char mBrand[50]="";
int len_name=30;
int lenA = 50; 
do {
	cout<<"Enter brand(������� �����): "; cin>>mBrand; lenA = strlen(mBrand);
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
	cout<<"Enter color(������� ����): ";
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
	cout<<"Enter type(������� ���): ";
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
	cout<<"Enter license plate(������� ���.�����): ";
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
cout<<"Enter max speed(������� ����.��������): ";	cin>>s;
mMaxSpeed=atoi(s);
while ((mMaxSpeed<=0)||(mMaxSpeed>=1000)){cout<<"Error input, try again"<<endl;cin>>s;mMaxSpeed=atoi(s);};
a.MaxSpeed=mMaxSpeed;
return 1;
}
int Driver::SetOil(Auto &a) 
{ int mOil; char s[50]="";
	cout<<"Enter oil(������� ������): ";cin>>s;
mOil=atoi(s);
while ((mOil<=0)||(mOil>=1000)){cout<<"Error input, try again"<<endl;cin>>s;mOil=atoi(s);};
a.Oil=mOil;
return 1;
}
int Driver::SetIns(Auto &a) 
{ int mInsurance; char s[50]="";
	cout<<"Enter insurance(������� ���������� ��� ���������): "; cin>>s;
mInsurance=atoi(s);
while ((mInsurance<=0)||(mInsurance>=1000)){cout<<"Error input, try again"<<endl;cin>>s;mInsurance=atoi(s);};
a.Insurance=mInsurance;
return 1;
}
long Driver::SetMile(Auto &a) 
{long mMile; char s[50]="";
	cout<<"Enter miles(������� ������): "; cin>>s;
mMile=atoi(s);
while ((mMile<=0)||(mMile>=10000000)){cout<<"Error input, try again"<<endl;cin>>s;mMile=atoi(s);};//
a.Mile=mMile;
return 1;
} 
//���������� ������
int Driver::SetAuto(Auto &a)
{
 return SetBrand(a)&&SetColor(a)&&SetMax(a)&&SetT(a)&&SetLP(a)&&SetMile(a)&&SetOil(a)&&SetIns(a);
}

//�������� ������
void Driver::GetAuto(Auto a)
{	cout<<"Auto(������)"<<endl;
cout<<"Brand(�����): "<<a.Brand;
cout<<"Color(����): "<<a.Color;
cout<<"MaxSpeed(����.��������): "<<a.MaxSpeed;
cout<<"Type(���): "<<a.Type; 
cout<<"Licenseplate(���.�����): "<<a.Licenseplate;
cout<<"Mile(������): "<<a.Mile;
cout<<"Oil(������): "<<a.Oil;
cout<<"Insurance(�������� ��): "<<a.Insurance;
}

/////////////////////////////////////////
//�������� ������
void Driver::GetAr(int j)
{
			  arrad[j]->print();
		 ++(*(arrad[j]));
              	  arrad[j]->print();
}
 //�������� ����
void Driver::Add()
{
	arrad[k] = new Driver(GetFN(),GetLN(),GetOtch(),GetAge(),Code,Stage);
	arrad[k++]->SetInfo();
}
//����� ������
void Driver::Display()
{
	for(int j = 0; j<k; j++)
	{
		cout <<(j+1)<<endl;
       cout <<" Driver(��������) "<<endl; 
	arrad[j]->print();

	}
}
//������ � ����
void Driver::write()
{fstream pb(s2, ios::out|ios::app);
if(!pb){cout<<"You can`t write or read. Error file\n";}
for(int j = 0; j<k; j++)
	{
    pb<<"Driver(��������) �"<<j+1<<": ";
	pb<<(*arrad[j]); cout<<endl;
	arrad[j]->print();
}
}
//���� � ����
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
//�������� ������
void Driver::GetAr1(int j)
{
	cout<<endl;
   cout<<(arrad[j]->GetInfo());
}
//�������� ����
char* Driver::GetInfo()
{   char info[1]="";
	Person::print();
	cout<<"Code: "<<Code<<endl;
	cout<<"Stage: "<<Stage<<endl;
	return info;
}
//�������� ���
char* Driver::GetFIO()
{
	return Person::GetFIO();
}
//���������� ��� 
void Driver::sset1(int j)
{
	char mcode[3]="B1";
   arrad[j]->SetCode(mcode);
}
//���������� ���
void Driver::SetCode(char *mCode)
{	int len_name=30;
int lenA = strlen(mCode); 
if(lenA==0 || lenA >=len_name) 
{cerr<< "ERROR code !!!"<< endl; 
} 
Code = new char [lenA+1]; 
strcpy(Code, mCode); 
}
//�������� ���������� ��������
int Driver::Ret()
{
	return k;
}