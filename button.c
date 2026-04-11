#include "button.h"

#include <stdlib.h>

struct sfButton
{
    sfRectangleShape* shape;
    sfText* text;
};

static void sfButton_updateTextPosition(sfButton* button)
{
    sfFloatRect textBounds;
    sfVector2f buttonPosition;
    sfVector2f buttonSize;
    sfVector2f buttonOrigin;

    textBounds = sfText_getLocalBounds(button->text);

    buttonPosition = sfRectangleShape_getPosition(button->shape);
    buttonSize = sfRectangleShape_getSize(button->shape);
    buttonOrigin = sfRectangleShape_getOrigin(button->shape);

    sfText_setOrigin(
        button->text,
        (sfVector2f){
            textBounds.left + textBounds.width / 2.0f,
            textBounds.top + textBounds.height / 2.0f
        }
    );

    sfText_setPosition(
        button->text,
        (sfVector2f){
            buttonPosition.x + buttonSize.x / 2.0f - buttonOrigin.x,
            buttonPosition.y + buttonSize.y / 2.0f - buttonOrigin.y
        }
    );
}

sfButton* sfButton_create(void)
{
    sfButton* button;

    button = malloc(sizeof(*button));

    button->shape = sfRectangleShape_create();
    button->text = sfText_create();

    sfRectangleShape_setSize(button->shape, (sfVector2f){0.0f, 0.0f});
    sfRectangleShape_setPosition(button->shape, (sfVector2f){0.0f, 0.0f});
    sfRectangleShape_setOrigin(button->shape, (sfVector2f){0.0f, 0.0f});
    sfRectangleShape_setFillColor(button->shape, sfWhite);
    sfRectangleShape_setOutlineColor(button->shape, sfBlack);
    sfRectangleShape_setOutlineThickness(button->shape, 0.0f);

    sfText_setString(button->text, "");
    sfText_setCharacterSize(button->text, 30);
    sfText_setLetterSpacing(button->text, 1.0f);
    sfText_setFillColor(button->text, sfBlack);

    sfButton_updateTextPosition(button);

    return button;
}

sfButton* sfButton_copy(const sfButton* button)
{
    sfButton* copy;

    copy = malloc(sizeof(*copy));

    copy->shape = sfRectangleShape_copy(button->shape);
    copy->text = sfText_copy(button->text);

    sfButton_updateTextPosition(copy);

    return copy;
}

void sfButton_destroy(sfButton* button)
{
    sfRectangleShape_destroy(button->shape);
    sfText_destroy(button->text);
    free(button);
}

void sfButton_setSize(sfButton* button, sfVector2f size)
{
    sfRectangleShape_setSize(button->shape, size);
    sfButton_updateTextPosition(button);
}

sfVector2f sfButton_getSize(const sfButton* button)
{
    return sfRectangleShape_getSize(button->shape);
}

void sfButton_setPosition(sfButton* button, sfVector2f position)
{
    sfRectangleShape_setPosition(button->shape, position);
    sfButton_updateTextPosition(button);
}

sfVector2f sfButton_getPosition(const sfButton* button)
{
    return sfRectangleShape_getPosition(button->shape);
}

void sfButton_setOrigin(sfButton* button, sfVector2f origin)
{
    sfRectangleShape_setOrigin(button->shape, origin);
    sfButton_updateTextPosition(button);
}

sfVector2f sfButton_getOrigin(const sfButton* button)
{
    return sfRectangleShape_getOrigin(button->shape);
}

void sfButton_setFillColor(sfButton* button, sfColor color)
{
    sfRectangleShape_setFillColor(button->shape, color);
}

sfColor sfButton_getFillColor(const sfButton* button)
{
    return sfRectangleShape_getFillColor(button->shape);
}

void sfButton_setTexture(sfButton* button, const sfTexture* texture, sfBool resetRect)
{
    sfRectangleShape_setTexture(button->shape, texture, resetRect);
}

const sfTexture* sfButton_getTexture(const sfButton* button)
{
    return sfRectangleShape_getTexture(button->shape);
}

void sfButton_setTextureRect(sfButton* button, sfIntRect textureRect)
{
    sfRectangleShape_setTextureRect(button->shape, textureRect);
}

sfIntRect sfButton_getTextureRect(const sfButton* button)
{
    return sfRectangleShape_getTextureRect(button->shape);
}

void sfButton_setTextString(sfButton* button, const char* string)
{
    sfText_setString(button->text, string);
    sfButton_updateTextPosition(button);
}

const char* sfButton_getTextString(const sfButton* button)
{
    return sfText_getString(button->text);
}

void sfButton_setTextFont(sfButton* button, const sfFont* font)
{
    sfText_setFont(button->text, font);
    sfButton_updateTextPosition(button);
}

const sfFont* sfButton_getTextFont(const sfButton* button)
{
    return sfText_getFont(button->text);
}

void sfButton_setCharacterSize(sfButton* button, unsigned int size)
{
    sfText_setCharacterSize(button->text, size);
    sfButton_updateTextPosition(button);
}

unsigned int sfButton_getCharacterSize(const sfButton* button)
{
    return sfText_getCharacterSize(button->text);
}

void sfButton_setLetterSpacing(sfButton* button, float spacing)
{
    sfText_setLetterSpacing(button->text, spacing);
    sfButton_updateTextPosition(button);
}

float sfButton_getLetterSpacing(const sfButton* button)
{
    return sfText_getLetterSpacing(button->text);
}

void sfButton_setTextColor(sfButton* button, sfColor color)
{
    sfText_setFillColor(button->text, color);
}

sfColor sfButton_getTextColor(const sfButton* button)
{
    return sfText_getFillColor(button->text);
}

void sfButton_setOutlineColor(sfButton* button, sfColor color)
{
    sfRectangleShape_setOutlineColor(button->shape, color);
}

sfColor sfButton_getOutlineColor(const sfButton* button)
{
    return sfRectangleShape_getOutlineColor(button->shape);
}

void sfButton_setOutlineThickness(sfButton* button, float thickness)
{
    sfRectangleShape_setOutlineThickness(button->shape, thickness);
    sfButton_updateTextPosition(button);
}

float sfButton_getOutlineThickness(const sfButton* button)
{
    return sfRectangleShape_getOutlineThickness(button->shape);
}

sfFloatRect sfButton_getGlobalBounds(const sfButton* button)
{
    return sfRectangleShape_getGlobalBounds(button->shape);
}

void sfButton_draw(sfRenderWindow* window, const sfButton* button)
{
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}