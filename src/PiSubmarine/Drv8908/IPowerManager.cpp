#include "PiSubmarine/Drv8908/IPowerManager.h"

namespace PiSubmarine::Drv8908
{
    PowerLease IPowerManager::CreateLease(IPowerManager* manager, int userIndex)
    {
        return PowerLease(manager, userIndex);
    }

    IPowerManager* IPowerManager::GetLeaseManager(PowerLease& lease)
    {
        return lease.m_PowerManager;
    }

    void IPowerManager::SetLeaseManager(PowerLease& lease, IPowerManager* leaseManager)
    {
        lease.m_PowerManager = leaseManager;
    }

    int IPowerManager::GetLeaseUserIndex(const PowerLease& lease)
    {
        return lease.m_UserIndex;
    }

    void IPowerManager::SetLeaseUserIndex(PowerLease& lease, int userIndex)
    {
        lease.m_UserIndex = userIndex;
    }
}
