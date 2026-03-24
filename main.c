#include <stdio.h>

#include <SFML/Graphics.h>


int main(int argc, char* argv[])
{
    sfRenderWindow* window = sfRenderWindow_create((sfVideoMode){400, 400, 8}, "Chess: The Game", 0x4, NULL);

    sfEvent event;

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
            }
        }

        sfRenderWindow_clear(window, (sfColor){100, 100, 100, 255});
        sfRenderWindow_display(window);
        
    }

    sfRenderWindow_destroy(window);


    return 0;
}
