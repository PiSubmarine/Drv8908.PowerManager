#include <gtest/gtest.h>
#include "PiSubmarine/Drv8908/PowerManager.h"
#include "PiSubmarine/GPIO/Api/IPinGroupMock.h"
#include "PiSubmarine/SPI/Api/IDriverMock.h"
#include "PiSubmarine/Drv8908/Device.h"

using namespace ::testing;

namespace PiSubmarine::Drv8908
{
    TEST(PowerManagerTest, AcquireRelease)
    {

        StrictMock<GPIO::Api::IPinGroupMock> pinGroupMock;
        StrictMock<SPI::Api::IDriverMock> spiMock;

        EXPECT_CALL(pinGroupMock, Num()).WillRepeatedly(Return(2));
        EXPECT_CALL(pinGroupMock, SetDirections(_));
        Drv8908::Device device(spiMock, pinGroupMock);
        PowerManager powerManager(device);

        GPIO::Api::Mask sleepMask;
        sleepMask.Set(Device::NSleepPinIndex, GPIO::Api::MaskBit::Included);

        GPIO::Api::Levels enterSleepLevels;
        enterSleepLevels.Set(Device::NSleepPinIndex, GPIO::Api::Level::Low);

        GPIO::Api::Levels leaveSleepLevels;
        leaveSleepLevels.Set(Device::NSleepPinIndex, GPIO::Api::Level::High);

        ASSERT_NE(enterSleepLevels, leaveSleepLevels);

        {
            InSequence s;
            EXPECT_CALL(pinGroupMock, SetLevels(Eq(leaveSleepLevels), sleepMask));
            EXPECT_CALL(pinGroupMock, SetLevels(Eq(enterSleepLevels), sleepMask));
            EXPECT_CALL(pinGroupMock, SetLevels(Eq(enterSleepLevels), sleepMask)); // PowerManager destructor
        }
        auto lease2 = powerManager.Acquire();
        {
            auto lease1Unmoved = powerManager.Acquire();
            auto lease1 = std::move(lease1Unmoved);
        }
        powerManager.Release(lease2);
    }
}
