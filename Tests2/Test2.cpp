#include <cassert>
#include "../histogram.h"
void test_positive() {
    double min ;
    double max;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative()
{



    double min ;
    double max;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);

}
void test_equal()
{

    double min ;
    double max;
    find_minmax({1, 1, 1}, min, max);
    assert(min == max);




}
void test_zero()
{


     double min ;
    double max;
    find_minmax({}, min, max);
    assert(min == max);



}


int main() {
    test_positive();
    test_negative();
    test_equal();
    test_zero();
}
