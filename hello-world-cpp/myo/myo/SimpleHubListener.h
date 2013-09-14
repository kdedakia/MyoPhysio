// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_SIMPLEHUBLISTENER_H_
#define INCLUDE_MYO_SIMPLEHUBLISTENER_H_

#include <myo/Event.h>
#include <myo/HubListener.h>
#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

class SimpleHubListener : public HubListener
{
  public:
    MYO_API Event<Hub&>& onConnect() { return _onConnect; }
    MYO_API Event<Hub&>& onDisconnect() { return _onDisconnect; }
    MYO_API Event<Device&>& onDevicePair() { return _onDevicePair; }
    MYO_API Event<Device&>& onDeviceUnpair() { return _onDeviceUnpair; }

    virtual void onConnect(Hub& hub) override;
    virtual void onDisconnect(Hub& hub) override;
    virtual void onDevicePair(Device& device) override;
    virtual void onDeviceUnpair(Device& device) override;

  private:
    Event<Hub&> _onConnect;
    Event<Hub&> _onDisconnect;
    Event<Device&> _onDevicePair;
    Event<Device&> _onDeviceUnpair;
};

}  // namespace myo

#endif  // INCLUDE_MYO_SIMPLEHUBLISTENER_H_

