#pragma once

#include "CCheat.hpp"
#include "CGame.hpp"
#include "Draw.hpp"
#include "Globals.hpp"
#include "Settings.hpp"
#include "XOR.hpp"
#include "Virtualiser.hpp"
#include "KManager.hpp"
#include "CHookSpoofcall.hpp"
#include "GUI.h"

#include <stdio.h>
#include <windows.h>

#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_internal.h>

#include <MinHook.h>
#pragma comment(lib, "minhook.lib")

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

ImGuiWindow &BeginScene();
VOID EndScene(ImGuiWindow &window);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool esp = 0;
bool menu = 0;