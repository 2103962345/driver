#pragma once
#include <iostream>
#include <fstream>
#include "Driver.hpp" 
using namespace std;
class Driver;
class Auto
{
private: 
	     char* Brand; //�����
		 char* Color; //����
		  int  MaxSpeed; //����.��������
		 char* Type; //���
		 char* Licenseplate; //���.�����
         long  Mile;  //������
          int  Oil; //������
       friend  Driver;// ������������� ����� ��������
	      int  Insurance; //���������
		
public:
	      Auto(); //����������� ��� ����������
	      Auto(char* mBrand, char* mColor, int mMaxSpeed, char* mType, char* mLP, long mMile,int mOil,int mInsuranse);//����������� � �����������
	     ~Auto(); //����������
	void  print(); ///����� �� �����
	 friend ostream& operator<<(ostream &stream, Auto &o);//���� � ����
};
