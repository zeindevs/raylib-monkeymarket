#ifndef CHART_WIDGET_H
#define CHART_WIDGET_H

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

#endif // !CHART_WIDGET_H
