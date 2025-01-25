#ifndef H_SIDE_WIDGET
#define H_SIDE_WIDGET

#include "enum.h"
#include <raylib.h>

typedef struct SideWidget
{
    WidgetType type;
    char *title;
    Font *font;
    Rectangle bounds;
    int width;
    int height;
    float round;
} SideWidget;

void UpdateSideWidget(SideWidget *widget);
void RenderSideWidget(SideWidget *widget);

#endif // !H_SIDE_WIDGET
