/* change to `float/fmodf` or `long long double/fmodl` or `int/%` as appropriate */

#include <iostream>
#include <cmath>

using namespace std;

/* wrap x -> [0,max) */
long double wrapMax(long double x, long double max)
{
    /* integer math: `(max + x % max) % max` */
    return fmod(max + fmod(x, max), max);
}
/* wrap x -> [min,max) */
long double wrapMinMax(long double x, long double min, long double max)
{
    return min + wrapMax(x - min, max - min);
}

int main(){

    cout << wrapMinMax(6.28,-3.14,3.14) << endl;


    return 0;

}