#ifndef H_APP
#define H_APP

#include "mouse_axis.h"
#include "panel.h"
#include "y_axis.h"

typedef struct App
{
    Font font;
    void **child;
    int size;
} App;

void Update(App *app);
void Render(App *app);
void AddChild(App *app, void *widget);

#endif // !H_APP
