TARGET = libcl_dll.a
DEFINES = -D_KOS_ -D_SH4_ -DCLIENT_DLL -Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -D_snprintf=snprintf  -DNO_VOICEGAMEMGR 
INCLUDES = -I. -I../common -I../engine -I../pm_shared -I../game_shared -I../public -I../external -I../dlls -I../utils/fake_vgui/include
KOS_CFLAGS = -nostartfiles -Ofast -Wl,-q -Wfatal-errors -Wno-write-strings -fsigned-char -fno-short-enums -fno-lto 
KOS_CPPFLAGS =  $(INCLUDES) $(DEFINES) $(KOS_CFLAGS) -fno-exceptions -fpermissive
OBJS = ev_hldm.o \
	hl/hl_events.o \
	hl/hl_objects.o \
	hl/hl_weapons.o \
	ammo.o \
	ammo_secondary.o \
	ammohistory.o \
	battery.o \
	cdll_int.o \
	com_weapons.o \
	death.o \
	demo.o \
	entity.o \
	ev_common.o \
	events.o \
	flashlight.o \
	GameStudioModelRenderer.o \
	geiger.o \
	health.o \
	hud.o \
	hud_msg.o \
	hud_redraw.o \
	hud_spectator.o \
	hud_update.o \
	in_camera.o \
	input.o \
	input_goldsource.o \
	input_mouse.o \
	input_xash3d.o \
	interpolation.o \
	menu.o \
	message.o \
	parsemsg.o \
	saytext.o \
	status_icons.o \
	statusbar.o \
	studio_util.o \
	StudioModelRenderer.o \
	text_message.o \
	train.o \
	tri.o \
	util.o \
	view.o \
	scoreboard.o \
	MOTD.o \
	../game_shared/vcs_info.o \
	link_helper.o 
	
include ${KOS_PORTS}/scripts/lib.mk