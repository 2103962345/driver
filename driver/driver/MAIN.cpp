//������������� �������
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;
#include "Auto.hpp"
#include "Person.hpp"
#include "Driver.hpp"
#include "B.hpp"
#include "BE.hpp"
#include "B1.hpp"
#include "LicenseTag.hpp"
//��������� �������
void ab_pro(); 
void ab_au(); 
void change();
void comp_age();
void cr_base();
void create_obj();
void create_sys();
void FIO();
void help();
void getin();
void main_menu();
void menu_help();
void menu_obj();
void menu_sys();
void LoadCaption(int k);
void op_man();
void over_sta();
void show_sys();
void sset();
void read_f();
void view();
void write_f();
void zastavka();
// ������ ���������
char any_key[]="Press any key to continue...";
char ex[]="Press Esc to exit";
const int CCAPT=50;
const int LCAPT=50;
int k;
char mas_cap[CCAPT][LCAPT];
int lang = 0;
int reply;
// �������
Person person;
Driver driver;
Auto aut;
B b;
// ������� ���� ����������
void zastavka()
{
system("cls");
cout <<endl;
LoadCaption(1);
reply=_getch();
if(reply==109){
	system("cls");
	main_menu();}
else if(reply==108){if(lang)lang=0; else lang=1;}
system("cls");
zastavka();
}
// ������� ����
void main_menu()
{
LoadCaption(3);
cout << endl;
reply=_getch();
switch(reply)
{
case 49: zastavka(); break;
case 50: view(); break;
case 51: menu_help(); break;
case 52:case 101:case 27: exit(-1); break;
case 108: if(lang)lang=0; else lang=1; LoadCaption(3); main_menu();break;
default:
cerr<<"You are mistaken. Press any "<<
" key and then type the option "<<
" number." <<endl; getch();
system("cls");
main_menu();
}
cout << any_key << endl; getch();
}

// ���� ������
void menu_help()
{  
system("cls");
cout <<endl;
LoadCaption(4);
cout << endl;
reply=_getch();
switch(reply)
{
case 49: help(); break; //1 �������
case 50: ab_pro(); break; //2 � ���������
case 51: ab_au(); break; //3 �� ������
case 52: op_man(); break; //4 ���������� ���������
case 109: case 27: system("cls"); main_menu(); break;//m ����
case 108: if(lang)lang=0; else lang=1; LoadCaption(4); menu_help();break; // l ����� �����
default:
cerr<<"You are mistaken. Press any "<<
" key and then type the option "<<
" number." <<endl; getch();
system("cls");
menu_help();
}
cout << any_key << endl; getch();
}
//����� ���� �������
void help()
{  
	system("cls");
cout <<endl;
LoadCaption(2);
cout << endl;
reply=_getch();
if(reply==109||reply==8){
	system("cls");
	menu_help();}
else if(reply==108){if(lang)lang=0; else lang=1;}
system("cls");
help();
}
//����� ����� � ���������
 void ab_pro()
 {
	 system("cls");
cout <<endl;
LoadCaption(5);
cout << endl;
reply=_getch();
if(reply==109||reply==8){
	system("cls");
	menu_help();}
else if(reply==108){if(lang)lang=0; else lang=1;}
system("cls");
ab_pro();
 }
//����� ����� �� ������
void ab_au()
{
system("cls");
cout <<endl;
LoadCaption(6);
cout << endl;
reply=_getch();
if(reply==109||reply==8){
	system("cls");
	menu_help();}
else if(reply==108){if(lang)lang=0; else lang=1;}
system("cls");
ab_au();
}
//����� ����� ���������� ����������
void op_man()
{
system("cls");
cout <<endl;
LoadCaption(7);
cout << endl;
reply=_getch();
if(reply==109||reply==8){
	system("cls");
	menu_help();}
else if(reply==108){if(lang)lang=0; else lang=1;}
system("cls");
op_man();
}

