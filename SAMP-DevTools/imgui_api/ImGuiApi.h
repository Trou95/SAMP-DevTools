#pragma once


#include "../imgui/imgui.h"
#include "../imgui//imgui_impl_dx9.h"
#include "../imgui//imgui_impl_win32.h"
#include "../imgui//imgui_internal.h"
#include "../window/include/MainWindow.h"
#include "../window/include/ChatMessageWindow.h"
#include "../window/include/DialogWindow.h"
#include "../window/include/ColorEditWindow.h"
#include <d3dx9.h>
#include <vector>

#include "../../SFAPI/SAMPFUNCS_API.h"

extern SAMPFUNCS *SF;
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class ImGuiApi
{
	private:
		static bool init;
		static IDirect3DDevice9* m_pDevice;

		static std::vector<AWindow*> windows;

		static bool CALLBACK WndProcHandler(HWND hwd, UINT msg, WPARAM wParam, LPARAM lParam);
		static bool CALLBACK Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);

	public:
		static void Init();
		static void addWindow(AWindow* window);
		static std::vector<AWindow*>& getWindows();

		static void OnImGuiEvent(AWindow& src, int event_id);

};

