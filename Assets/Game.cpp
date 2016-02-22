/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	Game.cpp																			  *
 *	Copyright 2011 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"
#include "time.h"

static bool firstRun;
Game::Game( HWND hWnd,const KeyboardServer& kServer )
:	gfx ( hWnd ),
	kbd( kServer ),
	x ( 100 ),
	y ( 100 ),
	b ( 100 ),
	noclip ( false ),
	spawn ( false ),
	spawned ( false ),
	loaded ( false ),
	f ( 1 ),
	version ( 0.1 ),
	temp ( 0 )
	
{}

void Game::Go()
{
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::drawPlayerModel(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x-4,y,0,0,0); //First row
	gfx.PutPixel(x-5,y,0,0,0);
	gfx.PutPixel(x-6,y,0,0,0);
	gfx.PutPixel(x-7,y,0,0,0);

	gfx.PutPixel(x-3,y-1,0,0,0); //second row
	gfx.PutPixel(x-4,y-1,255,255,255);
	gfx.PutPixel(x-5,y-1,255,255,255);
	gfx.PutPixel(x-6,y-1,255,255,255);
	gfx.PutPixel(x-7,y-1,255,255,255);
	gfx.PutPixel(x-8,y-1,0,0,0);

	gfx.PutPixel(x-2,y-2,0,0,0); //third row
	gfx.PutPixel(x-3,y-2,0,0,0);
	gfx.PutPixel(x-4,y-2,0,0,0);
	gfx.PutPixel(x-5,y-2,0,0,0);
	gfx.PutPixel(x-6,y-2,255,255,255);
	gfx.PutPixel(x-7,y-2,255,255,255);
	gfx.PutPixel(x-8,y-2,0,0,0);

	gfx.PutPixel(x-1,y-3,0,0,0); //fourth row
	gfx.PutPixel(x-2,y-3,50,50,255);
	gfx.PutPixel(x-3,y-3,0,0,0);
	gfx.PutPixel(x-4,y-3,255,255,255);
	gfx.PutPixel(x-5,y-3,255,255,255);
	gfx.PutPixel(x-6,y-3,0,0,0);
	gfx.PutPixel(x-7,y-3,0,0,0);

	gfx.PutPixel(x-1,y-4,0,0,0); //fifth row
	gfx.PutPixel(x-2,y-4,50,50,255);
	gfx.PutPixel(x-3,y-4,0,0,0);
	gfx.PutPixel(x-4,y-4,255,255,255);
	gfx.PutPixel(x-5,y-4,255,255,255);
	gfx.PutPixel(x-6,y-4,0,0,0);
	gfx.PutPixel(x-7,y-4,0,0,0);
	
	gfx.PutPixel(x-1,y-5,0,0,0); //sixth row
	gfx.PutPixel(x-2,y-5,50,50,255);
	gfx.PutPixel(x-3,y-5,50,50,255);
	gfx.PutPixel(x-4,y-5,0,0,0);
	gfx.PutPixel(x-5,y-5,0,0,0);
	gfx.PutPixel(x-6,y-5,0,0,0);
	gfx.PutPixel(x-7,y-5,0,0,0);
	gfx.PutPixel(x-8,y-5,0,0,0);

	gfx.PutPixel(x-1,y-6,0,0,0); //seventh row
	gfx.PutPixel(x-2,y-6,50,50,255);
	gfx.PutPixel(x-3,y-6,0,0,0);
	gfx.PutPixel(x-4,y-6,0,0,0);
	gfx.PutPixel(x-5,y-6,255,255,255);
	gfx.PutPixel(x-6,y-6,255,255,255);
	gfx.PutPixel(x-7,y-6,255,255,255);
	gfx.PutPixel(x-8,y-6,255,255,255);
	gfx.PutPixel(x-9,y-6,0,0,0);

	gfx.PutPixel(x-2,y-7,0,0,0); //eight row
	lineLeft(7,x-3,y-7,255,255,255,false,1);
	gfx.PutPixel(x-10,y-7,0,0,0);

	gfx.PutPixel(x-1,y-8,0,0,0); //ninth row?
	gfx.PutPixel(x-2,y-8,0,0,0);
	gfx.PutPixel(x-3,y-8,255,255,255);
	gfx.PutPixel(x-4,y-8,255,255,255);
	gfx.PutPixel(x-5,y-8,0,0,0);
	gfx.PutPixel(x-6,y-8,255,255,255);
	gfx.PutPixel(x-7,y-8,255,255,255);
	gfx.PutPixel(x-8,y-8,0,0,0);
	gfx.PutPixel(x-9,y-8,255,255,255);
	gfx.PutPixel(x-10,y-8,0,0,0);

	lineLeft(6,x,y-9,0,0,0,false,1); // tenth row
	gfx.PutPixel(x-6,y-9,255,255,255);
	gfx.PutPixel(x-7,y-9,255,255,255);
	gfx.PutPixel(x-8,y-9,0,0,0);
	gfx.PutPixel(x-9,y-9,255,255,255);
	gfx.PutPixel(x-10,y-9,0,0,0);

	lineLeft(7,x,y-10,0,0,0,false,1); //eleventh row
	gfx.PutPixel(x-7,y-10,255,0,0);
	gfx.PutPixel(x-8,y-10,255,0,0);
	gfx.PutPixel(x-9,y-10,255,0,0);
	gfx.PutPixel(x-10,y-10,0,0,0);
	gfx.PutPixel(x-11,y-10,0,0,0);

	gfx.PutPixel(x,y-11,0,0,0); //twelveth row
	gfx.PutPixel(x-1,y-11,0,0,0);
	gfx.PutPixel(x-2,y-11,0,0,0);
	lineLeft(5,x-3,y-11,255,0,0,false,1);
	lineLeft(4,x-8,y-11,255,255,255,false,1);
	gfx.PutPixel(x-12,y-11,0,0,0);

	gfx.PutPixel(x-1,y-12,0,0,0); //thirteen row
	lineLeft(7,x-2,y-12,255,0,0,false,1);
	gfx.PutPixel(x-9,y-12,255,255,255);
	gfx.PutPixel(x-10,y-12,0,0,0);
	gfx.PutPixel(x-11,y-12,0,0,0);

	gfx.PutPixel(x-1,y-13,0,0,0); //fourtheen row
	lineLeft(8,x-2,y-13,255,0,0,false,1);
	gfx.PutPixel(x-10,y-13,0,0,0);

	gfx.PutPixel(x-2,y-14,0,0,0); //fiftheenth row
	lineLeft(6,x-3,y-14,255,0,0,false,1);
	gfx.PutPixel(x-9,y-14,0,0,0);

	lineLeft(6,x-3,y-15,0,0,0,false,1);

}

