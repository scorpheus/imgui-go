#include "imguiWrappedHeader.h"
#include "imguiWrapper.h"
#include "WrapperConverter.h"

IggContext iggCreateContext(IggFontAtlas sharedFontAtlas)
{
   ImGuiContext *context = ImGui::CreateContext(reinterpret_cast<ImFontAtlas *>(sharedFontAtlas));
   return reinterpret_cast<IggContext>(context);
}

void iggDestroyContext(IggContext context)
{
   ImGui::DestroyContext(reinterpret_cast<ImGuiContext *>(context));
}

IggContext iggGetCurrentContext()
{
   return reinterpret_cast<IggContext>(ImGui::GetCurrentContext());
}

void iggSetCurrentContext(IggContext context)
{
   ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext *>(context));
}

IggIO iggGetCurrentIO()
{
   return reinterpret_cast<IggIO>(&ImGui::GetIO());
}

IggGuiStyle iggGetCurrentStyle()
{
   return reinterpret_cast<IggGuiStyle>(&ImGui::GetStyle());
}

void iggNewFrame()
{
   ImGui::NewFrame();
}

void iggRender()
{
   ImGui::Render();
}

IggDrawData iggGetDrawData()
{
   return reinterpret_cast<IggDrawData>(ImGui::GetDrawData());
}

void iggEndFrame()
{
   ImGui::EndFrame();
}

char const *iggGetVersion()
{
   return ImGui::GetVersion();
}

void iggShowDemoWindow(IggBool *open)
{
   BoolWrapper openArg(open);

   ImGui::ShowDemoWindow(openArg);
}

void iggShowUserGuide(void)
{
   ImGui::ShowUserGuide();
}

void iggStyleColorsDark()
{
    ImGui::StyleColorsDark();
}

void iggStyleColorsClassic()
{
   ImGui::StyleColorsClassic();
}

void iggStyleColorsLight()
{
   ImGui::StyleColorsLight();
}

IggBool iggBegin(char const *id, IggBool *open, int flags)
{
   BoolWrapper openArg(open);
   return ImGui::Begin(id, openArg, flags) ? 1 : 0;
}

void iggEnd(void)
{
   ImGui::End();
}

IggBool iggBeginChild(char const *id, IggVec2 const *size, IggBool border, int flags)
{
   Vec2Wrapper sizeArg(size);
   return ImGui::BeginChild(id, *sizeArg, border, flags) ? 1 : 0;
}

void iggEndChild(void)
{
   ImGui::EndChild();
}

void iggWindowPos(IggVec2 *pos)
{
   exportValue(*pos, ImGui::GetWindowPos());
}

void iggWindowSize(IggVec2 *size)
{
   exportValue(*size, ImGui::GetWindowSize());
}

float iggWindowWidth(void)
{
   return ImGui::GetWindowWidth();
}

float iggWindowHeight(void)
{
   return ImGui::GetWindowHeight();
}

void iggContentRegionAvail(IggVec2 *size)
{
   exportValue(*size, ImGui::GetContentRegionAvail());
}

void iggSetNextWindowPos(IggVec2 const *pos, int cond, IggVec2 const *pivot)
{
   Vec2Wrapper posArg(pos);
   Vec2Wrapper pivotArg(pivot);
   ImGui::SetNextWindowPos(*posArg, cond, *pivotArg);
}

void iggSetNextWindowSize(IggVec2 const *size, int cond)
{
   Vec2Wrapper sizeArg(size);
   ImGui::SetNextWindowSize(*sizeArg, cond);
}

void iggSetNextWindowSizeConstraints(const IggVec2* size_min, const IggVec2* size_max)
{
   Vec2Wrapper sizeMinArg(size_min);
   Vec2Wrapper sizeMaxArg(size_max);
   ImGui::SetNextWindowSizeConstraints(*sizeMinArg, *sizeMaxArg);
}

void iggSetNextWindowContentSize(IggVec2 const *size)
{
   Vec2Wrapper sizeArg(size);
   ImGui::SetNextWindowContentSize(*sizeArg);
}

void iggSetNextWindowFocus(void)
{
   ImGui::SetNextWindowFocus();
}

