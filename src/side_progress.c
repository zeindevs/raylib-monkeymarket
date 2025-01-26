#include "side_progress.h"
#include <raylib.h>
#include <stdio.h>

void UpdateSideProgress(Rectangle bounds, SideProgress *progress)
{
}

void RenderSideProgress(Rectangle bounds, SideProgress *progress, Font *font)
{
    Vector2 posPrice = {.x = bounds.x + 10, .y = bounds.y + progress->offset + 20};
    Vector2 posBid = {.x = bounds.x + bounds.width / 2 - 10, .y = bounds.y + progress->offset + 20};
    Vector2 posDate = {.x = bounds.x + bounds.width - 40, .y = bounds.y + progress->offset + 20};

    char priceTxt[16];
    char bidTxt[16];
    char rateTxt[16];
    sprintf(priceTxt, "%.2f", progress->price);
    sprintf(bidTxt, "%.2f", progress->bid);
    sprintf(rateTxt, "%.2f", progress->rate);

    Vector2 measure = MeasureTextEx(*font, priceTxt, 14, 0);
    Rectangle rec = {.x = bounds.x, .y = bounds.y + progress->offset + 16, .width = bounds.width, .height = measure.y + 6};

    DrawRectangleRec(rec, ColorAlpha(progress->color, 0.3));
    rec.width = bounds.width * (progress->rate / 100);
    rec.x = bounds.x + bounds.width - rec.width;
    DrawRectangleRec(rec, ColorAlpha(progress->color, 0.5));

    DrawTextEx(*font, priceTxt, posPrice, 14, 0, ColorAlpha(progress->color, 1));
    DrawTextEx(*font, bidTxt, posBid, 14, 0, WHITE);
    DrawTextEx(*font, rateTxt, posDate, 14, 0, WHITE);
}
