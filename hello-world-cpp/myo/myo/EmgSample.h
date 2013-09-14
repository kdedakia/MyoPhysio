// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_EMGSAMPLE_H_
#define INCLUDE_MYO_EMGSAMPLE_H_

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

namespace myo {

class EmgSample
{
  public:
    static const int NUM_CHANNELS = 8;

    explicit EmgSample(std::vector<std::int8_t> data)
        : _data(std::move(data))
    {
        assert(_data.size() == NUM_CHANNELS);
    }

    EmgSample(EmgSample&& other)
        : _data(std::move(other._data))
    {}

    EmgSample& operator=(EmgSample&& other)
    {
        using std::swap;  // enable ADL
        swap(*this, other);
        return *this;
    }

    const std::vector<std::int8_t>& data() const { return _data; }

  private:
    std::vector<std::int8_t> _data;

    // disallow copying
    EmgSample(const EmgSample&);
    EmgSample& operator=(const EmgSample&);
};

}  // namespace myo

#endif  // INCLUDE_MYO_EMGSAMPLE_H_
