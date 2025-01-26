#ifndef H_APP
#define H_APP

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

#endif // !H_APP
