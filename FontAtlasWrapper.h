#pragma once

#include "imguiWrapperTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern IggFont iggAddFontDefault(IggFontAtlas handle);
extern IggFont iggAddFontFromFileTTF(IggFontAtlas handle, char const *filename, float sizePixels);
extern IggFont iggAddFontFromMemoryTTF(IggFontAtlas handle, void* font_data, int font_size, float sizePixels);

extern void iggFontAtlasGetTexDataAsAlpha8(IggFontAtlas handle, unsigned char **pixels,
      int *width, int *height, int *bytesPerPixel);
extern void iggFontAtlasSetTextureID(IggFontAtlas handle, IggTextureID id);

#ifdef __cplusplus
}
#endif
