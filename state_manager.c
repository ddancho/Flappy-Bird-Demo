#include "state_manager.h"

extern funcPtrUpdate pUpdate;
extern funcPtrRender pRender;

bool running;

static State state;

void setState(State s){
	state = s;

	if(s == menu){
		pUpdate = msUpdate;
		pRender = msRender;
	} 
	else if(s == play){
		pUpdate = psUpdate;
		pRender = psRender;
	}
}

void update(void){
	pUpdate();
}

void render(void){
	pRender();
}

