#ifndef Y_AXIS_H
#define Y_AXIS_H

#include <raylib.h>

typedef struct YAxis
{
    float value;
    Vector2 pos;
    int space;
} YAxis;

void UpdateYAxis(Rectangle bounds, YAxis *YAxis);
void RenderYAxis(Rectangle bounds, YAxis *YAxis, Font *font);

#endif // !Y_AXIS_H
