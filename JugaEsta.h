#pragma once
#include "iostream"
#include "cstring"
#include <SFML/System/String.hpp>
using namespace  std;
class JugaEsta
{
private:
    float _pts=0;

    sf::String _name="";
public:
    float getPts();
    void setName(sf::String name);
    void setPts(int pts);
    sf::String getName();
};
