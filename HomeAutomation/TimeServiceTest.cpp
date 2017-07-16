extern "C"
{
#include "TimeService.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(TimeService)
{
    void setup()
    {
      TimeService_Create();
    }

    void teardown()
    {
       TimeService_Destroy();
    }
};

TEST(TimeService, Create)
{
  FAIL("Start here");
}

