void fireStart(int x, int y, int levelX, int levelY)
{
	fireObjects[fireCount].x = x;
	fireObjects[fireCount].y = y;
	fireObjects[fireCount].levelX = levelX;
	fireObjects[fireCount].levelY = levelY;
	fireObjects[fireCount].status = true;
	fireObjects[fireCount].maxHeight = 0;
	fireObjects[fireCount].velocityX = 15;
	fireObjects[fireCount].velocityY = -15;

	fireCount++;
}
void fireCheck()
{
	fired = false;
	if (relativeTime % 5 == 0)
	{
		bossFired = false;
	}
}
void fireCollision()
{
	int flag2;
	for (int i = 0; i < fireCount; i++)
	{
		int j, k, l;
		if (fireObjects[i].velocityX > 0)
		{
			k = 1;
		}
		else if (fireObjects[i].velocityX < 0)
		{
			k = -1;
		}
		if (fireObjects[i].velocityY > 0)
		{
			l = 1;
		}
		else if (fireObjects[i].velocityY < 0)
		{
			l = -1;
		}
		if (fireObjects[i].status == true)
		{
			flag2 = 0;
			for (j = 1; j <= abs(fireObjects[i].velocityX); j++)
			{
				int flag = 0;
				for (int o = 0; o < objectCount; o++)
				{
					if (objects[o].show == true)
					{
						if (aabbCollisionFireObjects(i, o, k, 0))
						{
							flag = 1;
						}
					}
				}
				if (flag == 0)
				{
					fireObjects[i].x += k;
					fireObjects[i].levelX += k;
				}
				else
				{
					flag2 = 1;
				}
			}
			if (flag2 == 1)
			{
				fireObjects[i].status = false;
			}
			for (j = 1; j <= abs(fireObjects[i].velocityY); j++)
			{
				int flag = 0;
				for (int o = 0; o < objectCount; o++)
				{
					if (objects[o].show == true)
					{
						if (aabbCollisionFireObjects(i, o, 0, l))
						{
							flag = 1;
						}
					}
				}
				if (flag == 0)
				{
					fireObjects[i].y += l;
					fireObjects[i].levelY += l;
					fireObjects[i].maxHeight += l;
				}
				else
				{
					flag2 = 1;
				}
			}
			if (flag2 == 1)
			{
				fireObjects[i].velocityY *= -1;
			}
			else if (fireObjects[i].maxHeight > 48)
			{
				fireObjects[i].velocityY *= -1;
			}
		}
		for (int e = 0; e < enemyCount; e++)
		{
			if (fireObjects[i].status == true)
			{
				if (enemyObjects[e].alive == true)
				{
					if (aabbCollisionFireEnemy(i, e))
					{
						fireObjects[i].status = false;
						enemyObjects[e].alive = false;
						pointAdd(100);
					}
				}
			}
		}
	}
}
bool aabbCollisionFireObjects(int f, int o, int x, int y)
{
	if (objects[o].levelX > (fireObjects[f].levelX + 32 + x))
	{
		return false;
	}
	if ((objects[o].levelX + objects[o].width) < (fireObjects[f].levelX + x))
	{
		return false;
	}
	if (objects[o].levelY > (fireObjects[f].levelY + 32 + y))
	{
		return false;
	}
	if ((objects[o].levelY + objects[o].height) < (fireObjects[f].levelY + y))
	{
		return false;
	}
	return true;
}
bool aabbCollisionFireEnemy(int f, int e)
{
	if (enemyObjects[e].levelX > (fireObjects[f].levelX + 32))
	{
		return false;
	}
	if ((enemyObjects[e].levelX + enemyObjects[e].width) < (fireObjects[f].levelX))
	{
		return false;
	}
	if (enemyObjects[e].levelY > (fireObjects[f].levelY + 32))
	{
		return false;
	}
	if ((enemyObjects[e].levelY + enemyObjects[e].height) < (fireObjects[f].levelY))
	{
		return false;
	}
	return true;
}