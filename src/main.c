#include "app.h"
#include "chart_widget.h"
#include "enum.h"
#include "side_label.h"
#include "side_widget.h"
#include <raylib.h>

#define WIDTH 1080
#define HEIGHT 640
#define FPS 30

int main(int argc, char *argv[])
{
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
        labels[i] = (SideLabel){
            .type = WIDGET_SIDE_LABEL,
            .price = 10.00,
            .bid = 10.00,
            .date = "10:10:10",
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
