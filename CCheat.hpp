/*
Mefaw#1511
Here is a small message , this is a open-source base .
You can skid it but dont sell it
Update all offsets you skid
*/

#pragma once

#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#include <cstdint>
#include "Virtualiser.hpp"
#include "CStructs.hpp"
#include "CHookSpoofcall.hpp"
#include "stdafx.h"
#include "stdafx.h"
PVOID jmp_rbx_0 = NULL;

namespace CData {
	PVOID* uWorld = 0;
	PVOID LaunchCharacter = 0;
	uintptr_t GetBounds = 0;
	uintptr_t LineOfSightTo = 0;
	uintptr_t FreeFn = 0;
	uintptr_t BRUH = 0;
	uintptr_t GetBoneMatrix = 0;
	uintptr_t ObjectsCountOnWorld = 0;
	uintptr_t ObjectsOnWorld = 0;
	uintptr_t GetWeaponStats = 0;

	namespace Engine {
		namespace World {
			DWORD OwningGameInstance = 0x180;
			DWORD Levels = 0x138;
			DWORD PersistentLevel = 0x30;
		}
		namespace SceneComponent {
			DWORD RelativeLocation = 0x11C;
			DWORD ComponentVelocity = 0x140;
		}

		namespace Level {
			DWORD AActors = 0x98;
		}

		namespace GameInstance {
			DWORD LocalPlayers = 0x38;
		}

		namespace Player {
			DWORD PlayerController = 0x30;
		}

		namespace Controller {
			DWORD ControlRotation = 0x288;
			DWORD RemoteViewPitch = 0x232;
			PVOID SetControlRotation = 0;
			PVOID SetActorHiddenInGame = 0;
		}

		namespace PlayerController {
			DWORD AcknowledgedPawn = 0x2A0;
			DWORD PlayerCameraManager = 0x2B8;
		}

		namespace Pawn {
			DWORD PlayerState = 0x240;
		}

		namespace PlayerState {
			PVOID GetPlayerName = 0;
		}

		namespace Actor {
			PVOID SetActorHiddenInGame = 0;
			DWORD CustomTimeDilation = 0x98;
			DWORD RootComponent = 0x130;
		}

		namespace Character {
			DWORD Mesh = 0x280;
		}

		namespace StaticMeshComponent {
			DWORD ComponentToWorld = 0x1C0;
			DWORD StaticMesh = 0x478;
		}

		namespace SkinnedMeshComponent {
			DWORD CachedWorldSpaceBounds = 0x600;
		}
	}

	namespace FortniteGame {
		namespace FortPawn {
			DWORD bIsDBNO = 0x552;
			DWORD bIsDying = 0x538;
			DWORD CurrentWeapon = 0x5D0;
		}
		namespace FortMeatballVehicle {
			DWORD BoostMinPushForce = 0x0478;
			DWORD BoostTopSpeedForceMultiplier = 0x047C;
			DWORD BoostTopSpeedMultiplier = 0x0480;
			DWORD LandTopSpeedMultiplier = 0x0488;
			DWORD LandPushForceMultiplier = 0x048C;
			DWORD BoostSteeringMultiplier = 0x04CC;
			DWORD LandSteeringMultiplier = 0x04D4;
			DWORD LandMinSpeedSteeringAngle = 0x04D8;
			DWORD LandMaxSpeedSteeringAngle = 0x04DC;
		}
		namespace FortPickup {
			DWORD PrimaryPickupItemEntry = 0x2A8;
		}

		namespace FortItemEntry {
			DWORD ItemDefinition = 0x18;
		}

		namespace FortItemDefinition {
			DWORD DisplayName = 0x80;
			DWORD Tier = 0x64;
		}

		namespace FortPlayerStateAthena {
			DWORD TeamIndex = 0xEB8;
		}

		namespace FortWeapon {
			DWORD LastFireTime = 0x8BC;
			DWORD LastFireTimeVerified = 0x8C0;
			DWORD WeaponData = 0x378;
			DWORD LastFireAbilityTime = 0xAB8;
		}

		namespace FortWeaponItemDefinition {
			DWORD WeaponStatHandle = 0x7E8;
		}

