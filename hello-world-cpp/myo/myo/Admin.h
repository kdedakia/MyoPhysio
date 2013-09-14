// Copyright 2013 Thalmic Labs Inc.
#ifndef INCLUDE_MYO_ADMIN_H_
#define INCLUDE_MYO_ADMIN_H_

#include <string>

#include <myo/Event.h>
#include <myo/types_fwd.h>
#include <myo/detail/config.h>

namespace myo {

class Admin
{
  public:
    MYO_API Admin();
    MYO_API Admin(Admin&& other);
    MYO_API Admin& operator=(Admin&& other);
    MYO_API ~Admin();

    /**
     * Try to connect to a specific MYO.
     */
    MYO_API bool connectDevice(const std::string& address);

    /**
     * Disconnect from all MYOs.
     */
    MYO_API void disconnectDevices();

    MYO_API void setDataMode(DataMode mode);

    MYO_API void startClassifier(const std::string& filePath);

    MYO_API void stopClassifier();

    MYO_API void startDeviceDiscovery();

    MYO_API void stopDeviceDiscovery();

	MYO_API Event<const std::string&>& onDeviceFound();

  private:
    class AdminImpl* _impl;

    // disallow copying
    Admin(const Admin&);
    Admin& operator=(const Admin&);
};

}  // namespace myo

#endif  // INCLUDE_MYO_ADMIN_H_

