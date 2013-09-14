// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_DEVICELISTENER_H_
#define INCLUDE_MYO_DEVICELISTENER_H_

#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

class DeviceListener
{
  public:
    MYO_API virtual ~DeviceListener() {}

    /**
     * Called once, when this DeviceListener is added to a Device.
     */
    MYO_API virtual void onAdd(Device& device) {}

    /**
     * Called at most once, either when this DeviceListener is removed from the Device, or when the Device is destroyed.
     */
    MYO_API virtual void onRemove(bool destroyed) {}

    /**
     * Called when the Device is ready to be used for control, or when this DeviceListener is added to a Device that is already active.
     */
    MYO_API virtual void onActive(Device& device) {}

    /**
     * Called when the Device becomes inactive (e.g. the MYO has disconnected).
     */
    MYO_API virtual void onInactive(Device& device) {}

    /**
     * Called when new Motion data is available from the Device.
     */
    MYO_API virtual void onMotion(const Motion& motion) {}

    /**
     * Called when the Device detects the start of a Pose.
     */
    MYO_API virtual void onPoseStart(const Pose& pose) {}

    /**
     * Called when the Device detects that the current Pose has finished.
     */
    MYO_API virtual void onPoseFinish(const Pose& pose) {}

    /**
     * Called when a new sample of EMG data is available from the Device.
     */
    MYO_API virtual void onEmgSample(const EmgSample& emgSample) {}

    /**
     * Called when a new feature vector is available from the Device.
     */
    MYO_API virtual void onFeatureVector(const FeatureVector& featureVector) {}
};

}  // namespace myo

#endif  // INCLUDE_MYO_DEVICELISTENER_H_

