#include "FreekApplication.h"

FreeKApplication* FreeKApplication::_app = nullptr;
FreeKApplication::FreeKApplication(int &argc, char* argv[])
   :QApplication(argc, argv)

{
     _app = this;
}

FreeKApplication::~FreeKApplication()
{

}

FreeKApplication* FreeKApp(void)
{
    return FreeKApplication::_app;
}


bool FreeKApplication::checkErrorState(){

     return true;
}

void FreeKApplication::setLanguage() {


}

bool FreeKApplication::event(QEvent *e) {

     return true;
}

void FreeKApplication::_initAppCommon() {


}
