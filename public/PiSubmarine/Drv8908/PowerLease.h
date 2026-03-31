#pragma once

namespace PiSubmarine::Drv8908
{
    class IPowerManager;

    class PowerLease final
    {
    public:

        // Copy is forbidden
        PowerLease(const PowerLease& other) = delete;
        // Copy is forbidden
        PowerLease& operator=(const PowerLease& other) = delete;

        PowerLease();

        PowerLease(PowerLease&& other) noexcept;
        PowerLease& operator=(PowerLease&& other) noexcept;

        ~PowerLease();
        [[nodiscard]] bool IsValid() const;

    protected:
        IPowerManager* m_PowerManager;
        int m_UserIndex;

        explicit PowerLease(IPowerManager* manager, int userIndex);

        friend class IPowerManager;
    };
}
