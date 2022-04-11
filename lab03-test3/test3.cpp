#include <iostream>
#include <cassert>
#include <vector>
#include "test3.h"

void test3(vector <double> &x10,double i,double j)
{


for(size_t i=0;i<3;i++)
    {
        if(x10[i]!=j)
            x10[i]=j;
        assert(x10[i]==j);
    }



}




int main()
{
    double i,j;
    vector <double> x10 (3);
    for(size_t i=0;i<3;i++)
    {
        cout<<"x10["<<i<<"]=";
        cin>>x10[i];
    }
    i=x10[0];
    j=x10[0];

 test3(x10,i,j);
}
