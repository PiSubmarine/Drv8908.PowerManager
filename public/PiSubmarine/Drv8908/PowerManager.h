#pragma once

#include "PiSubmarine/Drv8908/IPowerManager.h"
#include "PiSubmarine/Drv8908/Device.h"

namespace PiSubmarine::Drv8908
{
    class PowerManager : public IPowerManager
    {
    public:
        explicit PowerManager(Device& device);
        ~PowerManager() override;
        PowerLease Acquire() override;
        void Release(PowerLease& lease) override;

        [[nodiscard]] int GetUserCounter() const { return m_UserCounter; }
    private:
        Device& m_Device;
        int m_UserCounter = 0;
    };
}

