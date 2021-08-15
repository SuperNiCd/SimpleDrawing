%module PassThru_libPassThru
%include <od/glue/mod.cpp.swig>

%{

#undef SWIGLUA

#include <./PassThru.h>
#include <./PassThruGraphic.h>


#define SWIGLUA

%}

%include <./PassThru.h>
%include <./PassThruGraphic.h>
