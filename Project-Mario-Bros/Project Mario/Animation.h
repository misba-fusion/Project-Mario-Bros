void change(){
	if (ahead == true)
	{
		if (marioPowerState == 0)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 0)
				{
					marioIndex = 3;
				}
				else if (marioIndex == 2 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 2 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 3)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 1)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 0;
				}
			}
			else if (jump == true)
			{
				marioIndex = 4;
			}
			else
			{
				marioIndex = 0;
			}
		}
		else if (marioPowerState == 1)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 6)
				{
					marioIndex = 9;
				}
				else if (marioIndex == 8 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 8 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 9)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 7)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 6;
				}
			}
			else if (jump == true)
			{
				marioIndex = 10;
			}
			else
			{
				marioIndex = 6;
			}
		}
		else if (marioPowerState == 2)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 11)
				{
					marioIndex = 14;
				}
				else if (marioIndex == 13 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 13 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 14)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 12)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 11;
				}
			}
			else if (jump == true)
			{
				marioIndex = 15;
			}
			else
			{
				marioIndex = 11;
			}
		}
	}
	else
	{
		if (marioPowerState == 0)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 16)
				{
					marioIndex = 19;
				}
				else if (marioIndex == 18 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 18 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 19)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 17)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 16;
				}
			}
			else if (jump == true)
			{
				marioIndex = 20;
			}
			else
			{
				marioIndex = 16;
			}
		}
		else if (marioPowerState == 1)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 21)
				{
					marioIndex = 24;
				}
				else if (marioIndex == 23 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 23 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 24)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 22)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 21;
				}
			}
			else if (jump == true)
			{
				marioIndex = 25;
			}
			else
			{
				marioIndex = 21;
			}
		}
		else if (marioPowerState == 2)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 26)
				{
					marioIndex = 29;
				}
				else if (marioIndex == 28 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 28 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 29)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 27)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 26;
				}
			}
			else if (jump == true)
			{
				marioIndex = 30;
			}
			else
			{
				marioIndex = 26;
			}
		}
	}
	if (currentLevel == 4)
	{
		for (int i = 0; i < 42; i++)
		{
			fires[i].fireX = fires[i].originX + (fires[i].radius* cos((degree * PICT) / 180));
			fires[i].fireY = fires[i].originY + (fires[i].radius* sin((degree * PICT) / 180));
		}
		if (degree < 360)
		{
			degree += 10;
		}
		else
		{
			degree = 0;
		}
	}
}
void animationCall(string x){
	animationState = x;
	capturedTime = relativeTime;
	if (!animationTimer)
	{
		animationTimer = iSetTimer(10, animation);/////
	}
	else
	{
		iResumeTimer(animationTimer);
	}
}
void animation(){
	if (animationState == "death")
	{
		if ((!deathHeightReached) && (storedMarioY + 600 > marioY))
		{
			marioY += 10;
			if (storedMarioY + 600 <= marioY)
			{
				deathHeightReached = true;
			}
		}
		else if (marioY > -300)
		{
			marioY -= 10;
		}
		else
		{
			iPauseTimer(animationTimer);
			animationState = "";
			deathHeightReached = false;
			restart();
		}
	}
	else if (animationState == "levelEnd")
	{
		if (!levelEnd_ground){
			marioCollision(0, -5);
			cout << marioY << endl;
			if (marioY == 192)
			{
				levelEnd_ground = true;
			}
		}
		else
		{
			if (!levelboundreached)
			{
				marioCollision(5, -5);
			}
			else
			{
				if (marioX < 550)
				{
					marioX += 5;
				}
				else
				{
					marioX = 2000;
				}
			}
		}
		if (clockTime > 0)
		{
			clockTime -= 1;
			point += 50;
		}
		if (capturedTime + 7 < relativeTime)
		{
			cout << "loading level 2" << endl;
			iPauseTimer(animationTimer);
			animationState = "";
			levelEnd_ground = false;
			levelboundreached = false;
			levelEndFlag = false;
			if (currentLevel == 1)
			{
				loadLevel2();
			}
			else if (currentLevel == 3)
			{
				loadLevel4();
			}

		}
	}
	else if (animationState == "gameover")
	{
		if ((!deathHeightReached) && (storedMarioY + 600 > marioY))
		{
			marioY += 10;
			if (storedMarioY + 600 <= marioY)
			{
				deathHeightReached = true;
			}
		}
		else if (marioY > -300)
		{
			marioY -= 10;
		}
		else
		{
			//iPauseTimer(animationTimer);
			//animationState = "";
			deathHeightReached = false;
			gameState = 5;
			animationState = "gameover-screen";
			engine->play2D("Music/smb_gameover.wav");
			capturedTime = relativeTime;
		}
	}
	else if (animationState == "gameover-screen")
	{
		if (capturedTime + 5 < relativeTime)
		{
			iPauseTimer(animationTimer);
			animationState = "";
			gameState = 1;
			resetAll();
		}
	}
	else if (animationState == "elevate")
	{
		if (capturedTime + 3 < relativeTime)
		{
			iPauseTimer(animationTimer);
			animationState = "";
			loadLevel3();
		}
	}
	else if (animationState == "boss-bridge")
	{
		if (capturedTime + 1 < relativeTime)
		{
			objects[43].show = false;
		}
		if (capturedTime + 2 < relativeTime)
		{
			objects[42].show = false;
		}
		if (capturedTime + 3 < relativeTime)
		{
			objects[41].show = false;
		}
		if (capturedTime + 4 < relativeTime)
		{
			objects[40].show = false;
			animationCall("boss-die");
		}
	}
	else if (animationState == "boss-die")
	{
		bossY -= 5;
		if (capturedTime + 2 < relativeTime)
		{
			bossDead = true;
			engine->play2D("Music/smb_world_clear.wav");
			animationCall("screen pan");
		}
	}
	else if (animationState == "screen pan")
	{
		if (marioX > 328)
		{
			marioX -= 5;
			levelX -= 5;
			for (int i = 1; i <= 5; i++)
			{
				levelScroll();
			}
		}
		else
		{
			cout << "finished" << endl;
			if (marioPowerState == 0)
				marioIndex = 0;
			else if (marioPowerState == 1)
				marioIndex = 6;
			else if (marioPowerState == 2)
				marioIndex = 11;
			animationCall("finalWalk");
		}
	}
	else if (animationState == "finalWalk")
	{
		marioCollision(5, -5);
		if (capturedTime + 3 < relativeTime)
		{
			showThanks = true;
		}
		if (capturedTime + 8 < relativeTime)
		{
			iPauseTimer(animationTimer);
			animationState = "";
			gameState = 1;
			resetAll();
		}
	}
}