//Line FunctionS
void Game::lineDown(int l, int x, int y, int r, int g, int b, bool clip,int thick)
{
	tempY = y;
	if(clip)
	{
	if( x < 0 )
		{
			x = 1;
		}

			if( x > 800 )
		{
			x = 800;
		}

			if( y < 0 )
		{
			y = 1;
		}

		if( y+l > 600 )
		{
			y = 600 - l;
		}
	}
	for(int p = 0;p < thick;p++)
	{
		y = tempY;
		temp = l;
	while( temp > 0 )
	{
		gfx.PutPixel( x, y, r, g, b );
		y++;
		temp--;
	}
	x = x+1;
	}
	


}
void Game::lineUp(int l, int x, int y, int r, int g, int b, bool clip,int thick)
{
	tempY = y;
	if (clip)
	{
		if( x < 0 )
		{
			x = 1;
		}

			if( x > 800 )
		{
			x = 800;
		}

			if( y - l < 0 )
		{
			y = 1 + l;
		}

		if( y > 600 )
		{
			y = 600;
		}
	}
	for(int p = 0;p < thick;p++)
	{
		y = tempY;
		temp = l;

	while( temp > 0 )
	{
		gfx.PutPixel( x, y, r, g, b );
		y--;
		temp--;
	}
	x = x+1;
	}
}
void Game::lineLeft(int l, int x, int y, int r, int g, int b, bool clip,int thick)
{
	tempX = x;
	if(clip)
	{
	if( x - l < 0 )
		{
			x = 1 + l;
		}

			if( x > 800 )
		{
			x = 800;
		}

			if( y < 0 )
		{
			y = 1;
		}

		if( y > 600 )
		{
			y = 600;
		}
	}
	for(int p = 0;p < thick;p++)
	{
		x = tempX;
		temp = l;

	while( temp > 0 )
	{
		gfx.PutPixel( x, y, r, g, b );
		x--;
		temp--;
	}
	y = y-1;
	}
}
void Game::lineRight(int l, int x, int y, int r, int g, int b, bool clip,int thick)
{
	tempX = x;
	if(clip)
	{
	if( x < 0 )
		{
			x = 1;
		}

			if( x + l > 800 )
		{
			x = 800 - l;
		}

			if( y < 0 )
		{
			y = 1;
		}

		if( y > 600 )
		{
			y = 600;
		}
	}

	for(int p = 0;p < thick;p++)
	{
		x = tempX;
		temp = l;
	while( temp > 0 )
	{
		gfx.PutPixel( x, y, r, g, b );
		x++;
		temp--;
	}
	y = y-1;
	}
}



void Game::scanKdb()
{

	if(kbd.SpaceIsPressed())
	{
		
		
	}

	if( kbd.EnterIsPressed())
	{
		setUp();
	}

	

		if(kbd.RightIsPressed())
	{
		b = 0;
		x = x + speed;
	}

	if(kbd.DownIsPressed())
	{
		b = 0;
		y = y + speed;
	}

	if(kbd.LeftIsPressed())
	{
		b = 0;
		x = x - speed;
	}
	
}

