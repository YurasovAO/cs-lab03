#include "../svg.h"
#include <cassert>
#include <iostream>
#include <sstream>
void test1()
{
string input;
string input2;
stringstream source (input);
svg_line2(17,1,416,1,"grey",2,source);
string expected_result="<line x1='17' y1='1' x2='416' y2='1' stroke='grey' stroke-width='2' stroke-dasharray = '10 10' />";

getline(source,input2);
cout<<input2;
assert(input2==expected_result);


}
void test2 ()
{

string input;
string input2;
stringstream source (input);
svg_line2(17,1,416,1,"grey",2,source);
string expected_result="<line x1='17' y1='1' x2='17' y2='1' stroke='grey' stroke-width='2' stroke-dasharray = '10 10' />";

getline(source,input2);
cout<<input2;
assert(input2==expected_result);


}
void test3 ()
{

string input;
string input2;
stringstream source (input);
svg_line2(17,1,416,1,"grey",2,source);
string expected_result="<line x1='17' y1='1' x2='1705' y2='1' stroke='grey' stroke-width='2' stroke-dasharray = '10 10' />";

getline(source,input2);
cout<<input2;
assert(input2==expected_result);


}
void test4 ()
{

string input;
string input2;
stringstream source (input);
svg_line2(17,1,416,1,"grey",2,source);
string expected_result="<line x1='17' y1='1' x2='17' y2='3000' stroke='grey' stroke-width='2' stroke-dasharray = '10 10' />";

getline(source,input2);
cout<<input2;
assert(input2==expected_result);


}

void test5 ()
{

string input;
string input2;
stringstream source (input);
svg_line2(17,1,416,1,"grey",2,source);
string expected_result="<line x1='0' y1='0' x2='0' y2='0' stroke='grey' stroke-width='2' stroke-dasharray = '10 10' />";

getline(source,input2);
cout<<input2;
assert(input2==expected_result);


}
void test6()
{
    string input;
string input2;
stringstream source (input);
svg_line2(17,1,416,1,"grey",2,source);
string expected_result="<line x1='0' y1='0' x2='0' y2='0' stroke='white' stroke-width='2' stroke-dasharray = '10 10' />";

getline(source,input2);
cout<<input2;
assert(input2==expected_result);


}


int main()
{

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

}
