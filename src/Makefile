EXE = conv_engine
OBJ = main.o option.o

UTEST = unit_test
UTEST_OBJ = test.o option.o rgbapixel.o png.o depth.o kernel.o

CXX = g++
LDX = g++

CXXFLAGS = -std=c++11 -stdlib=libc++ -c -O3 -Wall -Wextra -pedantic
LDXFLAGS = -std=c++11 -stdlib=libc++ -lpng -lboost_program_options -lc++abi -lpthread
LDFLAGS+="-L/usr/local/Cellar/boost/1.70.0/lib/"

all : $(EXE)

$(EXE) : $(OBJ)
	$(LDX) $(LDXFLAGS) -o $(EXE) $(OBJ)

test : $(UTEST_OBJ)
	$(LDX) $(LDXFLAGS) -o $(UTEST) $(UTEST_OBJ)

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

test.o : test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

option.o : option.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

depth.o : depth.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

kernel.o : kernel.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

png.o : png.cpp png.h
	$(CXX) $(CXXFLAGS) -o $@ png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) -o $@ rgbapixel.cpp

clean:
	rm -f *.o $(EXE) $(UTEST)
