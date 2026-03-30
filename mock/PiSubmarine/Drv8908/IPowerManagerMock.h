#pragma once

#include <gmock/gmock.h>
#include "PiSubmarine/Drv8908/IPowerManager.h"

namespace PiSubmarine::Drv8908
{
    class IPowerManagerMock : public IPowerManager
    {
    public:
        MOCK_METHOD(PowerLease, Acquire, (), (override));
        MOCK_METHOD(void, Release, (PowerLease& lease), (override));
    };
}