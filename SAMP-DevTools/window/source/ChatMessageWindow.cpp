#include "../include/ChatMessageWindow.h"

ChatMessageWindow::ChatMessageWindow(const std::string& title) : AWindow(title)
{
	window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
	memset(msg, 0, sizeof(msg));
}

void ChatMessageWindow::OnWindowEvent(int event_id)
{
	//TODO: abstraction layer for samp
	if (event_id == 1)
		SF->getSAMP()->getChat()->AddChatMessage(-1, msg);
}

void ChatMessageWindow::Draw()
{
	ImGui::Begin(title, &visible, ImGuiWindowFlags_NoResize | window_flags);

	style->FramePadding.y = 10.0f;
	ImGui::SetNextItemWidth(INPUT_WIDTH);
	if(ImGui::InputText("##input", msg, IM_ARRAYSIZE(msg), ImGuiInputTextFlags_EnterReturnsTrue))
		OnWindowEvent(1);
	if (ImGui::Button("Send Message", ImVec2(100, 0)))
		OnWindowEvent(1);


	ImGui::End();
}


ChatMessageWindow::~ChatMessageWindow() {

}