		namespace FortProjectileAthena {
			DWORD FireStartLoc = 0x878;
		}

		namespace FortBaseWeaponStats {
			//Reload
			DWORD ReloadTime = 0xFC;
			DWORD ReloadScale = 0x100;
			DWORD ChargeDownTime = 0x12C;
		}

		namespace FortRangedWeaponStats {
			//No Recoil
			DWORD RecoilHoriz = 0x200;
			DWORD RecoilVert = 0x1F0;
			DWORD RecoilDownsightsMultiplier = 0x21C;
			//No Spread
			DWORD Spread = 0x15C;
			DWORD SpreadDownsights = 0x160;
			DWORD StandingStillSpreadMultiplier = 0x164;
			DWORD AthenaJumpingFallingSpreadMultiplier = 0x16C;
			DWORD AthenaCrouchingSpreadMultiplier = 0x168;
			DWORD AthenaSprintingSpreadMultiplier = 0x170;
			DWORD MinSpeedForSpreadMultiplier = 0x174;
			DWORD MaxSpeedForSpreadMultiplier = 0x178;
		}

		namespace BuildingContainer {
			DWORD bAlreadySearched = 0xC41;
		}
	}

	namespace UI {
		namespace ItemCount {
			DWORD ItemDefinition = 0x18;
		}
	}

}

uintptr_t OldAimingActor = 0;

uint64_t OFFSET_UOBJECT = NULL;
uint64_t OFFSET_UWORLD = NULL;
uint64_t OFFSET_GETOBJECTNAMES = NULL;
uint64_t OFFSET_GETNAMEBYINDEX = NULL;
uint64_t OFFSET_FNFREE = NULL;

uint64_t entityx;

vector3d CamLoc;
vector3d rotation;
float player_fov = 80.f;

struct FBox
{
	vector3d  Min;
	vector3d  Max;
	unsigned char IsValid;
	unsigned char UnknownData00[0x3];
};

struct FMinimalViewInfo
{
	vector3d Loc;
	vector3d Rot;
	float FOV;
};

struct FMatrix
{
	float M[4][4];
};

template<typename T>
T c_read(DWORD_PTR address, const T& def = T())
{
	return *(T*)address;
}

vector3d CalcAim();
typedef uintptr_t(__fastcall* Cam)(uintptr_t, FMinimalViewInfo*);
Cam o_GetCameraInfo = NULL;
static auto Dummy_vTable = new uintptr_t[0x1001];

uint64_t base_address;

DWORD_PTR c_uWorld;
DWORD_PTR self_pawn;
DWORD_PTR LocalWeapon;
DWORD_PTR camera_manager;
DWORD_PTR local_player;
DWORD_PTR rootcomp;
DWORD_PTR target_aactor_mesh;
DWORD_PTR local_player_controller;
DWORD_PTR Ulevel;
DWORD_PTR Levels;
int LevelsCount;

static const void* game_rbx_jmp;
DWORD_PTR a_actors;
int actor_count;

int Actors[2] = { 0,0 };
int Bots[2] = { 0,0 };

float X;
float Y;

static FMatrix* myMatrix = new FMatrix();


D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut;
	pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
	pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
	pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
	pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
	pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
	pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
	pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
	pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
	pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
	pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
	pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
	pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
	pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
	pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
	pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
	pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

	return pOut;
}

