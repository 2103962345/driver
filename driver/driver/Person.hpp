#pragma once
#include <iostream>
#include <fstream>
using namespace std;
	const int MAXEM = 50; //���������� ��������
class Person 

{private:
	   static int  n; //���������� �������
	         char* FirstName; //���
	         char* LastName; //�������
	         char* Otchestvo; //��������
	         char* FIO; //���
	       static  Person* arrap[]; // ������ ����������
protected:
	          int  Age;//�������
public:
	               Person(); //����������� �� ���������
				   Person(char* FN, char* LN, char* Otch, int NAge); // ����������� � �����������
 	              ~Person();//����������
	         char* GetFIO(); // ����� ���
	          int  GetAge(); //����� �������� ��������
	         void  GetInfo();  //�������� ���������� � ��������
              int  SetPerson(); //���������� ���� ��������
	 virtual void  SetInfo(); //���������� ����������
	          int  SetFN();  //��������� ���
              int  SetLN();  //���������� �������
	          int  SetOtch(); //���������� ��������
              int  SetAge();  //���������� �������
	         char* GetOtch(); //�������� ��������
   	         char* GetFN(); //�������� ���
	         char* GetLN(); //�������� �������
             void  GetAr(int j); // �������� ������
			 void  GetAr2(int j,int k); //�������� 2 �������
     virtual void  print();  //����� �� �����
	         void  read(); //������
			 void  write(); //������� � ����
	          int  MidAge(); //������� �������
          virtual  void  Add(); // dobavit chela
          virtual void  Display(); //vivod dannih obo vseh
		  int Ret(); //������� ���������� ��������
		  void oper(int j); //�������� ������ � ��������
void File(); //���� � �����
friend bool operator<(const Person &p1,const Person &p2); //�������� 2 �����
friend bool operator<(const Person &p1,const int p2); //������ 18
friend bool operator<(const int p2,const Person &p1);//������ 18
friend ostream& operator<<(ostream &stream, Person &o); //����� � ����
friend istream& operator>>(istream &stream, Person &o); //���� �� �����
	};
