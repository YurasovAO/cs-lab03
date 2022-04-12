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
    void show_histogram_svg(const vector<size_t>& bins,size_t bin_count,string stroke,size_t wid,size_t &X,size_t &Y,size_t &L)
    {

           const auto IMAGE_WIDTH = 400;
        const auto IMAGE_HEIGHT = 300;
        const auto TEXT_LEFT = 20;
        const auto TEXT_BASELINE = 20;
        const auto TEXT_WIDTH = 50;
        const auto BIN_HEIGHT = 30;
        const auto BLOCK_WIDTH = 10;
         size_t max_bin_width=1;
        const size_t MAX_ASTERISK=IMAGE_WIDTH-TEXT_WIDTH-3;//347
        X=TEXT_LEFT-3;
        Y=max_bin_width+53;
        size_t max_count = 0;
        for (size_t count : bins)
        {
            if (count > max_count)
            {
                max_count = count;
            }

        }
        max_bin_width=max_count*BLOCK_WIDTH;
        X=TEXT_LEFT-3;
        Y=max_bin_width+53;
        const bool scaling_needed=max_count*BLOCK_WIDTH>MAX_ASTERISK;

        svg_begin(IMAGE_WIDTH,IMAGE_HEIGHT);
        double top = 5;
        double s=1;
        for (size_t bin : bins)
        {

            size_t bin_width=bin*BLOCK_WIDTH;
            if(scaling_needed)
            {
                const double scalling_factor=(double)MAX_ASTERISK/(max_count*BLOCK_WIDTH);
                bin_width=(size_t)(bin*scalling_factor*BLOCK_WIDTH);

            }

            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"red");
            top += BIN_HEIGHT;
        }
        if(scaling_needed)
            {
                const double scalling_factor=(double)MAX_ASTERISK/max_bin_width;
                max_bin_width=(size_t)(max_bin_width*scalling_factor);

            }

        size_t hist_hight=bin_count*BIN_HEIGHT;
         cout<<"<line x1='"<<X<<"' y1='"<<s<<"' x2='"<<Y<<"' y2='"<<s<<"' stroke='"<<stroke<<"' stroke-width='"<<wid<<"' stroke-dasharray = '10 10' />";
         cout<<"<line x1='"<<Y<<"' y1='"<<s<<"' x2='"<<Y<<"' y2='"<<hist_hight+3+5<<"' stroke='"<<stroke<<"' stroke-width='"<<wid<<"' stroke-dasharray = '10 10' />";
         cout<<"<line x1='"<<Y<<"' y1='"<<hist_hight+3+5<<"' x2='"<<X<<"' y2='"<<hist_hight+3+5<<"' stroke='"<<stroke<<"' stroke-width='"<<wid<<"' stroke-dasharray = '10 10' />";
         cout<<"<line x1='"<<X<<"' y1='"<<hist_hight+3+5<<"' x2='"<<X<<"' y2='"<<s<<"' stroke='"<<stroke<<"' stroke-width='"<<wid<<"' stroke-dasharray = '10 10' />";
        svg_end();
           L=max_bin_width;
    }
