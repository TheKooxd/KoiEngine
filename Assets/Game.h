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
	void lineUp( int l,int x,int y, int r, int g, int b,bool clip,int thick );
	void lineDown( int l,int x,int y, int r, int g, int b,bool clip,int thick );
	void lineLeft( int l,int x,int y, int r, int g, int b,bool clip,int thick );
	void lineRight( int l,int x,int y, int r, int g, int b,bool clip,int thick );
	void Clip(bool noclip, int dx, int dy);
	void scanKdb();
	void Spawn(int entCount,int entType, int var, int r, int g, int b,int f );
	void setUp();
	void loadEnt();
	void updateConsole();
	void gameOver();
	void writeGameOver();
	void verWatermark(int x, int y);
	void loadStage(int stageNum);
	void stage1();
	void stage2();
	

private:
	D3DGraphics gfx;
	KeyboardClient kbd;
	D3DCOLOR surface[ 50 * 80 ];
	D3DCOLOR surface1[ 80 * 128];
	int x;
	int getEnemyHealth(int type, int option);
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
	bool firstRun;
	int entMem[1000];
	int entX[1000];
	int entY[1000];
	int entR[1000];
	int entG[1000];
	int entB[1000];
	int entV[1000];
	int entH[1000];
	int entS[1000];
	int entF[1000];
	bool spawn;
	int q;
	bool spawned;
	bool loaded;
	int f;
	double version;
	int temp;
	int tempX;
	int tempY;
	bool dev;
	Sprite dude;
	int a;
	bool firstTime;
	int stageNum;
	bool stageDone;
	int fRun;
	bool enemies;
	Sprite enemy1;
	Sprite wall1;
	Sprite wall2;
};