//����� �����
void LoadCaption(int k)
 {char nfile[16], * nfile_r, * nfile_a;
  string line;
	 if(k==1) {nfile_a="condition_a.txt";
               nfile_r="condition_r.txt";}
	 if(k==2) {nfile_a="caption_a.txt";
               nfile_r="caption_r.txt";}
	 if(k==3) {nfile_a="menu_a.txt";
               nfile_r="menu_r.txt";}
	 if(k==4) {nfile_a="menu_h_a.txt";
               nfile_r="menu_h_r.txt";}
	 if(k==5) {nfile_a="abpro_a.txt";
               nfile_r="abpro_r.txt";}
	 if(k==6) {nfile_a="abau_a.txt";
               nfile_r="abau_r.txt";}
	 if(k==7) {nfile_a="opm_a.txt";
               nfile_r="opm_r.txt";}
	 if(k==8) {nfile_a="result_a.txt";
               nfile_r="result_r.txt";}
	 if(k==9) {nfile_a="menu_obj_a.txt";
               nfile_r="menu_obj_r.txt";}
	 if(k==10) {nfile_a="view_a.txt"; // menu system
               nfile_r="view_r.txt";}
	 if(k==11) {nfile_a="menu_sys_a.txt"; // menu driver
               nfile_r="menu_sys_r.txt";}
  if(lang) strcpy(nfile, nfile_r);
  else strcpy(nfile, nfile_a);
  ifstream fcapt;
  fcapt.open(nfile);
  if(fcapt.fail())
  {
   cerr<<"File "<<nfile<<"isn`t open"<<endl;
   getch();
   exit(-1);
  }
  system("cls");
   while ( getline (fcapt,line) )
    {
      cout << line << '\n';
    }
 }
// ����  
void view() 
{ 
 LoadCaption(10);
cout << endl;
cout << ex << endl;
	reply=_getch();
switch(reply)
{
case 49: menu_sys(); break;//1 ���� ������������
case 50: menu_obj(); break;//2 ���� ��������
case 51: write_f(); cout<<endl<<"Done"; view(); break;//3 ������ � ����
case 52:system("cls"); read_f(); view();  break;//4 ������ �� �����
case 53: case 27: case 109: main_menu();//5
case 108: if(lang)lang=0; else lang=1; LoadCaption(10); view();break;//l
default:
cerr<<"You are mistaken. Press any "<<
" key and then type the option "<<
" number." <<endl; getch();
system("cls");
view();
}
cout << any_key << endl; getch();
reply=_getch();
if(reply==109||reply==8){
	system("cls");
	main_menu();
}
}
//���� ������������
void menu_sys()
{	
 LoadCaption(11);
cout << endl;
cout << ex << endl;
	reply=_getch();
switch(reply)
{
case 49: create_sys(); break;//1 ������� �������
case 50: show_sys();menu_sys();  break;//2 �������� �������
case 51: write_f(); cout<<endl<<"Done"; menu_sys(); break;//3 �������� � ����
case 52: system("cls");read_f(); menu_sys(); break;//4 ��������� ����
case 53: case 27: case 109: view();//5
case 108: if(lang)lang=0; else lang=1; LoadCaption(11); menu_sys();break;
default:
cerr<<"You are mistaken. Press any "<<
" key and then type the option "<<
" number." <<endl; getch();
system("cls");
menu_sys();
}
cout << any_key << endl; getch();
reply=_getch();
if(reply==109||reply==8){
	system("cls");
	view();}
}
//������� ��� �������
void create_sys(){
	system("cls");
cout << "Do you have lisence tag?(Press y for yes) : " << endl;
 reply=_getch();
 if (reply=='y') {driver.Add();}
 else{ person.Add();}
cout << "For repeat enter write y" << endl; reply=_getch();
if (reply=='y') {
	create_sys();} else menu_sys(); 
}
//�������� �������
void show_sys()
{system("cls");
person.Display();
driver.Display();
cout << any_key << endl; getch(); 
} 

