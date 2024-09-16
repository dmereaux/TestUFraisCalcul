#include <string>
#include "CalculFrais.h"
#include "Param.h"
#include <iostream>

CalculFrais::CalculFrais(): m_limit1(100),m_limit2(500)
{
//std::cout << "bonjour";
}
CalculFrais::~CalculFrais()
{
}

void CalculFrais::setLimit(Param2 *x)
{

    m_limit1 = x->getLimit1();
    m_limit2 = x->getLimit2();



}
double CalculFrais::montant(double total)
 {

     if (total >= m_limit2)
        return 0.0;
     else if (total >= m_limit1)
        return 20.0;
     else
        return 30.0;

    return 0.0;

}
