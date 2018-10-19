#include "menu_state.h"

extern bool running;
extern int hiScore;
extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;

static Vector2 birdPosition = { 150, 200 };
static Texture2D bird;
static Texture2D groundTex;
static Rectangle frameRec;
static Rectangle playRec = { 90, 300, 300, 100 };
static Rectangle quitRec = { 90, 410, 300, 100 };
static float animationFrame = 0;
static float animationSpeed = 7.0;

void msPrepare(void){
	rmResizeTexture(background, SCREEN_WIDTH, SCREEN_HEIGHT);
	rmResizeTextureByRatio(birdAnimation, 1.5f);
	rmResizeTexture(toptube, 52, 400);
	rmResizeTexture(bottomtube, 52, 400);
	// prepare bird
	bird = rmGetTexture2D(birdAnimation);
	frameRec = (Rectangle){ 0, 0, bird.width/3, bird.height };
	// 
	groundTex = rmGetTexture2D(ground);
	hiScore = 0;
}

void msUpdate(void){
	animationFrame += animationSpeed * GetFrameTime();
	if(animationFrame > 3)
		animationFrame = 0;

#ifdef PLATFORM_DESKTOP
	if(CheckCollisionPointRec(GetMousePosition(), playRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_P)){
		psPrepare();
		setState(play);		
	}

	if(CheckCollisionPointRec(GetMousePosition(), quitRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_Q))
		running = false;
#endif
}

void msRender(void){
	frameRec.x = ((int)animationFrame) * bird.width/3;

	// draw background
	DrawTexture(rmGetTexture2D(background), 0, 0, WHITE);
	
	// draw bird
	DrawTextureRec(bird, frameRec, birdPosition, WHITE);

	// draw ground - 2 part
	DrawTexture(rmGetTexture2D(ground), 0, SCREEN_HEIGHT - groundTex.height, WHITE);
	DrawTexture(rmGetTexture2D(ground), 336, SCREEN_HEIGHT - groundTex.height, WHITE);

	// draw high score
	DrawText(FormatText("HI-SCORE %d", hiScore), 150, 10, 20, DARKPURPLE);

	// draw options boxes
	DrawRectangleLines(playRec.x, playRec.y, playRec.width, playRec.height, BLACK);	DrawText("(P)LAY", 125, 320, 66, BLACK);
	DrawRectangleLines(quitRec.x, quitRec.y, quitRec.width, quitRec.height, BLACK);	DrawText("(Q)UIT", 125, 425, 66, BLACK);

	// draw flappy name
	DrawText("Flappy Bird Demo", 40, 100, 48, RED);

	// draw info
	DrawText("* WIN Version , Left Mouse Button or Space to Jump *", 20, 750, 18, DARKGREEN);
}
















