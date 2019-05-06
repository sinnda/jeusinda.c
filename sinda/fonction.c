#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"

void InitSprite(Sprite* Sp)
{
	Sp->x = 100.0f;
	Sp->y = 220.0f;
	Sp->status = STAT_SOL;
	Sp->vx = Sp->vy = 0.0f;
}

void Render(Sprite* Sp,SDL_Surface* screen)
{
	SDL_Rect R;
	R.x = (Sint16)Sp->x;
	R.y = (Sint16)Sp->y;
	//R.w = 20;
	//R.h = 40;
	Sp->image=IMG_Load("perso.png");
	SDL_BlitSurface(Sp->image,NULL,screen,&R);

}

void Saute(Sprite* Sp,float impulsion)
{
	Sp->vy = -impulsion;
	Sp->status = STAT_AIR; 
}

void ControleSol(Sprite* Sp)
{
	if (Sp->y>200.0f)
	{
		Sp->y = 200.0f;
		if (Sp->vy>0)
			Sp->vy = 0.0f;
		Sp->status = STAT_SOL;
	}
}

void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys)
 {
	if (Sp->status == STAT_AIR && keys[SDLK_SPACE])
		factgravite/=factsautmaintenu;
	Sp->vy += factgravite;
}

void Evolue(Sprite* Sp,Uint8* keys)
{
	float lateralspeed = 0.5f;
	float airlateralspeedfacteur = 1.0f;
	float maxhspeed = 5.0f;//max vitesse 
	float adherance = 1.8f;
	float impulsion = 5.0f;
	float factgravite = 0.3f;
	float factsautmaintenu = 3.0f;
// on retranche au vecteur vx la constante lateralspeed
	if (keys[SDLK_LEFT]) 
		Sp->vx-=lateralspeed;
//on ajoute au vecteur vx la constante lateralspeed
	if (keys[SDLK_RIGHT])
		Sp->vx+=lateralspeed;


	if (Sp->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
		Sp->vx/=adherance;
// limite vitesse
	if (Sp->vx>maxhspeed) // //on teste avec le vecteur x si vx > vitesse (*4)
		Sp->vx = maxhspeed;
	if (Sp->vx< -maxhspeed)
		Sp->vx = -maxhspeed;
// saut
	if (keys[SDLK_SPACE] && Sp->status == STAT_SOL)
	Saute(Sp,impulsion);
	Gravite(Sp,factgravite,factsautmaintenu,keys);
	ControleSol(Sp);
// application du vecteur à la position.
	Sp->x +=Sp->vx;
	Sp->y +=Sp->vy;
}
