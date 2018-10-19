#ifndef RES_MANAGER_H
#define RES_MANAFER_H

#define INCLUDE_GUID_DEVINTERFACE_HID
#include <raylib.h>
#include "textures.h"

void rmLoadResource(void);
void rmFreeResource(void);
Texture2D rmGetTexture2D(TexturesID texture);
Sound rmGetSound(void);
void rmResizeTexture(TexturesID texture, int w, int h);
void rmResizeTextureByRatio(TexturesID texture, float ratio);

#endif // RES_MANAGER_H

