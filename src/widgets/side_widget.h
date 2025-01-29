#ifndef SIDE_WIDGET_H
#define SIDE_WIDGET_H

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
    int offset;
    float round;
    int size;
    void **child;
} SideWidget;

void UpdateSideWidget(SideWidget *widget);
void RenderSideWidget(SideWidget *widget);
void AddSideWidget(SideWidget *widget, void *child);

#endif // !SIDE_WIDGET_H
