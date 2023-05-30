#include "main.h"

SAMPFUNCS* SF = new SAMPFUNCS();

int key_timer = 0;

void Clear()
{
	if (SF)
		delete SF;
	for (auto window : ImGuiApi::getWindows())
		delete window;
}

void CALLBACK mainloop()
{
	static bool init = false;
	if (!init)
	{
		if (GAME == nullptr)
			return;
		if (GAME->GetSystemState() != eSystemState::GS_PLAYING_GAME)
			return;
		if (!SF->getSAMP()->IsInitialized())
			return;
		if(SF->getSAMP()->getInfo()->iGameState != GAMESTATE_CONNECTED)
			return;
		SF->getSAMP()->getChat()->AddChatMessage(0xFF2F96F3, "| SAMP-Devtools v1.0 | {FFFFFF}loaded successfully");
		ImGuiApi::Init();
		ImGuiApi::addWindow(new MainWindow("SAMP DevTools"));
		ImGuiApi::addWindow(new ChatMessageWindow("Chat Message"));
		ImGuiApi::addWindow(new DialogWindow("Dialog Window"));
		ImGuiApi::addWindow(new ColorEditWindow("Color"));
		init = true;
	}
	else 
	{
		//TODO: implement key event
		if (SF->getGame()->isKeyDown(VK_F5) && key_timer < GetTickCount())
		{
			key_timer = GetTickCount() + 500;
			ImGuiApi::getWindows()[0]->ToggleVisible();
			SF->getSAMP()->getMisc()->ToggleCursor(ImGuiApi::getWindows()[0]->IsVisible());
		}
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReasonForCall, LPVOID lpReserved)
{
	switch (dwReasonForCall)
	{
		case DLL_PROCESS_ATTACH:
			SF->initPlugin(mainloop, hModule);
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}
