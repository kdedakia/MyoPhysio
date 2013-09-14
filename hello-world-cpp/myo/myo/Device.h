// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_DEVICE_H_
#define INCLUDE_MYO_DEVICE_H_

#include <cstdint>
#include <string>

#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

// forward declaration for internal use
class DeviceImpl;

class Device
{
  public:
    Device(DeviceImpl* deviceImpl);
    MYO_API Device(Device&& other);
    MYO_API Device& operator=(Device&& other);
    MYO_API ~Device();

    MYO_API void addListener(DeviceListener& listener);
    MYO_API void removeListener(DeviceListener& listener);

    MYO_API void enablePose(PoseType type, bool enable);
    MYO_API void vibrate(VibrationType type);

    MYO_API std::int32_t id() const;
    MYO_API std::int64_t address() const;
    MYO_API const std::string& name() const;

    MYO_API bool isActive() const;
    MYO_API const Motion& motion() const;
    MYO_API const Pose& pose() const;

  private:
    DeviceImpl* _impl;

    // disallow copying
    Device(const Device&);
    Device& operator=(const Device&);
};

}  // namespace myo

#endif  // INCLUDE_MYO_DEVICE_H_

