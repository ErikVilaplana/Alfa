#pragma once
#include "iostream"
#include "cstring"
#include <SFML/System/String.hpp>
using namespace  std;
class JugaEsta
{
private:
    float _pts=0;
    char _name[20];
public:
    float getPts();
    void setName(const char* name);
    void setPts(int pts);
    const char * getName();
};
