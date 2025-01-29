#include "y_axis.h"
#include <raylib.h>
#include <stdio.h>

void UpdateYAxis(Rectangle bounds, YAxis *yAxis)
{
}

void RenderYAxis(Rectangle bounds, YAxis *yAxis, Font *font)
{
    Rectangle rec = {.x = bounds.width - 80, .y = 30, .width = 80, .height = bounds.height - 29};
    Vector2 startPos = {.x = 0, .y = bounds.height / 2};
    Vector2 endPos = {.x = rec.x, .y = startPos.y};

    DrawLineEx(startPos, endPos, 1, ColorAlpha(GRAY, 0.3));
    DrawRectangleRec(rec, ColorAlpha(GRAY, 0.1));

    int offset = 0;
    for (float val = 0.0; val < yAxis->value; val += 0.1)
    {
        int textY = endPos.y - offset - 5;
        if (textY < rec.y)
            break;
        char valueText[16];
        sprintf(valueText, "%.2f", val);
        Vector2 textMeasure = MeasureTextEx(*font, valueText, 14, 0);
        Vector2 pos = {.x = rec.x + rec.width - textMeasure.x - 5, .y = textY};
        DrawTextEx(*font, valueText, pos, 14, 0, GRAY);
        offset += yAxis->space;
    }
}
