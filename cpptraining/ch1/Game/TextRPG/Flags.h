#pragma once

typedef struct tag_CharacterInfo {
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHp;
	int iHpMax;
	int iMp;
	int iMpMax;
	int iLevel;
	int iExp;
}CHARACTERINFO, *PCHARACTERINFO;

// Object Type
enum OBJECT_TYPE {
	OT_PLAYER,
	OT_MONSTER
};