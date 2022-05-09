#include "histogram.h"
#include <iostream>
#include <vector>
#include "svg.h"
#include <curl/curl.h>
using namespace std;

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


Input read_input(istream& in,bool prompt)
{
    Input data;
    if(prompt)
    {
        cerr << "Enter number count: ";
    }

    size_t number_count;
    in >> number_count;
    if (prompt)
    {
        cerr << "Enter numbers: ";
    }
    data.numbers = input_numbers(in, number_count);
    if(prompt)
    {
        cerr<<"bin count:";

    }

    in>>data.bin_count;

    return data;
}




vector <size_t> make_histigram(double max,double min,size_t bin_count,const vector <double> &numbers);













vector <size_t>  make_histigram(Input input)
{
    double min;
    double max;
    find_minmax(input.numbers,min,max);
    vector <size_t> result(input.bin_count);
    for (double number : input.numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) *(input.bin_count));
        if (bin == input.bin_count)
        {
            bin--;
        }
        result[bin]++;
    }
    return result;
}


int main()
{
    curl_global_init(CURL_GLOBAL_ALL);
    const auto input=read_input(cin,true);
    const auto bins=make_histigram(input);
    show_histogram_svg(bins);
    return 0;
}










