#include "../svg.h"
#include <cassert>
#include <vector>
void test()
{
size_t X=1;
size_t Y=1;
size_t L=1;
const auto TEXT_LEFT = 20;
string stroke ="blue";
    size_t wid =2;
show_histogram_svg({3,3,4,4,4,4,4,5,5,5 },3,stroke,wid,X,Y,L);
assert(X ==TEXT_LEFT-3);
assert(Y==L+53);

}

int main()
{

 test();


}
