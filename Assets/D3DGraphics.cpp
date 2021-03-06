/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	D3DGraphics.cpp																		  *
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
#include "D3DGraphics.h"
#include "Bitmap.h"

	void loadSprite( Sprite* sprite,D3DCOLOR* surface,const char* filename,
		unsigned int width, unsigned int height,D3DCOLOR key )
	{
	LoadBmp( filename,surface );
	sprite->height = height;
	sprite->width = width;
	sprite->key = key;
	sprite->surface = surface;
	}

D3DGraphics::D3DGraphics( HWND hWnd )
{
	backRect.pBits = NULL;

	pDirect3D = Direct3DCreate9( D3D_SDK_VERSION );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

    pDirect3D->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );

	pDevice->GetBackBuffer( 0,0,D3DBACKBUFFER_TYPE_MONO,&pBackBuffer ); //Interface create for backBuffer

}

D3DGraphics::~D3DGraphics()
{
	if( pDevice )
	{
		pDevice->Release();
		pDevice = NULL;
	}
	if( pDirect3D )
	{
		pDirect3D->Release();
		pDirect3D = NULL;
	}
	if( pBackBuffer ) //Check if backBuffer is free and ready to go
	{
		pBackBuffer->Release();
		pBackBuffer = NULL;
	}
}

void D3DGraphics::PutPixel( int x,int y,int r,int g,int b ) //edited 20.02.2016 (Optimized)
{	
	((D3DCOLOR*)backRect.pBits)[ x + (backRect.Pitch >> 2) * y ] = D3DCOLOR_XRGB( r,g,b );
	
}

void D3DGraphics::PutPixel( int x,int y,D3DCOLOR c ) //edited 20.02.2016 (Optimized)
{	
	((D3DCOLOR*)backRect.pBits)[ x + (backRect.Pitch >> 2) * y ] = c;
	
}


void D3DGraphics::BeginFrame()
{
	pDevice->Clear( 0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),0.0f,0 );
	//Memory Lock to backBuffer
	pBackBuffer->LockRect( &backRect,NULL,NULL );
	//LockDone
}

void D3DGraphics::EndFrame()
{
	//Unlocking BackBuffer to GPU
	pBackBuffer->UnlockRect();
	//DONE
	pDevice->Present( NULL,NULL,NULL,NULL );
}




void D3DGraphics::DrawSprite( int xoff,int yoff,Sprite* sprite )
{
	for( int y = 0; y < sprite->height; y++ )
	{
		for( int x = 0; x < sprite->width; x++ )
		{
			D3DCOLOR c = sprite->surface[ x + y * sprite->width ];
			if( c != sprite->key )
			{
			PutPixel( x + xoff,y + yoff,c );
			}
		}


	}
}