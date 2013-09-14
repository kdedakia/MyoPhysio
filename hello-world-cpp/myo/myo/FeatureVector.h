// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_FEATUREVECTOR_H_
#define INCLUDE_MYO_FEATUREVECTOR_H_

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

namespace myo {

class FeatureVector
{
  public:
    static const int NUM_CHANNELS = 8;

    explicit FeatureVector(std::vector<std::int16_t> rms)
        : _rms(std::move(rms))
    {
        assert(_rms.size() == NUM_CHANNELS);
    }

    FeatureVector(FeatureVector&& other)
        : _rms(std::move(other._rms))
    {}

    FeatureVector& operator=(FeatureVector&& other)
    {
        using std::swap;  // enable ADL
        swap(*this, other);
        return *this;
    }

    const std::vector<std::int16_t>& rms() const { return _rms; }

  private:
    std::vector<std::int16_t> _rms;

    // disallow copying
    FeatureVector(const FeatureVector&);
    FeatureVector& operator=(const FeatureVector&);
};

}  // namespace myo

#endif  // INCLUDE_MYO_FEATUREVECTOR_H_

