#pragma once

#include <od/objects/Object.h>
#include <vector> 

class PassThru : public od::Object
{
public:
  PassThru();
   ~PassThru();

#ifndef SWIGLUA
    virtual void process();
    od::Inlet mInput{"In"};
    od::Outlet mOutput{"Out"};
    od::Parameter mIndex{"Index", 0};

#endif
    // void setVaults(int, float);
    // float getVaults(int);

protected:
  friend class PassThruGraphic;

};