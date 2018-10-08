#pragma once

extern void importValue(bool &out, IggBool const &in);
extern void exportValue(IggBool &out, bool const &in);

extern void importValue(ImVec2 &out, IggVec2 const &in);
extern void exportValue(IggVec2 &out, ImVec2 const &in);

extern void importValue(ImVec4 &out, IggVec4 const &in);
extern void exportValue(IggVec4 &out, ImVec4 const &in);

template <typename ImGuiType, typename IggType>
class TypeWrapper
{
public:
   TypeWrapper(IggType *iggValue)
      :  iggValue(iggValue), imguiValue(NULL)
   {
      if (iggValue != NULL)
      {
         imguiValue = &imguiBuffer;
         importValue(*imguiValue, *iggValue);
      }
   }

   TypeWrapper(IggType const *constIggValue)
      :  iggValue(NULL), imguiValue(NULL)
   {
      if (constIggValue != NULL)
      {
         imguiValue = &imguiBuffer;
         importValue(*imguiValue, *constIggValue);
      }
   }

   ~TypeWrapper()
   {
      if (iggValue != NULL)
      {
         exportValue(*iggValue, *imguiValue);
      }
   }

   operator ImGuiType *()
   {
      return imguiValue;
   }

private:
   IggType *iggValue;
   ImGuiType *imguiValue;
   ImGuiType imguiBuffer;
};

typedef TypeWrapper<bool, IggBool> BoolWrapper;
typedef TypeWrapper<ImVec2, IggVec2> Vec2Wrapper;
typedef TypeWrapper<ImVec4, IggVec4> Vec4Wrapper;
