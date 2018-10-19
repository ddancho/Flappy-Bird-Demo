#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#define INCLUDE_GUID_DEVINTERFACE_HID
#include <raylib.h>
#include "textures.h"
#include "res_manager.h"
#include "state_manager.h"
#include "tube.h"
#include "bird.h"

void psPrepare(void);
void psUpdate(void);
void psRender(void);

#endif // PLAY_STATE_H
