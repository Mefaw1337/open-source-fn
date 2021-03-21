#include "stdafx.h"
#include "CHookSpoofcall.hpp"

static BOOL RenderInit = FALSE;

ID3D11Device *device = nullptr;
ID3D11DeviceContext *immediateContext = nullptr;
ID3D11RenderTargetView *renderTargetView = nullptr;
WNDPROC WndProc;

HRESULT(*PresentOriginal)(IDXGISwapChain *swapChain, UINT syncInterval, UINT flags) = nullptr;
HRESULT(*ResizeOriginal)(IDXGISwapChain *swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) = nullptr;
BOOLEAN MaskCompare(PVOID buffer, LPCSTR pattern, LPCSTR mask) {
	for (auto b = reinterpret_cast<PBYTE>(buffer); *mask; ++pattern, ++mask, ++b) {
		if (*mask == 'x' && *reinterpret_cast<LPCBYTE>(pattern) != *b) {
			return FALSE;
		}
	}

	return TRUE;
}

PBYTE FindPattern(PVOID base, DWORD size, LPCSTR pattern, LPCSTR mask) {
	size -= static_cast<DWORD>(strlen(mask));

	for (auto i = 0UL; i < size; ++i) {
		auto addr = reinterpret_cast<PBYTE>(base) + i;
		if (MaskCompare(addr, pattern, mask)) {
			return addr;
		}
	}

	return NULL;
}
PBYTE FindPattern(LPCSTR pattern, LPCSTR mask) {
	MODULEINFO info = { 0 };
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info));

	return FindPattern(info.lpBaseOfDll, info.SizeOfImage, pattern, mask);
}

__declspec(dllexport) HRESULT PresentHook(IDXGISwapChain *swapChain, UINT syncInterval, UINT flags) {
	if (!device) {
		swapChain->GetDevice(__uuidof(device), reinterpret_cast<PVOID *>(&device));
		device->GetImmediateContext(&immediateContext);

		ID3D11Texture2D *renderTarget = nullptr;
		swapChain->GetBuffer(0, __uuidof(renderTarget), reinterpret_cast<PVOID *>(&renderTarget));
		device->CreateRenderTargetView(renderTarget, nullptr, &renderTargetView);
		renderTarget->Release();

		DXGI_SWAP_CHAIN_DESC desc;
		swapChain->GetDesc(&desc);

		ImFontConfig font_cfg;
		font_cfg.GlyphExtraSpacing.x = 1.5f;
		ImGui::GetIO().Fonts->AddFontFromFileTTF(("C:\\Windows\\Fonts\\Verdana.ttf"), 16.f, &font_cfg);

		ImGui_ImplDX11_Init(desc.OutputWindow, device, immediateContext);
		ImGui_ImplDX11_CreateDeviceObjects();
	}

	immediateContext->OMSetRenderTargets(1, &renderTargetView, nullptr);

	auto& p_Window = BeginScene();

	const char* label = C("FORTNITE, UE_4.25 BY MEFAW#1511");

	p_Window.DrawList->AddText(ImVec2(25, 2 + 1), ImGui::GetColorU32({ 0, 0, 0, 1 }), label);
	p_Window.DrawList->AddText(ImVec2(25, 2 + 2), ImGui::GetColorU32({ 0, 0, 0, 1 }), label);
	p_Window.DrawList->AddText(ImVec2(25, 2), ImGui::GetColorU32({ 1, 0, 0, 1 }), label);

	bool bUpdated = MainAddress();

	if (bUpdated)
	{
		esp_loop(esp);
	}

	EndScene(p_Window);

	return PresentOriginal(swapChain, syncInterval, flags);
}

__declspec(dllexport) HRESULT ResizeHook(IDXGISwapChain *swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) {
	ImGui_ImplDX11_Shutdown();
	renderTargetView->Release();
	immediateContext->Release();
	device->Release();
	device = nullptr;

	return ResizeOriginal(swapChain, bufferCount, width, height, newFormat, swapChainFlags);
}

ImGuiWindow &BeginScene() {
	ImGui_ImplDX11_NewFrame();
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
	ImGui::Begin("##scene", nullptr, ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar);

	auto &io = ImGui::GetIO();
	ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2
	(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);

	return *ImGui::GetCurrentWindow();
}

VOID EndScene(ImGuiWindow &window) {
	window.DrawList->PushClipRectFullScreen();
	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
	ImGui::Render();
}

VOID Main() {
	IDXGISwapChain      *swapChain    = nullptr;
	ID3D11Device        *device       = nullptr;
	ID3D11DeviceContext *context      = nullptr;
	auto                 featureLevel = D3D_FEATURE_LEVEL_11_0;

	DXGI_SWAP_CHAIN_DESC sd           = { 0 };
	sd.BufferCount                    = 1;
	sd.BufferDesc.Format              = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferUsage                    = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.Flags                          = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.OutputWindow                   = GetForegroundWindow();
	sd.SampleDesc.Count               = 1;
	sd.Windowed                       = TRUE;

	if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, 0, 0, &featureLevel, 1, D3D11_SDK_VERSION, &sd, &swapChain, &device, nullptr, &context))) {
		MessageBox(0, L"ALLAH AKBAR", L"ALLAH AKBAR", MB_ICONERROR);
		return;
	}

	auto table = *reinterpret_cast<PVOID **>(swapChain);
	auto present = table[8];
	auto resize = table[13];

	context->Release();
	device->Release();
	swapChain->Release();
	
	MH_Initialize();

	Sleep(1000);
	game_rbx_jmp = gadget(NULL);

	auto PE = FindPattern(
		C("\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xD9\x41\x8B\xF0\x48\x8B\x49\x30\x48\x8B\xFA\xE8\x00\x00\x00\x00\xBA\x00\x00\x00\x00\x48\x8B\xC8"), 
		C("xxxx?xxxx?xxxxxxxxxxxxxxxxxxx????x????xxx"));

	MH_CreateHook(PE, GetViewPointHook, (PVOID*)&GetViewPoint);
	MH_EnableHook(PE);


	MH_CreateHook(present, PresentHook, reinterpret_cast<PVOID *>(&PresentOriginal));
	MH_EnableHook(present);

	MH_CreateHook(resize, ResizeHook, reinterpret_cast<PVOID *>(&ResizeOriginal));
	MH_EnableHook(resize);

	CGame::CreateGameObjects();
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
	if (reason)
	{
		Main();
	}

	return true;
}
