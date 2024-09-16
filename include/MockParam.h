#ifndef MOCKPARAM_H_INCLUDED
#define MOCKPARAM_H_INCLUDED


class MockParam : public Param2
{
public:
MOCK_METHOD(double,getLimit1,(), (override));
MOCK_METHOD(double,getLimit2,(), (override));
MOCK_METHOD(double,getTaux1,(), (override));
MOCK_METHOD(double,getTaux2,(), (override));
 };

#endif // MOCKPARAM_H_INCLUDED
