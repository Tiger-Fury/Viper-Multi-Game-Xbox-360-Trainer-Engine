//Static addresses
static DWORD addr;
static DWORD addr1;
static DWORD addr_1HK;
static DWORD addr_ammo;
static DWORD addr_Gren;
static DWORD addr_Cash;
static DWORD addr_XP;
static DWORD addr_Silencer;
static DWORD addr_Special;
static DWORD addr_Skill;
static DWORD addr_Stamina;
static DWORD addr_Light;
static DWORD addr_Weapon;
static DWORD addr_Rage;
static DWORD addr_Items;
static DWORD addr_After;
static DWORD uv_addr;
static DWORD Gold_addr;
static DWORD Charge_addr;
static DWORD HVaddr;
static DWORD Recaddr;
static DWORD RoFaddr;
static BYTE Gamexex;
DWORD MYPtr1;
DWORD MYPtr2;
DWORD MYPtr3;
DWORD MYPtr4;
DWORD MYPtr5;
DWORD MYPtr6;

//Bools
DWORD staticcode = 0;
bool functstatic = false;
bool InfMoney = false;
bool InfTimer = false;
bool Dymbool = false;
bool ALLCheats = false;
bool AllCheats = false;
bool ALLCheats1 = false;
bool ALLCheats2 = false;
bool InfHealthZOM = false;
bool InfHealth = false;
bool OneHitKo = false;
bool InfAmmoZom = false;
bool InfAmmo = false;
bool InfSpecial = false;
bool InfStamina = false;
bool InfGrenade = false;
bool NOAmmo = false;
bool killstreaks = false;
bool HooksSet = false;
bool SetAddr = false;
bool Setstatics = false;
bool maxcashzm = false;
bool InfScore = false;
bool Max_Cash = false;
bool Max_XP = false;
bool InfLight = false;
bool InfRage = false;
bool InfItems = false;
bool InfGold = false;
bool MaxCash =false;
bool NoWeight = false;
bool StaticRoutine = false;
bool Unbreakable = false;

//Values
DWORD NOPThis = 0x60000000;
DWORD Max_IT = 0x3b9ac9ff;
DWORD Li_r11_Max = 0x39607530;
DWORD Li_r11_999 = 0x396003E7;
DWORD Li_r11_99 = 0x39600063;
DWORD Addi_r11_FFFF = 0x396bffff;
DWORD Addi_r11_nil = 0x396b0000;
DWORD Addi_r11_1 = 0x396b0001;
DWORD Null_It = 0x00000000;

bool AIAmmo = false;
bool InfBP = false;
bool TU = false;
bool CheatXX = FALSE;
bool CheatLB = FALSE;
bool CheatYY = FALSE;
bool CheatRB = FALSE;
bool CheatRT = FALSE;
bool CheatLT = FALSE;
bool CheatDU = FALSE;
bool CheatDL = FALSE;
bool CheatDR = FALSE;


bool CheckGame = FALSE;
bool CheckGame2 = FALSE;
bool GameReady = false;

BYTE gcheck[] = { 0x00 };
BYTE gcheck2[] = { 0x00 };

BYTE gchecktu[] = { 0x00 };
BYTE gchecktu2[] = { 0x00 };

BYTE nop[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnano[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnades[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopammo[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nophealth[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnv[] = { 0x60, 0x00, 0x00, 0x00 };

BYTE nano[] = { 0x7d, 0x6b, 0x52, 0x14 }; // 7D6B5214

BYTE XpMode[] = { 0x39, 0x60, 0x7f, 0xff }; // 39607FFF

BYTE ammo[] = { 0x91, 0x7f, 0x05, 0x84 }; // 917F0584

BYTE health[] = { 0x91, 0x5f, 0x00, 0x10 }; // 915F0010
BYTE healthact[] = { 0x39, 0x60, 0x27, 0x10 }; // on 39602710

BYTE nades[] = { 0x90, 0x88, 0x00, 0x64 }; // 90880064

BYTE nv[] = { 0xd1, 0xbf, 0x01, 0x60 };