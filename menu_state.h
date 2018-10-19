#ifndef MENU_STATE_H
#define MENU_STATE_H

#define INCLUDE_GUID_DEVINTERFACE_HID
#include <raylib.h>
#include "textures.h"
#include "res_manager.h"
#include "state_manager.h"
#include "play_state.h"

void msPrepare(void);
void msUpdate(void);
void msRender(void);

#endif // MENU_STATE_H
