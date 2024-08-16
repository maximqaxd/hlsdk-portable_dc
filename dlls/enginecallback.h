/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
#pragma once
#if !defined(ENGINECALLBACK_H)
#define ENGINECALLBACK_H

#include "event_flags.h"

// Fix warning in MSVC8
#undef SERVER_EXECUTE

// Must be provided by user of this code
extern enginefuncs_t g_engfuncs_h;

// The actual engine callbacks
#define GETPLAYERUSERID (*g_engfuncs_h.pfnGetPlayerUserId)
#define PRECACHE_MODEL	(*g_engfuncs_h.pfnPrecacheModel)
#define PRECACHE_SOUND	(*g_engfuncs_h.pfnPrecacheSound)
#define PRECACHE_GENERIC	(*g_engfuncs_h.pfnPrecacheGeneric)
#define SET_MODEL		(*g_engfuncs_h.pfnSetModel)
#define MODEL_INDEX		(*g_engfuncs_h.pfnModelIndex)
#define MODEL_FRAMES	(*g_engfuncs_h.pfnModelFrames)
#define SET_SIZE		(*g_engfuncs_h.pfnSetSize)
#define CHANGE_LEVEL	(*g_engfuncs_h.pfnChangeLevel)
#define GET_SPAWN_PARMS	(*g_engfuncs_h.pfnGetSpawnParms)
#define SAVE_SPAWN_PARMS (*g_engfuncs_h.pfnSaveSpawnParms)
#define VEC_TO_YAW		(*g_engfuncs_h.pfnVecToYaw)
#define VEC_TO_ANGLES	(*g_engfuncs_h.pfnVecToAngles)
#define MOVE_TO_ORIGIN  (*g_engfuncs_h.pfnMoveToOrigin)
#define oldCHANGE_YAW		(*g_engfuncs_h.pfnChangeYaw)
#define CHANGE_PITCH	(*g_engfuncs_h.pfnChangePitch)
#define MAKE_VECTORS	(*g_engfuncs_h.pfnMakeVectors)
#define CREATE_ENTITY	(*g_engfuncs_h.pfnCreateEntity)
#define REMOVE_ENTITY	(*g_engfuncs_h.pfnRemoveEntity)
#define CREATE_NAMED_ENTITY		(*g_engfuncs_h.pfnCreateNamedEntity)
#define MAKE_STATIC		(*g_engfuncs_h.pfnMakeStatic)
#define ENT_IS_ON_FLOOR	(*g_engfuncs_h.pfnEntIsOnFloor)
#define DROP_TO_FLOOR	(*g_engfuncs_h.pfnDropToFloor)
#define WALK_MOVE		(*g_engfuncs_h.pfnWalkMove)
#define SET_ORIGIN		(*g_engfuncs_h.pfnSetOrigin)
#define EMIT_SOUND_DYN2 (*g_engfuncs_h.pfnEmitSound)
#define BUILD_SOUND_MSG (*g_engfuncs_h.pfnBuildSoundMsg)
#define TRACE_LINE		(*g_engfuncs_h.pfnTraceLine)
#define TRACE_TOSS		(*g_engfuncs_h.pfnTraceToss)
#define TRACE_MONSTER_HULL		(*g_engfuncs_h.pfnTraceMonsterHull)
#define TRACE_HULL		(*g_engfuncs_h.pfnTraceHull)
#define GET_AIM_VECTOR	(*g_engfuncs_h.pfnGetAimVector)
#define SERVER_COMMAND	(*g_engfuncs_h.pfnServerCommand)
#define SERVER_EXECUTE	(*g_engfuncs_h.pfnServerExecute)
#define CLIENT_COMMAND	(*g_engfuncs_h.pfnClientCommand)
#define PARTICLE_EFFECT	(*g_engfuncs_h.pfnParticleEffect)
#define LIGHT_STYLE		(*g_engfuncs_h.pfnLightStyle)
#define DECAL_INDEX		(*g_engfuncs_h.pfnDecalIndex)
#define POINT_CONTENTS	(*g_engfuncs_h.pfnPointContents)
#define CRC32_INIT           (*g_engfuncs_h.pfnCRC32_Init)
#define CRC32_PROCESS_BUFFER (*g_engfuncs_h.pfnCRC32_ProcessBuffer)
#define CRC32_PROCESS_BYTE   (*g_engfuncs_h.pfnCRC32_ProcessByte)
#define CRC32_FINAL          (*g_engfuncs_h.pfnCRC32_Final)
#define RANDOM_LONG		(*g_engfuncs_h.pfnRandomLong)
#define RANDOM_FLOAT	(*g_engfuncs_h.pfnRandomFloat)
#define GETPLAYERAUTHID	(*g_engfuncs_h.pfnGetPlayerAuthId)

inline void MESSAGE_BEGIN( int msg_dest, int msg_type, const float *pOrigin = NULL, edict_t *ed = NULL )
{
	(*g_engfuncs_h.pfnMessageBegin)(msg_dest, msg_type, pOrigin, ed);
}
#define MESSAGE_END		(*g_engfuncs_h.pfnMessageEnd)
#define WRITE_BYTE		(*g_engfuncs_h.pfnWriteByte)
#define WRITE_CHAR		(*g_engfuncs_h.pfnWriteChar)
#define WRITE_SHORT		(*g_engfuncs_h.pfnWriteShort)
#define WRITE_LONG		(*g_engfuncs_h.pfnWriteLong)
#define WRITE_ANGLE		(*g_engfuncs_h.pfnWriteAngle)
#define WRITE_COORD		(*g_engfuncs_h.pfnWriteCoord)
#define WRITE_STRING	(*g_engfuncs_h.pfnWriteString)
#define WRITE_ENTITY	(*g_engfuncs_h.pfnWriteEntity)
#define CVAR_REGISTER	(*g_engfuncs_h.pfnCVarRegister)
#define CVAR_GET_FLOAT	(*g_engfuncs_h.pfnCVarGetFloat)
#define CVAR_GET_STRING	(*g_engfuncs_h.pfnCVarGetString)
#define CVAR_SET_FLOAT	(*g_engfuncs_h.pfnCVarSetFloat)
#define CVAR_SET_STRING	(*g_engfuncs_h.pfnCVarSetString)
#define CVAR_GET_POINTER (*g_engfuncs_h.pfnCVarGetPointer)
#define ALERT			(*g_engfuncs_h.pfnAlertMessage)
#define ENGINE_FPRINTF	(*g_engfuncs_h.pfnEngineFprintf)
#define ALLOC_PRIVATE	(*g_engfuncs_h.pfnPvAllocEntPrivateData)

