// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_QUATERNION_H_
#define INCLUDE_MYO_QUATERNION_H_

#include <cmath>
#include <cstdint>

#include "./Angle.h"

namespace myo {

class Quaternion
{
  public:
    Quaternion();
    Quaternion(double w, double x, double y, double z);
    Quaternion(const Quaternion& other);
    Quaternion& operator=(const Quaternion& other);
    ~Quaternion() {}

	bool normed() const;
    double norm() const;

    Angle roll() const;
    Angle pitch() const;
    Angle yaw() const;

    double w() const { return _w; }
    double x() const { return _x; }
    double y() const { return _y; }
    double z() const { return _z; }

  private:
    double _w;
    double _x;
    double _y;
    double _z;

	bool _normed;
};

inline Quaternion::Quaternion()
    : _w(0), _x(0), _y(0), _z(0), _normed(false)
{}

inline Quaternion::Quaternion(double w, double x, double y, double z)
    : _w(w), _x(x), _y(y), _z(z)
{
    double norm = Quaternion::norm();
    _w = _w / norm;
    _x = _x / norm;
    _y = _y / norm;
    _z = _z / norm;
	_normed = true;
}

inline Quaternion::Quaternion(const Quaternion& other)
    : _w(other._w), _x(other._x), _y(other._y), _z(other._z), _normed(other._normed)
{}

inline Quaternion& Quaternion::operator=(const Quaternion& other)
{
    _w = other._w;
    _x = other._x;
    _y = other._y;
    _z = other._z;
	_normed = other._normed;
    return *this;
}

inline bool Quaternion::normed() const
{
	return _normed;
}

inline double Quaternion::norm() const
{
    return sqrt(_w * _w + _x * _x + _y * _y + _z * _z);
}

inline Angle Quaternion::roll() const
{
    Angle roll(std::atan2(2.0 * (_w * _x + _y * _z), 1.0 - 2.0 * (_x * _x + _y * _y)));
    return roll;
}

inline Angle Quaternion::pitch() const
{
    Angle pitch(std::asin(2.0 * (_w * _y - _z * _x)));
    return pitch;
}

inline Angle Quaternion::yaw() const
{
    Angle yaw(std::atan2(2.0 * (_w * _z + _x * _y), 1.0 - 2.0 * (_y * _y + _z * _z)));
    return yaw;
}

}  // namespace myo

#endif  // INCLUDE_MYO_QUATERNION_H_

