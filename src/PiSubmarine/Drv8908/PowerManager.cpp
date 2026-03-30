#include "PiSubmarine/Drv8908/PowerManager.h"

#include <iostream>
#include <ostream>

namespace PiSubmarine::Drv8908
{
    PowerManager::PowerManager(Device& device) : m_Device(device)
    {

    }

    PowerManager::~PowerManager()
    {
        m_Device.SetSleeping(true);
    }

    PowerLease PowerManager::Acquire()
    {
        if (m_UserCounter == 0)
        {
            m_Device.SetSleeping(false);
        }
        PowerLease lease = CreateLease(*this, m_UserCounter);
        m_UserCounter++;
        return std::move(lease);
    }

    void PowerManager::Release(PowerLease& lease)
    {
        if (!lease.IsValid())
        {
            return;
        }

        if (m_UserCounter == 0)
        {
            throw std::runtime_error("PowerManager::Release called with zero user counter");
        }

        if (m_UserCounter == 1)
        {
            m_UserCounter = 0;
            m_Device.SetSleeping(true);
        }
        else
        {
            m_UserCounter--;
        }

        SetLeaseUserIndex(lease, -1);
    }
}
