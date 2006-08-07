
// ff_lualib_base.cpp

//---------------------------------------------------------------------------
// includes
//---------------------------------------------------------------------------
// includes
#include "cbase.h"
#include "ff_lualib.h"
#include "ff_item_flag.h"
#include "ff_team.h"

#include "triggers.h"

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
// TODO: evaluate these functions off lua's BaseEntity types
namespace FFLib
{
	bool IsDispenser(CBaseEntity* pEntity);
	bool IsGrenade(CBaseEntity* pEntity);
	bool IsSentrygun(CBaseEntity* pEntity);
	bool IsDetpack(CBaseEntity* pEntity);
}

//---------------------------------------------------------------------------
void CFFLuaLib::InitBase(lua_State* L)
{
	ASSERT(L);

	module(L)
	[
		// CBaseEntity
		class_<CBaseEntity>("BaseEntity")
			.def("EmitSound",			&CBaseEntity::PlaySound)
			.def("GetClassName",		&CBaseEntity::GetClassname)
			.def("GetName",				&CBaseEntity::GetName)
			.def("GetTeam",				&CBaseEntity::GetTeam)
			.def("GetTeamId",			&CBaseEntity::GetTeamNumber)
			.def("GetId",				&CBaseEntity::entindex)
			.def("GetVelocity",			&CBaseEntity::GetAbsVelocity)
			.def("IsDispenser",			&FFLib::IsDispenser)
			.def("IsGrenade",			&FFLib::IsGrenade)
			.def("IsPlayer",			&CBaseEntity::IsPlayer)
			.def("IsSentryGun",			&FFLib::IsSentrygun)
			.def("IsDetpack",			&FFLib::IsDetpack)
			.def("SetModel",			(void(CBaseEntity::*)(const char*))&CBaseEntity::SetModel)
			.def("SetModel",			(void(CBaseEntity::*)(const char*, int))&CBaseEntity::SetModel)
			.def("SetSkin",				&CBaseEntity::SetSkin)
			.def("GetOrigin",			&CBaseEntity::GetAbsOrigin)
			.def("SetOrigin",			&CBaseEntity::SetAbsOrigin)
			.def("GetAngles",			&CBaseEntity::GetAbsAngles)
			.def("SetAngles",			&CBaseEntity::SetAbsAngles)
			.def("IsOnFire",			&CBaseEntity::IsOnFire)
			.def("GetGravity",			&CBaseEntity::GetGravity)
			.def("SetGravity",			&CBaseEntity::SetGravity)
			.def("SetRenderColor",		(void(CBaseEntity::*)(byte,byte,byte))&CBaseEntity::SetRenderColor)
			.def("SetRenderMode",		&CBaseEntity::SetRenderMode)
			.def("GetFriction",			&CBaseEntity::GetFriction)
			.def("SetFriction",			&CBaseEntity::GetFriction),

		// CFFInfoScript
		class_<CFFInfoScript, CBaseEntity>("InfoScript")
			.def("Drop",				&CFFInfoScript::Drop)
			.def("Pickup",				&CFFInfoScript::Pickup)
			.def("Respawn",				&CFFInfoScript::Respawn)
			.def("Return",				&CFFInfoScript::Return)
			.def("IsCarried",			&CFFInfoScript::IsCarried)
			.def("IsReturned",			&CFFInfoScript::IsReturned)
			.def("IsDropped",			&CFFInfoScript::IsDropped)
			.def("IsActive",			&CFFInfoScript::IsActive)
			.def("IsInactive",			&CFFInfoScript::IsInactive)
			.def("IsRemoved",			&CFFInfoScript::IsRemoved)
			.def("Remove",				&CFFInfoScript::LUA_Remove)
			.def("EntName",				&CFFInfoScript::EntName)
			.def("Restore",				&CFFInfoScript::LUA_Restore)
			.def("SetBotGoalInfo",		&CFFInfoScript::SetBotGoalInfo),

		// CFuncFFScript - trigger_ff_script
		class_<CFuncFFScript>("TriggerScript")
			.def("IsActive",			&CFuncFFScript::IsActive)
			.def("IsInactive",			&CFuncFFScript::IsInactive)
			.def("IsRemoved",			&CFuncFFScript::IsRemoved)
			.def("Remove",				&CFuncFFScript::LuaRemove)
			.def("Restore",				&CFuncFFScript::LuaRestore)
			.def("IsTouching",			&CFuncFFScript::IsTouching)
			.def("SetBotGoalInfo",		&CFuncFFScript::SetBotGoalInfo)
	];
};