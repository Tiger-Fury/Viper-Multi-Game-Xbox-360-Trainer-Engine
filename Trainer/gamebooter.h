#include "GameInclude.h"
#include "StaticRoutine.h"


void Boot_584109B7(void);//0 Day attack on earth
void Boot_584108DB(void);//a kingdom of
void Boot_584109DB(void);//a world of
void Boot_58410886(void);//ace of the galaxy
void Boot_44500807(void);//adventure time etdbidk

void Boot_4E4D07D8(void);//Afro Samurai
void Boot_58410A06(void);//afterburner climax
void Boot_413307D9(void);//air conflicts vietnam
void Boot_58411233(void);//alan wake an
void Boot_58410A22(void);//alien breed assault
void Boot_58410AA3(void);//alien breed descent
void Boot_58410964(void);//alien breed evo
void Boot_5345080C(void);//Alien CM 
void Boot_58410B22(void);//Alien rage
void Boot_58411204(void);//All zombies must die
void Boot_494707D1(void);//Alone in the dark
void Boot_58410807(void);//arkadian warrior
void Boot_584107FE(void);//assault heroes
void Boot_454109E0(void);//battlefield hardline
void Boot_464507DD(void);//Bound by Flame
void Boot_41560855(void);//Cod BLops
void Boot_415608C3(void);//Cod BLops2
void Boot_58410957(void);//Cod Classic
void Boot_415608FC(void);//Cod Ghosts
void Boot_415607E6(void);//Cod MW 
void Boot_415608CB(void);//Cod MW3
void Boot_4156081C(void);//Cod WAW
void Boot_534307D3(void);//conflict denied ops
void Boot_45410968(void);//crysis
void Boot_445407DE(void);//cursed crusade
void Boot_4B4D07F2(void);//dead island riptide
void Boot_435907D5(void);//Enemy Front
void Boot_4B4E07E5(void);//Silent Hill HC
void Boot_555308b7(void);//Watch Dogs
void Boot_425307F5(void);//Wolfenstein TNO



typedef struct
{
	DWORD id;
	void (*init)(void);
}GAME_INIT;

const GAME_INIT Game_Init[] =
{
	0x584109B7, Boot_584109B7,//0 day
	0x584108DB, Boot_584108DB,//A kingdom of
	0x584109DB, Boot_584109DB,//A world of
	0x58410886, Boot_58410886,//Aces of the galaxy
	0x44500807, Boot_44500807,//Adventure time etdbidk

 	0x4E4D07D8, Boot_4E4D07D8,//Afro Samurai
	0x58410A06, Boot_58410A06,//afterburner climax
	0x413307D9, Boot_413307D9,//air conflicts Vietnam
	0x58411233, Boot_58411233,//alan wake an
	0x58410A22, Boot_58410A22,//alien breed assault
	0x58410AA3, Boot_58410AA3,//alien breed descent
	0x58410964, Boot_58410964,//alien breed evo
	0x5345080C, Boot_5345080C,//Alien CM
	0x58410B22, Boot_58410B22,//Alien rage
	0x58411204, Boot_58411204,//All Zombie must die
	0x494707D1, Boot_494707D1,//Alone in the dark
	0x58410807, Boot_58410807,//arkadian warrior
	0x584107FE, Boot_584107FE,//assault heroes
	0x584108C3, Boot_584108C3,//assault heroes 2
	0x454109E0, Boot_454109E0,//battlefield Hardline
 	0x464507DD, Boot_464507DD,//Bound by Flame
 	0x41560855, Boot_41560855,//Cod BLops
	0x415608C3, Boot_415608C3,//Cod BLops2
 	0x58410957, Boot_58410957,//Cod Classic
 	0x415608FC, Boot_415608FC,//Cod Ghosts
 	0x415607E6, Boot_415607E6,//Cod MW
 	0x415608CB, Boot_415608CB,//Cod MW3
 	0x4156081C, Boot_4156081C,//Cod waw
	0x534307D3, Boot_534307D3,//Conflict Denied denied ops
	0x45410968, Boot_45410968,//crysis
	0x445407DE, Boot_445407DE,//cursed crusade
	0x4B4D07F2, Boot_4B4D07F2,//Dead Island riptide
 	0x435907D5, Boot_435907D5,//Enemy Front
	0x4B4E07E5, Boot_4B4E07E5,//Silent Hill HC
	0x555308b7, Boot_555308b7,//Watch Dogs
	0x425307F5, Boot_425307F5,//Wolfenstein TNO
};