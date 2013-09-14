// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_DATAMODE_H_
#define INCLUDE_MYO_DATAMODE_H_

#include <cstdint>

namespace myo {

enum class DataMode : std::int32_t
{
    NONE = 0,
    EMG = 1,
    EMG_NO_NOTCH = 2,
    FV_IMU = 3
};

}  // namespace myo

#endif  // INCLUDE_MYO_DATAMODE_H_

