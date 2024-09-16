#include "CalculFrais.h"
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockParam.h"

namespace {
class demo : public::testing::TestWithParam<testing::tuple<double,double,double> >
{

 //  créer un set UP
     void SetUp() override {
         std::cout << "ceci est mon nouveau setUP";     }

};
class Param : public::testing::TestWithParam<testing::tuple<double,double> >
{
    protected:
        CalculFrais frais;
        double montant;
        double resAtt;

 //  créer un set UP
     void SetUp() override {
         std::cout << "ceci est le setUP de ma class Param";
        montant = testing::get<0>(GetParam());
        resAtt = testing::get<1>(GetParam());
   }
};

TEST(CalculTest, testSimple) {
    CalculFrais frais;
    EXPECT_DOUBLE_EQ(frais.montant(450.0),20.0);
}


TEST(CalculTest, testAvecMock) {
    MockParam toto;
    CalculFrais frais;
    EXPECT_CALL(toto,getLimit1()).WillOnce(testing::Return(200.0));
    EXPECT_CALL(toto,getLimit2()).WillOnce(testing::Return(500.0));
    frais.setLimit(&toto);
    EXPECT_DOUBLE_EQ(frais.montant(450.0),20.0);
}
TEST(CalculTest, test2) {
    MockParam toto;
    CalculFrais frais;
    EXPECT_CALL(toto,getLimit1()).WillOnce(testing::Return(200.0));
    EXPECT_CALL(toto,getLimit2()).WillOnce(testing::Return(500.0));
    frais.setLimit(&toto);
    EXPECT_DOUBLE_EQ(frais.montant(450.0),20.0);
}
TEST_P(Param, testParametrise)
{

    EXPECT_DOUBLE_EQ(frais.montant(montant),resAtt);

}
INSTANTIATE_TEST_SUITE_P(ValeurAvecTuple,Param,testing::Values(testing::make_tuple(550.0,0.0),testing::make_tuple(100,30.0)));

TEST_P(demo, test5)
{
    double op1 = testing::get<0>(GetParam());
    double op2 = testing::get<1>(GetParam());
    double res = testing::get<2>(GetParam());
    EXPECT_DOUBLE_EQ(op1*op2,res);

}
INSTANTIATE_TEST_SUITE_P(ValeurAvecTuple,demo,testing::Values(testing::make_tuple(1.0,2.0,2.0),testing::make_tuple(1.0,2.0,3.0)));
 }


int main(int argc, char**argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
