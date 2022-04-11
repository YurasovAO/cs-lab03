#include "histogram.h"
#include <iostream>
#include <vector>
#include "svg.h"
using namespace std;

vector<double>input_numbers(size_t count);


vector <size_t> make_histigram(double max,double min,size_t bin_count,const vector <double> &numbers);






vector<double>input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
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
    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    cerr << "Enter numbers: ";
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;






    // Обработка данных
    double min = numbers[0];
    double max = numbers[0];
    find_minmax(numbers,min,max);
    const auto bins=make_histigram(max,min,bin_count,numbers);

    show_histogram_svg(bins);

    // Вывод данных
    return 0;
}




