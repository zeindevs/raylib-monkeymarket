#include "side_panel.h"
#include <raylib.h>

void UpdateSideWidget(SideWidget *widget)
{
    widget->bounds.width = (float)GetScreenWidth() * widget->width / widget->height;
    widget->bounds.height = GetScreenHeight() - 2;
}

void RenderSideWidget(SideWidget *widget)
{
    /*DrawRectangleRoundedLines(widget->bounds, widget->round, 1, GRAY);*/
    Rectangle rec = {.x = 0, .y = 0, .width = widget->bounds.width + 1, .height = 30};
    Vector2 pos = {.x = 10, .y = 9};
    widget->bounds.x = GetScreenWidth() - widget->bounds.width;
    rec.x = GetScreenWidth() - widget->bounds.width;
    pos.x = rec.x + 10;
    DrawRectangleRounded(widget->bounds, widget->round, 1, BLACK);
    DrawRectangleRounded(rec, widget->round, 1, ColorAlpha(GRAY, 0.3));
    DrawTextEx(*widget->font, widget->title, pos, 14, 0, WHITE);
}
