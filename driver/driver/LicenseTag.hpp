#pragma once
#include "Driver.hpp"
#include <iostream>
#include <fstream>
using namespace std;
class LicenseTag
{
public: 
virtual void getData()=0;//����.�������
virtual void putData()=0; // ����.�������
friend ostream& operator<<(ostream &stream, LicenseTag o);
friend istream& operator>>(istream &stream, LicenseTag &o);
};
