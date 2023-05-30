#include "../include/ColorEditWindow.h"


ColorEditWindow::ColorEditWindow(const std::string& title) : AWindow(title)
{
	window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
	color = ImVec4(0, 0, 0, 1);
}

void ColorEditWindow::Draw()
{
	ImGui::Begin(title, &visible, window_flags);

	static char color_text[64] = { 0 };
	static char color_text_hex[64] = { 0 };
	static int colors[4] = { 0 };

	colors[0] = (int)(color.x * 255);
	colors[1] = (int)(color.y * 255);
	colors[2] = (int)(color.z * 255);
	colors[3] = (int)(color.w * 255);
	sprintf(color_text, "{%02X%02X%02X}", colors[0], colors[1], colors[2]);
	sprintf(color_text_hex, "0x%02X%02X%02X%02X", colors[0], colors[1], colors[2], colors[3]);

	ImGui::ColorPicker4("##Color Edit", (float*)&color, ImGuiColorEditFlags_AlphaBar);
	ImGui::InputText("##Color RGB", (char*)color_text, IM_ARRAYSIZE(color_text), ImGuiInputTextFlags_ReadOnly);
	ImGui::InputText("##Color Hex", (char*)color_text_hex, IM_ARRAYSIZE(color_text_hex), ImGuiInputTextFlags_ReadOnly);

	ImGui::End();
}

ColorEditWindow::~ColorEditWindow()
{

}
