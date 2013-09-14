// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_VIBRATIONTYPE_H_
#define INCLUDE_MYO_VIBRATIONTYPE_H_

#include <cstdint>

namespace myo {

enum class VibrationType : std::int32_t
{
    NONE = 0,
    SHORT = 1,
    MEDIUM = 2,
    LONG = 3
};

}  // namespace myo

#endif  // INCLUDE_MYO_VIBRATIONTYPE_H_

