// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_EVENT_H_
#define INCLUDE_MYO_EVENT_H_

#include <functional>

#include <myo/detail/config.h>

namespace myo {

template<typename TParam>
class Event
{
  public:
    // forward declaration for internal use
    class Impl;

    Event();
    ~Event();

    /**
     * Add a new handler for this event.
     */
    MYO_API void add(std::function<void (TParam)> handler);
    
    /**
     * Remove a handler from this event.
     */
    MYO_API void remove(std::function<void (TParam)> handler);

    Impl* impl() { return _impl; }

  private:
    Impl* _impl;

    // disallow copying
    Event(const Event&);
    Event& operator=(const Event&);
};

}  // namespace myo

#endif  // INCLUDE_MYO_EVENT_H_

