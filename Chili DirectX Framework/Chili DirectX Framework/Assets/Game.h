/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	Game.h																				  *
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
#pragma once

#include "D3DGraphics.h"
#include "Keyboard.h"

class Game
{
public:
	Game( HWND hWnd,const KeyboardServer& kServer );
	void Go();
private:
	void ComposeFrame();
	/********************************/
	/*  User Functions              */

	void drawPlayerModel( int x,int y,int r,int g, int b );
	void lineUp( int l,int x,int y, int r, int g, int b,bool clip );
	void lineDown( int l,int x,int y, int r, int g, int b,bool clip );
	void lineLeft( int l,int x,int y, int r, int g, int b,bool clip );
	void lineRight( int l,int x,int y, int r, int g, int b,bool clip );
	void Clip(bool noclip, int dx, int dy);
	void scanKdb();

	/********************************/
private:
	D3DGraphics gfx;
	KeyboardClient kbd;
	int x;
	int y;
	int l;
	int xt;
	int locx;
	int locy;
	int b;
	int speed;
	int noclip;
	int dx;
	int dy;
	int r;
	int g;
};