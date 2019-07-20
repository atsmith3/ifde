EXE = conv_engine
OBJ = main.o png.o rgbapixel.o

CXX = g++
LDX = g++

CXXFLAGS = -std=c++11 -stdlib=libc++ -c -O3 -Wall -Wextra -pedantic
LDXFLAGS = -std=c++11 -stdlib=libc++ -lpng -lc++abi -lpthread

all : $(EXE)

$(EXE) : $(OBJ)
	$(LDX) $(LDXFLAGS) -o $(EXE) $(OBJ)

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

png.o : png.cpp png.h
	$(CXX) $(CXXFLAGS) -o $@ png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) -o $@ rgbapixel.cpp

clean:
	rm -f *.o *.a $(EXE)
