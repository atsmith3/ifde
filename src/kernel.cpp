#include "kernel.h"

#include <math.h>
#include <vector>
#include <iostream>

Kernel::Kernel()
{
    multiplier.resize(9,-2);
    multiplier[4] = 16;
}


Kernel::Kernel(std::vector<int>mults)
{
    //check if vector is a sqaure
    int size = mults.size();
    if(! testSqrt(size))
    {
        std::cout<<"Vector multiplier must have a perfect square size";
    }
    else
    {
        multiplier.resize(size);
        for(int i = 0; i < size; i++)
        {
            multiplier[i] = mults[i];
        }
    }
}


Kernel::Kernel(Kernel &ker)
{
    int size = ker.getSize();
    multiplier.resize(size);
    
    for(int i = 0; i < size; i++)
    {
        multiplier[i] = ker[i];
    }
}

Kernel& Kernel::operator = (Kernel &ker)
{
    int size = ker.getSize();
    this->resizeKer(size);
    for(int i = 0; i < size; i++)
    {
        this->multiplier[i] = ker[i];
    }
    return *this;
}


int Kernel::operator [] (int index)
{
    return multiplier[index];
}

int Kernel::getSize()
{
    return multiplier.size();
}

void Kernel::resizeKer(int n)
{
    multiplier.resize(n);
}

bool testSqrt(int n)
{
    int root = round(sqrt(n));
    if( root * root == n)
    {
        return true;
    }
    return false;
}
