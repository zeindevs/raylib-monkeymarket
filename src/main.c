#include "app.h"
#include "widgets/chart_widget.h"
#include "widgets/enum.h"
#include "widgets/side_label.h"
#include "widgets/side_progress.h"
#include "widgets/side_widget.h"
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1080
#define HEIGHT 640
#define FPS 30

int randomInt(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(WIDTH, HEIGHT, "Monkey Market v0.1");

    SetTargetFPS(FPS);

    App app = {.font = LoadFont("assets/fonts/Roboto-Regular.ttf")};

    ChartWidget chartWidget = {
        .type = WIDGET_CHART,
        .title = "Main Panel",
        .width = 75,
        .height = 100,
        .font = &app.font,
        .mouseAxis = (MouseAxis){.tick = 1, .color = ColorAlpha(GRAY, 0.3)},
        .yAxis = (YAxis){.value = 10.0, .space = 100},
    };
    AddWidget(&app, &chartWidget);

    SideWidget sideWidgetTop = {
        .type = WIDGET_SIDE,
        .title = "Side Panel Top",
        .width = 25,
        .height = 50,
        .font = &app.font,
    };
    AddWidget(&app, &sideWidgetTop);

    SideProgress progress[14];
    for (int i = 0; i < 14; i++)
    {
        Color color = RED;
        int rate = 10.00 * i;
        if (i >= 7)
        {
            color = GREEN;
            rate = 10.00 * (14 - i);
        }
        progress[i] = (SideProgress){
            .type = WIDGET_SIDE_PROGRESS,
            .price = (float)randomInt(10, 100),
            .bid = (float)randomInt(10, 100),
            .rate = rate,
            .color = color,
        };
        AddSideWidget(&sideWidgetTop, &progress[i]);
    }

    SideWidget sideWidgetOne = {
        .type = WIDGET_SIDE,
        .title = "Side Panel 1",
        .width = 25,
        .height = 25,
        .font = &app.font,
    };
    AddWidget(&app, &sideWidgetOne);

    SideWidget sideWidgetTwo = {
        .type = WIDGET_SIDE,
        .title = "Side Panel 2",
        .width = 25,
        .height = 25,
        .font = &app.font,
    };
    AddWidget(&app, &sideWidgetTwo);

    SideLabel labels[10];
    for (int i = 0; i < 10; i++)
    {
        Color color = RED;
        if (randomInt(0, 1) == 1)
            color = GREEN;
        labels[i] = (SideLabel){
            .type = WIDGET_SIDE_LABEL,
            .price = (float)randomInt(10, 100),
            .bid = (float)randomInt(1, 10),
            .date = "10:10:10",
            .color = color,
        };
        AddSideWidget(&sideWidgetOne, &labels[i]);
        AddSideWidget(&sideWidgetTwo, &labels[i]);
    }

    while (!WindowShouldClose())
    {
        Update(&app);

        BeginDrawing();

        ClearBackground(BLACK);

        Render(&app);

        DrawFPS(10, GetScreenHeight() - 25);

        EndDrawing();
    }

    UnloadFont(app.font);
    CloseWindow();
    return 0;
}
