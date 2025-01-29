#include "app.h"
#include "widgets/chart_widget.h"
#include "widgets/enum.h"
#include "widgets/side_widget.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void Update(App *app)
{
    int sw = 0;
    for (int i = 0; i < app->size; i++)
    {
        WidgetType tag = *((WidgetType *)app->child[i]);
        switch (tag)
        {
        case WIDGET_CHART:
            UpdateChartWidget(app->child[i]);
            break;
        case WIDGET_SIDE:
            SideWidget *side = app->child[i];
            if (sw > 0)
            {
                SideWidget *sideRoot = app->child[i - 1];
                side->offset = sideRoot->bounds.y + sideRoot->bounds.height;
            }
            UpdateSideWidget(side);
            sw++;
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

void AddWidget(App *app, void *widget)
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