void Game::Spawn(int entCount,int entId,int entVar, int r, int g, int b)
{
	while(entCount > 0)
	{
	for(int i = 0; i < 1000;i = i+1)
	{
		if (entMem[i] == 0)
		{

		if (entId == 1)
		{
			
			entMem[i] = 1;
			entX[i] = rand() % 800;
			entY[i] = rand() % 600;
			entR[i] = rand() % 255;
			entG[i] = rand() % 255;
			entB[i] = rand() % 255;
			entV[i] = entVar;
			i = 1000;
		}


		if (entId == 2)
		{
			entMem[i] = 2;
			entR [i] = r;
			entG [i] = b;
			entB [i] = g;
			i = 1000;

		}

		if (entId == 3)
		{
			entMem[i] = 3;
			entH[i] = 100;
			entS[i] = 5;
			entX[i] = 400;
			entY[i] = 400;
			i = 1000;

		}

	}
		
	}
	entCount--;
	}
	
}

void Game::loadEnt()
{
	

	for(int i = 0; i<1000;i++)
	{
		if (entMem[i] == 1)
		
		{
			lineRight(entV[i],entX[i],entY[i],entR[i],entG[i],entB[i],false,1);
		
			
		}

		if (entMem[i] == 2)
		{
				for(int q = 0;q < 600; q++)
			{
				lineRight(800,0,0+q,entR[i],entG[i],entB[i],false,1);
				
			}

		}


		if (entMem[i] == 3) // Player Update
		{
		
			if(kbd.RightIsPressed())
			{
				entX[i] = entX[i] + entS[i];
			
			}
			if(kbd.LeftIsPressed())
			{
				entX[i] = entX[i] - entS[i];
			
			}
			if(kbd.DownIsPressed())
			{
				entY[i] = entY[i] + entS[i];
			
			}
			if(kbd.UpIsPressed())
			{
				entY[i] = entY[i] - entS[i];
			
			}

			if(kbd.EnterIsPressed())
			{
				setUp();
			}

			if(kbd.SpaceIsPressed())
			{
				entS[i] = 1;
			}


			if(entX[i] < 12)
			{
				entX[i] = 12;
			}

			if(entX[i] > 800)
			{
				entX[i] = 800;
			}

			if(entY[i] < 18)
			{
				entY[i] = 18;
			}

			
			if(entY[i] > 597)
			{
				entY[i] = 599;
			}

			for(int k = 0; k<1000;k++)
			{
				
				if(entMem[k] == 1)
				{
					//Spawn(1,2,255,255,255,0);
					if(entX[i] > entX[k] && entX[i] - 12 < entX[k] + 30)
					{
						if(entY[i] > entY[k] && entY[i] - 12 < entY[k])
						{
							entH[i] = 0;
						}
					}
				}
			}


			if(entH[i] == 0)
			{
				gameOver();

			}


			drawPlayerModel(entX[i],entY[i],0,0,0);
		}

		
	}


}

void Game::gameOver()
{
	
	writeGameOver();
}

void Game::writeGameOver()
{
	x = 0;
	y = 0;
	lineUp(30,x+100,y+290,255,0,0,false,10); //G
	lineRight(30,x+110,y+260,255,0,0,false,10);
	lineRight(30,x+110,y+300,255,0,0,false,10);
	lineUp(10,x+130,y+290,255,0,0,false,10);

	lineUp(40,x+160,y+300,255,0,0,false,10); //A
	lineRight(20,x+170,y+260,255,0,0,false,10);
	lineUp(40,x+190,y+300,255,0,0,false,10);
	lineRight(20,x+170,y+280,255,0,0,false,10);

	lineUp(50,x+220,y+300,255,0,0,false,10); //M
	lineUp(10,x+230,y+270,255,0,0,0,10);
	lineDown(20,x+240,y+270,255,0,0,0,10);
	lineUp(10,x+250,y+270,255,0,0,0,10);
	lineUp(50,x+260,y+300,255,0,0,false,10);

	lineUp(50,x+290,y+300,255,0,0,0,10); // E
	lineRight(30,x+290,y+280,255,0,0,0,10);
	lineRight(40,x+290,y+260,255,0,0,0,10);
	lineRight(40,x+290,y+300,255,0,0,0,10);

	lineUp(30,x+450,y+290,255,0,0,0,10); //O
	lineUp(30,x+490,y+290,255,0,0,0,10);
}

void Game::setUp()
{
	for(int i = 0;i<1000;i++) //reset entity memory variable to mark memory free 
	{
	entMem[i] = 0;
	}

	//Spawn(1,2,255,255,255,255);
	Spawn(1,3,0,0,0,0);
	Spawn(3,1,20,255,0,0);
	
}



void Game::ComposeFrame()
{
	if (f == 1)
	{
		setUp();
		f = 0;
	}

	
	loadEnt();
	
    //writeGameOver();
}