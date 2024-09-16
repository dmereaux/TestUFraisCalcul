#ifndef CALCULFRAIS_H_INCLUDED
#define CALCULFRAIS_H_INCLUDED
#include "Param.h"
#include <string>

class CalculFrais
    {
private:
double m_limit1;
double m_limit2;

public:

CalculFrais();
virtual ~CalculFrais();

void setLimit(Param2 *x);
double montant(double total);
 };
#endif // CALCULFRAIS_H_INCLUDED
