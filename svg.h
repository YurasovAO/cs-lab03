#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <vector>
#include <string>
using namespace std;
void svg_begin(double width, double height);


    void svg_end();


    void svg_text(double left, double baseline, string text);


    void show_histogram_svg(const vector<size_t>& bins, size_t bin_count, string stroke, size_t &X1, size_t &X2 ,size_t &hist_hight, size_t &s ,size_t wid);



    void svg_rect(double x, double y, double width, double height,string stroke = "black", string fill = "black");

    void svg_line(const vector<size_t>& bins,string stroke,size_t wid,size_t bin_count);


    void svg_line2(size_t X1,size_t Y1,size_t X2,size_t Y2,string stroke,size_t wid,ostream &stream);
    void fin();

#endif // SVG_H_INCLUDED
