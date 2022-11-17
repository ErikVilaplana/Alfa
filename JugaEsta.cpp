#include "JugaEsta.h"
void  JugaEsta::setName(sf::String name)
{
    _name = name;
}


sf::String JugaEsta::getName()
{
    return _name;

}
float JugaEsta::getPts()
{
    return _pts;
}

void JugaEsta::setPts(int pts)
{
    _pts=pts;
}
