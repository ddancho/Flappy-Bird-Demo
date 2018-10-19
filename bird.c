#include "bird.h"
#include <stdio.h>

extern int pause;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

static const float GRAVITY = 18;

static Texture2D birdTex;
static Rectangle birdRec;
static Vector2 birdPosition;
static Vector2 birdSpeed;
static float animationFrame = 0;
static float animationSpeed = 7.0;

void bPrepare(void){
	birdTex = rmGetTexture2D(birdAnimation);
	birdRec = (Rectangle){ 0, 0, birdTex.width/3, birdTex.height };
	birdPosition = (Vector2){ 150, 200 };
	birdSpeed = (Vector2){ 0, 0 };
}

void bUpdate(void){
	animationFrame += animationSpeed * GetFrameTime() * pause;
	if(animationFrame > 3)
		animationFrame = 0;
	
	birdSpeed.y += GRAVITY * GetFrameTime() * pause;
	birdPosition.y += birdSpeed.y * pause;
}

void bDraw(void){
	birdRec.x = ((int)animationFrame) * birdTex.width/3;
	DrawTextureRec(birdTex, birdRec, birdPosition, WHITE);
}

void bJump(void){
	birdSpeed.y = -5 * pause;
	if(pause == 1)
		PlaySound(rmGetSound());
}

Vector2* getBirdPosition(void){
	return &birdPosition;
}

Rectangle* getBirdRecTangle(void){
	return &birdRec;
}