D3DXMATRIX Matrix(vector3d rot, vector3d origin = vector3d(0, 0, 0))
{
	float radPitch = (rot.x * float(M_PI) / 180.f);
	float radYaw = (rot.y * float(M_PI) / 180.f);
	float radRoll = (rot.z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}
struct ccamera
{
	FTransform GetBoneIndex(DWORD_PTR mesh, int index)
	{
		DWORD_PTR bonearray = c_read<DWORD_PTR>(mesh + 0x478);

		return c_read<FTransform>(bonearray + (index * 0x30));
	}

	vector3d rotation(DWORD_PTR mesh, int id)
	{
		FTransform bone = GetBoneIndex(mesh, id);
		FTransform ComponentToWorld = c_read<FTransform>(mesh + 0x1C0);

		D3DMATRIX Matrix;
		Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());

		return vector3d(Matrix._41, Matrix._42, Matrix._43);
	}
	vector3d world_to_screen(vector3d WorldLocation, vector3d camrot)
	{
		vector3d Screenlocation = vector3d(0, 0, 0);
		vector3d Rotation = camrot;

		D3DMATRIX tempMatrix = Matrix(Rotation);

		vector3d vAxisX, vAxisY, vAxisZ;

		vAxisX = vector3d(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
		vAxisY = vector3d(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
		vAxisZ = vector3d(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

		vector3d vDelta = WorldLocation - CamLoc;
		vector3d vTransformed = vector3d(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

		float FovAngle = player_fov;
		float ScreenCenterX = X / 2.0f;
		float ScreenCenterY = Y / 2.0f;

		if (vTransformed.z < 1.f || tanf(FovAngle * (float)M_PI / 360.f) == 0.f) return vector3d(0, 0, 0);

		Screenlocation.x = ScreenCenterX + vTransformed.x * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;
		Screenlocation.y = ScreenCenterY - vTransformed.y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;

		return Screenlocation;
	}
};
ccamera* camera;


//Vector3 GetBoneLocByIdx(uintptr_t mesh, int id)
//{
//	if (!mesh) return { 0,0,0 };
//
//	auto fGetBoneMatrix = ((FMatrix * (__fastcall*)(uintptr_t, FMatrix*, int))(CData::GetBoneMatrix));
//	
//	spoof_call(game_rbx_jmp, fGetBoneMatrix, mesh, myMatrix, id);
//	
//	return Vector3(myMatrix->M[3][0], myMatrix->M[3][1], myMatrix->M[3][2]);
//}



vector3d ProjectWorldToScreen(vector3d WorldLocation, vector3d camrot)
{
	vector3d Screenlocation = vector3d(0, 0, 0);
	vector3d Rotation = camrot;

	D3DMATRIX tempMatrix = Matrix(Rotation);

	vector3d vAxisX, vAxisY, vAxisZ;

	vAxisX = vector3d(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	vAxisY = vector3d(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	vAxisZ = vector3d(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	vector3d vDelta = WorldLocation - CamLoc;
	vector3d vTransformed = vector3d(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	float FovAngle = player_fov;
	float ScreenCenterX = X / 2.0f;
	float ScreenCenterY = Y / 2.0f;

	if (vTransformed.z < 1.f || tanf(FovAngle * (float)M_PI / 360.f) == 0.f) return vector3d(0, 0, 0);

	Screenlocation.x = ScreenCenterX + vTransformed.x * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;
	Screenlocation.y = ScreenCenterY - vTransformed.y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;

	return Screenlocation;
}


INT(*GetViewPoint)(PVOID, FMinimalViewInfo*, BYTE) = nullptr;
INT GetViewPointHook(PVOID player, FMinimalViewInfo* viewInfo, BYTE stereoPass)
{
	auto ret = GetViewPoint(player, viewInfo, stereoPass);

	CamLoc = viewInfo->Loc;
	rotation = viewInfo->Rot;

	player_fov = viewInfo->FOV;
	return ret;
}
#include <algorithm>//std::search
void* SetHook_1(void* pSource, void* pDestination, int dwLen)
{
	DWORD MinLen = 14;

	if (dwLen < MinLen) return NULL;

	BYTE stub[] = {
	0xFF, 0x25, 0x00, 0x00, 0x00, 0x00, // jmp qword ptr [$+6]
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // ptr
	};

	static const void* pTrampoline = nullptr;
	if (!pTrampoline) {
		const auto ntdll = reinterpret_cast<const unsigned char*>(GetModuleHandleW((LPCWSTR)NULL));
		const auto dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(ntdll);
		const auto nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(ntdll + dos->e_lfanew);
		const auto sections = IMAGE_FIRST_SECTION(nt);
		const auto num_sections = nt->FileHeader.NumberOfSections;

		constexpr char section_name[5]{ '.', 't', 'e', 'x', 't' };
		const auto     section = std::find_if(sections, sections + num_sections, [&](const auto& s) {
			return std::equal(s.Name, s.Name + 5, section_name);
			});

		constexpr unsigned char instr_bytes[2]{ 0xFF, 0x25 };
		const auto              va = ntdll + section->VirtualAddress;
		pTrampoline = std::search(va, va + section->Misc.VirtualSize, instr_bytes, instr_bytes + 2);
	}

	DWORD64 retto = (DWORD64)pSource + dwLen;

	// trampoline
	memcpy(stub + 6, &retto, 8);
	memcpy((void*)((DWORD_PTR)pTrampoline), pSource, dwLen);
	memcpy((void*)((DWORD_PTR)pTrampoline + dwLen), stub, sizeof(stub));

	// orig
	memcpy(stub + 6, &pDestination, 8);
	memcpy(pSource, stub, sizeof(stub));

	for (int i = MinLen; i < dwLen; i++)
	{
		*(BYTE*)((DWORD_PTR)pSource + i) = 0x90;
	}

	return (void*)((DWORD_PTR)pTrampoline);
}

//Types::Vec3 BulletCorrection(Vector3 vec)
//{
//	Vector3 Corrected = Vector3(0, 0, 0);
//
//	if (CGame::IsProjectile)
//	{
//		Corrected = MyDummyMatrix._11 -= vec.x;
//		Corrected = MyDummyMatrix._12 -= vec.y;
//		Corrected = MyDummyMatrix._13 -= vec.z; //only for vec3
//	}
//
//	return (Types::Pointertoaddr*)Corrected;
//}

vector3d Normalize(vector3d vec)
{
	float a1 = vec.x;
	float a2 = vec.y;
	float a3 = vec.z;
	double length = vec.Length();

	if (length == 0.0) return { 0,0,0 };

	return vector3d(a1 / length, a2 / length, a3 / length);
}

int self_team_id = 0;
int actor_team_id = 1;

vector3d inline LimitRotation(vector3d startRotation, vector3d endRotation)
{
	vector3d ret;
	auto scale = AimSmooth;
	auto currentRotation = startRotation;

	ret.x = (endRotation.x - startRotation.x) / scale + startRotation.x;
	ret.y = (endRotation.y - startRotation.y) / scale + startRotation.y;

	return ret;
}

namespace definitions
{
	typedef uintptr_t pointer_address;
	typedef uint8_t NewCastedPointer;

	namespace playerstruct
	{
		struct mesh
		{
			typedef uintptr_t new_actor;
			typedef uintptr_t ActorObject;
			DWORD64 ActorMesh = 0x280;
		};
	}
}

#define IN_GAME 80


void FreeMemory(__int64 address)
{
	if (!address) return;

	auto func = reinterpret_cast<__int64(__fastcall*)(__int64 a1)>(CData::FreeFn);

	spoof_call(jmp_rbx_0, func, address);
}

struct cmmfe
{
	//float get_firerate(bool& developer_mode)
	//{
	//	if (developer_mode)
	//	{
	//		Classes::FWeapon* wep;
	//		FMinimalViewInfo* info;
	//		CHooks->GetHookedWeapon(&info, &wep);
	//		
	//		float AR_FOVTEST = info->FOV;
	//		float LocationTest = (info->Loc.x / 3.14) / 2;
	//		float LocationTest2 = (info->Loc.y / 3.14) / 2;

	//		if (wep->IsBurst((float)cfunc))
	//		{
	//			auto chain1 = wep->GetWeaponSwitch();
	//			auto chain2 = chain1->Abilities;
	//			
	//			float test = chain2->GetFireRate();

	//			if (setting->misc_button.lock_fire_rate_DEV)
	//			{
	//				while (!wep->IsReloading())
	//				{
	//					test = 0.03f; // 0.00f = instant kick, 0.01f = even worse meme, 0.02f = instant
	//				}
	//			}

	//			return test;
	//		}
	//	}
	//	else
	//	{
	//		return ExitProcess(-1);
	//	}
	//}
	 
	std::string get_object_name(uintptr_t Object) { //dano20zombie <3
		if (Object == NULL)
			return "";
		auto fGetObjName = reinterpret_cast<FString * (__fastcall*)(FString * name, uintptr_t entity)>(OFFSET_GETOBJECTNAMES);
		FString result;
		spoof_call(jmp_rbx_0, fGetObjName, &result, Object);
		if (result.c_str() == NULL)
			return "";

		auto result_str = result.ToString();
		if (result.c_str() != NULL)
			spoof_call(jmp_rbx_0, FreeMemory, (__int64)result.c_str());
		return result_str;
	}
};
cmmfe* player;




bool testw2s(vector3d vWorldPos, vector3d* vScreenPos)
{
	auto
		testw2s
		=
		reinterpret_cast<bool(__fastcall*)(uintptr_t pPlayerController,
			vector3d vWorldPos,
			vector3d * vScreenPosOut,
			char)>(ProjectWorldToScreen);

	return
		spoof_call(jmp_rbx_0, testw2s,
			(uintptr_t)local_player_controller,
			vWorldPos, vScreenPos,
			(char)0);
}

bool esp_loop(bool esp_toggle)
{
	for (int i = 0; i < actor_count; i++)
	{
		definitions::playerstruct::mesh::new_actor actor = c_read<uint64_t>(a_actors + i * 0x8);

		int self_id = *(int*)(actor + 0x18);

		if (actor != self_pawn && actor != local_player && actor != local_player_controller)
		{
			definitions::pointer_address self_state = c_read<uint64_t>(self_pawn + 0x240);

			definitions::pointer_address actor_state = c_read<uint64_t>(actor + 0x240);

			if (actor_state && self_state)
			{
				self_team_id = *(int*)(self_state + 0xEB8);
				actor_team_id = *(int*)(actor_state + 0xEB8);
			}

			//definitions::playerstruct::mesh::ActorObject ActorMesh = c_read<uint64_t>(actor + 0x280);

			//vector3d target_head = camera->rotation(ActorMesh, 66);

			//vector3d head_w2s = camera->world_to_screen(target_head, rotation);
			//vector3d head_box_w2s = camera->world_to_screen(vector3d(head_w2s.x, head_w2s.y, head_w2s.z + 15), rotation);


				uintptr_t root = c_read<uintptr_t>(actor + 0x130);
				vector3d loc = c_read<vector3d>(root + 0x11C);
				vector3d vScreenPos;
				testw2s(loc, &vScreenPos);
			

			

			/*vector3d w2s_pos = camera->world_to_screen(loc, rotation);
			render->drawtext(w2s_pos.x, w2s_pos.y, &colors.red, "Player");*/
		}
	}
	
	return true;
}


bool MainAddress() {

	uint64_t ImageBase = (uint64_t)GetModuleHandleA(0);

	AllocConsole();
	static_cast<VOID>(freopen("CONIN$", "r", stdin));
	static_cast<VOID>(freopen("CONOUT$", "w", stdout));
	static_cast<VOID>(freopen("CONOUT$", "w", stderr));
	
	c_uWorld = c_read<DWORD_PTR>(OFFSET_UWORLD);

	DWORD_PTR game_instance = c_read<DWORD_PTR>(c_uWorld + CData::Engine::World::OwningGameInstance);
	DWORD_PTR local_players = c_read<DWORD_PTR>(game_instance + CData::Engine::GameInstance::LocalPlayers);
	local_player = c_read<DWORD_PTR>(local_players);
	local_player_controller = c_read<DWORD_PTR>(local_player + CData::Engine::Player::PlayerController);
	self_pawn = c_read<uint64_t>(local_player_controller + CData::Engine::PlayerController::AcknowledgedPawn);
	camera_manager = c_read<uint64_t>(local_player_controller + CData::Engine::PlayerController::PlayerCameraManager);
	rootcomp = c_read<uint64_t>(self_pawn + CData::Engine::Actor::RootComponent);
	target_aactor_mesh = c_read<uint64_t>(self_pawn + CData::Engine::Character::Mesh);
	Levels = c_read<DWORD_PTR>(c_uWorld + CData::Engine::World::Levels);
	LevelsCount = c_read<DWORD_PTR>(c_uWorld + CData::Engine::World::Levels + 0x8);
	Ulevel = c_read<DWORD_PTR>(c_uWorld + CData::Engine::World::PersistentLevel);

	a_actors = c_read<DWORD_PTR>(Ulevel + 0x98);
	actor_count = *(int*)(Ulevel + 0xA0);

	return true;
}