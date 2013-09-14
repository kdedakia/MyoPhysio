// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_HUBLISTENER_H_
#define INCLUDE_MYO_HUBLISTENER_H_

#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

class HubListener
{
  public:
    MYO_API virtual ~HubListener() {}

    /**
     * Called once, when this HubListener is added to a Hub.
     */
    MYO_API virtual void onAdd(Hub& hub) {}

    /**
     * Called at most once, either when this HubListener is removed from the Hub, or when the Hub is destroyed.
     */
    MYO_API virtual void onRemove(bool destroyed) {}

    /**
     * Called when the Hub connects to the MYO software, or when this HubListener is added to a Hub that is already connected.
     */
    MYO_API virtual void onConnect(Hub& hub) {}

    /**
     * Called when the Hub disconnects from the MYO software.
     */
    MYO_API virtual void onDisconnect(Hub& hub) {}

    /**
     * Called when a new MYO is paired with the MYO software.
     */
    MYO_API virtual void onDevicePair(Device& device) {}

    /**
     * Called when a paired MYO is removed from the MYO software.
     */
    MYO_API virtual void onDeviceUnpair(Device& device) {}
};

}  // namespace myo

#endif  // INCLUDE_MYO_HUBLISTENER_H_

