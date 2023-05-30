#pragma once

#include "AWindow.h"

#define MAX_CHAT_MESSAGE_LENGTH 144
#define INPUT_WIDTH 500
#define INPUT_HEIGHT 50

class ChatMessageWindow : public AWindow
{
	public:
		ChatMessageWindow(const std::string& title);
		~ChatMessageWindow();

		void Draw();
		void OnWindowEvent(int event_id);

	private:
		char msg[MAX_CHAT_MESSAGE_LENGTH];

};

