#ifndef SIDE_PROGRESS_H
#define SIDE_PROGRESS_H

#include "enum.h"
#include <raylib.h>
typedef struct SideProgress
{
    WidgetChildType type;
    float price;
    float bid;
    float rate;
    int offset;
    Color color;
} SideProgress;

void UpdateSideProgress(Rectangle bounds, SideProgress *progess);
void RenderSideProgress(Rectangle bounds, SideProgress *progess, Font *font);

#endif // !SIDE_PROGRESS_H
