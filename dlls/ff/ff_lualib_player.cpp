
// ff_lualib_player.cpp

//---------------------------------------------------------------------------
// includes
//---------------------------------------------------------------------------
// includes
#include "cbase.h"
#include "ff_lualib.h"
#include "ff_player.h"

// Lua includes
extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include "luabind/luabind.hpp"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//---------------------------------------------------------------------------
using namespace luabind;

//---------------------------------------------------------------------------
void CFFLuaLib::InitPlayer(lua_State* L)
{
	ASSERT(L);

	module(L)
	[
		// CBasePlayer
		class_<CBasePlayer, CBaseEntity>("BasePlayer"),

		// CFFPlayer
		class_<CFFPlayer, CBasePlayer>("Player")
			.def("AddAmmo",				&CFFPlayer::LuaAddAmmo)
			.def("AddArmor",			&CFFPlayer::AddArmor)
			.def("AddFrags",			&CFFPlayer::IncrementFragCount)
			.def("AddHealth",			&CFFPlayer::AddHealth)
			.def("GetClass",			&CFFPlayer::GetClassSlot)
			.def("GetName",				&CFFPlayer::GetPlayerName)
			.def("HasItem",				&CFFPlayer::HasItem)
			.def("IsFeetDeepInWater",	&CFFPlayer::IsFeetDeepInWater)
			.def("IsInNoBuild",			&CFFPlayer::IsInNoBuild)
			.def("IsUnderWater",		&CFFPlayer::IsUnderWater)
			.def("IsWaistDeepInWater",	&CFFPlayer::IsWaistDeepInWater)
			.def("IsInAttack1",			&CFFPlayer::IsInAttack1)
			.def("IsInAttack2",			&CFFPlayer::IsInAttack2)
			.def("IsInUse",				&CFFPlayer::IsInUse)
			.def("IsInJump",			&CFFPlayer::IsInJump)
			.def("IsInForward",			&CFFPlayer::IsInForward)
			.def("IsInBack",			&CFFPlayer::IsInBack)
			.def("IsInMoveLeft",		&CFFPlayer::IsInMoveLeft)
			.def("IsInMoveRight",		&CFFPlayer::IsInMoveRight)
			.def("IsInLeft",			&CFFPlayer::IsInLeft)
			.def("IsInRight",			&CFFPlayer::IsInRight)
			.def("IsInRun",				&CFFPlayer::IsInRun)
			.def("IsInReload",			&CFFPlayer::IsInReload)
			.def("IsInSpeed",			&CFFPlayer::IsInSpeed)
			.def("IsInWalk",			&CFFPlayer::IsInWalk)
			.def("IsInZoom",			&CFFPlayer::IsInZoom)
			.def("IsOnGround",			&CFFPlayer::IsOnGround)
			.def("IsInAir",				&CFFPlayer::IsInAir)
			.def("IsDucking",			&CFFPlayer::IsDucking)
			.def("MarkRadioTag",		&CFFPlayer::SetRadioTagged)
			//.def("RemoveAmmo",			(void(CFFPlayer::*)(int, const char*))&CFFPlayer::RemoveAmmo)
			.def("RemoveAmmo",			&CFFPlayer::LuaRemoveAmmo)
			.def("RemoveArmor",			&CFFPlayer::RemoveArmor)
			.def("RemoveLocation",		&CFFPlayer::RemoveLocation)
			.def("Respawn",				&CFFPlayer::KillAndRemoveItems)
			.def("SetDisguisable",		&CFFPlayer::SetDisguisable)
			.def("SetLocation",			&CFFPlayer::SetLocation)
			.def("SetRespawnDelay",		&CFFPlayer::LUA_SetPlayerRespawnDelay)
			//.def("InstaSwitch",			&CFFPlayer::InstaSwitch) -- doing this as part of ApplyToPlayer()
			.def("GetActiveWeaponName",	&CFFPlayer::GetActiveWeaponName)
			.def("GiveWeapon",			&CFFPlayer::GiveNamedItem)
			.def("RemoveWeapon",		&CFFPlayer::TakeNamedItem)
			.def("RemoveAllWeapons",	&CFFPlayer::RemoveAllItems)
			.def("IsFeigned",			&CFFPlayer::IsFeigned)
			.def("IsDisguised",			&CFFPlayer::IsDisguised)
			.def("GetDisguisedClass",	&CFFPlayer::GetDisguisedClass)
			.def("GetDisguisedTeam",	&CFFPlayer::GetDisguisedTeam)
			.def("AddEffect",			&CFFPlayer::LuaAddEffect)
			.def("IsEffectActive",		&CFFPlayer::LuaIsEffectActive)
			.def("RemoveEffect",		&CFFPlayer::LuaRemoveEffect)
			.def("GetSteamID",			&CFFPlayer::GetSteamID)
			.def("GetPing",				&CFFPlayer::GetPing)
			.def("GetPacketloss",		&CFFPlayer::GetPacketloss)
			.enum_("ClassId")
			[
				value("kScout",			CLASS_SCOUT),
				value("kSniper",		CLASS_SNIPER),
				value("kSoldier",		CLASS_SOLDIER),
				value("kDemoman",		CLASS_DEMOMAN),
				value("kMedic",			CLASS_MEDIC),
				value("kHwguy",			CLASS_HWGUY),
				value("kPyro",			CLASS_PYRO),
				value("kSpy",			CLASS_SPY),
				value("kEngineer",		CLASS_ENGINEER),
				value("kCivilian",		CLASS_CIVILIAN)
			]
	];
}