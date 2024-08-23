void loadLevel1(){
	setObjects();
	setEnemy();
	setNpc();
	if (!changeTimer)
	{
		changeTimer = iSetTimer(100, change);
	}
	else
	{
		iResumeTimer(changeTimer);
	}
	if (!fourmsTimer)
	{
		fourmsTimer = iSetTimer(4, fourms);
	}
	else
	{
		iResumeTimer(fourmsTimer);
	}
	if (!fireCheckTimer)
	{
		fireCheckTimer = iSetTimer(800, fireCheck);
	}
	else
	{
		iResumeTimer(fireCheckTimer);
	}
	if (!clockTimer)
	{
		clockTimer = iSetTimer(1000, gameClock);
	}
	else
	{
		iResumeTimer(clockTimer);
	}
	createSoundEngine();
}
void loadLevel2()
{
	setCoins();
	setEnemy2();
	setNpc2();
	currentLevel = 2;
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	objectCount = 292;
	marioMove = false;
	levelX = 0;
	levelY = 0;
	marioTrueX = 200;
	marioX = 200;
	marioY = 880; //default 128
	jumpDistance = 0;
	enemyCount = 16;
	npcCount = 5;
	fired = false;
	fireCount = 0;
	clockTime = 150;
	setObjects2();
	for (int i = 0; i < 11; i++)
	{
		encounter[i] = false;
	}
	cout << levelX << endl;
	cout << levelY << endl;
	iResumeTimer(checkInputTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
	engine->play2D("Music/smb_underground.wav");
}
void loadLevel3()
{
	setObjects3();
	currentLevel = 3;
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	objectCount = 11;
	marioMove = false;
	levelX = 0;
	levelY = 0;
	marioTrueX = 200;
	marioX = 200;
	marioY = 256; //default 128
	jumpDistance = 0;
	enemyCount = 0;
	npcCount = 0;
	fired = false;
	fireCount = 0;
	iResumeTimer(checkInputTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
	engine->play2D("Music/smb_overworld.wav");
}
void loadLevel4()
{
	currentLevel = 4;
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	objectCount = 44;
	marioMove = false;
	levelX = 0;
	levelY = 0;
	marioTrueX = 100;
	marioX = 100;
	marioY = 512; //default 128
	jumpDistance = 0;
	enemyCount = 0;
	npcCount = 1;
	fired = false;
	fireCount = 0;
	clockTime = 150;
	setNpc3();
	setObjects4();
	setFire();
	for (int i = 0; i < 11; i++)
	{
		encounter[i] = false;
	}
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
	iResumeTimer(checkInputTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
	engine->play2D("Music/smb_castle.wav");
}