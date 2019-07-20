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
        multiplier[i] = ker[i]
    }
}

Kernel::Kernel operator = (Kernel &ker)
{
    int size = ker.getSize();
    Kernel.multiplier.resize(size);
    
    for(int i = 0; i < size; i++)
    {
        Kernel.multiplier[i] = ker[i];
    }
}


Kernel::Kernel operator [] (int index)
{
    if (index >= self.multiplier.size())
    {
        std::cout<<"Index is out of the range of the kernel";
    }
    else
        return self.multiplier[index];
}

int Kernel::getSize()
{
    return multiplier.size();
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
