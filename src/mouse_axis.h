#ifndef H_MOUSE_AXIS
#define H_MOUSE_AXIS

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

#endif // !H_MOUSE_AXIS
