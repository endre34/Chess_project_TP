#include <stdio.h>

#include <SFML/Graphics.h>

#include "button.h"


int main(int argc, char* argv[])
{
    sfRenderWindow* window = sfRenderWindow_create((sfVideoMode){400, 400, 8}, "Chess: The Game", 0x0, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    sfRectangleShape* rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectangle, (sfVector2f){100.0f, 100.0f});
    sfRectangleShape_setSize(rectangle, (sfVector2f){100.0f, 100.0f});
    sfRectangleShape_setFillColor(rectangle, sfWhite);

    sfEvent event;


    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
        sfRenderWindow_display(window);
        
    }

    sfRenderWindow_destroy(window);


    return 0;
}
