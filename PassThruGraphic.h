#pragma once

#include <od/graphics/Graphic.h>
#include <PassThru.h>

class PassThruGraphic : public od::Graphic
{
public:
  PassThruGraphic(int left, int bottom, int width, int height);
  virtual ~PassThruGraphic();

#ifndef SWIGLUA
  virtual void draw(od::FrameBuffer &fb);
#endif

//   void follow(EuclideanSequencer *pSequencer);

// private:
//   EuclideanSequencer *mpSequencer = 0;
};