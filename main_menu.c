#include "main_menu.h"

#include "ui_elements.h"
#include "mouse.h"


struct mainMenu
{
    Button* play;
    Button* settings;
    Button* credits;

    DisplayField* titlebar;

    Mouse mouse;
};

