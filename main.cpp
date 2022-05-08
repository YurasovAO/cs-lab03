#include "histogram.h"
#include <iostream>
#include <vector>
#include "svg.h"
using namespace std;

vector<double>input_numbers(size_t count);


vector <size_t> make_histigram(double max,double min,size_t bin_count,const vector <double> &numbers);






vector<double>input_numbers(istream& in,size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}






vector <size_t>  make_histigram(double max,double min,size_t bin_count,const vector <double> &numbers)
{
    vector <size_t> result(bin_count);
    for (double number : numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count)
        {
            bin--;
        }
        result[bin]++;
    }
    return result;
}


int main()
{
    // ¬вод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(cin,number_count);
    cerr << "Enter numbers: ";
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;





    // ќбработка данных
    double min;
    double max;
    string stroke ="blue";
    size_t wid =2;
    size_t X1=0;
    size_t X2=0;
    size_t hist_hight =0;
    size_t s=1;
    find_minmax(numbers,min,max);
    const auto bins=make_histigram(max,min,bin_count,numbers);
    show_histogram_svg(bins,bin_count,stroke,X1,X2 ,hist_hight,s ,wid);
  svg_line2(X1,s,X2,s,"grey",wid,cout);
  svg_line2(X2,s,X2,hist_hight,"grey",wid,cout);
  svg_line2(X2,hist_hight,X1,hist_hight,"grey",wid,cout);
  svg_line2 (X1,hist_hight,X1,s,"grey",wid,cout);
  fin();
    return 0;
}










