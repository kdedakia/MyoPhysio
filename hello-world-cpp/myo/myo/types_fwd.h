// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_TYPESFWD_H_
#define INCLUDE_MYO_TYPESFWD_H_

#include <cstdint>

namespace myo {

class Admin;
class Angle;
enum class DataMode : std::int32_t;
class Device;
class DeviceListener;
class EmgSample;
class FeatureVector;
class Gesture;
enum class GestureType : std::int32_t;
class Hub;
class HubListener;
class Motion;
class Pose;
enum class PoseState : std::int32_t;
enum class PoseType : std::int32_t;
class Quaternion;
class Vector;
enum class VibrationType : std::int32_t;

}  // namespace myo

#endif  // INCLUDE_MYO_TYPESFWD_H_

