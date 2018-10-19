#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#define INCLUDE_GUID_DEVINTERFACE_HID
#include <raylib.h>
#include <stdio.h>
#include "state.h"
#include "menu_state.h"
#include "play_state.h"
#include "funcptr.h"

void setState(State s);
void update(void);
void render(void);

#endif // STATE_MANAGER_H
