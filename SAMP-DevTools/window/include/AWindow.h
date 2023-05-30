#pragma once

#include "IWIndow.h"
#include <string>
#include <vector>


class SAMPFUNCS;

class ImGuiApi;
class ImGuiStyle;
class AWindow : public IWindow
{
	public:
		virtual ~AWindow();
		virtual void Draw() = 0;

		bool IsVisible() const;
		void SetVisible(bool visible);
		void ToggleVisible();

	protected:
		AWindow(const std::string& title);

		ImGuiStyle* style;

		bool visible;
		const char* title;
		int window_flags;
};

#include "../../imgui/imgui.h"
#include "../../imgui_api/ImGuiApi.h"


