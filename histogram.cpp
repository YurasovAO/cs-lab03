#include "histogram.h"
#include <stdlib.h>
void find_minmax(const vector <double> &numbers, double &min,double &max)
{ size_t n=numbers.size();
if(n!=0)
{min=numbers[0];
  max=numbers[0];

     for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }
}
else
{
  exit(0);
}
}

