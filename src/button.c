#include "button.h"

#include <stdlib.h>
#include "ui_utils.h"

typedef enum State
{
    idle,
    hovered,
    pressed

} State;

typedef struct TextureInfo
{
    sfIntRect idle;
    sfBool idleAvailability;

    sfIntRect hover;
    sfBool hoverAvailability;

    sfIntRect press;
    sfBool pressAvailability;

} TextureInfo;

struct Button
{
    sfRectangleShape* shape;
    sfText* text;

    TextureInfo textureInfo;
    State state;

    buttonAction action;
    void* actionData;
};

static void button_updateTextPosition(Button* button)
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

static sfIntRect button_getOptionalIntRect(sfBool available, sfIntRect rect)
{
    if (available)
        return rect;

    return ZeroRect;
}

Button* button_create(void)
{
    Button* button;

    button = malloc(sizeof(Button));

    button->shape = sfRectangleShape_create();
    button->text = sfText_create();

    button->textureInfo.idle = (sfIntRect){0};
    button->textureInfo.idleAvailability = sfFalse;

    button->textureInfo.hover = (sfIntRect){0};
    button->textureInfo.hoverAvailability = sfFalse;

    button->textureInfo.press = (sfIntRect){0};
    button->textureInfo.pressAvailability = sfFalse;

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

    button_updateTextPosition(button);

    return button;
}

Button* button_copy(const Button* button)
{
    Button* copy;

    copy = malloc(sizeof(Button));

    copy->shape = sfRectangleShape_copy(button->shape);
    copy->text = sfText_copy(button->text);

    button_updateTextPosition(copy);

    return copy;
}

void button_destroy(Button* button)
{
    sfRectangleShape_destroy(button->shape);
    sfText_destroy(button->text);
    free(button);
}

void button_setSize(Button* button, sfVector2f size)
{
    sfRectangleShape_setSize(button->shape, size);
    button_updateTextPosition(button);
}

sfVector2f button_getSize(const Button* button)
{
    return sfRectangleShape_getSize(button->shape);
}

void button_setPosition(Button* button, sfVector2f position)
{
    sfRectangleShape_setPosition(button->shape, position);
    button_updateTextPosition(button);
}

sfVector2f button_getPosition(const Button* button)
{
    return sfRectangleShape_getPosition(button->shape);
}

void button_setOrigin(Button* button, sfVector2f origin)
{
    sfRectangleShape_setOrigin(button->shape, origin);
    button_updateTextPosition(button);
}

sfVector2f button_getOrigin(const Button* button)
{
    return sfRectangleShape_getOrigin(button->shape);
}

void button_setFillColor(Button* button, sfColor color)
{
    sfRectangleShape_setFillColor(button->shape, color);
}

sfColor button_getFillColor(const Button* button)
{
    return sfRectangleShape_getFillColor(button->shape);
}

void button_setTexture(Button* button, const sfTexture* texture, sfBool resetRect)
{
    sfRectangleShape_setTexture(button->shape, texture, resetRect);
}

const sfTexture* button_getTexture(const Button* button)
{
    return sfRectangleShape_getTexture(button->shape);
}

void button_setTextureRect_onIdle(Button* button, sfIntRect idle)
{
    button->textureInfo.idle = idle;

    button->textureInfo.idleAvailability = (sfVector2i_cmp(sfIntRect_getSize(&idle), ZeroIntVect)) ? sfFalse : sfTrue;
}

sfIntRect button_getTextureRect_onIdle(const Button* button)
{
    return button_getOptionalIntRect(button->textureInfo.idleAvailability, button->textureInfo.idle);
}

void button_setTextureRect_onHover(Button* button, sfIntRect hover)
{
    button->textureInfo.hover = hover;

    button->textureInfo.hoverAvailability = (sfVector2i_cmp(sfIntRect_getSize(&hover), ZeroIntVect)) ? sfFalse : sfTrue;
}

sfIntRect button_getTextureRect_onHover(const Button* button)
{
    return button_getOptionalIntRect(button->textureInfo.hoverAvailability, button->textureInfo.hover);
}

void button_setTextureRect_onPress(Button* button, sfIntRect press)
{
    button->textureInfo.press = press;

    button->textureInfo.pressAvailability = (sfVector2i_cmp(sfIntRect_getSize(&press), ZeroIntVect)) ? sfFalse : sfTrue;
}

sfIntRect button_getTextureRect_onPress(const Button* button)
{
    return button_getOptionalIntRect(button->textureInfo.pressAvailability, button->textureInfo.press);
}

void button_setTextString(Button* button, const char* string)
{
    sfText_setString(button->text, string);
    button_updateTextPosition(button);
}

const char* button_getTextString(const Button* button)
{
    return sfText_getString(button->text);
}

void button_setTextFont(Button* button, const sfFont* font)
{
    sfText_setFont(button->text, font);
    button_updateTextPosition(button);
}

const sfFont* button_getTextFont(const Button* button)
{
    return sfText_getFont(button->text);
}

void button_setCharacterSize(Button* button, unsigned int size)
{
    sfText_setCharacterSize(button->text, size);
    button_updateTextPosition(button);
}

unsigned int button_getCharacterSize(const Button* button)
{
    return sfText_getCharacterSize(button->text);
}

void button_setLetterSpacing(Button* button, float spacing)
{
    sfText_setLetterSpacing(button->text, spacing);
    button_updateTextPosition(button);
}

float button_getLetterSpacing(const Button* button)
{
    return sfText_getLetterSpacing(button->text);
}

void button_setTextColor(Button* button, sfColor color)
{
    sfText_setFillColor(button->text, color);
}

sfColor button_getTextColor(const Button* button)
{
    return sfText_getFillColor(button->text);
}

void button_setOutlineColor(Button* button, sfColor color)
{
    sfRectangleShape_setOutlineColor(button->shape, color);
}

sfColor button_getOutlineColor(const Button* button)
{
    return sfRectangleShape_getOutlineColor(button->shape);
}

void button_setOutlineThickness(Button* button, float thickness)
{
    sfRectangleShape_setOutlineThickness(button->shape, thickness);
    button_updateTextPosition(button);
}

float button_getOutlineThickness(const Button* button)
{
    return sfRectangleShape_getOutlineThickness(button->shape);
}

sfFloatRect button_getGlobalBounds(const Button* button)
{
    return sfRectangleShape_getGlobalBounds(button->shape);
}

void button_draw(sfRenderWindow* window, const Button* button)
{
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}