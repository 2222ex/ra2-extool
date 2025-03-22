#pragma once

#include <Helpers/CompileTime.h>

#ifndef GAMEMD_STRING
#define GAMEMD_STRING(name,addr)\
static constexpr constant_ptr<const char,addr> const name;

namespace GameStrings
{
	// unsorted names
	GAMEMD_STRING(YURI_S_REVENGE, 0x849F48u);
	GAMEMD_STRING(BLOWFISH_DLL  , 0x840A78u);
	GAMEMD_STRING(XXICON_SHP    , 0x8204FCu);
	GAMEMD_STRING(LSSOBS_SHP    , 0x8297F4u);
	GAMEMD_STRING(_800          , 0x8297DCu);
	GAMEMD_STRING(_640          , 0x8297E0u);
	GAMEMD_STRING(_none_        , 0x817474u);
	GAMEMD_STRING(none          , 0x817694u);

	// ini file names
	GAMEMD_STRING(UIMD_INI    , 0x827DC8u);
	GAMEMD_STRING(THEMEMD_INI , 0x825D94u);
	GAMEMD_STRING(EVAMD_INI   , 0x825DF0u);
	GAMEMD_STRING(SOUNDMD_INI , 0x825E50u);
	GAMEMD_STRING(BATTLEMD_INI, 0x826198u);
	GAMEMD_STRING(AIMD_INI    , 0x82621Cu);
	GAMEMD_STRING(ARTMD_INI   , 0x826254u);
	GAMEMD_STRING(RULESMD_INI , 0x826260u);
	GAMEMD_STRING(RA2MD_INI   , 0x826444u);
	GAMEMD_STRING(MAPSELMD_INI, 0x830370u);

	// ini section names
	GAMEMD_STRING(General     , 0x826278u);
	GAMEMD_STRING(Basic       , 0x82BF9Cu);
	GAMEMD_STRING(AudioVisual , 0x839EA8u);
	GAMEMD_STRING(CombatDamage, 0x839E8Cu);
	GAMEMD_STRING(Radiation   , 0x839E80u);
	GAMEMD_STRING(ToolTips    , 0x833188u);
	GAMEMD_STRING(CrateRules  , 0x839E9Cu);
	GAMEMD_STRING(JumpjetControls,0x839D58u);
	GAMEMD_STRING(Waypoints   , 0x82DB0Cu);
	GAMEMD_STRING(VariableNames, 0x83D824u);

	GAMEMD_STRING(MCVRedeploys, 0x83CF68);

	// EVA entry names
	GAMEMD_STRING(EVA_StructureSold      , 0x819030u);
	GAMEMD_STRING(EVA_UnitSold           , 0x822630u);
	GAMEMD_STRING(EVA_OreMinerUnderAttack, 0x824784u);

	// CSF Labels
	GAMEMD_STRING(TXT_TO_REPLAY        , 0x83DB24);
	GAMEMD_STRING(TXT_OK               , 0x825FB0);
	GAMEMD_STRING(TXT_CANCEL           , 0x825FD0);
	GAMEMD_STRING(TXT_CONTROL          , 0x82729C);
	GAMEMD_STRING(TXT_INTERFACE        , 0x826FEC);
	GAMEMD_STRING(TXT_SELECTION        , 0x827250);
	GAMEMD_STRING(TXT_TAUNT            , 0x827218);
	GAMEMD_STRING(TXT_TEAM             , 0x826FA4);
	GAMEMD_STRING(TXT_SAVING_GAME      , 0x820DD4);
	GAMEMD_STRING(TXT_GAME_WAS_SAVED   , 0x829FE0);
	GAMEMD_STRING(TXT_ERROR_SAVING_GAME, 0x829EBC);
	GAMEMD_STRING(GUI_DEBUG            , 0x827AF8);

	// ....
}

#undef GAMEMD_STRING
#endif
