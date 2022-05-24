#include "histogram.h"
#include <iostream>
#include <vector>
#include "svg.h"
#include <curl/curl.h>
#include <sstream>
#include <string>
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
     size_t number_count;
    if(prompt)
    {
        cerr << "Enter number count: ";
    }
     in >> number_count;
     if(prompt)
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


size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
   size_t data_size = item_size * item_count;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(reinterpret_cast<const char*>(items), data_size);
    return data_size;

}




Input
download(const string& address) {
    stringstream buffer;
    CURL* curl = curl_easy_init();
    if(curl){
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        if (res!=CURLE_OK){
            cerr<<curl_easy_strerror(res);
            exit(1);
        }
        curl_version_info_data * ver=curl_version_info(CURLVERSION_NOW);
        size_t i=0;
        while(((ver->protocols[i])))
        {
          cerr<<((ver->protocols[i]))<<endl;
          i++;
        }
        curl_easy_cleanup(curl);

    }

    return read_input(buffer, false);
}




vector <size_t> make_histogram(Input input);













vector <size_t>  make_histogram(Input input)
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




int main(int argc, char* argv[])
{printf("n = %08x\n", 0x1234567);
  return(0);

    Input input;
    if (argc>1){
        input = download(argv[1]);

    }
    else{
        input = read_input(cin,true);
    }
    const auto bins = make_histogram(input);
    show_histogram_svg(bins);
    return 0;
}










