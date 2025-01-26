#include "chart_widget.h"
#include <raylib.h>
#include <stdio.h>

void UpdateChartWidget(ChartWidget *widget)
{
    if (widget->zoom >= 0)
        widget->zoom += GetMouseWheelMove();
    else
        widget->zoom = 0;

    widget->bounds.width = (float)GetScreenWidth() * widget->width / widget->height;
    widget->bounds.height = GetScreenHeight() - 2;
    widget->mouseAxis.offsetTop = 30;

    UpdateMouseAxis(widget->bounds, &widget->mouseAxis);
    UpdateYAxis(widget->bounds, &widget->yAxis);
}

void RenderChartWidget(ChartWidget *widget)
{
    /*DrawRectangleRoundedLines(widget->bounds, widget->round, 1, GRAY);*/
    Rectangle rec = {.x = 0, .y = 0, .width = widget->bounds.width + 1, .height = 30};
    Vector2 pos = {.x = 10, .y = 9};

    DrawRectangleRounded(widget->bounds, widget->round, 1, BLACK);
    DrawRectangleRounded(rec, widget->round, 1, ColorAlpha(GRAY, 0.3));
    DrawTextEx(*widget->font, widget->title, pos, 14, 0, WHITE);

    char zoomStr[16];
    sprintf(zoomStr, "zoom: %d", widget->zoom);
    DrawTextEx(*widget->font, zoomStr, (Vector2){.x = 10, .y = 40}, 14, 0, WHITE);

    RenderYAxis(widget->bounds, &widget->yAxis, widget->font);
    RenderMouseAxis(widget->bounds, &widget->mouseAxis, widget->font);
}
