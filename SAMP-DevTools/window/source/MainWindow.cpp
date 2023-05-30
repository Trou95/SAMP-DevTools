#include "../include/MainWindow.h"

MainWindow::MainWindow(const std::string& title) : AWindow(title)
{
	window_flags = ImGuiWindowFlags_NoResize;
	buttonSize = ImVec2(BUTTON_WIDTH, BUTTON_HEIGHT);
}

void MainWindow::OnWindowEvent(int event_id)
{
	ImGuiApi::OnImGuiEvent(*this, event_id);
}

void MainWindow::Draw()
{
	
	ImGui::SetNextWindowSize(ImVec2(buttonSize.x + (style->WindowPadding.x * 2), 400));
	ImGui::Begin(title, &visible, window_flags);

	if (ImGui::Button("Chat Message", buttonSize))
		OnWindowEvent(1);
	if (ImGui::Button("Dialog", buttonSize))
		OnWindowEvent(2);
	if (ImGui::Button("Color Editor", buttonSize))
		OnWindowEvent(3);

	ImGui::End();
}

MainWindow::~MainWindow()
{

}