#ifndef MOUSE_H
#define MOUSE_H

#include <SFML/Window/Mouse.h>

typedef struct Mouse
{
    sfMouseButton button;
    bool pressed;

    int x;
    int y;
} Mouse;

#endif // MOUSE_H