// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_DEVICEFOUND_H_
#define INCLUDE_MYO_DEVICEFOUND_H_

#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

class DeviceFound
{
  public:
    DeviceFound() {}
    int64_t deviceAddressAsInt;
    std::string deviceAddress;

    //const Device& device() { return _device; }

  private:
    //Device _device;
};

}  // namespace myo

#endif  // INCLUDE_MYO_DEVICEFOUND_H_
