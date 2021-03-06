#include "svg.h"
#include <iostream>


    void
    svg_begin(double width, double height)
    {
        cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
        cout << "<svg ";
        cout << "width='" << width << "' ";
        cout << "height='" << height << "' ";
        cout << "viewBox='0 0 " << width << " " << height << "' ";
        cout << "xmlns='http://www.w3.org/2000/svg'>\n";
    }

    void
    svg_end()
    {
        cout << "</svg>\n";
    }
    void svg_text(double left, double baseline, string text)
    {
        cout << "<text x='" << left << "' y='" <<baseline << "'>"<< text << "</text>";
    }

 void svg_rect(double x, double y, double width, double height,string stroke, string fill)
    {
        cout<< "<rect x='" << x << "' y='"<<y<<"' " "width='" <<width<< "' " "height='" <<height << "' " "stroke='" << stroke << "' " "fill='" << fill << "' />";
    }
    void show_histogram_svg(const vector<size_t>& bins, size_t bin_count, string stroke,size_t &X1, size_t &X2 ,size_t &hist_hight, size_t &s ,size_t wid)
    {

        const auto IMAGE_WIDTH = 400;
        const auto IMAGE_HEIGHT = 300;
        const auto TEXT_LEFT = 20;
        const auto TEXT_BASELINE = 20;
        const auto TEXT_WIDTH = 50;
        const auto BIN_HEIGHT = 30;
        const auto BLOCK_WIDTH = 10;
         size_t max_bin_width=1;
        const size_t MAX_ASTERISK=IMAGE_WIDTH-TEXT_WIDTH;//345//-wid,?.? ????? ?????? ??? ?????? ????? ?? X

        size_t max_count = 0;
        for (size_t count : bins)
        {
            if (count > max_count)
            {
                max_count = count;
            }

        }
        max_bin_width=max_count*BLOCK_WIDTH;
        double top = 5;
        X1=TEXT_LEFT-3;
        const bool scaling_needed= max_bin_width>MAX_ASTERISK;
        svg_begin(IMAGE_WIDTH,IMAGE_HEIGHT);

        for (size_t bin : bins)
        {

            size_t bin_width=bin*BLOCK_WIDTH;
            if(scaling_needed)
            {
                const double scalling_factor=(double)MAX_ASTERISK/( max_bin_width);
                bin_width=(size_t)(bin*scalling_factor*BLOCK_WIDTH-3-wid);
            }

            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"red");
            top += BIN_HEIGHT;
        }
        if(scaling_needed)
            {
                const double scalling_factor=(double)MAX_ASTERISK/( max_bin_width);
                max_bin_width=(size_t)(max_bin_width*scalling_factor-3-wid);
                X2=max_bin_width+53+wid-1;
            }
        else
        {
            X2=max_bin_width+53+wid;
        }

          hist_hight=bin_count*BIN_HEIGHT+9;
    }


    void svg_line2(size_t X1,size_t Y1,size_t X2,size_t Y2,string stroke,size_t wid,ostream &stream)
    {

      stream<<"<line x1='"<<X1<<"' y1='"<<Y1<<"' x2='"<<X2<<"' y2='"<<Y2<<"' stroke='"<<stroke<<"' stroke-width='"<<wid<<"' stroke-dasharray = '10 10' />";



   }
   void fin()
   {
       svg_end();
   }


