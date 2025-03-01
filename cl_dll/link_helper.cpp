#include "hud.h"
#include "cl_util.h"
#include "netadr.h"
#include "parsemsg.h"

extern "C"
{
#include "pm_shared.h"
}

#include <string.h>

extern "C"
{

int DLLEXPORT Initialize( cl_enginefunc_t *pEnginefuncs, int iVersion );
int DLLEXPORT HUD_VidInit( void );
void DLLEXPORT HUD_Init( void );
int DLLEXPORT HUD_Redraw( float flTime, int intermission );
int DLLEXPORT HUD_UpdateClientData( client_data_t *cdata, float flTime );
void DLLEXPORT HUD_Reset ( void );
void DLLEXPORT HUD_PlayerMove( struct playermove_s *ppmove, int server );
void DLLEXPORT HUD_PlayerMoveInit( struct playermove_s *ppmove );
char DLLEXPORT HUD_PlayerMoveTexture( char *name );
int DLLEXPORT HUD_ConnectionlessPacket( const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size );
int DLLEXPORT HUD_GetHullBounds( int hullnumber, float *mins, float *maxs );
void DLLEXPORT HUD_Frame( double time );
void DLLEXPORT HUD_VoiceStatus(int entindex, qboolean bTalking);
void DLLEXPORT HUD_DirectorMessage( int iSize, void *pbuf );
void DLLEXPORT HUD_MobilityInterface( mobile_engfuncs_t *gpMobileEngfuncs );
void DLLEXPORT HUD_Shutdown( void );
void DLLEXPORT HUD_PostRunCmd( struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed );
int DLLEXPORT HUD_Key_Event( int down, int keynum, const char *pszCurrentBinding );
int DLLEXPORT HUD_AddEntity( int type, struct cl_entity_s *ent, const char *modelname );
void DLLEXPORT HUD_CreateEntities( void );
void DLLEXPORT HUD_StudioEvent( const struct mstudioevent_s *event, const struct cl_entity_s *entity );
void DLLEXPORT HUD_TxferLocalOverrides( struct entity_state_s *state, const struct clientdata_s *client );
void DLLEXPORT HUD_ProcessPlayerState( struct entity_state_s *dst, const struct entity_state_s *src );
void DLLEXPORT HUD_TxferPredictionData ( struct entity_state_s *ps, const struct entity_state_s *pps, struct clientdata_s *pcd, const struct clientdata_s *ppcd, struct weapon_data_s *wd, const struct weapon_data_s *pwd );
void DLLEXPORT HUD_TempEntUpdate( double frametime, double client_time, double cl_gravity, struct tempent_s **ppTempEntFree, struct tempent_s **ppTempEntActive, int ( *Callback_AddVisibleEntity )( struct cl_entity_s *pEntity ), void ( *Callback_TempEntPlaySound )( struct tempent_s *pTemp, float damp ) );
int DLLEXPORT HUD_GetStudioModelInterface( int version, struct r_studio_interface_s **ppinterface, struct engine_studio_api_s *pstudio );
void DLLEXPORT HUD_DrawNormalTriangles( void );
void DLLEXPORT HUD_DrawTransparentTriangles( void );
cl_entity_t DLLEXPORT *HUD_GetUserEntity( int index );
void DLLEXPORT Demo_ReadBuffer( int size, unsigned char *buffer );
void DLLEXPORT CL_CreateMove( float frametime, struct usercmd_s *cmd, int active );
struct kbutton_s DLLEXPORT *KB_Find( const char *name );
void DLLEXPORT CAM_Think( void );
int DLLEXPORT CL_IsThirdPerson( void );
void DLLEXPORT CL_CameraOffset( float *ofs );
void DLLEXPORT IN_ClientMoveEvent( float forwardmove, float sidemove );
void DLLEXPORT IN_ClientLookEvent( float relyaw, float relpitch );
void DLLEXPORT IN__MouseEvent( int mstate );
void DLLEXPORT IN_ClearStates( void );
void DLLEXPORT IN__ActivateMouse( void );
void DLLEXPORT IN__DeactivateMouse( void );
void DLLEXPORT IN_Accumulate( void );
void DLLEXPORT V_CalcRefdef( struct ref_params_s *pparams );
int		iJumpSpectator;



struct {const char *name;void *func;} lib_cl_dll_exports[] =
{
	//{ "PM_Init", &PM_Init} ,
	//{ "PM_FindTextureType", &PM_FindTextureType },
	//{ "PM_Move", &PM_Move },
	{ "Initialize", &Initialize },
	{ "HUD_VidInit", &HUD_VidInit },
	{ "HUD_Init", &HUD_Init },
	{ "HUD_Shutdown", &HUD_Shutdown },
	{ "HUD_Redraw", &HUD_Redraw },
	{ "HUD_UpdateClientData", &HUD_UpdateClientData },
	{ "HUD_Reset", &HUD_Reset },
	{ "HUD_PlayerMove", &HUD_PlayerMove },
	{ "HUD_PlayerMoveInit", &HUD_PlayerMoveInit },
	{ "HUD_PlayerMoveTexture", &HUD_PlayerMoveTexture },
	{ "HUD_ConnectionlessPacket", &HUD_ConnectionlessPacket },
	{ "HUD_GetHullBounds", &HUD_GetHullBounds },
	{ "HUD_Frame", &HUD_Frame },
	{ "HUD_PostRunCmd", &HUD_PostRunCmd },
	{ "HUD_Key_Event", &HUD_Key_Event },
	{ "HUD_AddEntity", &HUD_AddEntity },
	{ "HUD_CreateEntities", &HUD_CreateEntities },
	{ "HUD_StudioEvent", &HUD_StudioEvent },
	{ "HUD_TxferLocalOverrides", &HUD_TxferLocalOverrides },
	{ "HUD_ProcessPlayerState", &HUD_ProcessPlayerState },
	{ "HUD_TxferPredictionData", &HUD_TxferPredictionData },
	{ "HUD_TempEntUpdate", &HUD_TempEntUpdate },
	{ "HUD_DrawNormalTriangles", &HUD_DrawNormalTriangles },
	{ "HUD_DrawTransparentTriangles", &HUD_DrawTransparentTriangles },
	{ "HUD_GetUserEntity", &HUD_GetUserEntity },
	{ "Demo_ReadBuffer", &Demo_ReadBuffer },
	{ "CAM_Think", &CAM_Think },
	{ "CL_IsThirdPerson", &CL_IsThirdPerson },
	{ "CL_CameraOffset", &CL_CameraOffset },
	{ "CL_CreateMove", &CL_CreateMove },
	{ "IN__ActivateMouse", &IN__ActivateMouse },
	{ "IN__DeactivateMouse", &IN__DeactivateMouse },
	{ "IN__MouseEvent", &IN__MouseEvent },
	{ "IN_Accumulate", &IN_Accumulate },
	{ "IN_ClearStates", &IN_ClearStates },
	{ "V_CalcRefdef", &V_CalcRefdef },
	{ "KB_Find", &KB_Find },
	{ "HUD_GetStudioModelInterface", &HUD_GetStudioModelInterface },
	{ "HUD_DirectorMessage", &HUD_DirectorMessage },
	{ "HUD_VoiceStatus", &HUD_VoiceStatus },
	{ "IN_ClientMoveEvent", &IN_ClientMoveEvent}, // Xash3D ext
	{ "IN_ClientLookEvent", &IN_ClientLookEvent}, // Xash3D ext
	{ "iJumpSpectator", &iJumpSpectator },
	{ 0, 0 },
};

}