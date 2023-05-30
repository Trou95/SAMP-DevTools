#pragma once

#include "AWindow.h"

class ColorEditWindow : public AWindow
{
	public:
		ColorEditWindow(const std::string& title);
		~ColorEditWindow();

		void Draw();

	private:
		ImVec4 color;


};

