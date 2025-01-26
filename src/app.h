#ifndef APP_H
#define APP_H

#include <raylib.h>

typedef struct App
{
    Font font;
    void **child;
    int size;
} App;

void Update(App *app);
void Render(App *app);
void AddWidget(App *app, void *widget);

#endif // !APP_H
