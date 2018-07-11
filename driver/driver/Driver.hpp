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
	      static int  k;   //���������� ��������� � �������
	    unsigned int  Stage; //���� ��������
		        char* Code;  //���      
		  LicenseTag* lt[10]; //������������ �����
		  	    Auto* aut;   // ������ 
	  static  Driver* arrad[]; // ������ ��������  
public:
	      Driver(); //����������� �� ���������
          Driver(char* FN, char* LN, char* Otch, int NAge, char* mCode, int mStage); //����������� � �����������
	     ~Driver(); //����������
	void  SetInfo(); //���������� ����������
	char* GetCode(); // �������� ���
   	 int  GetStage(); //�������� ����
	void  SetLI();  //���������� ������ � ������������ ������
	void  GetLI(); //�������� ������������ �����
	 void SetCode(char *mCode);//���������� ����������
	 int  SetStage(); //�������� ����
	 friend ostream& operator<<(ostream &stream, Driver &o);//���� � ����
	 int  SetDriver(); // �������� ������
    void  print();  //����� �� �����
	void  GetA(int i); //�������� ������ � ������
	void  SetA(); //���������� ������ � ������
	/////////////////////////////////////////////////////
	void  GetAuto(Auto);  
	char* GetInfo();//���������� � �������� (���+���������+���� ��������)
	int  SetCode1();//���������� ���������� v uslovii void
	char* GetFIO();  //�������� ���
     int  SetAuto(Auto &);  //���������� ������
	char* GetColor(Auto); //�������� ����
	char* GetBrand(Auto); //�������� �����
	char* GetT(Auto); //�������� ���
	char* GetLP(Auto); //�������� ���.�����
	 int  GetIns(Auto); //�������� ���������
	 int  GetMax(Auto); //�������� ����.��������
	 int  GetOil(Auto); //�������� ������
	long  GetMile(Auto); //�������� ������
	 int  SetBrand(Auto &); //���������� �����
	 int  SetColor(Auto &); //���������� ����
	 int  SetMax(Auto &); //���������� ����.��������
	 int  SetOil(Auto &); //���������� ������
	long  SetMile(Auto &); //���������� ������
	 int  SetT(Auto &); //���������� ���
	 int  SetLP(Auto &); //���������� ���.�����
	 int  SetIns(Auto &);//���������� ���������
		 /////////////////////////////////////////////
	 void operator++(); ///��������� ����+�������
	 void  GetAr(int j); //�������� ������
	 void Driver::GetAr1(int j); //�������� ������
	 void Add(); //�������� ����������
	 void Display(); //����� �� �����
	 void File(); //���� � �����
	 void sset1(int j); //���������� ���
	 void write();	 //������ � ����
	 int Ret();//������� ���������� ��������
};
