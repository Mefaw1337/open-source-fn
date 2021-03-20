#pragma once

#define RELATIVE_ADDR(addr, size) ((PBYTE)((UINT_PTR)(addr) + *(PINT)((UINT_PTR)(addr) + ((size) - sizeof(INT))) + (size))
#define st C
#include "CMemory.hpp"
#include "CCheat.hpp"

BOOLEAN ccMaskCompare(PVOID buffer, LPCSTR pattern, LPCSTR mask) {
	for (auto b = reinterpret_cast<PBYTE>(buffer); *mask; ++pattern, ++mask, ++b) {
		if (*mask == 'x' && *reinterpret_cast<LPCBYTE>(pattern) != *b) {
			return FALSE;
		}
	}

	return TRUE;
}

PBYTE yikes(PVOID base, DWORD size, LPCSTR pattern, LPCSTR mask) {
	size -= static_cast<DWORD>(strlen(mask));

	for (auto i = 0UL; i < size; ++i) {
		auto addr = reinterpret_cast<PBYTE>(base) + i;
		if (ccMaskCompare(addr, pattern, mask)) {
			return addr;
		}
	}

	return NULL;
}
PBYTE yikes(LPCSTR pattern, LPCSTR mask) {
	MODULEINFO info = { 0 };
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info));

	return yikes(info.lpBaseOfDll, info.SizeOfImage, pattern, mask);
}

namespace CGame
{
	bool CreateGameObjects()
	{
		uint64_t UWorld = memory::occurence(st("FortniteClient-Win64-Shipping.exe"), st("48 8B 1D ? ? ? ? 48 85 DB 74 3B 41"));
		uint64_t GObjects = memory::occurence(st("FortniteClient-Win64-Shipping.exe"), st("48 8B 05 7E 38 79 05 4C 8D 34 CD"));

		UWorld = reinterpret_cast<uintptr_t>(RELATIVE_ADDR(UWorld, 7)));
		GObjects = reinterpret_cast<uintptr_t>(RELATIVE_ADDR(GObjects, 7)));

		OFFSET_UWORLD = UWorld;
		OFFSET_UOBJECT = GObjects;

		OFFSET_GETOBJECTNAMES = (memory::occurence(st("FortniteClient-Win64-Shipping.exe"), st("40 53 48 83 EC 20 48 8B D9 48 85 D2 75 45 33 C0 48 89 01 48 89 41 08 8D 50 05 E8 ? ? ? ? 8B 53 08 8D 42 05 89 43 08 3B 43 0C 7E 08 48 8B CB E8 ? ? ? ? 48 8B 0B 48 8D 15 ? ? ? ? 41 B8 ? ? ? ? E8 ? ? ? ? 48 8B C3 48 83 C4 20 5B C3 48 8B 42 18")));
		OFFSET_GETNAMEBYINDEX = (memory::occurence(st("FortniteClient-Win64-Shipping.exe"), st("48 89 5C 24 ? 55 56 57 48 8B EC 48 83 EC 30 8B")));
		OFFSET_FNFREE = (memory::occurence(st("FortniteClient-Win64-Shipping.exe"), st("48 85 C9 74 2E 53 48 83 EC 20 48 8B D9 48 8B 0D ? ? ? ? 48 85 C9 75 0C")));

		auto GetBounds_Addr = (memory::occurence(st("FortniteClient-Win64-Shipping.exe"),
			st("E8 ? ? ? ? 48 8B 4D 77 B3 01")));
		CData::GetBounds = (GetBounds_Addr + *(DWORD*)(GetBounds_Addr + 0x1) + 0x5);

		CData::FreeFn = (uintptr_t)yikes(st("\x48\x85\xC9\x74\x2E\x53\x48\x83\xEC\x20\x48\x8B\xD9\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9\x75\x0C"), st("xxxxxxxxxxxxxxxx????xxxxx"));


		CData::BRUH = (uintptr_t)yikes(st("\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x83\xC4\x28\xC3\xCC\x48\xE9\xCC\x2F\xC2\xFB"), st("xxxxx????xxxxxxxxxxxx"));


		CData::LineOfSightTo = (memory::occurence(st("FortniteClient-Win64-Shipping.exe"),
			st("40 55 53 56 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 E0 49")));
		CData::GetWeaponStats = (memory::occurence(st("FortniteClient-Win64-Shipping.exe"),
			st("48 83 EC 58 48 8B 91 ? ? ? ? 48 85 D2 0F 84 ? ? ? ? F6 81 ? ? ? ? ? 74 10 48 8B 81 ? ? ? ? 48 85 C0 0F 85 ? ? ? ? 48 8B 8A ? ? ? ? 48 89 5C 24 ? 48 8D 9A ? ? ? ? 48 85 C9")));

		return true;
	}

}