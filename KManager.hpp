#pragma once
#include <windows.h>

typedef int (WINAPI* GetCastedKeyState)(DWORD);
static GetCastedKeyState CheckInput;