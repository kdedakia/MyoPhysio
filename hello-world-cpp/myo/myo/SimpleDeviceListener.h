// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_SIMPLEDEVICELISTENER_H_
#define INCLUDE_MYO_SIMPLEDEVICELISTENER_H_

#include <myo/Event.h>
#include <myo/DeviceListener.h>
#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

class SimpleDeviceListener : public DeviceListener
{
  public:
    MYO_API Event<Device&>& onActive() { return _onActive; }
    MYO_API Event<Device&>& onInactive() { return _onInactive; }
    MYO_API Event<const Motion&>& onMotion() { return _onMotion; }
    MYO_API Event<const Pose&>& onPoseStart() { return _onPoseStart; }
    MYO_API Event<const Pose&>& onPoseFinish() { return _onPoseFinish; }
    MYO_API Event<const EmgSample&>& onEmgSample() { return _onEmgSample; }
    MYO_API Event<const FeatureVector&>& onFeatureVector() { return _onFeatureVector; }

    virtual void onActive(Device& device) override;
    virtual void onInactive(Device& device) override;
    virtual void onMotion(const Motion& motion) override;
    virtual void onPoseStart(const Pose& pose) override;
    virtual void onPoseFinish(const Pose& pose) override;
    virtual void onEmgSample(const EmgSample& emgSample) override;
    virtual void onFeatureVector(const FeatureVector& featureVector) override;

  private:
    Event<Device&> _onActive;
    Event<Device&> _onInactive;
    Event<const Motion&> _onMotion;
    Event<const Pose&> _onPoseStart;
    Event<const Pose&> _onPoseFinish;
    Event<const EmgSample&> _onEmgSample;
    Event<const FeatureVector&> _onFeatureVector;
};

}  // namespace myo

#endif  // INCLUDE_MYO_SIMPLEDEVICELISTENER_H_

