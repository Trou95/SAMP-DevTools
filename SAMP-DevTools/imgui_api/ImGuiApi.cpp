#include "ImGuiApi.h"

bool ImGuiApi::init = false;
IDirect3DDevice9* ImGuiApi::m_pDevice = nullptr;
std::vector<AWindow*> ImGuiApi::windows;

void ImGuiApi::Init()
{
	if(init)
		return;
	if(SF == nullptr)
		return;
	if(SF->getRender() == nullptr)
		return;
	if(SF->getRender()->getD3DDevice() == nullptr)
		return;

	auto pDevice = SF->getRender()->getD3DDevice();
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(FindWindowA(NULL, "GTA:SA:MP"));
	ImGui_ImplDX9_Init(pDevice);

	SF->getRender()->registerD3DCallback(D3DMETHOD_PRESENT, Present);
	SF->getRender()->registerD3DCallback(D3DMETHOD_RESET, Reset);
	SF->getGame()->registerWndProcCallback(SFGame::MEDIUM_CB_PRIORITY, WndProcHandler);
	init = true;
}

void ImGuiApi::OnImGuiEvent(AWindow& window, int event_id)
{
	if (event_id > windows.size())
		return;
	windows[event_id]->ToggleVisible();
}

void ImGuiApi::addWindow(AWindow* window)
{
	windows.push_back(window);
}

std::vector<AWindow*>& ImGuiApi::getWindows()
{
	return windows;
}

bool CALLBACK ImGuiApi::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
	if(!SF->getRender()->CanDraw())
			return true;

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	for (auto window : windows)
	{
		if (window->IsVisible())
			window->Draw();
	}

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return true;
}

bool CALLBACK ImGuiApi::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	return true;
}

bool CALLBACK ImGuiApi::WndProcHandler(HWND hwd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (SF->getSAMP()->getInput()->iInputEnabled)
		return true;
	ImGui_ImplWin32_WndProcHandler(hwd, msg, wParam, lParam);
	return true;
}