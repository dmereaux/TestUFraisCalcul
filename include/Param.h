#ifndef PARAM_H_INCLUDED
#define PARAM_H_INCLUDED
#include <iostream>
class Param2
    {

public:

virtual ~Param2() {std::cout << "toto";}
virtual double getLimit1()=0;
virtual double getLimit2()=0;
virtual double getTaux1()=0;
virtual double getTaux2()=0;
 };

#endif // PARAM_H_INCLUDED
