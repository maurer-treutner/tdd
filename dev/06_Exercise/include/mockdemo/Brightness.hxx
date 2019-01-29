#include <string>

namespace mockdemo
{
    class ConfigMgr
    {
        public:
            virtual ~ConfigMgr(){};
            virtual int getIntParam(std::string pname)=0;
    };

    class BrightnessCtrl
    {
        public:
            BrightnessCtrl(ConfigMgr *cmgr):
                cmgr_(cmgr)
            {}

            bool setBrightness()
            {
                int min = cmgr_->getIntParam("MIN_BRIGHTNESS");
                int max = cmgr_->getIntParam("MAX_BRIGHTNESS");
                return (min < max);
            }
        
        private:
            ConfigMgr* cmgr_;
    };

}