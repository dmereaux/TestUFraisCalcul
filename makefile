CXX = g++
LDFLAGS = -g C:/TP/essai/lib/libgmock.a -g C:/TP/essai/lib/libgtest.a -DGTEST_HAS_PTHREAD=0 -lgcov --coverage
INCS = -I./include  -IC:/TP/googletest-1.14.0/googletest/include -IC:/TP/googletest-1.14.0/googlemock/include
LIB = C:/TP/essai/lib/libgmock.a C:/TP/essai/lib/libgtest.a
OPTION = -Wall -fexceptions  -fprofile-arcs -ftest-coverage

all: compil1 compil2
	$(CXX) $(LDFLAGS) $(INCS)  -o testAll  CalculFrais.o TestCalculFrais.o $(LIB)

coverage :
	gcovr.exe --xml -o toto.xml
	
exec : all
	testAll.exe
compil1: 
	$(CXX)  -c $(OPTION)  ./src/CalculFrais.cpp   $(INCS)
compil2: 
	$(CXX)  -c    ./test/TestCalculFrais.cpp $(INCS)	
clean:
	cmd /C del CalculFrais.o TestCalculFrais.o
	cmd /C del CalculFrais.gcda CalculFrais.gcno iostream.gcov TestCalculFrais.gcda TestCalculFrais.gcno

mrproper: clean
	cmd /C del testAll.exe