#include "app.h"
#include "chart_widget.h"
#include "enum.h"
#include "side_panel.h"
#include <raylib.h>

#define WIDTH 1080
#define HEIGHT 640
#define FPS 60

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
    AddChild(&app, &chartWidget);

    SideWidget sideWidget = {
        .type = WIDGET_SIDE,
        .title = "Side Panel",
        .width = 25,
        .height = 100,
        .font = &app.font,
    };

    AddChild(&app, &sideWidget);

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
