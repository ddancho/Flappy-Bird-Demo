#include <raylib.h>
#include <stdio.h>

#include "res_manager.h"
#include "state.h"
#include "state_manager.h"
#include "funcptr.h"

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 800;

extern bool running;

funcPtrUpdate pUpdate;
funcPtrRender pRender;

int main(int argc, char **argv){

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Demo");
	InitAudioDevice();
	Music music = LoadMusicStream("res/music.ogg");
	SetMusicVolume(music, 0.1f);

	SetTargetFPS(60);

	rmLoadResource();

	// start of the game is the menu state
	msPrepare();
	setState(menu);

	running = true;

	PlayMusicStream(music);

	while(!WindowShouldClose() && running ){

		if(IsWindowMinimized())
			PauseMusicStream(music);
		else
			ResumeMusicStream(music);

		// update
		update();

		ClearBackground(RED);

		UpdateMusicStream(music);

		// draw
		BeginDrawing();
		render();
		EndDrawing();
	}

	rmFreeResource();
    UnloadMusicStream(music);
	CloseAudioDevice();
	CloseWindow();

	return 0;
}

