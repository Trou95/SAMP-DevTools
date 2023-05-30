#pragma once

#include "AWindow.h"


extern SAMPFUNCS * SF;

#define BUTTON_WIDTH 250
#define BUTTON_HEIGHT 50

class MainWindow : public AWindow
{
	public:
		MainWindow(const std::string& title);
		~MainWindow();

		void Draw();
		void OnWindowEvent(int event_id);

	private:
		ImVec2 buttonSize;
};

#include "../../SFAPI/SAMPFUNCS_API.h"