void iggSetNextWindowBgAlpha(float value)
{
   ImGui::SetNextWindowBgAlpha(value);
}

void iggPushFont(IggFont handle)
{
   ImFont *font = reinterpret_cast<ImFont *>(handle);
   ImGui::PushFont(font);
}

void iggPopFont(void)
{
   ImGui::PopFont();
}

void iggPushStyleColor(int index, IggVec4 const *col)
{
   Vec4Wrapper colArg(col);
   ImGui::PushStyleColor(index, *colArg);
}

void iggPopStyleColor(int count)
{
   ImGui::PopStyleColor(count);
}

void iggPushStyleVarFloat(int index, float value)
{
   ImGui::PushStyleVar(index, value);
}

void iggPushStyleVarVec2(int index, IggVec2 const *value)
{
   Vec2Wrapper valueArg(value);
   ImGui::PushStyleVar(index, *valueArg);
}

void iggPopStyleVar(int count)
{
   ImGui::PopStyleVar(count);
}

float iggGetFontSize()
{
   return ImGui::GetFontSize();
}

void iggPushItemWidth(float width)
{
   ImGui::PushItemWidth(width);
}

void iggPopItemWidth(void)
{
   ImGui::PopItemWidth();
}

float iggCalcItemWidth(void)
{
   return ImGui::CalcItemWidth();
}

void iggPushTextWrapPos(float wrapPosX)
{
   ImGui::PushTextWrapPos(wrapPosX);
}

void iggPopTextWrapPos(void)
{
   ImGui::PopTextWrapPos();
}

void iggPushID(char const *id)
{
   ImGui::PushID(id);
}
void iggPopID(void)
{
   ImGui::PopID();
}

void iggTextUnformatted(char const *text)
{
   ImGui::TextUnformatted(text);
}

void iggLabelText(char const *label, char const *text)
{
   ImGui::LabelText(label, "%s", text);
}

IggBool iggButton(char const *label, IggVec2 const *size)
{
   Vec2Wrapper sizeArg(size);
   return ImGui::Button(label, *sizeArg) ? 1 : 0;
}

void iggImage(IggTextureID textureID,
              IggVec2 const *size, IggVec2 const *uv0, IggVec2 const *uv1,
              IggVec4 const *tintCol, IggVec4 const *borderCol)
{
   Vec2Wrapper sizeArg(size);
   Vec2Wrapper uv0Arg(uv0);
   Vec2Wrapper uv1Arg(uv1);
   Vec4Wrapper tintColArg(tintCol);
   Vec4Wrapper borderColArg(borderCol);
   ImGui::Image(static_cast<ImTextureID>(textureID), *sizeArg, *uv0Arg, *uv1Arg, *tintColArg, *borderColArg);
}

IggBool iggImageButton(IggTextureID textureID,
                       IggVec2 const *size, IggVec2 const *uv0, IggVec2 const *uv1,
                       int framePadding, IggVec4 const *bgCol,
                       IggVec4 const *tintCol)
{
   Vec2Wrapper sizeArg(size);
   Vec2Wrapper uv0Arg(uv0);
   Vec2Wrapper uv1Arg(uv1);
   Vec4Wrapper bgColArg(bgCol);
   Vec4Wrapper tintColArg(tintCol);
   return ImGui::ImageButton(static_cast<ImTextureID>(textureID), *sizeArg, *uv0Arg, *uv1Arg, framePadding, *bgColArg, *tintColArg) ? 1 : 0;
}

IggBool iggCheckbox(char const *label, IggBool *selected)
{
   BoolWrapper selectedArg(selected);
   return ImGui::Checkbox(label, selectedArg) ? 1 : 0;
}

void iggProgressBar(float fraction, IggVec2 const *size, char const *overlay)
{
   Vec2Wrapper sizeArg(size);
   ImGui::ProgressBar(fraction, *sizeArg, overlay);
}

IggBool iggBeginCombo(char const *label, char const *previewValue, int flags)
{
   return ImGui::BeginCombo(label, previewValue, flags) ? 1 : 0;
}

void iggEndCombo(void)
{
   ImGui::EndCombo();
}

