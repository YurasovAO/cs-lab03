#include "../svg.h"
#include <cassert>
#include <iostream>
#include <sstream>
void test2 ()
{

string input;
string input2;
stringstream source (input);
svg_line2(17,1,416,1,"grey",2,source);
string expected_result="<line x1='17' y1='1' x2='17' y2='1' stroke='grey' stroke-width='2' stroke-dasharray = '10 10' />";

getline(source,input2);
cout<<input2;
assert(input2!=expected_result);


}














int main()
{

    test2();
}
