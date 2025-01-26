#include "side_widget.h"
#include "enum.h"
#include "side_label.h"
#include "side_progress.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void UpdateSideWidget(SideWidget *widget)
{
    widget->bounds.width = GetScreenWidth() * (float)widget->width / 100;
    widget->bounds.height = GetScreenHeight() * (float)widget->height / 100;

    for (int i = 0; i < widget->size; i++)
    {
        WidgetChildType tag = *((WidgetChildType *)widget->child[i]);
        switch (tag)
        {
        case WIDGET_SIDE_LABEL:
            SideLabel *label = widget->child[i];
            label->offset = (i + 1) * 20;
            UpdateSideLabel(widget->bounds, label);
            break;
        case WIDGET_SIDE_PROGRESS:
            SideProgress *progress = widget->child[i];
            progress->offset = (i + 1) * 20;
            UpdateSideProgress(widget->bounds, progress);
            break;
        }
    }
}

void RenderSideWidget(SideWidget *widget)
{
    /*DrawRectangleRoundedLines(widget->bounds, widget->round, 1, GRAY);*/
    Rectangle rec = {.x = 0, .y = widget->offset, .width = widget->bounds.width + 1, .height = 30};
    Vector2 pos = {.x = 10, .y = widget->offset + 9};
    widget->bounds.x = GetScreenWidth() - widget->bounds.width;
    widget->bounds.y = widget->offset;
    rec.x = GetScreenWidth() - widget->bounds.width;
    pos.x = rec.x + 10;
    DrawRectangleRounded(widget->bounds, widget->round, 1, BLACK);
    DrawRectangleRounded(rec, widget->round, 1, ColorAlpha(GRAY, 0.3));
    DrawTextEx(*widget->font, widget->title, pos, 14, 0, WHITE);

    for (int i = 0; i < widget->size; i++)
    {
        WidgetChildType tag = *((WidgetChildType *)widget->child[i]);
        switch (tag)
        {
        case WIDGET_SIDE_LABEL:
            RenderSideLabel(widget->bounds, widget->child[i], widget->font);
            break;
        case WIDGET_SIDE_PROGRESS:
            RenderSideProgress(widget->bounds, widget->child[i], widget->font);
            break;
        }
    }
}
void AddSideWidget(SideWidget *widget, void *child)
{
    widget->child = realloc(widget->child, (widget->size + 1) * sizeof(void *));
    if (widget->child == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    widget->child[widget->size] = child;
    widget->size++;
}
