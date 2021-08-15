#define BUILDOPT_VERBOSE
#define BUILDOPT_DEBUG_LEVEL 10

#include <./PassThru.h>
#include <hal/ops.h>
// #include <hal/simd.h>
#include <hal/ops.h>
#include <od/config.h>
// #include <vector>
#include <hal/log.h>

PassThru::PassThru()
{
    addInput(mInput);
    addOutput(mOutput);
    addParameter(mIndex);
}

PassThru::~PassThru()
{
}

void PassThru::process()
{
    float *out = mOutput.buffer();
    float *in = mInput.buffer();

    for (int i = 0; i < FRAMELENGTH; i += 4)
    {
        out[i] = in[i];
    }
}
