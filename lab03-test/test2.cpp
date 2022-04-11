#include <iostream>
#include <cassert>
#include <vector>
void test1(vector <double> &testI,double & min,double &max);
void test1(vector <double> &test1,double & min,double & max)
{  min=testI[0];
   max=testI[0];
 for(double check:testI)
 {
     if(check<min)
        min=check;
     if(check>max)
        max=check;
 }



}


int main()
{

    double min=0;
    double max=0;
    vector <double> testI (3);
    for(size_t i=0;i<3;i++)
    {
        cout<<"testI["<<i<<"]=";
        cin>>test1[i];
    }
test1(testI,-600,-900);
assert(max==-1);
assert(min==-3);

}
