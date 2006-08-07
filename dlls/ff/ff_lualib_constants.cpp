
// ff_lualib_constants.cpp

//---------------------------------------------------------------------------
// includes
//---------------------------------------------------------------------------
// includes
#include "cbase.h"
#include "ff_lualib.h"
#include "ff_entity_system.h"
#include "ff_gamerules.h"
#include "ff_shareddefs.h"

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


//---------------------------------------------------------------------------
void CFFLuaLib::InitConstants(lua_State* L)
{
	ASSERT(L);

	module(L)
	[	
		class_<CFFEntity_AmmoTypes>("Ammo")
			.enum_("AmmoType")
			[
				value("kShells",			LUA_AMMO_SHELLS),
				value("kCells",				LUA_AMMO_CELLS),
				value("kNails",				LUA_AMMO_NAILS),
				value("kRockets",			LUA_AMMO_ROCKETS),
				value("kRadiotag",			LUA_AMMO_RADIOTAG),
				value("kDetpack",			LUA_AMMO_DETPACK),
				value("kGren1",				LUA_AMMO_GREN1),
				value("kGren2",				LUA_AMMO_GREN2),
				value("kInvalid",			LUA_AMMO_INVALID)
			],

		class_<CFFEntity_Effect_Flags>("EF")
			.enum_("EffectFlagId")
			[
				value("kOnfire",			LUA_EF_ONFIRE),
				value("kConc",				LUA_EF_CONC),
				value("kGas",				LUA_EF_GAS),
				value("kInfect",			LUA_EF_INFECT),
				value("kRadiotag",			LUA_EF_RADIOTAG),
				value("kHeadshot",			LUA_EF_HEADSHOT),
				value("kLegshot",			LUA_EF_LEGSHOT),
				value("kTranq",				LUA_EF_TRANQ),
				value("kCaltrop",			LUA_EF_CALTROP),
				value("kACSpinup",			LUA_EF_ACSPINUP),
				value("kSniperrifle",		LUA_EF_SNIPERRIFLE),
				value("kSpeedlua1",			LUA_EF_SPEED_LUA1),
				value("kSpeedlua2",			LUA_EF_SPEED_LUA2),
				value("kSpeedlua3",			LUA_EF_SPEED_LUA3),
				value("kSpeedlua4",			LUA_EF_SPEED_LUA4),
				value("kSpeedlua5",			LUA_EF_SPEED_LUA5),
				value("kSpeedlua6",			LUA_EF_SPEED_LUA6),
				value("kSpeedlua7",			LUA_EF_SPEED_LUA7),
				value("kSpeedlua8",			LUA_EF_SPEED_LUA8),
				value("kSpeedlua9",			LUA_EF_SPEED_LUA9),
				value("kSpeedlua10",		LUA_EF_SPEED_LUA10)
			],

		class_<CFFEntity_ApplyTo_Flags>("AT")
			.enum_("ApplyToFlagId")
			[
				value("kKillPlayers",		AT_KILL_PLAYERS),
				value("kRespawnPlayers",	AT_RESPAWN_PLAYERS),
				value("kDropItems",			AT_DROP_ITEMS),
				value("kForceDropItems",	AT_FORCE_DROP_ITEMS),
				value("kThrowItems",		AT_THROW_ITEMS),
				value("kForceThrowItems",	AT_FORCE_THROW_ITEMS),
				value("kReturnCarriedItems",	AT_RETURN_CARRIED_ITEMS),
				value("kReturnDroppedItems",	AT_RETURN_DROPPED_ITEMS),
				value("kRemoveRagdolls",	AT_REMOVE_RAGDOLLS),
				value("kRemovePacks",		AT_REMOVE_PACKS),
				value("kRemoveProjectiles",	AT_REMOVE_PROJECTILES),
				value("kRemoveBuildables",	AT_REMOVE_BUILDABLES),
				value("kRemoveDecals",		AT_REMOVE_DECALS),
				value("kEndMap",			AT_END_MAP),

				value("kChangeClassScout",	AT_CHANGECLASS_SCOUT),
				value("kChangeClassSniper",	AT_CHANGECLASS_SNIPER),
				value("kChangeClassSoldier",	AT_CHANGECLASS_SOLDIER),
				value("kChangeClassDemoman",	AT_CHANGECLASS_DEMOMAN),
				value("kChangeClassMedic",	AT_CHANGECLASS_MEDIC),
				value("kChangeClassHWGuy",	AT_CHANGECLASS_HWGUY),
				value("kChangeClassPyro",	AT_CHANGECLASS_PYRO),
				value("kChangeClassSpy",	AT_CHANGECLASS_SPY),
				value("kChangeClassEngineer",	AT_CHANGECLASS_ENGINEER),
				value("kChangeClassCivilian",	AT_CHANGECLASS_CIVILIAN),
				value("kChangeClassRandom",	AT_CHANGECLASS_RANDOM),

				value("kStopPrimedGrens",	AT_STOP_PRIMED_GRENS)
			],

		class_<CFFEntity_HudItemTypes>("Hud")
			.enum_("HudItemTypes")
			[
				value("kIcon",				LUA_HUD_ITEM_ICON),
				value("kText",				LUA_HUD_ITEM_TEXT),
				value("kTimer",				LUA_HUD_ITEM_TIMER),
				value("kRemove",			LUA_HUD_ITEM_REMOVE)
			]
	];
};