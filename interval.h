#ifndef INTERVAL_H
#define INTERVAL_H

#include <limits>

inline double interval_infinity() { return std::numeric_limits<double>::infinity(); }

class interval{
public:

double min,max;
interval(): min(+interval_infinity()),max(-interval_infinity()){}
interval(double min,double max): min(min),max(max){}

double size() const{

    return max - min;
}
double contains(double x) const{
    return min <= x && x <= max;
}

double surrounds(double x) const{
    return min < x && x < max;
}
double clamp(double x) const {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

static const interval empty,universe;
};


const interval interval::empty = interval(+interval_infinity(),-interval_infinity());
const interval interval::universe = interval(-interval_infinity(),+interval_infinity());




#endif