//���� ��������
void menu_obj()
{	
 LoadCaption(9);
cout << endl;
cout << ex << endl;
	reply=_getch();
switch(reply)
{
case 49: create_obj(); break;//1 
case 50: show_sys(); menu_obj(); break;//2 �������� �����-�� ���� ������
case 51: case 27: case 109: view();//5
case 108: if(lang)lang=0; else lang=1; LoadCaption(9); menu_obj();break;
default:
cerr<<"You are mistaken. Press any "<<
" key and then type the option "<<
" number." <<endl; getch();
system("cls");
menu_obj();
}
cout << any_key << endl; getch();
reply=_getch();
if(reply==109||reply==8){
	system("cls");
	main_menu();}
}
//����� ���������� ����������
void create_obj()
{
	cr_base();
}
// ������� ��� ������ � ��������� 
void cr_base() 
{	system("cls"); 
	cout<<"1.Overload Stage(++)(��������� ����(++))"<<endl;
	cout<<"2.Compare ages(<)(�������� ��������(<))"<<endl;
	cout<<"3.Middle Age(������� �������)"<<endl;
	cout<<"4.FIO(�.�.�.)"<<endl;
	cout<<"5.Get driver info(�������� ���������� � ��������)"<<endl;
	cout<<"6.Change person(�������� ������ ��������)"<<endl;
	cout<<"7.Set code(���������� ���)"<<endl;
	cout<<"8.Exit(�����)"<<endl;
	reply=_getch();
switch(reply)
{
case 49: over_sta(); break;//1 ��������� ����
case 50: comp_age(); break;//2 �������� ��������
case 51: person.MidAge(); break; //3 ������� �������
case 52: FIO();break; //4 ���
case 53: getin();break;//5 info driver
case 54: change();break;//6 �������� ��������
case 55: sset();break;//7 ���������� ���
case 56:case 27: case 109:system("cls");menu_obj();//8
default:
cerr<<"You are mistaken. Press any "<<
" key and then type the option "<<
" number." <<endl; getch();
system("cls");
menu_obj();
}
cout << any_key << endl; getch();
reply=_getch();
if(reply==109||reply==8){
	system("cls");
	main_menu();}
}

//�������� � ����
void write_f()
{  
	person.write();
	driver.write();
}
//������ �� �����
void read_f()
{
 person.read();
 cout << any_key << endl; getch();
}
//��������  ���� ��������
void getin()
{int nn;
nn=driver.Ret();
if(nn==0)cout<<"Error"<<endl;
else{
    int n;
	do{
		cout<<"\nEnter number driver: ";
	cout<<"\n������� ����� ��������: ";
	cin>>n;
	}while(n<=0||n>nn);
	driver.GetAr1(n-1);
	cout<<endl;}
}
//�������� ���� ��������
void change()
{
	int n,nn;
nn=person.Ret();
if(nn==0)cout<<"Error"<<endl;
else
{ do{
	cout<<"\nEnter number person: ";
	cout<<"\n������� ����� ��������: ";
	cin>>n;
} while(n<=0||n>nn);
	person.oper(n-1);
}
cout<<endl;
}
//���������� ���
void sset()
{
	int nn;
	nn=driver.Ret();
	if(nn==0)cout<<"Error"<<endl;
	else{
    int n;
	do{
		cout<<"\nEnter number driver: ";
	cout<<"\n������� ����� ��������: ";
	cin>>n;
	}while(n<=0||n>nn);
driver.sset1(n-1);
cout<<endl;}

}
//����� �.�.� ��������
void FIO(){
    int n,nn;
nn=person.Ret();
if(nn==0)cout<<"Error"<<endl;
else
{ do{
	cout<<"\nEnter number person: ";
	cout<<"\n������� ����� ��������: ";
	cin>>n;
} while(n<=0||n>nn);
	person.GetAr(n-1);
}
cout<<endl;
}
//�������� ��������
void comp_age()
{ int nn;
nn=person.Ret();
if(nn==0||nn==1)cout<<"Error"<<endl;
else
{
	  int n;
	int k;
	do{
    cout<<"\nEnter number person 1: ";
	cout<<"\n������� ����� 1 ��������: ";
	cin>>n;
	}while(n>nn||n<=0);
		do{
	cout<<"\nEnter number person 2:";
	cout<<"\n������� ����� 2 ��������: ";
	cin>>k;
		}while(k>nn||k<=0||n==k);
	person.GetAr2(n-1,k-1);
	cout<<endl;}
}
//��������� ����
void over_sta()
{
	int nn;
	nn=driver.Ret();
	if(nn==0)cout<<"Error"<<endl;
	else{
    int n;
	do{
		cout<<"\nEnter number driver: ";
	cout<<"\n������� ����� ��������: ";
	cin>>n;
	}while(n<=0||n>nn);
driver.GetAr(n-1);
cout<<endl;}
}
// ������� �������
int main()
{  
driver.File();
person.File();
SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
system("cls");
zastavka();
return 0;
}