#include "play_state.h"

#define NUM_OF_GROUNDS 3

extern bool running;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

int hiScore = 0;
int score = 0;
int pause = 1;

static Texture2D groundTex;
static Rectangle groundRec[NUM_OF_GROUNDS];
static Rectangle menuRec = { 8, 8 , 78, 22 };
static float groundSpeed = 100.0f;

void psPrepare(void){
	score = 0;
	pause = 1;

	// prepare bird
	bPrepare();

	// prepare tubes
	tbPrepare();
	
	// prepare ground
	groundTex = rmGetTexture2D(ground);
	for(unsigned int i = 0; i < NUM_OF_GROUNDS; i++){
		groundRec[i] = (Rectangle){ 0 + groundTex.width * i, SCREEN_HEIGHT - groundTex.height, groundTex.width, groundTex.height };
	}
}

void psUpdate(void){
	if(CheckCollisionPointRec(GetMousePosition(), menuRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_M))
		setState(menu);
	
	if(IsKeyPressed(KEY_Q))
		running = false;
	
	if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_SPACE))
		bJump();

	// update bird
	bUpdate();

	// update tubes
	tbUpdate();

	// update ground
	for(unsigned int i = 0; i < NUM_OF_GROUNDS; i++){
		groundRec[i].x -= (int)(groundSpeed * GetFrameTime() * pause);
		if(groundRec[i].x + groundRec[i].width < 0){
			groundRec[i].x = groundRec[i].width * 2 - 1;
		}
	}
}

void psRender(void){
	// draw background
	DrawTexture(rmGetTexture2D(background), 0, 0, WHITE);
	
	// draw bird
	bDraw();

	// draw tubes
	tbDraw();
	
	// draw ground
	for(unsigned int i = 0; i < NUM_OF_GROUNDS; i++){
		DrawTexture(groundTex, groundRec[i].x, groundRec[i].y, WHITE);
	}

	// draw menu
	DrawRectangleLines(menuRec.x, menuRec.y, menuRec.width, menuRec.height, BLACK); DrawText("(M)ENU", 10, 10, 20, DARKGREEN);

	// draw score & high score
	DrawText(FormatText("HI-SCORE %d", hiScore), 150, 10, 20, DARKPURPLE);
	DrawText(FormatText("SCORE %d", score), 350, 10, 20, BLACK);

	// draw game over
	if(pause == 0)
		DrawText("GAME\nOVER", 150, 300, 60, RED);

	// fps
	DrawFPS(5, 780);

}


