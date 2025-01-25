#include "mouse_axis.h"
#include <raylib.h>

void UpdateMouseAxis(Rectangle bounds, MouseAxis *mouseAxis)
{
    if (CheckCollisionPointRec(GetMousePosition(), bounds))
    {
        if (GetMousePosition().y >= mouseAxis->offsetTop + 10)
        {
            mouseAxis->startPosH.x = 0;
            mouseAxis->startPosH.y = GetMousePosition().y;
            mouseAxis->endPosH.x = bounds.width;
            mouseAxis->endPosH.y = GetMousePosition().y;
        }
        else
        {
            mouseAxis->startPosH.y = mouseAxis->offsetTop + 10;
            mouseAxis->endPosH.y = mouseAxis->offsetTop + 10;
        }

        if (GetMousePosition().x <= bounds.width - 80)
        {
            mouseAxis->startPosV.x = GetMousePosition().x;
            mouseAxis->startPosV.y = mouseAxis->offsetTop;
            mouseAxis->endPosV.x = GetMousePosition().x;
            mouseAxis->endPosV.y = bounds.width;
        }
        else
        {
            mouseAxis->startPosV.x = bounds.width - 80;
            mouseAxis->endPosV.x = bounds.width - 80;
        }
    }
}

void RenderMouseAxis(Rectangle bounds, MouseAxis *mouseAxis, Font *font)
{
    DrawLineEx(mouseAxis->startPosH, mouseAxis->endPosH, mouseAxis->tick, mouseAxis->color);
    char *labelH = "0.00";
    Vector2 labelHWidth = MeasureTextEx(*font, labelH, 14, 0);
    Vector2 labelHPos = {.x = bounds.width - (labelHWidth.x + 5), .y = mouseAxis->endPosH.y - 5};
    DrawRectangle(labelHPos.x - 4, labelHPos.y - 4, labelHWidth.x + 10, 20, WHITE);
    DrawTextEx(*font, labelH, labelHPos, 14, 0, BLACK);

    DrawLineEx(mouseAxis->startPosV, mouseAxis->endPosV, mouseAxis->tick, mouseAxis->color);
    char *labelV = "10:10:10";
    Vector2 labelVWidth = MeasureTextEx(*font, labelV, 14, 0);
    Vector2 labelVPos = {.x = mouseAxis->startPosV.x - (labelVWidth.x / 2), .y = bounds.height - 16};
    DrawRectangle(labelVPos.x - 4, labelVPos.y - 4, labelVWidth.x + 10, 20, WHITE);
    DrawTextEx(*font, labelV, labelVPos, 14, 0, BLACK);
}
