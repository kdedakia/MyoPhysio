// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_POSE_H_
#define INCLUDE_MYO_POSE_H_

#include <cstdint>

#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

enum class PoseType : std::int32_t
{
    NONE = 0,
    LEFT = 1,
    RIGHT = 2,
    GUN = 3,
    FIST = 4
};

enum class PoseState : std::int32_t
{
    INVALID = 0,
    HOLDING = 1,
    RELEASED = 2
};

// forward declaration for internal use
class PoseImpl;

class Pose
{
  public:
    Pose();
    explicit Pose(PoseImpl* impl);
    MYO_API Pose(const Pose& other);
    MYO_API Pose(Pose&& other);
    MYO_API Pose& operator=(Pose other);
    MYO_API ~Pose();

    MYO_API std::int32_t deviceId() const;
    MYO_API std::int64_t start() const;
    MYO_API std::int64_t finish() const;

    MYO_API PoseType type() const;
    MYO_API PoseState state() const;

    MYO_API bool isValid() const;

  private:
    PoseImpl* _impl;
};

}  // namespace myo

#endif  // INCLUDE_MYO_POSE_H_

