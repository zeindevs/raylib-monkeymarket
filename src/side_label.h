#ifndef H_SIDE_LABEL
#define H_SIDE_LABEL

#include "enum.h"
#include <raylib.h>

typedef struct SideLabel
{
    WidgetChildType type;
    char date[16];
    float price;
    float bid;
    int offset;
} SideLabel;

void UpdateSideLabel(Rectangle bounds, SideLabel *label);
void RenderSideLabel(Rectangle bounds, SideLabel *label, Font *font);

#endif // !H_SIDE_LABEL
