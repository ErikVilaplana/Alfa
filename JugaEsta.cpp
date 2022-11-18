#include "JugaEsta.h"
void  JugaEsta::setName(const char * name)
{
   strcpy(_name , name) ;
}


const char* JugaEsta::getName()
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
