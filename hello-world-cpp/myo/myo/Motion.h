// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_MOTION_H_
#define INCLUDE_MYO_MOTION_H_

#include <cstdint>

#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

// forward declaration for internal use
class MotionImpl;

class Motion
{
  public:
    Motion();
    explicit Motion(MotionImpl* impl);
    MYO_API Motion(const Motion& other);
    MYO_API Motion(Motion&& other);
    MYO_API Motion& operator=(Motion other);
    MYO_API ~Motion();

    MYO_API std::int32_t deviceId() const;
    MYO_API std::int64_t timestamp() const;

    MYO_API const Vector& acceleration() const;
    MYO_API const Vector& angularVelocity() const;
    MYO_API const Quaternion& orientation() const;

    MYO_API PoseType poseType() const;
    
    MYO_API bool isValid() const;

  private:
    MotionImpl* _impl;
};

}  // namespace myo

#endif  // INCLUDE_MYO_MOTION_H_
