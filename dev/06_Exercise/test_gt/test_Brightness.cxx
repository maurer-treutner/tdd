#include "mockdemo/Brightness.hxx"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace mockdemo;

class MockConfigMgr : public ConfigMgr
{
public:
    MOCK_METHOD1(getIntParam,int(std::string));
};

class test_Brightness : public testing::Test
{
public:
    void SetUp() override 
    {
        cnf_ = new MockConfigMgr();
        testCtrl_ = new BrightnessCtrl(cnf_);
    }

    void TearDown() override 
    {
        delete testCtrl_;
        delete cnf_;
    }

protected:
    BrightnessCtrl *testCtrl_;
    MockConfigMgr *cnf_;
};

TEST_F(test_Brightness,setBrightness)
{
    EXPECT_CALL(*cnf_,getIntParam("MIN_BRIGHTNESS"))
        .WillOnce(testing::Return(42));
    EXPECT_CALL(*cnf_,getIntParam("MAX_BRIGHTNESS"))
        .WillOnce(testing::Return(4711));
    EXPECT_TRUE(testCtrl_->setBrightness());
}

