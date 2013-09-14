// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_VECTOR_H_
#define INCLUDE_MYO_VECTOR_H_

#include <cstdint>

namespace myo {

class Vector
{
  public:
    Vector();
    Vector(double x, double y, double z);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector() {}

    double operator[](unsigned int index);

    double x() const { return _x; }
    double y() const { return _y; }
    double z() const { return _z; }

  private:
    double _x;
    double _y;
    double _z;
};

inline Vector::Vector()
    : _x(0), _y(0), _z(0)
{}

inline Vector::Vector(double x, double y, double z)
    : _x(x), _y(y), _z(z)
{}

inline Vector::Vector(const Vector& other)
    : _x(other._x), _y(other._y), _z(other._z)
{}

inline Vector& Vector::operator=(const Vector& other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
}

inline double Vector::operator[](unsigned int index)
{
    return (index < 3) ? (&_x)[index] : 0.0;
}

}  // namespace myo

#endif  // INCLUDE_MYO_VECTOR_H_

