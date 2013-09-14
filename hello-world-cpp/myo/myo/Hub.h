// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_HUB_H_
#define INCLUDE_MYO_HUB_H_

#include <list>

#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

class Hub
{
  public:
    MYO_API Hub();
    MYO_API Hub(Hub&& other);
    MYO_API Hub& operator=(Hub&& other);
    MYO_API ~Hub();

    MYO_API void addListener(HubListener& listener);
    MYO_API void removeListener(HubListener& listener);

    /**
     * Report whether this Hub is connected to the MYO software.
     */
    MYO_API bool isConnected() const;

    /**
     * Return a reference to the default device, regardless of whether it is connected.
     */
    MYO_API Device& defaultDevice() const;

    /**
     * Return a list of all devices that are currently connected.
     */
    MYO_API const std::list<Device*>& devices() const;

    /**
     * Enable or disable broadcast of motion data.
     */
    MYO_API void enableMotion(bool enable = true);

    /**
     * Enable or disable broadcast of pose change events.
     */
    MYO_API void enablePoses(bool enable = true);

    /**
     * Enable or disable broadcast of raw EMG data.
     */
    MYO_API void enableEmg(bool enable = true);

    /**
     * Enable or disable broadcast of feature vector (FV) data.
     */
    MYO_API void enableFv(bool enable = true);

  private:
    class HubImpl* _impl;

    // disallow copying
    Hub(const Hub&);
    Hub& operator=(const Hub&);
};

}  // namespace myo

#endif  // INCLUDE_MYO_HUB_H_

