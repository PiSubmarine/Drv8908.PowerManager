#include "PiSubmarine/Drv8908/PowerLease.h"

#include "PiSubmarine/Drv8908/IPowerManager.h"

namespace PiSubmarine::Drv8908
{
    PowerLease::PowerLease() : m_PowerManager(nullptr), m_UserIndex(-1)
    {

    }

    PowerLease::PowerLease(PowerLease&& other) noexcept :m_PowerManager(other.m_PowerManager), m_UserIndex(other.m_UserIndex)
    {
        other.m_UserIndex = -1;
        other.m_PowerManager = nullptr;
    }

    PowerLease& PowerLease::operator=(PowerLease&& other) noexcept
    {
        m_PowerManager = other.m_PowerManager;
        m_UserIndex = other.m_UserIndex;
        other.m_UserIndex = -1;
        other.m_PowerManager = nullptr;
        return *this;
    }

    PowerLease::~PowerLease()
    {
        if (IsValid())
        {
            m_PowerManager->Release(*this);
        }
    }

    bool PowerLease::IsValid() const
    {
        return m_UserIndex >= 0 && m_PowerManager != nullptr;
    }

    PowerLease::PowerLease(IPowerManager* manager, int userIndex) : m_PowerManager(manager), m_UserIndex(userIndex)
    {
    }
}
