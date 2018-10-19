#include "res_manager.h"

#define NUM_OF_TEXTURES 7

static Texture2D textures[NUM_OF_TEXTURES];
static Sound flap;

void rmLoadResource(void){
	textures[background] 	= LoadTexture("res/background.png");
	textures[birdFrame] 	= LoadTexture("res/bird.png");
	textures[birdAnimation] = LoadTexture("res/birdAnimation.png");
	textures[bottomtube] 	= LoadTexture("res/bottomTube.png");
	textures[ground] 		= LoadTexture("res/ground.png");
	textures[playButton] 	= LoadTexture("res/playButton.png");
	textures[toptube] 		= LoadTexture("res/topTube.png");

	flap = LoadSound("res/flap.ogg");
	SetSoundVolume(flap, 0.3f);
}

void rmFreeResource(void){
	for(unsigned int i = 0; i < NUM_OF_TEXTURES; i++)
		UnloadTexture(textures[i]);

	UnloadSound(flap);
}

Texture2D rmGetTexture2D(TexturesID texture){
	return textures[texture];
}

Sound rmGetSound(void){
	return flap;
}

void rmResizeTexture(TexturesID texture, int w, int h){
	textures[texture].height = h;
	textures[texture].width = w;
}

void rmResizeTextureByRatio(TexturesID texture, float ratio){
	textures[texture].height = (int)(textures[texture].height * ratio);
	textures[texture].width = (int)(textures[texture].width * ratio);
}


