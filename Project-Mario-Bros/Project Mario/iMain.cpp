#define PICT 3.141592654
#include<iostream>
#include <cstdlib>
#include <string>
#include <fstream> 
#include <irrKlang.h>
#pragma comment(lib,"irrKlang.lib")
using namespace std;
#include "iGraphics.h"
#include "WinUser.h"
#include "FunctionDeclarations.h"
#include "Variables.h"
#include "Animation.h"
#include "LevelLoad.h"
#include "Input.h"
#include "Collision.h"
#include "SetFunctions.h"
#include "Fire.h"
#include "Music.h"
//*******************************************************************iDraw***********************************************************************//
void iDraw()
{
	iClear();
	if (gameState == 1)
	{
		iShowBMP(0, 0, "Levels\\Main Menu\\Main-menu.bmp");
		pointDraw();
		clockDraw();
		iShowBMP2(cursorX, cursorY, "Font\\UI\\cursor.bmp", 255);
	}
	else if (gameState == 2)
	{
		iShowBMP(0, 0, "Levels\\Main Menu\\help.bmp");
	}
	else if (gameState == 3)
	{
		iShowBMP(0, 0, "Levels\\Main Menu\\credits.bmp");
	}
	else if (gameState == 4)
	{
		if (currentLevel == 1)
		{
			iShowImage(levelX, levelY, 13504, 960, levelTexture);
		}
		else if (currentLevel == 2)
		{
			iShowImage(levelX, levelY, 11328, 960, level2Texture);
			for (int i = 0; i < 17; i++)
			{
				if (coins[i].show == true)
				{
					iShowBMP2(coins[i].x, coins[i].y, static_coin[0], 0);
				}
			}
		}
		else if (currentLevel == 3)
		{
			iShowImage(levelX, levelY, 2240, 960, level3Texture);
		}
		else if (currentLevel == 4)
		{
			iShowImage(levelX, levelY, 10240, 960, level4Texture);
			iShowBMP2(bossX + levelX, bossY, boss[0], 0);
			if (axeShow)
			{
				iShowBMP2(9024 + levelX, 384, axe[0], 0);
			}
			for (int i = 0; i < 42; i++)
			{
				iShowBMP2(fires[i].fireX + levelX, fires[i].fireY, fire[0], 0);
			}
			for (int i = 0; i < bossFireIndex; i++)
			{
				iShowBMP2(bossFireObjects[i].x + levelX, bossFireObjects[i].y, bossFireTex[0], 0);
			}
			if (showThanks)
			{
				iShowBMP2(172, 360, "Objects\\Thanks\\Thanks.bmp", 0);
			}
		}
		iShowBMP2(marioX, marioY, Mario[marioIndex], 0);
		for (int i = 0; i < enemyCount; i++)
		{
			if (enemyObjects[i].alive == true)
			{
				iShowBMP2(enemyObjects[i].x, enemyObjects[i].y, goomba[0], 255);
			}
		}
		for (int i = 0; i < npcCount; i++)
		{
			if (npc[i].show == true)
			{
				//cout <<"Showing NPC = "<< i << endl;
				if (npc[i].objectType == "mushroom")
				{
					iShowBMP2(npc[i].x, npc[i].y, mushroom[0], 0);
				}
				else if (npc[i].objectType == "coin")
				{
					iShowBMP2(npc[i].x, npc[i].y, coin[0], 0);
				}
				
			}
		}
		for (int i = 0; i < objectCount; i++)
		{
			if (objects[i].show == true)
			{
				if (currentLevel == 1)
				{
					if (objects[i].type == "brick")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, brickTexture);
					}
					else if (objects[i].type == "power")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, powerTexture);
					}
					else if (objects[i].type == "done")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, doneTexture);
					}
				}
				else if (currentLevel == 2)
				{
					if (objects[i].type == "brick")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, brickTexture2);
					}
					else if (objects[i].type == "power")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, powerTexture2);
					}
					else if (objects[i].type == "done")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, doneTexture2);
					}
					else if (objects[i].type == "ladder")
					{
						iShowImage(objects[i].x, objects[i].y, 192, 32, ladderTexture);
					}
				}
				else if (currentLevel == 4)
				{
					if (objects[i].type == "ladder2")
					{
						iShowImage(objects[i].x, objects[i].y, 128, 32, ladder2Texture);
					}
					if (objects[i].type == "bridge")
					{
						iShowImage(objects[i].x, objects[i].y, 208, 64, bridgeTexture);
					}
				}
			}
		}
		for (int i = 0; i < fireCount; i++)
		{
			if (fireObjects[i].status == true)
			{
				iShowBMP2(fireObjects[i].x, fireObjects[i].y, fire[0], 0);
			}
		}
		pointDraw();
		clockDraw();
		UIDraw();
	}
	else if (gameState == 5)
	{
		iShowBMP(0, 0, "Levels\\Game Over\\gameover.bmp");
	}
	else if (gameState == 6)
	{
		iShowBMP(0, 0, "Levels\\Main Menu\\highscore.bmp");
		showHighscore();
	}
}
//******************************************************************Useless **************************************************************************//
void iMouseMove(int mx, int my)
{

}
void iPassiveMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{

}
void iKeyboard(unsigned char key)
{
	if (gameState == 4 && animationState == "" && key == 'p')
	{
		if (pauseState)
		{
			iResumeTimer(checkInputTimer);
			iResumeTimer(fourmsTimer);
			iResumeTimer(changeTimer);
			iResumeTimer(clockTimer);
			pauseState = false;
		}
		else
		{
			iPauseTimer(checkInputTimer);
			iPauseTimer(fourmsTimer);
			iPauseTimer(changeTimer);
			iPauseTimer(clockTimer);
			pauseState = true;
		}
	}
}
void iSpecialKeyboard(unsigned char key)
{

}

