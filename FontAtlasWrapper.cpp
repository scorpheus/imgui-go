#include "imguiWrappedHeader.h"
#include "FontAtlasWrapper.h"
#include "WrapperConverter.h"

IggFont iggAddFontDefault(IggFontAtlas handle)
{
   ImFontAtlas *fontAtlas = reinterpret_cast<ImFontAtlas *>(handle);
   ImFont *font = fontAtlas->AddFontDefault();
   return static_cast<IggFont>(font);
}

IggFont iggAddFontFromFileTTF(IggFontAtlas handle, char const *filename, float sizePixels)
{
   ImFontAtlas *fontAtlas = reinterpret_cast<ImFontAtlas *>(handle);
   ImFont *font = fontAtlas->AddFontFromFileTTF(filename, sizePixels);
   return static_cast<IggFont>(font);
}

IggFont iggAddFontFromMemoryTTF(IggFontAtlas handle, void* font_data, int font_size, float sizePixels)
{
   ImFontAtlas *fontAtlas = reinterpret_cast<ImFontAtlas *>(handle);   
   ImFontConfig font_cfg;
   font_cfg.FontDataOwnedByAtlas = false;
   ImFont *font = fontAtlas->AddFontFromMemoryTTF(font_data, font_size, sizePixels, &font_cfg);
   return static_cast<IggFont>(font);
}

void iggFontAtlasGetTexDataAsAlpha8(IggFontAtlas handle, unsigned char **pixels,
                                    int *width, int *height, int *bytesPerPixel)
{
   ImFontAtlas *fontAtlas = reinterpret_cast<ImFontAtlas *>(handle);
   fontAtlas->GetTexDataAsAlpha8(pixels, width, height, bytesPerPixel);
}

void iggFontAtlasGetTexDataAsRGBA32(IggFontAtlas handle, unsigned char **pixels,
                                    int *width, int *height, int *bytesPerPixel)
{
   ImFontAtlas *fontAtlas = reinterpret_cast<ImFontAtlas *>(handle);
   fontAtlas->GetTexDataAsRGBA32(pixels, width, height, bytesPerPixel);
}

void iggFontAtlasSetTextureID(IggFontAtlas handle, IggTextureID id)
{
   ImFontAtlas *fontAtlas = reinterpret_cast<ImFontAtlas *>(handle);
   fontAtlas->SetTexID(id);
}
