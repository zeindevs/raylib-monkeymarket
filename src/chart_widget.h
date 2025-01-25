#ifndef H_CHART_WIDGET
#define H_CHART_WIDGET

#include "enum.h"
#include "mouse_axis.h"
#include "y_axis.h"
#include <raylib.h>

typedef struct ChartWidget
{
    WidgetType type;
    char *title;
    Font *font;
    Rectangle bounds;
    int zoom;
    int width;
    int height;
    float round;
    YAxis yAxis;
    MouseAxis mouseAxis;
} ChartWidget;

void UpdateChartWidget(ChartWidget *widget);
void RenderChartWidget(ChartWidget *widget);

#endif // !H_CHART_WIDGET
