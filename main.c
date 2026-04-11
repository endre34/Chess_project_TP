#include <stdio.h>

#include <SFML/Graphics.h>

#include "button.h"


int main(int argc, char* argv[])
{
    sfTexture* background = sfTexture_createFromFile("background.png", NULL);
    sfTexture* buttons = sfTexture_createFromFile("buttons.png", NULL);
    sfTexture* pieces = sfTexture_createFromFile("pieces.png", NULL);

    sfRenderWindow* window = sfRenderWindow_create((sfVideoMode){400, 400, 8}, "Chess: The Game", 0x0, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    sfEvent event;
    while (sfRenderWindow_isOpen(window))
    {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
        
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape)
            {
                sfRenderWindow_close(window);
            }
        }
    }

    sfRenderWindow_destroy(window);


    return 0;
}
