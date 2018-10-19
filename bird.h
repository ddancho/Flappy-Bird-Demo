#ifndef BIRD_H
#define BIRD_H

#define INCLUDE_GUID_DEVINTERFACE_HID
#include <raylib.h>
#include "res_manager.h"

void bPrepare(void);
void bUpdate(void);
void bDraw(void);
void bJump(void);
Vector2* getBirdPosition(void);
Rectangle* getBirdRecTangle(void);

#endif // BIRD_H
