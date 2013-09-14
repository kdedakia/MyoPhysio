// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_ANGLE_H_
#define INCLUDE_MYO_ANGLE_H_

#include <cmath>

#include <myo/detail/config.h>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

namespace myo {

class Angle
{
  public:
    Angle(double radians)
        : _radians(radians)
    {}

    double radians() const { return _radians; }
    double degrees() const { return (_radians * 180.0) / M_PI; }

  private:
    double _radians;
};

}

#endif  // INCLUDE_MYO_ANGLE_H_

