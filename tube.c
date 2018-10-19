#include "tube.h"
#include <stdio.h>

#define NUM_OF_TUBES 10

typedef struct {
	Vector2 position;
	Rectangle rec;
	bool check;
} Tube;

extern int score;
extern int hiScore;
extern int pause;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

static const unsigned int TUBE_GAP = 2;
static const unsigned int BIRD_GAP = 215;

static Tube topTube[NUM_OF_TUBES];
static Tube bottomTube[NUM_OF_TUBES];
static Texture2D tTube;
static Texture2D bTube;
static Texture2D groundTex;
static Rectangle bRec;
static Rectangle *birdRec;
static Vector2 *birdPos;
static Vector2 center;
static float tubeSpeed = 80.0;

void tbPrepare(void){
	groundTex = rmGetTexture2D(ground);
	tTube = rmGetTexture2D(toptube);
	bTube = rmGetTexture2D(bottomtube);
	// reset tubes position just otside of screen
	for(unsigned int i = 0; i < NUM_OF_TUBES; i++){
		int random = GetRandomValue(0, 150);		

		topTube[i].position.y = 0 - random;
		topTube[i].position.x = SCREEN_WIDTH + TUBE_GAP + (TUBE_GAP + tTube.width) * i; 		
		topTube[i].rec.x = (int)topTube[i].position.x;
		topTube[i].rec.y = (int)topTube[i].position.y;
		topTube[i].rec.width = tTube.width;
		topTube[i].rec.height = tTube.height;
		topTube[i].check = false;
		
		bottomTube[i].position.y = topTube[i].position.y + tTube.height + BIRD_GAP; 
		bottomTube[i].position.x = SCREEN_WIDTH + TUBE_GAP + (TUBE_GAP + bTube.width) * i;
		bottomTube[i].rec.x = (int)bottomTube[i].position.x;
		bottomTube[i].rec.y = (int)bottomTube[i].position.y;
		bottomTube[i].rec.width = bTube.width;
		bottomTube[i].rec.height = bTube.height;
		bottomTube[i].check = false;
	}
}

void tbUpdate(void){
	birdRec = getBirdRecTangle();
	birdPos = getBirdPosition();
	bRec = (Rectangle){ birdPos->x, birdPos->y, birdRec->width, birdRec->height };
	center = (Vector2){ bRec.x + bRec.width/2, bRec.y + bRec.height/2 };

	for(unsigned int i = 0; i < NUM_OF_TUBES; i++){
		int random = GetRandomValue(0, 150);

		topTube[i].position.x -= tubeSpeed * GetFrameTime() * pause;
		bottomTube[i].position.x -= tubeSpeed * GetFrameTime() * pause;		

		topTube[i].rec.x = (int)topTube[i].position.x;
		topTube[i].rec.y = (int)topTube[i].position.y;

		bottomTube[i].rec.x = (int)bottomTube[i].position.x;
		bottomTube[i].rec.y = (int)bottomTube[i].position.y;
		
		/*if(CheckCollisionRecs(bRec, topTube[i].rec))
			pause = 0;

		if(CheckCollisionRecs(bRec, bottomTube[i].rec))
			pause = 0;*/
		
		if(CheckCollisionCircleRec(center, 20, topTube[i].rec)){
			pause = 0;
			if(score > hiScore)
				hiScore = score;
		}
		
		if(CheckCollisionCircleRec(center, 20, bottomTube[i].rec)){
			pause = 0;
			if(score > hiScore)
				hiScore = score;
		}

		if(bRec.y + bRec.height > SCREEN_HEIGHT - groundTex.height){
			pause = 0;
			if(score > hiScore)
				hiScore = score;
		}
		
		if(topTube[i].position.x + tTube.width < birdPos->x && pause == 1 && topTube[i].check == false){
			topTube[i].check = true;
			score++;
		}


		if(topTube[i].position.x + tTube.width <= 0){
			// reposit tube
			topTube[i].position.y = 0 - random;
			topTube[i].position.x = SCREEN_WIDTH + TUBE_GAP * 3;
			topTube[i].check = false;

			// reposit tube
			bottomTube[i].position.y = topTube[i].position.y + tTube.height + BIRD_GAP; 
			bottomTube[i].position.x = SCREEN_WIDTH + TUBE_GAP * 3;			
			bottomTube[i].check =false;
		}
	}
}

void tbDraw(void){
	
	for(unsigned int i = 0; i < NUM_OF_TUBES; i++){
		DrawTextureV(tTube, topTube[i].position, WHITE);
		DrawTextureV(bTube, bottomTube[i].position, WHITE);
	}
	
}






















