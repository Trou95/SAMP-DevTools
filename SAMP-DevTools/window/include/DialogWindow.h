#pragma once

#include "AWindow.h"

#define DIALOG_CAPTION_LENGTH 256
#define DIALOG_INFO_LEN 4096
#define DIALOG_BUTTON_LEN 256

class DialogWindow : public AWindow
{
	public:
		DialogWindow(const std::string& title);
		~DialogWindow();

		void Draw();
		void OnWindowEvent(int event_id);

	private:
		int dialog_style;
		char caption[DIALOG_CAPTION_LENGTH];
		char info[DIALOG_INFO_LEN];
		char buttons[2][DIALOG_BUTTON_LEN];

};

