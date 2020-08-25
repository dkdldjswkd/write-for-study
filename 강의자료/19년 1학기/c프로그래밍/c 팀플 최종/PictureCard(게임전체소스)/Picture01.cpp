// Picture01.cpp : 夔樂 擬辨 Щ煎斜極縑 渠и 霞殮薄擊 薑曖м棲棻.
// 蘋萄, っ, 蝶纔檜雖 薑爾

#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <fmod.h>
#include <time.h>
#define MAX_COUNT 26

typedef enum _GAME_STATE { INIT, READY, RUNNING, SUCCESS, FAILED, STOP, RESULT, END } GAME_STATE; // 內 啪歜曖 鼻鷓
GAME_STATE g_nGameState = INIT;

int g_nStage = 0;
int g_nRow = 0, g_nCol = 0;
int g_nCorrectCard = 0; //蜃轔 蘋萄 偃熱
int g_nTotalGrade = 0;

typedef enum _CARD_STATE { OPEN, CLOSE, MATCH } CARD_STATE;

int choi = 0;
int c1 = 0;

// Note: 蘋萄曖 薑爾
typedef struct _CARD_INFO
{
	CARD_STATE sCardState; // 蜓曖 鼻鷓	
	int  nUse; // っ擊 餌辨ж堅 氈朝陛 橈朝陛?
	char cMunja; // 轎溘 僥濠 
	int  x, y;
} CARD_INFO;

CARD_INFO g_sGameCard[30]; // 內 蘋萄朝 30濰?

// Note: 蘋萄縑 菟橫 陛朝 僥濠 等檜攪
typedef struct _CARD_DATA
{
	int  nUse;
	char Munja;
} CARD_DATA;

CARD_DATA g_sCardInfo[26]; //憲だ漯擎 26濠 

typedef struct _MATCH_CARD_DATA
{
	int nMatching;
	int nCount;
	int nIndex[2];
	clock_t OldTime;
} MATCH_CARD_DATA;

MATCH_CARD_DATA g_sMatchCardInfo;// 內 礎檜 蜃擎 蘋萄曖 薑爾

clock_t g_GameStartTime;         // 碟 蟾 塵葬撮鐘お 
clock_t g_StageLimitTime[3] = { 4*60*1000, 3*60*1000, 2*60*1000 };

// Note: 纔蝶お辨 3蝶纔檜雖 等檜顫 clock_t g_StageLimitTime[3] = { 10*1000, 10*1000, 10*1000 };

FMOD_SYSTEM *g_System;
FMOD_SOUND *g_EffectSound[6];
FMOD_SOUND *g_LoopSound[2]; // 顫檜ぎ婁 寡唳 擠學
FMOD_CHANNEL *g_LoopChannel[2];
FMOD_CHANNEL *g_TempChannel;
                                                                                                                                                                                                                                    
void gotoxy( int x, int y )
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), CursorPosition ); 
}

void MatchCard( int x, int y, char cMunja )
{
	gotoxy( x, y ); 	printf( "旨 收 旬");
	gotoxy( x, y + 1 );	printf( "早   早");
	gotoxy( x, y + 2 );	printf( "曲 收 旭");
	gotoxy( x+2, y + 1 ); printf( "%c", cMunja );
}

void CloseCard(int x, int y)
{
    gotoxy( x, y );		printf( "忙 式 忖");
	gotoxy( x, y + 1 ); printf( "弛 ﹥弛");
	gotoxy( x, y + 2 );	printf( "戌 式 戎");
}

void OpenCard( int x, int y, char cMunja )
{
	gotoxy( x, y ); 	printf( "忙 式 忖");
	gotoxy( x, y + 1 );	printf( "弛   弛");
	gotoxy( x, y + 2 );	printf( "戌 式 戎");
	gotoxy( x+2, y + 1 ); printf( "%c", cMunja );
}

