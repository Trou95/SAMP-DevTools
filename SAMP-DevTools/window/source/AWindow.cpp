#include "../include/AWindow.h"


AWindow::AWindow(const std::string& title) : visible(false) , window_flags(0)
{
	this->title = _strdup(title.c_str());
	style = &ImGui::GetStyle();
}

bool AWindow::IsVisible() const
{
	return visible;
}

void AWindow::SetVisible(bool visible)
{
	this->visible = visible;
}

void AWindow::ToggleVisible()
{
	visible = !visible;
}

AWindow::~AWindow()
{
	if(title)
		delete title;
}

