#ifndef KERNEL_H
#define KERNEL_H

#include <vector>

class Kernel{
private:
    std::vector<int> multiplier;
public:
    Kernel();
    Kernel(std::vector<int> mults);
    Kernel(Kernel &ker);
    Kernel& operator = (Kernel &ker);
    int operator [] (int index);
    
    int getSize();
    void resizeKer(int n);
};

bool testSqrt(int n);

#endif
