#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct
{
	int status;
	float x,y;
	float vx,vy;
	SDL_Surface *image;
} Sprite;
void InitSprite(Sprite* Sp);
void Render(Sprite* Sp,SDL_Surface* screen);
void Saute(Sprite* Sp,float impulsion);
void ControleSol(Sprite* Sp);
void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys);
void Evolue(Sprite* Sp,Uint8* keys);