IggBool iggDragFloat(char const *label, float *value, float speed, float min, float max, char const *format, float power)
{
   return ImGui::DragFloat(label, value, speed, min, max, format, power) ? 1 : 0;
}

IggBool iggDragInt(char const *label, int *value, float speed, int min, int max, char const *format)
{
   return ImGui::DragInt(label, value, speed, min, max, format) ? 1 : 0;
}

IggBool iggSliderFloat(char const *label, float *value, float minValue, float maxValue, char const *format, float power)
{
   return ImGui::SliderFloat(label, value, minValue, maxValue, format, power) ? 1 : 0;
}

IggBool iggSliderFloatN(char const *label, float *value, int n, float minValue, float maxValue, char const *format, float power)
{
   return ImGui::SliderScalarN(label, ImGuiDataType_Float, (void *)value, n, &minValue, &maxValue, format, power) ? 1 : 0;
}

IggBool iggSliderInt(char const *label, int *value, int minValue, int maxValue, char const *format)
{
   return ImGui::SliderInt(label, value, minValue, maxValue, format) ? 1 : 0;
}

IggBool iggSplitter(IggBool split_vertically, float thickness, float *size1, float *size2)
{
    using namespace ImGui;
    ImGuiContext& g = *GImGui;
    ImGuiWindow* window = g.CurrentWindow;
    ImGuiID id = window->GetID("##Splitter");
    ImRect bb;
    bb.Min = window->DC.CursorPos + (split_vertically != 0 ? ImVec2(*size1, 0.0f) : ImVec2(0.0f, *size1));
    bb.Max = bb.Min + CalcItemSize(split_vertically != 0 ? ImVec2(thickness, -1.f) : ImVec2(-1.f, thickness), 0.0f, 0.0f);
    return SplitterBehavior(bb, id, split_vertically != 0 ? ImGuiAxis_X : ImGuiAxis_Y, size1, size2, 8.f, 8.f, 0.0f);
}

extern "C" int iggInputTextCallback(IggInputTextCallbackData data, int key);

static int iggInputTextCallbackWrapper(ImGuiInputTextCallbackData *data)
{
   return iggInputTextCallback(reinterpret_cast<IggInputTextCallbackData>(data), static_cast<int>(reinterpret_cast<size_t>(data->UserData)));
}

IggBool iggInputText(char const *label, char* buf, unsigned int bufSize, int flags, int callbackKey)
{
   return ImGui::InputText(label, buf, static_cast<size_t>(bufSize), flags,
                           iggInputTextCallbackWrapper, reinterpret_cast<void *>(callbackKey)) ? 1 : 0;
}

IggBool iggInputTextMultiline(char const *label, char* buf, unsigned int bufSize, IggVec2 const *size, int flags, int callbackKey)
{
   Vec2Wrapper sizeArg(size);
   return ImGui::InputTextMultiline(label, buf, static_cast<size_t>(bufSize), *sizeArg, flags,
                                    iggInputTextCallbackWrapper, reinterpret_cast<void *>(callbackKey)) ? 1 : 0;
}

void iggSeparator(void)
{
   ImGui::Separator();
}

void iggSameLine(float posX, float spacingW)
{
   ImGui::SameLine(posX, spacingW);
}

void iggSpacing(void)
{
   ImGui::Spacing();
}

void iggDummy(IggVec2 const *size)
{
   Vec2Wrapper sizeArg(size);
   ImGui::Dummy(*sizeArg);
}

void iggBeginGroup(void)
{
   ImGui::BeginGroup();
}

void iggEndGroup(void)
{
   ImGui::EndGroup();
}

void iggCursorPos(IggVec2 *pos)
{
   exportValue(*pos, ImGui::GetCursorPos());
}

float iggCursorPosX(void)
{
   return ImGui::GetCursorPosX();
}

float iggCursorPosY(void)
{
   return ImGui::GetCursorPosY();
}

void iggCursorStartPos(IggVec2 *pos)
{
   exportValue(*pos, ImGui::GetCursorStartPos());
}

void iggCursorScreenPos(IggVec2 *pos)
{
   exportValue(*pos, ImGui::GetCursorScreenPos());
}

