//*******************************************************************Variables*********************************************************************//
struct keyState
{
	bool bPressed;
	bool bReleased;
	bool bHeld;
} m_keys[256];
struct levelObjects
{
	int x;
	int y;
	int levelX;
	int levelY;
	int width;
	int height;
	string type;
	bool show;
	int linkedObject;
}objects[300];
struct staticCoin
{
	int x;
	int y;
	int levelX;
	int levelY;
	int width;
	int height;
	bool show;
}coins[20];
struct powerObjects{
	int x;
	int y;
	int levelX;
	int levelY;
	int width;
	int height;
	int maxHeight;
	int velocityX;
	bool show;
	string objectType;
}npc[13];
struct fire
{
	int x;
	int y;
	int levelX;
	int levelY;
	int maxHeight;
	int velocityX;
	int velocityY;
	bool status;
	fire()
	{

	}
	fire(int _x,int _y,int _levelX,int _levelY,bool _status,int max,int velX,int velY)
	{
		x = _x;
		y = _y;
		levelX = _levelX;
		levelY = _levelY;
		status = _status;
		maxHeight = max;
		velocityX = velX;
		velocityY = velY;
	}
}fireObjects[1000];
struct bossFire{
	int x;
	int y;
}bossFireObjects[200];
struct enemy
{
	int x;
	int y;
	int levelX;
	int levelY;
	int width;
	int height;
	int velocityX;
	bool alive;
}enemyObjects[18];
struct rotatingFire{
	int fireX;
	int fireY;
	int originX;
	int originY;
	int radius;
}fires[100];

struct highscore{
	int score;
}highscores[5];

bool jumpUp = false;
bool jump = false;
int jumpLimit = 300;
bool pos = false;
int objectCount = 78;
int marioHeight = 63;
int marioWidth = 48;
bool marioMove = false;
int marioIndex = 0;
short m_keyOldState[256] = { 0 };
short m_keyNewState[256] = { 0 };
int levelX = 0;
int levelY = 0;
int loadFlag = 1;
int marioTrueX = 200;
int marioX = 200;
int marioY = 128; //default 128
int screenWidth = 1024;// default 1024
int screenHeight = 960;
int jumpDistance = 0;
int enemyCount = 17;
int gameState = 1;
int npcCount = 13;
int marioPowerState = 0;
int checkInputTimer;
int changeTimer;
int enemyCollisionTimer;
int fourmsTimer;
int clockTimer;
int animationTimer;
int fireCheckTimer;
bool fired = false;
int fireCount = 0;
bool encounter[11] = { false, false, false, false, false, false, false, false, false, false,false};
int point = 0;
int clockTime = 150;
int cursorX = 320;
int cursorY = 380;
int cursorPosition = 1;
bool ahead = true;
int currentLevel = 1;
irrklang::ISoundEngine* engine;
int storedMarioY;
bool deathHeightReached = false;
string animationState = "";
bool levelEnd_ground = false;
bool levelEndFlag = false;
bool levelboundreached = false;
int capturedTime;
int relativeTime = 0;
int marioLife = 3;
float degree = 0;
int bossX = 8420;
int bossY = 320;
bool bossForward = false;
bool bossUp = true;
bool xFlag = false;
bool bossFired = false;
int bossFireIndex = 0;
int ladderForward = false;
bool axeShow = true;
bool bossReached = false;
bool bossDead = false;
bool showThanks = false;
bool pauseState = false;






unsigned int  levelTexture;
unsigned int  level2Texture;
unsigned int  brickTexture;
unsigned int  powerTexture;
unsigned int  doneTexture;
unsigned int  brickTexture2;
unsigned int  powerTexture2;
unsigned int  doneTexture2;
unsigned int  ladderTexture;
unsigned int  ladder2Texture;
unsigned int  level3Texture;
unsigned int  level4Texture;
unsigned int  bridgeTexture;

char Mario[31][40] = { "Characters\\Mario\\A1.bmp", "Characters\\Mario\\A2.bmp", "Characters\\Mario\\A3.bmp", "Characters\\Mario\\A4.bmp", "Characters\\Mario\\A5.bmp", "Characters\\Mario\\A6.bmp", "Characters\\Big Mario\\A15.bmp", "Characters\\Big Mario\\A16.bmp", "Characters\\Big Mario\\A17.bmp", "Characters\\Big Mario\\A18.bmp", "Characters\\Big Mario\\A19.bmp", "Characters\\Fire Mario\\1.bmp", "Characters\\Fire Mario\\2.bmp", "Characters\\Fire Mario\\3.bmp", "Characters\\Fire Mario\\4.bmp", "Characters\\Fire Mario\\5.bmp", "Characters\\Inverse Mario\\A1.bmp", "Characters\\Inverse Mario\\A2.bmp", "Characters\\Inverse Mario\\A3.bmp", "Characters\\Inverse Mario\\A4.bmp", "Characters\\Inverse Mario\\A5.bmp", "Characters\\Inverse Big Mario\\A15.bmp", "Characters\\Inverse Big Mario\\A16.bmp", "Characters\\Inverse Big Mario\\A17.bmp", "Characters\\Inverse Big Mario\\A18.bmp", "Characters\\Inverse Big Mario\\A19.bmp","Characters\\Inverse Fire Mario\\1.bmp", "Characters\\Inverse Fire Mario\\2.bmp", "Characters\\Inverse Fire Mario\\3.bmp", "Characters\\Inverse Fire Mario\\4.bmp", "Characters\\Inverse Fire Mario\\5.bmp"};
char goomba[3][35] = { "Characters\\Goomba\\g1.bmp", "Characters\\Goomba\\g2.bmp", "Characters\\Goomba\\g3.bmp" };
char mainMenu[1][40] = { " " };
char mushroom[1][40] = { "Objects\\Mushroom\\mushroom.bmp" };
char coin[1][40] = { "Objects\\Coin\\coin.bmp" };
char fire[1][40] = { "Objects\\Fire\\fire.bmp" };
char static_coin[1][40] = { "Objects\\Coin\\static_coin.bmp" };
char number[10][40] = { "Font\\Numbers\\0.bmp", "Font\\Numbers\\1.bmp", "Font\\Numbers\\2.bmp", "Font\\Numbers\\3.bmp", "Font\\Numbers\\4.bmp", "Font\\Numbers\\5.bmp", "Font\\Numbers\\6.bmp", "Font\\Numbers\\7.bmp", "Font\\Numbers\\8.bmp", "Font\\Numbers\\9.bmp", };
char boss[1][40] = { "Objects\\Boss\\boss.bmp" };
char bossFireTex[1][40] = { "Objects\\Boss\\bossFire.bmp" };
char axe[1][40] = { "Objects\\Boss\\axe.bmp" };
char dot[1][40] = { "Font\\UI\\dot.bmp" };