//*******************************************************************My Functions***********************************************************************//d

void levelScroll()
{
	for (int i = 0; i < enemyCount; i++)
	{
		enemyObjects[i].x--;
	}
	for (int i = 0; i < npcCount; i++)
	{
		npc[i].x--;
	}
	for (int i = 0; i < objectCount;i++)
	{
		objects[i].x--;
	}
	for (int i = 0; i < fireCount; i++)
	{
		fireObjects[i].x--;
	}
	for (int i = 0; i < 17; i++)
	{
		coins[i].x--;
	}
}
void loadTexture()
{
	levelTexture = iLoadImage("Levels\\World 1-1\\Background.png");
	level2Texture = iLoadImage("Levels\\World 1-2\\Level 2.png");
	level3Texture = iLoadImage("Levels\\World 1-2\\Level 2_2.png");
	level4Texture = iLoadImage("Levels\\World 1-4\\Level 4.png");
	brickTexture = iLoadImage("Objects\\Brick\\brick.bmp");
	powerTexture = iLoadImage("Objects\\Brick\\power.bmp");
	doneTexture = iLoadImage("Objects\\Brick\\done.bmp");
	brickTexture2 = iLoadImage("Objects\\Brick\\brick2.bmp");
	powerTexture2 = iLoadImage("Objects\\Brick\\power2.bmp");
	doneTexture2 = iLoadImage("Objects\\Brick\\done2.bmp");
	ladderTexture = iLoadImage("Objects\\Ladder\\ladder.bmp");
	ladder2Texture = iLoadImage("Objects\\Ladder\\ladder2.bmp");
	bridgeTexture = iLoadImage("Objects\\Boss\\bridge.bmp");
}