void iggSetCursorPos(IggVec2 const *localPos)
{
   Vec2Wrapper localPosArg(localPos);
   ImGui::SetCursorPos(*localPosArg);
}

void iggSetCursorScreenPos(IggVec2 const *absPos)
{
   Vec2Wrapper absPosArg(absPos);
   ImGui::SetCursorScreenPos(*absPosArg);
}

void iggAlignTextToFramePadding()
{
   ImGui::AlignTextToFramePadding();
}

float iggGetTextLineHeight(void)
{
   return ImGui::GetTextLineHeight();
}

float iggGetTextLineHeightWithSpacing(void)
{
   return ImGui::GetTextLineHeightWithSpacing();
}

float iggGetFrameHeight()
{
   return ImGui::GetFrameHeight();
}

float iggGetFrameHeightWithSpacing()
{
   return ImGui::GetFrameHeightWithSpacing();
}

IggBool iggTreeNode(char const *label, int flags)
{
   return ImGui::TreeNodeEx(label, flags) ? 1 : 0;
}

void iggTreePop(void)
{
   ImGui::TreePop();
}

void iggSetNextTreeNodeOpen(IggBool open, int cond)
{
   ImGui::SetNextTreeNodeOpen(open != 0, cond);
}

 IggBool iggCollapsingHeader(const char* label, IggBool p_open)
 {
    bool open = p_open != 0;
    return ImGui::CollapsingHeader(label, &open, 0) ? 1 : 0;
 }

float iggGetTreeNodeToLabelSpacing(void)
{
   return ImGui::GetTreeNodeToLabelSpacing();
}


IggBool iggSelectable(char const *label, IggBool selected, int flags, IggVec2 const *size)
{
   Vec2Wrapper sizeArg(size);
   return ImGui::Selectable(label, selected != 0, flags, *sizeArg) ? 1 : 0;
}

IggBool iggListBoxV(char const *label, int *currentItem, char const *const items[], int itemsCount, int heightItems)
{
   return ImGui::ListBox(label, currentItem, items, itemsCount, heightItems) ? 1 : 0;
}

void iggPlotLines(char const *label, float const *values, int valuesCount, int valuesOffset, char const *overlayText, float scaleMin, float scaleMax, IggVec2 const *graphSize)
{
   Vec2Wrapper graphSizeArg(graphSize);
   ImGui::PlotLines(label, values, valuesCount, valuesOffset, overlayText, scaleMin, scaleMax, *graphSizeArg);
}

void iggPlotHistogram(char const *label, float const *values, int valuesCount, int valuesOffset, char const *overlayText, float scaleMin, float scaleMax, IggVec2 const *graphSize)
{
   Vec2Wrapper graphSizeArg(graphSize);
   ImGui::PlotHistogram(label, values, valuesCount, valuesOffset, overlayText, scaleMin, scaleMax, *graphSizeArg);
}

void iggSetTooltip(char const *text)
{
   ImGui::SetTooltip("%s", text);
}

void iggBeginTooltip(void)
{
   ImGui::BeginTooltip();
}

void iggEndTooltip(void)
{
   ImGui::EndTooltip();
}

IggBool iggBeginMainMenuBar(void)
{
   return ImGui::BeginMainMenuBar() ? 1 : 0;
}

void iggEndMainMenuBar(void)
{
   ImGui::EndMainMenuBar();
}

IggBool iggBeginMenuBar(void)
{
   return ImGui::BeginMenuBar() ? 1 : 0;
}

void iggEndMenuBar(void)
{
   ImGui::EndMenuBar();
}

IggBool iggBeginMenu(char const *label, IggBool enabled)
{
   return ImGui::BeginMenu(label, enabled != 0) ? 1 : 0;
}

void iggEndMenu(void)
{
   ImGui::EndMenu();
}

IggBool iggMenuItem(char const *label, char const *shortcut, IggBool selected, IggBool enabled)
{
   return ImGui::MenuItem(label, shortcut, selected != 0, enabled != 0) ? 1 : 0;
}

void iggOpenPopup(char const *id)
{
   ImGui::OpenPopup(id);
}