void InitScreen()
{	
	printf("旨 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旬\n");
	printf("早                                                         早\n");
	printf("早          忙 式 忖忙 式 忖忙 式 忖忙 式 忖忙 式 忖                      早\n");
	printf("早          弛 ^^弛弛 G 弛弛 C 弛弛 A 弛弛 Ⅵ弛                      早\n");
	printf("早          戌 式 戎戌 式 戎戌 式 戎戌 式 戎戌 式 戎                      早\n");
	printf("早                                                         早\n");
	printf("早          忙 式 忖忙 式 忖忙 式 忖忙 式 忖忙 式 忖                      早\n");
	printf("早          弛 Ⅵ弛弛 C 弛弛 A 弛弛 ^^弛弛 G 弛                      早\n");
	printf("早          戌 式 戎戌 式 戎戌 式 戎戌 式 戎戌 式 戎                      早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                   礎 蜃蹺晦 啪歜                        早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                   ( 餌辨 酈 )                           早\n");
	printf("早                                                         早\n");
	printf("早                 U : 蘋萄 菴餵晦                         早\n");
	printf("早                 J : 謝   L : 辦                         早\n");
	printf("早                 I : 鼻   K :ж                          早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("曲 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旭\n");
}

void RunningScreen()
{
	gotoxy( 0, 0 );
	printf("旨 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旬\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("曲 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旭\n");
}

void GameOverScreen()
{
	gotoxy( 0, 0 );
	printf("旨 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旬\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥                    ﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥     Game Over      ﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥                    ﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("曲 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旭\n");
}

void StageScreen()
{	
	gotoxy( 0, 0 );
	printf("旨 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旬\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥                    ﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf( "早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥     %d   蝶纔檜雖   ﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n", g_nStage);
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥                    ﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("早 ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早\n");
	printf("曲 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旭\n");
}

void SuccessScreen()
{
	gotoxy( 0, 0 );
	printf("旨 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旬\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                    // / // ′′′                       早\n");
	printf("早                    弛/′    /′弛Ｏ                       早\n");
	printf("早                    弛＜  ∩  ＜弛∞                       早\n");
	printf("早                     ′_________///                      早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                       蝶纔檜雖                          早\n");
	printf("早                                                         早\n");
	printf("早                   嘐暮 撩奢 !!!!                        早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早     識薄 :                                              早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("曲 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旭\n");

	gotoxy( 22 , 11 );
	printf( "%d", g_nStage );
	gotoxy( 13 , 19 );
	printf( "%d", g_nTotalGrade );
}

void FailureScreen()
{
	gotoxy( 0, 0 );
	printf("旨 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旬\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                     灰 -收 收 -汐                           早\n");
	printf("早                     d 玫,.玫 b                          早\n");
	printf("早                     早 老 式 考 早                           早\n");
	printf("早                     汍 糸 弛 牝 污                           早\n");
	printf("早                       汎 死 汛                             早\n");
	printf("早                     %d   蝶纔檜雖                        早\n", g_nStage);
	printf("早                                                         早\n");
	printf("早                     嘐暮 褒ぬ !!!!                      早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("曲 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旭\n");
}

void ResultScreen()
{
	gotoxy( 0, 0 );	
	printf("旨 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旬\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早          (((    礎 蜃蹺晦 啪歜 Score    ))))            早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早         蝶纔檜雖 :                                      早\n");
	printf("早                                                         早\n");
	printf("早         識 薄熱  :                                      早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                          啗樓 ж衛啊蝗棲梱? (y/n)       早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("早                                                         早\n");
	printf("曲 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 收 旭\n");
}

void Sound_Init()
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init( g_System, 32, FMOD_INIT_NORMAL, NULL);

	FMOD_System_CreateSound(g_System, "fail.wav" ,FMOD_HARDWARE , 0, &g_EffectSound[0]);
	FMOD_System_CreateSound(g_System, "jong.wav" ,FMOD_HARDWARE , 0, &g_EffectSound[1]);
	FMOD_System_CreateSound(g_System, "ready.wav" ,FMOD_HARDWARE , 0, &g_EffectSound[2]);
	FMOD_System_CreateSound(g_System, "Ahhahaha.wav" ,FMOD_HARDWARE , 0, &g_EffectSound[3]);
	FMOD_System_CreateSound(g_System, "success.wav" ,FMOD_HARDWARE , 0, &g_EffectSound[4]);
	FMOD_System_CreateSound(g_System, "alarm2.wav" ,FMOD_HARDWARE , 0, &g_EffectSound[5]);

	FMOD_System_CreateSound(g_System, "bgsound.mp3" , FMOD_LOOP_NORMAL , 0, &g_LoopSound[0]);
	FMOD_System_CreateSound(g_System, "title.mp3" ,FMOD_LOOP_NORMAL , 0, &g_LoopSound[1]);
}
//餌遴萄

void Init()
{	

	int nGapY = 0;
	int PAN_MIN = 0;
    int PAN_MAX = 29, nCardIndex = 0, nPanIndex;
	int CARD_MIN = 0, CARD_MAX = 25;
	int i;

	if(  g_nStage == 0 ) // 1廓虜 蟾晦�降� 腎朝 睡碟縑 渠и 籀葬 餌о
	{
		Sound_Init();

		// Note: 蘋萄 蟾晦��
		for (int m = 0; m < 26; m++)
		{
			g_sCardInfo[m].Munja = rand() % MAX_COUNT + 65;
			g_sCardInfo[m].nUse = 0;

		}
		// Note: っ縑 場橾 蘋萄曖 嬪纂 蟾晦��
		for( i = 0 ; i < 30 ; i++ )
		{
			g_sGameCard[i].x = ( i % 6 ) * 8 + 3;
			g_sGameCard[i].y = ( i / 6 ) * 4 + 1;
		}

		g_nStage = 1;
	}


	g_sMatchCardInfo.nMatching = 0;
	g_sMatchCardInfo.nCount = 0;

	// Note: 蝶纔檜雖葆棻 蟾晦�飛� п 輿橫撿 и棻.
	for( i = 0; i < 30 ; i++ )
	{		
		g_sGameCard[i].sCardState = CLOSE;
	}
	
	// 憲だ漯 歜曖 檣策蝶 儅撩曖 衛濛
	srand( (unsigned)time( NULL ) );

	for( i = 0 ; i < 15 ; i++ )
	{				
		//Note: 蘋萄 檣策蝶蒂 極渾ж啪 瓊朝 唳辦		
		nCardIndex = (int)((double) rand() / (double) RAND_MAX) * CARD_MAX; // 0 睡攪 25梱雖 陪熱
				
		if( g_sCardInfo[nCardIndex].nUse == 1 )
		{
			// 籀擠睡攪 棻衛 瓊擠
			for( int n = 0 ; n < 26 ; n++ )
			{
				if( g_sCardInfo[n].nUse == 0 )
				{							
					nCardIndex = n;					
					break;
				}
			}
		}

		//Note: 蘋萄1擊 楠渾ж啪 瓊擠
		while( 1 )
		{
			if (c1 > 10000)break;
			nPanIndex = (int)(((double) rand() / (double) RAND_MAX) * PAN_MAX + PAN_MIN);
			if( g_sGameCard[nPanIndex].nUse == 0 )
			{
				g_sGameCard[nPanIndex].nUse = 1;		
				g_sGameCard[nPanIndex].cMunja = g_sCardInfo[nCardIndex].Munja;
				g_sCardInfo[nCardIndex].nUse = 1; 
			break;
			}
			if (choi == 1)c1++;
		}	

		//Note: 蘋萄2蒂 楠渾ж啪 瓊擠
		while( 1 )
		{
			if (c1 > 10000)break;
			nPanIndex = (int)(((double) rand() / (double) RAND_MAX) * PAN_MAX + PAN_MIN);
			if( g_sGameCard[nPanIndex].nUse == 0 )
			{
				g_sGameCard[nPanIndex].nUse = 1;		
				g_sGameCard[nPanIndex].cMunja = g_sCardInfo[nCardIndex].Munja;
				break;
			}
			if (choi == 1)c1++;
		}		
	}
}

// 2 蟾翕寰 matching 鼻鷓蒂 嶸雖и棻.
void Update()
{
	if( g_nGameState != RUNNING )
		return ;

	clock_t CurrentTime = clock();

	if( (CurrentTime - g_GameStartTime ) > g_StageLimitTime[g_nStage-1] || g_nCorrectCard == 15 )
	{
		g_nGameState = STOP;	
		return ;
	}

	if( g_sMatchCardInfo.nCount == 2 ) // 衙蘆菟橫 除棻.
	{
		if( CurrentTime - g_sMatchCardInfo.OldTime > 600 ) // 衙蘆 鼻鷓蒂 п薯и棻. 2蟾 檜鼻檜賊 衙蘆 鼻鷓蒂 п薯и棻.
		{
			g_sMatchCardInfo.nMatching = 0; // 衙蘆 鼻鷓蒂 п薯и棻.
			g_sMatchCardInfo.nCount = 0;
			// Note: 唸婁蒂 �挨匹挬�.
			if( g_sGameCard[ g_sMatchCardInfo.nIndex[0] ].cMunja == g_sGameCard[ g_sMatchCardInfo.nIndex[1] ].cMunja )
			{
				// 薄熱煎 陛骯ж堅 鼻鷓蒂 Openж貊 餌遴萄 轎溘 и棻.
				g_sGameCard[ g_sMatchCardInfo.nIndex[0] ].sCardState = OPEN;
				g_sGameCard[ g_sMatchCardInfo.nIndex[1] ].sCardState = OPEN;	
				g_nCorrectCard++; // 蜃轔 蘋萄 偃熱
				g_nTotalGrade += 10; // 識薄 

			}else{
				FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[3], 0, &g_TempChannel );
				g_sGameCard[ g_sMatchCardInfo.nIndex[0] ].sCardState = CLOSE;
				g_sGameCard[ g_sMatchCardInfo.nIndex[1] ].sCardState = CLOSE;					
			}					
		}
		else{
			g_sMatchCardInfo.nMatching = 1; // 衙蘆 鼻鷓 嶸雖		
		}
	}
}

void Render()
{
	int i, nKey;
	clock_t RemindTime; 

	system( "cls" );
	clock_t CurrentTime = clock();

	switch( g_nGameState )
	{
	case INIT :
		InitScreen();					
		FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_LoopSound[1], 0, &g_LoopChannel[1] );
		_getch();
		FMOD_Channel_Stop( g_LoopChannel[1] );
		g_nGameState = READY;	
		break;

	case READY :
		StageScreen();
		FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[2], 0, &g_TempChannel );
		Sleep( 2000 );

		system( "cls" );
		RunningScreen();
		for( i = 0 ; i < 30  ; i++ )
			OpenCard( g_sGameCard[i].x, g_sGameCard[i].y, g_sGameCard[i].cMunja );

		Sleep( 4000 );
		FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_TempChannel );
		g_nGameState = RUNNING;
		g_GameStartTime = clock();
		FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_LoopSound[1], 0, &g_LoopChannel[0] );
		break;

	case RUNNING :
		RunningScreen();

		for( i = 0 ; i < 30  ; i++ )
		{	
			switch( g_sGameCard[i].sCardState )
			{
			case OPEN :				
				OpenCard( g_sGameCard[i].x, g_sGameCard[i].y, g_sGameCard[i].cMunja );
				break;
			case CLOSE :
				CloseCard( g_sGameCard[i].x, g_sGameCard[i].y ); 												
				break;
			case MATCH :
				MatchCard( g_sGameCard[i].x, g_sGameCard[i].y, g_sGameCard[i].cMunja );
				break;
			}
		}			
		
		gotoxy( g_sGameCard[g_nRow * 6 + g_nCol].x+2, g_sGameCard[g_nRow * 6 + g_nCol].y + 3 );
		printf( "%s", "∟");	

		gotoxy( 55, 5 );
		RemindTime = g_StageLimitTime[g_nStage-1] - ( CurrentTime - g_GameStartTime);
		printf( "薯и 衛除: %d碟 %d蟾",  RemindTime / 60000, (RemindTime % 60000) / 1000 ); 
		gotoxy( 55, 7 );
		printf( "薄熱 : %d", g_nTotalGrade );
		break;

	case STOP :		
		if( g_nCorrectCard == 15 )
		{
			g_nGameState = SUCCESS;
		}		
		else
		{
			g_nGameState = FAILED;
			g_nTotalGrade -= g_nCorrectCard * 10;
		}	
		g_nCorrectCard = 0;
		FMOD_Channel_Stop( g_LoopChannel[0] );
		break;

	case SUCCESS:
		choi = 1;
		SuccessScreen();
		FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[4], 0, &g_TempChannel );
		Sleep( 4000 );
		// Note: 蝶纔檜雖曖 偃熱蒂 撮朝 睡碟檜棻. 
		if( (g_nStage+1) > (sizeof( g_StageLimitTime ) / sizeof(clock_t)))
			g_nStage = 1;									
		else
			g_nStage++;

		int data[30], q, sub_i;
		//srand(time(NULL));

		for (q = 0; q < 30; q++) {
			data[q] = rand() % 30;
			for (sub_i = 0; sub_i < q; sub_i++) {
				if (data[q] == data[sub_i]) {
					q--;
					break;
				}
			}
		}

		for (int m = 0; m < 30; m+=2)
		{
			g_sGameCard[data[m]].cMunja = rand() % MAX_COUNT + 65;
			g_sGameCard[data[m+1]].cMunja = g_sGameCard[data[m]].cMunja;
		}

		Init();
		g_nGameState = READY;	
		FMOD_Channel_Stop( g_TempChannel );
		break;

	case FAILED :		
		FailureScreen();
		FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[0], 0, &g_TempChannel );		
		Sleep( 2000 );
		FMOD_Channel_Stop( g_TempChannel );
		g_nGameState = RESULT;
		break;

	case RESULT: // result縑憮 棻衛 除棻朝 匙擎 褒ぬп憮 棻衛 衛紫ж朝 匙檜棻.
		ResultScreen();
		gotoxy( 22, 6 );
		printf( "%d", g_nStage );
		gotoxy( 22, 8 );
		printf( "%d", g_nTotalGrade );		
		gotoxy( 53, 18 ); 				
		
		while( 1 ) // y, Y, n, N 酈 諼縑朝 奩擬ж雖 跤ж紫煙 ж晦 嬪п憮 
		{
			nKey = _getch();
			if( nKey == 'y' || nKey == 'Y' )
			{							
				Init();		
				g_nGameState = READY;
				break;
			}

			if( nKey == 'n' || nKey =='N' )
			{	
				g_nGameState = END;
				break;
			}				
		}
		break;		
	}
}

