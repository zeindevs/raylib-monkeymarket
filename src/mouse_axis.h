#ifndef MOUSE_AXIS_H
#define MOUSE_AXIS_H

#include <raylib.h>

typedef struct MouseAxis
{
    Vector2 startPosV;
    Vector2 endPosV;
    Vector2 startPosH;
    Vector2 endPosH;
    int offsetTop;
    Color color;
    int tick;
} MouseAxis;

void UpdateMouseAxis(Rectangle bounds, MouseAxis *mouseAxis);
void RenderMouseAxis(Rectangle bounds, MouseAxis *mouseAxis, Font *font);

#endif // !MOUSE_AXIS_H
