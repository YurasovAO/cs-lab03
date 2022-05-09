#include "histogram.h"
#include <iostream>
#include <vector>
#include "svg.h"
using namespace std;




struct Input {
    vector<double> numbers;
    size_t bin_count;
};
vector<double>input_numbers(size_t count);

vector<double>input_numbers(istream& in,size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}


Input read_input(istream& in)
{
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
    cerr<<"bin count:";
    in>>data.bin_count;

    return data;
}




vector <size_t> make_histigram(double max,double min,size_t bin_count,const vector <double> &numbers);













vector <size_t>  make_histigram(size_t bin_count,const vector <double> &numbers)
{  double min;
    double max;
    find_minmax(numbers,min,max);
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
    const auto input=read_input(cin);
    const auto bins=make_histigram(input.bin_count,input.numbers);
    show_histogram_svg(bins);
    return 0;
}










