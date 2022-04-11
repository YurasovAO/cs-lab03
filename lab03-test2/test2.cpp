
#include <iostream>
#include <cassert>
#include <vector>
#include "test2.h"
void test2(vector <double> &x9,double min,double max)
{
    for(double check:x9)
    {
        if(check<min)
            min=check;
        if(check>max)
            max=check;
    }

assert(max==-1);
assert(min==-3);



}
int main()
{
 vector <double> x9 (3);
double min=0;
double max=0;
    for(size_t i=0;i<3;i++)
    {
        cout<<"x9["<<i<<"]=";
        cin>>x9[i];
    }
    min=x9[0];
    max=x9[0];
test2(x9,min,max);





}
