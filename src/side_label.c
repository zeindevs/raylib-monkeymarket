#include "side_label.h"
#include <raylib.h>
#include <stdio.h>

void UpdateSideLabel(Rectangle bounds, SideLabel *label)
{
}

void RenderSideLabel(Rectangle bounds, SideLabel *label, Font *font)
{
    Vector2 posPrice = {.x = bounds.x + 10, .y = bounds.y + label->offset + 20};
    Vector2 posBid = {.x = bounds.x + bounds.width / 2 - 10, .y = bounds.y + label->offset + 20};
    Vector2 posDate = {.x = bounds.x + bounds.width - 55, .y = bounds.y + label->offset + 20};

    char priceTxt[16];
    char bidTxt[16];
    sprintf(priceTxt, "%.2f", label->price);
    sprintf(bidTxt, "%.2f", label->bid);

    DrawTextEx(*font, priceTxt, posPrice, 14, 0, ColorAlpha(label->color, 1));
    DrawTextEx(*font, bidTxt, posBid, 14, 0, WHITE);
    DrawTextEx(*font, label->date, posDate, 14, 0, WHITE);
}
