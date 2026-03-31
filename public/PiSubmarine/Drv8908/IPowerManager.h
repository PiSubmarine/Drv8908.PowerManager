#pragma once

#include "PiSubmarine/Drv8908/PowerLease.h"

namespace PiSubmarine::Drv8908
{
    class IPowerManager
    {
    public:
        virtual ~IPowerManager() = default;
        virtual PowerLease Acquire() = 0;
        virtual void Release(PowerLease& lease) = 0;

    protected:
        static PowerLease CreateLease(IPowerManager* manager, int userIndex);
        static IPowerManager* GetLeaseManager(PowerLease& lease);
        static void SetLeaseManager(PowerLease& lease, IPowerManager* leaseManager);
        static int GetLeaseUserIndex(const PowerLease& lease);
        static void SetLeaseUserIndex(PowerLease& lease, int userIndex);

        friend class PowerLease;
    };
}