IggBool iggBeginPopupModal(char const *name, IggBool *open, int flags)
{
   BoolWrapper openArg(open);
   return ImGui::BeginPopupModal(name, openArg, flags) ? 1 : 0;
}

IggBool iggBeginPopupContextItem(char const *label, int mouseButton)
{
   return ImGui::BeginPopupContextItem(label, mouseButton) ? 1 : 0;
}

void iggEndPopup(void)
{
   ImGui::EndPopup();
}

void iggCloseCurrentPopup(void)
{
   ImGui::CloseCurrentPopup();
}


IggBool iggBeginDragDropSource(int flags){
    return ImGui::BeginDragDropSource(flags) ? 1 : 0;
}
IggBool iggSetDragDropPayload(const char* type, const char* data, int size){
    return ImGui::SetDragDropPayload(type, (const void*)data, size) ? 1 : 0;
}
void iggEndDragDropSource(){
    ImGui::EndDragDropSource();
}
IggBool iggBeginDragDropTarget(){
    return ImGui::BeginDragDropTarget() ? 1 : 0;
}
void iggAcceptDragDropPayload(const char* type, int flags, char* payload_out, int size_out){
    const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(type, flags);
    if(payload && payload->IsDelivery())
        memcpy(payload_out, payload->Data, size_out);
}
void iggEndDragDropTarget(){
    ImGui::EndDragDropTarget();
}

IggBool iggIsItemHovered(int flags)
{
   return ImGui::IsItemHovered(flags) ? 1 : 0;
}

IggBool iggIsKeyDown(int key)
{
   return ImGui::IsKeyDown(key);
}

IggBool iggIsKeyPressed(int key, IggBool repeat)
{
   return ImGui::IsKeyPressed(key, repeat);
}

IggBool iggIsKeyReleased(int key)
{
   return ImGui::IsKeyReleased(key);
}

IggBool iggIsMouseDown(int button)
{
   return ImGui::IsMouseDown(button);
}

IggBool iggIsAnyMouseDown()
{
   return ImGui::IsAnyMouseDown();
}

IggBool iggIsMouseClicked(int button, IggBool repeat)
{
   return ImGui::IsMouseClicked(button, repeat);
}

IggBool iggIsMouseReleased(int button)
{
   return ImGui::IsMouseReleased(button);
}

IggBool iggIsMouseDoubleClicked(int button)
{
   return ImGui::IsMouseDoubleClicked(button);
}

void iggBeginColumns(int count, char const *label, int flags)
{
   ImGui::Columns(count, label, flags);
}

void iggNextColumn()
{
   ImGui::NextColumn();
}

int iggGetColumnIndex()
{
   return ImGui::GetColumnIndex();
}

int iggGetColumnWidth(int index)
{
   return ImGui::GetColumnWidth(index);
}

void iggSetColumnWidth(int index, float width)
{
   ImGui::SetColumnWidth(index, width);
}

float iggGetColumnOffset(int index)
{
   return ImGui::GetColumnOffset(index);
}

void iggSetColumnOffset(int index, float offsetX)
{
   ImGui::SetColumnOffset(index, offsetX);
}

int iggGetColumnsCount()
{
   return ImGui::GetColumnsCount();
}

void iggSetScrollHereY(float centerYRatio)
{
   ImGui::SetScrollHereY(centerYRatio);
}

void iggSetItemAllowOverlap()
{
   ImGui::SetItemAllowOverlap();
}

void iggCalcTextSize(const char* text, IggVec2 *out)
{    
    ImVec2 im_out = ImGui::CalcTextSize(text, NULL, true); 
    exportValue(*out, im_out);
}

void iggSetItemDefaultFocus()
{
   ImGui::SetItemDefaultFocus();
}

IggBool iggIsItemFocused()
{
   return ImGui::IsItemFocused();
}

IggBool iggIsAnyItemFocused()
{
   return ImGui::IsAnyItemFocused();
}

int iggGetMouseCursor()
{
   return ImGui::GetMouseCursor();
}

void iggSetMouseCursor(int cursor)
{
   ImGui::SetMouseCursor(cursor);
}
