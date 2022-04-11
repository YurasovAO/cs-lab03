#include <iostream>
#include <cassert>
#include <vector>
#include "test4.h"
void test4(vector <double> x11)
{
    size_t q=0;
    for(double fin:x11)
    {
        q++;
    }

    assert(q==1);

}








int main()
{

    vector <double> x11 (1);
    for(size_t i=0;i<1;i++)
    {
        cout<<"x11["<<i<<"]=";
        cin>>x11[i];
    }


}
