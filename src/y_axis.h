#ifndef H_Y_AXIS
#define H_Y_AXIS

#include <raylib.h>

typedef struct YAxis
{
    float value;
    Vector2 pos;
    int space;
} YAxis;

void UpdateYAxis(Rectangle bounds, YAxis *YAxis);
void RenderYAxis(Rectangle bounds, YAxis *YAxis, Font *font);

#endif // !H_Y_AXIS