void Release()
{
	int i;
	for( i = 0 ; i < 6 ; i++ )
		FMOD_Sound_Release( g_EffectSound[i] );
	for( i = 0 ; i < 2 ; i++ )
		FMOD_Sound_Release( g_LoopSound[i] );

	FMOD_System_Close( g_System );
	FMOD_System_Release( g_System );
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nKey, nIndex;
	static int nPushCardIndex = 0;
	clock_t OldTime, CurTime;

	CurTime = OldTime = clock();

	Init();

	while( 1 )
	{
		if( g_nGameState == END )
			break;

		if( _kbhit() )
		{
			nKey = _getch();
			if( nKey == 27 )
				break;		
			
			switch( nKey )
			{
			case 'j':
					if( g_nCol - 1 < 0 )
						g_nCol = 0;
					else
						g_nCol--;						
				break;
			case 'l':
					if( g_nCol + 1 > 5 )
						g_nCol = 5;
					else
						g_nCol++;
				break;
			case 'i':
					if( g_nRow - 1 < 0 )
						g_nRow = 0;
					else
						g_nRow--;
				break;
			case 'k':
					if( g_nRow + 1 > 4 )
						g_nRow = 4;
					else
						g_nRow++;
				break;
			case 'u': // 蘋萄 菴餵晦 (螃Ъ)
					if( g_sMatchCardInfo.nMatching == 0 )
					{							
						nIndex = g_nRow * 6 + g_nCol;					
						if( g_sGameCard[nIndex].sCardState != CLOSE ) 
							break;
						else
						{
							g_sGameCard[ nIndex ].sCardState = MATCH;
							g_sMatchCardInfo.nCount++;
							g_sMatchCardInfo.nIndex[g_sMatchCardInfo.nCount-1] = nIndex;
							if( g_sMatchCardInfo.nCount == 2 )
								g_sMatchCardInfo.OldTime = clock(); // Match 衛除擊 撲薑и棻.	

							FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[1], 0, &g_TempChannel );						
						}
					}
					break;
			}
		}

		Update();
		Render();

		FMOD_System_Update( g_System );
		
		while( 1 )
		{
			
			CurTime = clock();

			if( CurTime - OldTime > 33 )
			{
				OldTime = CurTime;
				break;
			}
		}				
	}

	Release();		
	GameOverScreen();
	return 0;
}

