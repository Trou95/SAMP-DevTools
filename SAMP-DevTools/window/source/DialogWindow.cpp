#include "../include/DialogWindow.h"

DialogWindow::DialogWindow(const std::string& title) : AWindow(title)
{
    window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;

    dialog_style = 0;
    memset(caption, 0, sizeof(caption));
    memset(info, 0, sizeof(info));
    memset(buttons, 0, sizeof(buttons));

    strcpy(buttons[0], "OK");
    strcpy(buttons[1], "Cancel");
}

void DialogWindow::OnWindowEvent(int event_id)
{
    SF->getSAMP()->getDialog()->ShowDialog(999, dialog_style, caption, info, buttons[0], buttons[1]);
}

void DialogWindow::Draw()
{
	ImGui::Begin(title, &visible, ImGuiWindowFlags_NoResize | window_flags);

    static const char* items[] = {
        "(0) - DIALOG_STYLE_MSGBOX",
        "(1) - DIALOG_STYLE_INPUT",
        "(2) - DIALOG_STYLE_LIST",
        "(3) - DIALOG_STYLE_PASSWORD",
        "(4) - DIALOG_STYLE_TABLIST",
        "(5) - DIALOG_STYLE_TABLIST_HEADERS",
    };

    ImGui::Text("Dialog Style");
    if (ImGui::BeginCombo("##Dialog Style", items[dialog_style]))
    {
        for (int i = 0; i < 6; i++)
        {
            bool isSelected = (dialog_style == i);
            if (ImGui::Selectable(items[i], isSelected))
                dialog_style = i;
            if (isSelected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }

    ImGui::Text("Caption");
    style->FramePadding.y = 5.0f;
    ImGui::SetNextItemWidth(INPUT_WIDTH);
    ImGui::InputText("##Caption", caption, IM_ARRAYSIZE(caption));
    ImGui::Text("Info");
    ImGui::SetNextItemWidth(INPUT_WIDTH);
    ImGui::InputTextMultiline("##Info", info, IM_ARRAYSIZE(info));

    ImGui::Text("Buttons");
    ImGui::InputText("##Button1", buttons[0], sizeof(buttons[0]));
    ImGui::SameLine();
    ImGui::InputText("##Button2", buttons[1], sizeof(buttons[1]));

    if (ImGui::Button("Dialog", ImVec2(100, 0)))
        OnWindowEvent(1);
  

	ImGui::End();

}

DialogWindow::~DialogWindow()
{

}