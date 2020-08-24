#pragma once

// As recommended in imgui/imconfig.h, the IMGUI_USER_CONFIG must be specified
// whenever imgui is used. As such, the wrapper code should never include imgui.h directly.

#define IMGUI_USER_CONFIG "wrapper/ConfigOverride.h"
#define IMGUI_DISABLE_OBSOLETE_FUNCTIONS
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"
