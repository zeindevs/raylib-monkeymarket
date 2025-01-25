#include "app.h"
#include "chart_widget.h"
#include "enum.h"
#include "side_panel.h"
#include <stdio.h>
#include <stdlib.h>

void Update(App *app)
{
    for (int i = 0; i < app->size; i++)
    {
        WidgetType tag = *((WidgetType *)app->child[i]);
        switch (tag)
        {
        case WIDGET_CHART:
            UpdateChartWidget(app->child[i]);
            break;
        case WIDGET_SIDE:
            UpdateSideWidget(app->child[i]);
            break;
        }
    }
}

void Render(App *app)
{
    for (int i = 0; i < app->size; i++)
    {
        WidgetType tag = *((WidgetType *)app->child[i]);
        switch (tag)
        {
        case WIDGET_CHART:
            RenderChartWidget(app->child[i]);
            break;
        case WIDGET_SIDE:
            RenderSideWidget(app->child[i]);
            break;
        }
    }
}

void AddChild(App *app, void *widget)
{
    app->child = realloc(app->child, (app->size + 1) * sizeof(void *));
    if (app->child == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    app->child[app->size] = widget;
    app->size++;
}
