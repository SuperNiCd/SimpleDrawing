#include <./PassThruGraphic.h>
#include <math.h>

PassThruGraphic::PassThruGraphic(int left, int bottom, int width, int height) : od::Graphic(left, bottom, width, height)

{
}

PassThruGraphic::~PassThruGraphic()
{
//   if (mpSequencer)
//   {
//     mpSequencer->release();
//   }
}

void PassThruGraphic::draw(od::FrameBuffer &fb)
{
  const int CURSOR = 3;
  const int MARGIN = 2;
  int radius = MIN(mWidth / 2, mHeight / 2) - MARGIN - CURSOR;
  int centerX = mWorldLeft + mWidth / 2;
  int centerY = mWorldBottom + mHeight / 2;
  fb.circle(GRAY5, centerX, centerY, radius);

}