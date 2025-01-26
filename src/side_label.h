#ifndef SIDE_LABEL_H
#define SIDE_LABEL_H

#include "enum.h"
#include <raylib.h>

typedef struct SideLabel
{
    WidgetChildType type;
    char date[16];
    float price;
    float bid;
    int offset;
    Color color;
} SideLabel;

void UpdateSideLabel(Rectangle bounds, SideLabel *label);
void RenderSideLabel(Rectangle bounds, SideLabel *label, Font *font);

#endif // !SIDE_LABEL_H
