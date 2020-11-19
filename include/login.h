// login.h
// Originally from ES2
// Modified for XKX

#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT		300

#define WELCOME			"/adm/etc/welcome"
#define NEW_PLAYER_INFO		"/adm/etc/new_player"
#define UNREG_MOTD		"/adm/etc/unreg_motd"
#ifdef MOTD
#undef MOTD
#endif
#define MOTD			"/adm/etc/motd"

#define GAOSHOU			"/data/gaoshou"
#define RICHMAN			"/data/richman"

#define WIZLIST			"/adm/etc/wizlist"

#define START_ROOM "/d/city/kedian.c"
#define DEATH_ROOM "/d/death/gate.c"
#define REVIVE_ROOM "/d/city/wumiao.c"

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
#define MAX_USERS			150

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK			"/d/wiz/courthouse"

// This defines the minimum wiz_level of users that are allowed to
// enter the mud. Note players has wiz_level 0.
#define WIZ_LOCK_LEVEL 0

#endif
