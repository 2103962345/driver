#pragma once
#include "Driver.hpp"
#include <iostream>
#include <fstream>
using namespace std;
class LicenseTag
{
public: 
virtual void getData()=0;//вирт.функция
virtual void putData()=0; // вирт.функция
friend ostream& operator<<(ostream &stream, LicenseTag o);
friend istream& operator>>(istream &stream, LicenseTag &o);
};