inline void *GET_PRIVATE( edict_t *pent )
{
	if( pent )
		return pent->pvPrivateData;
	return NULL;
}

#define FREE_PRIVATE	(*g_engfuncs_h.pfnFreeEntPrivateData)
//#define STRING			(*g_engfuncs_h.pfnSzFromIndex)
#define ALLOC_STRING	(*g_engfuncs_h.pfnAllocString)
#define FIND_ENTITY_BY_STRING	(*g_engfuncs_h.pfnFindEntityByString)
#define GETENTITYILLUM	(*g_engfuncs_h.pfnGetEntityIllum)
#define FIND_ENTITY_IN_SPHERE		(*g_engfuncs_h.pfnFindEntityInSphere)
#define FIND_CLIENT_IN_PVS			(*g_engfuncs_h.pfnFindClientInPVS)
#define EMIT_AMBIENT_SOUND			(*g_engfuncs_h.pfnEmitAmbientSound)
#define GET_MODEL_PTR				(*g_engfuncs_h.pfnGetModelPtr)
#define REG_USER_MSG				(*g_engfuncs_h.pfnRegUserMsg)
#define GET_BONE_POSITION			(*g_engfuncs_h.pfnGetBonePosition)
#define FUNCTION_FROM_NAME			(*g_engfuncs_h.pfnFunctionFromName)
#define NAME_FOR_FUNCTION			(*g_engfuncs_h.pfnNameForFunction)
#define TRACE_TEXTURE				(*g_engfuncs_h.pfnTraceTexture)
#define CLIENT_PRINTF				(*g_engfuncs_h.pfnClientPrintf)
#define CMD_ARGS					(*g_engfuncs_h.pfnCmd_Args)
#define CMD_ARGC					(*g_engfuncs_h.pfnCmd_Argc)
#define CMD_ARGV					(*g_engfuncs_h.pfnCmd_Argv)
#define GET_ATTACHMENT			(*g_engfuncs_h.pfnGetAttachment)
#define SET_VIEW				(*g_engfuncs_h.pfnSetView)
#define SET_CROSSHAIRANGLE		(*g_engfuncs_h.pfnCrosshairAngle)
#define LOAD_FILE_FOR_ME		(*g_engfuncs_h.pfnLoadFileForMe)
#define FREE_FILE				(*g_engfuncs_h.pfnFreeFile)
#define COMPARE_FILE_TIME		(*g_engfuncs_h.pfnCompareFileTime)
#define GET_GAME_DIR			(*g_engfuncs_h.pfnGetGameDir)
#define IS_MAP_VALID			(*g_engfuncs_h.pfnIsMapValid)
#define NUMBER_OF_ENTITIES		(*g_engfuncs_h.pfnNumberOfEntities)
#define IS_DEDICATED_SERVER		(*g_engfuncs_h.pfnIsDedicatedServer)

#define PRECACHE_EVENT			(*g_engfuncs_h.pfnPrecacheEvent)
#define PLAYBACK_EVENT_FULL		(*g_engfuncs_h.pfnPlaybackEvent)

#define ENGINE_SET_PVS			(*g_engfuncs_h.pfnSetFatPVS)
#define ENGINE_SET_PAS			(*g_engfuncs_h.pfnSetFatPAS)

#define ENGINE_CHECK_VISIBILITY (*g_engfuncs_h.pfnCheckVisibility)

#define DELTA_SET				( *g_engfuncs_h.pfnDeltaSetField )
#define DELTA_UNSET				( *g_engfuncs_h.pfnDeltaUnsetField )
#define DELTA_ADDENCODER		( *g_engfuncs_h.pfnDeltaAddEncoder )
#define ENGINE_CURRENT_PLAYER   ( *g_engfuncs_h.pfnGetCurrentPlayer )

#define	ENGINE_CANSKIP			( *g_engfuncs_h.pfnCanSkipPlayer )

#define DELTA_FINDFIELD			( *g_engfuncs_h.pfnDeltaFindField )
#define DELTA_SETBYINDEX		( *g_engfuncs_h.pfnDeltaSetFieldByIndex )
#define DELTA_UNSETBYINDEX		( *g_engfuncs_h.pfnDeltaUnsetFieldByIndex )

#define ENGINE_GETPHYSINFO		( *g_engfuncs_h.pfnGetPhysicsInfoString )

#define ENGINE_SETGROUPMASK		( *g_engfuncs_h.pfnSetGroupMask )

#define ENGINE_INSTANCE_BASELINE ( *g_engfuncs_h.pfnCreateInstancedBaseline )

#define ENGINE_FORCE_UNMODIFIED	( *g_engfuncs_h.pfnForceUnmodified )

#define PLAYER_CNX_STATS		( *g_engfuncs_h.pfnGetPlayerStats )

#endif		//ENGINECALLBACK_H
