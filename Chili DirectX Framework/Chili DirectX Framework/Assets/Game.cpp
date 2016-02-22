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

Game::Game( HWND hWnd,const KeyboardServer& kServer )
:	gfx ( hWnd ),
	kbd( kServer ),
	x ( 100 ),
	y ( 100 ),
	b ( 100 ),
	noclip ( false )
{}

void Game::Go()
{
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::drawPlayerModel(int x, int y, int r, int g, int b)
{
	


	lineUp(30, x, y, r, g, b,0);
	lineLeft(40,x,y,r,g,b,0);
	lineUp(30,x - 40,y,r,g,b,0);
	lineRight(40,x - 40,y - 30,r,g,b,0);
	
	
}

//Line FunctionS
void Game::lineDown(int l, int x, int y, int r, int g, int b, bool clip)
{
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
	while( l > 0 )
	{
		


		gfx.PutPixel( x, y, r, g, b );


		y++;

		l--;
	}
	
	


}
void Game::lineUp(int l, int x, int y, int r, int g, int b, bool clip)
{
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
	while( l > 0 )
	{
		gfx.PutPixel( x, y, r, g, b );
		y--;
		l--;
	}
}
void Game::lineLeft(int l, int x, int y, int r, int g, int b, bool clip)
{
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
	while( l > 0 )
	{
		gfx.PutPixel( x, y, r, g, b );
		x--;
		l--;
	}
}
void Game::lineRight(int l, int x, int y, int r, int g, int b, bool clip)
{
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

	while( l > 0 )
	{
		gfx.PutPixel( x, y, r, g, b );
		x++;
		l--;
	}
}



void Game::scanKdb()
{

	if(kbd.SpaceIsPressed())
	{
		r = 0;
		g = 255;
		
	}

	if( kbd.EnterIsPressed())
	{
		lineUp(60,400,400,0,255,0,true);
	}

	if(kbd.UpIsPressed())
	{
		b = 0;
		y = y - speed;
		
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
void Game::ComposeFrame()
{
	r = 255;
	g = 0;
	speed = 2;
	scanKdb();
	drawPlayerModel(x,y,r,g,b);
	
}