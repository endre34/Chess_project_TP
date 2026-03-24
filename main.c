#include <stdio.h>

#include <SFML/Graphics.h>


int main(int argc, char* argv[])
{
    sfRenderWindow* window = sfRenderWindow_create((sfVideoMode){400, 400, 8}, "Chess: The Game", 1 << 2, NULL);

    while (sfRenderWindow_isOpen(window))
    {

    }

    sfRenderWindow_destroy(window);
    return 0;
}
