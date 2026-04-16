#include <stdio.h>

#include <SFML/Graphics.h>



int main(int argc, char* argv[])
{
    sfTexture* background = sfTexture_createFromFile("media/textures/background.png", NULL);
    sfTexture* board = sfTexture_createFromFile("media/textures/board.png", NULL);
    sfTexture* buttons = sfTexture_createFromFile("media/textures/buttons.png", NULL);
    sfTexture* pieces = sfTexture_createFromFile("media/textures/pieces.png", NULL);
    sfTexture* sideBoard = sfTexture_createFromFile("media/textures/sideboard.png", NULL);
    sfTexture* timeBoard = sfTexture_createFromFile("media/textures/time_board.png", NULL);
    sfTexture* titleBoard = sfTexture_createFromFile("media/textures/title_board.png", NULL);


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