bool ground()
{
	int i;
	for(i=0;i<objectCount;i++)
	{
		if (objects[i].show == true)
		{
			if (aabbCollisionMario(i, marioTrueX, marioY - 1))
			{
				return true;
			}
		}
	}
	return false;
	
}
void setInput()
{
	short *m_keyNewState = new short[256];
	short *m_keyOldState = new short[256];
	keyState *m_keys = new keyState[256];
}
void gravity()
{
	if (jump)
	{
		if (jumpDistance + 12 <= jumpLimit && jumpUp)
		{
			jumpDistance += 12;
			if (!marioCollision(0, 12))
			{
				objectCollsionCheck(12);
				jumpUp = false;
			}
		}
		else
		{
			jumpDistance = 0;
			jumpUp = false;
			marioCollision(0, -12);
			if (ground())
			{
				jump = false;
			}
		}
	}
	else
	{
		marioCollision(0, -10);
	}
	if (currentLevel == 2)
	{
		for (int i = 288; i <= 289; i++)
		{
			if (!((objects[i].levelX > marioTrueX + marioWidth) || (objects[i].levelX + objects[i].width < marioTrueX) || (objects[i].levelY > marioY + marioHeight) || (objects[i].levelY + objects[i].height < marioY - 1)))
			{
				marioY -= 4;
			}
			if (((objects[i].levelX > marioTrueX + marioWidth) || (objects[i].levelX + objects[i].width < marioTrueX) || (objects[i].levelY - 4  > marioY + marioHeight) || (objects[i].levelY + objects[i].height - 4 < marioY)))
			{
				objects[i].y -= 4;
				objects[i].levelY -= 4;
			}
			if (objects[i].y < -100)
			{
				objects[i].y = 1060;
				objects[i].levelY = 1060;
			}
		}
		for (int i = 290; i <= 291; i++)
		{
			objects[i].y += 4;
			objects[i].levelY += 4;
			if (!((objects[i].levelX > marioTrueX + marioWidth) || (objects[i].levelX + objects[i].width < marioTrueX) || (objects[i].levelY > marioY + marioHeight) || (objects[i].levelY + objects[i].height < marioY - 1)))
			{
				marioY += 4;
			}
			if (objects[i].y > 1060)
			{
				objects[i].y = -100;
				objects[i].levelY = -100;
			}
		}
	}
	if (currentLevel == 4)
	{
		if (ladderForward)
		{
			if (((objects[39].levelX + 4 > marioTrueX + marioWidth) || (objects[39].levelX + 4 + objects[39].width < marioTrueX) || (objects[39].levelY > marioY + marioHeight) || (objects[39].levelY + objects[39].height < marioY)))
			{
				objects[39].x += 4;
				objects[39].levelX += 4;
				if (!((objects[39].levelX > marioTrueX + marioWidth) || (objects[39].levelX + objects[39].width < marioTrueX) || (objects[39].levelY > marioY + marioHeight) || (objects[39].levelY + objects[39].height < marioY - 1)))
				{
					marioX += 4;
					marioTrueX += 4;
				}
			}
			if (objects[39].levelX >= 8832)
			{
				ladderForward = false;
			}
		}
		else
		{
			if (((objects[39].levelX - 4 > marioTrueX + marioWidth) || (objects[39].levelX - 4 + objects[39].width < marioTrueX) || (objects[39].levelY > marioY + marioHeight) || (objects[39].levelY + objects[39].height < marioY)))
			{
				objects[39].x -= 4;
				objects[39].levelX -= 4;
				if (!((objects[39].levelX > marioTrueX + marioWidth) || (objects[39].levelX + objects[39].width < marioTrueX) || (objects[39].levelY > marioY + marioHeight) || (objects[39].levelY + objects[39].height < marioY - 1)))
				{
					marioX -= 4;
					marioTrueX -= 4;
				}
			}
			if (objects[39].levelX <= 8516)
			{
				ladderForward = true;
			}
		}
	}
}
void pipeDetect()
{
	if (currentLevel == 2)
	{
		if (aabbCollisionMario(138, marioTrueX, marioY - 1) && aabbCollisionMario(283, marioTrueX + 1, marioY))
		{
			elevateMario();
		}
	}
}
void fourms(){
	npcCollision();
	fireCollision();
	gravity();
	enemyCollision();
	coinCollision();
	pipeDetect();
	rotatingFireCollision();
	bossLogic();
	axeDetect();
}
void axeDetect()
{
	if (currentLevel == 4)
	{
		if (!((9024 > marioTrueX + marioWidth) || (9024 + 64 < marioTrueX) || (384 > marioY + marioHeight) || (384 + 64 < marioY)))
		{
			axeShow = false;
			finalEnd();
		}
	}
}
void bossLogic()
{
	if (currentLevel == 4)
	{
		if (xFlag)
		{
			if (bossForward)
			{
				bossX -= 1;
				if (bossX < 8420)
				{
					bossForward = false;
				}
			}
			else
			{
				bossX += 1;
				if (bossX > 8895)
				{
					bossForward = true;
				}
			}
		}
		if (bossUp)
		{
			bossY += 1;
			if (bossY > 448)
			{
				bossUp = false;
			}
		}
		else
		{
			bossY -= 1;
			if (bossY <= 320)
			{
				bossUp = true;
			}
		}
		xFlag = !xFlag;
		if (!bossFired)
		{
			if (!((bossY > marioY + marioHeight) || (bossY + 32 < marioY)))
			{
				if (marioTrueX > 6500 && (bossFired == false))
				{
					bossFireObjects[bossFireIndex].x = bossX - 96;
					bossFireObjects[bossFireIndex].y = bossY + 32;
					engine->play2D("Music/smb_bowserfire.wav");
					bossFireIndex++;
					bossFired = true;
				}
			}
		}
		for (int i = 0; i < bossFireIndex; i++)
		{
			bossFireObjects[i].x -= 3;
			if (!((bossFireObjects[i].x > marioTrueX + marioWidth) || (bossFireObjects[i].x + 96 < marioTrueX) || (bossFireObjects[i].y > marioY + marioHeight) || (bossFireObjects[i].y + 32 < marioY)))
			{
				death();
			}
		}
		if (!((bossX > marioTrueX + marioWidth) || (bossX + 128 < marioTrueX) || (bossY > marioY + marioHeight) || (bossY + 128 < marioY)))
		{
			death();
		}
	}
	
}
void pointAdd(int x)
{
	point += x;
}
void pointDraw()
{
	int temp = point;
	int temp2;
	int x = 256;
	int y = 832;
	int i;
	for (i = 0; temp != 0; i++)
	{
		temp2 = temp % 10;
		iShowBMP2(x, y, number[temp2], 0);
		x -= 32;
		temp = temp / 10;
	}
	for (int j = 6 - i; j != 0; j--)
	{
		iShowBMP2(x, y, number[0], 0);
		x -= 32;
	}
}
void clockDraw()
{
	int temp = clockTime;
	int temp2;
	int x = 892;
	int y = 832;
	int i;
	for (i = 0; temp != 0; i++)
	{
		temp2 = temp % 10;
		iShowBMP2(x, y, number[temp2], 0);
		x -= 32;
		temp = temp / 10;
	}
	for (int j = 3 - i; j != 0; j--)
	{
		iShowBMP2(x, y, number[0], 0);
		x -= 32;
	}
}
void UIDraw()
{
	iShowBMP2(93, 868, "Font\\UI\\mario.bmp", 0);
	iShowBMP2(801, 868, "Font\\UI\\time.bmp", 0);
}
void gameClock()
{
	clockTime -= 1;
	if (clockTime == 0)
	{
		death();
	}
}
void restart()
{
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	marioHeight = 63;
	marioWidth = 48;
	marioMove = false;
	marioIndex = 0;
	levelX = 0;
	levelY = 0;
	marioTrueX = 200;
	marioX = 200;
	marioY = 128; 
	jumpDistance = 0;
	marioPowerState = 0;
	fired = false;
	fireCount = 0;
	clockTime = 150;
	if (currentLevel == 1)
	{
		objectCount = 78;
		enemyCount = 17;
		npcCount = 13;
		for (int i = 0; i < 10; i++)
		{
			encounter[i] = false;
		}
		setObjects();
		setEnemy();
		setNpc();
		engine->play2D("Music/smb_overworld.wav");
	}
	else if (currentLevel == 2)
	{
		setCoins();
		objectCount = 292;
		for (int i = 0; i < 11; i++)
		{
			encounter[i] = false;
		}
		enemyCount = 16;
		npcCount = 5;
		setEnemy2();
		setObjects2();
		setNpc2();
		engine->play2D("Music/smb_underground.wav");
	}
	else if (currentLevel == 4)
	{
		objectCount = 44;
		marioTrueX = 100;
		marioX = 100;
		marioY = 512; //default 128
		enemyCount = 0;
		npcCount = 1;
		setNpc3();
		setObjects4();
		setFire();
		engine->play2D("Music/smb_castle.wav");
		bossX = 8420;
		bossY = 320;
		bossForward = false;
		bossUp = true;
		xFlag = false;
		bossFired = false;
		bossFireIndex = 0;
		bossX = 8420;
		bossY = 320;
		bossForward = false;
		bossUp = true;
		xFlag = false;
		bossFired = false;
		bossFireIndex = 0;
		ladderForward = false;
		axeShow = true;
		bossReached = false;
		bossDead = false;
		showThanks = false;
	}
	levelboundreached = false;
	iResumeTimer(checkInputTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
	
}
void death()
{
	marioLife -= 1;
	marioIndex = 5;
	engine->stopAllSounds();
	engine->play2D("Music/smb_mariodie.wav");
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	storedMarioY = marioY;
	if (marioLife > 0)
	{
		animationCall("death");
	}
	else
	{
		animationCall("gameover");
	}
	
}
void resetAll(){
	highscoreFunc();
	jumpUp = false;
	jump = false;
	jumpLimit = 300;
	pos = false;
	objectCount = 78;
	marioHeight = 63;
	marioWidth = 48;
	marioMove = false;
	marioIndex = 0;
	levelX = 0;
	levelY = 0;
	loadFlag = 1;
	marioTrueX = 200;
	marioX = 200;
	marioY = 128; 
	screenWidth = 1024;
	screenHeight = 960;
	jumpDistance = 0;
	enemyCount = 17;
	gameState = 1;
	npcCount = 13;
	marioPowerState = 0;
	fired = false;
	fireCount = 0;
	for (int i = 0; i < 10; i++)
	{
		encounter[i] = false;
	}
	point = 0;
	clockTime = 150;
	cursorX = 320;
	cursorY = 380;
	cursorPosition = 1;
	ahead = true;
	currentLevel = 1;
	deathHeightReached = false;
	animationState = "";
	levelEnd_ground = false;
	levelEndFlag = false;
	levelboundreached = false;
	relativeTime = 0;
	marioLife = 3;
	bossX = 8420;
	bossY = 320;
	bossForward = false;
	bossUp = true;
	xFlag = false;
	bossFired = false;
	bossFireIndex = 0;
	ladderForward = false;
	axeShow = true;
	bossReached = false;
	bossDead = false;
	showThanks = false;
	levelboundreached = false;
	iResumeTimer(checkInputTimer);
}
void levelEnd(){
	
	if (marioPowerState == 0)
		marioIndex = 0;
	else if (marioPowerState == 1)
		marioIndex = 6;
	else if (marioPowerState == 2)
		marioIndex = 11;
	engine->stopAllSounds();
	engine->play2D("Music/smb_stage_clear.wav");
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	animationCall("levelEnd");
}
void finalEnd(){
	engine->stopAllSounds();
	engine->play2D("Music/smb_bowserfalls.wav");
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	animationCall("boss-bridge");
}
void elevateMario()
{
	engine->stopAllSounds();
	engine->play2D("Music/smb_pipe.wav");
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	marioX = 1200;
	animationCall("elevate");
}
void highscoreFunc()
{
	string buffer;
	int size;
	bool flag = false;
	ifstream ofs("HighScore.txt", std::ifstream::in);
	if (ofs.is_open())
	{
		ofs >> size;
		for (int i = 0; i < size; i++)
		{
			ofs >> highscores[i].score;
		}
		for (int i = 0; i < size; i++)
		{
			if (highscores[i].score < point)
			{
				for (int j = size - 1; j >= i; j--)
				{
					highscores[j + 1].score = highscores[j].score;
				}
				highscores[i].score = point;
				flag = true;
				break;
			}
		}
		if (!flag && size < 5)
		{
			highscores[size].score = point;
		}
		if (size < 5)
		{
			size++;
		}
		ofs.close();
		ofstream ofs2("HighScore.txt", std::ofstream::out);
		ofs2 << size << endl;
		for (int i = 0; i < size; i++)
		{
			ofs2 << highscores[i].score << endl;
		}
		ofs2.close();
	}
	else
	{
		ofstream ofs2("HighScore.txt", std::ofstream::out);
		ofs2 << 1 << endl;
		ofs2 << point << endl;
		ofs2.close();
	}
}
void showHighscore()
{
	int temp;
	int temp2;
	int x = 550;
	int y = 700;
	string name;
	int size, score;
	ifstream ofs("HighScore.txt", std::ifstream::in);
	if (ofs.is_open())
	{
		ofs >> size;
		for (int i = 0; i < size; i++)
		{
			int j;
			ofs >> score;
			temp = score;
			for (j = 0; temp != 0; j++)
			{
				temp2 = temp % 10;
				iShowBMP2(x, y, number[temp2], 0);
				x -= 32;
				temp = temp / 10;
			}
			for (int k = 6 - j; k != 0; k--)
			{
				iShowBMP2(x, y, number[0], 0);
				x -= 32;
			}
			iShowBMP2(x, y, dot[0], 0);
			x -= 36;
			iShowBMP2(x, y, number[i + 1], 0);
			y -= 100;
			x = 550;
		}
		ofs.close();
	}
}
void gameTime(){
	relativeTime += 1;
}
//*******************************************************************main***********************************************************************//
int main()
{
	setInput();
	iSetTimer(1, winInput);
	checkInputTimer = iSetTimer(8, checkInput);
	iSetTimer(1000, gameTime);
	iInitialize(screenWidth, screenHeight, "Project Mario");
	loadTexture();
	iStart();
	return 0;
}
//*******************************************************************end***********************************************************************//