#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.h>

#include "interactables.h"


/* Lifecycle */
sfButton* sfButton_create(void);
sfButton* sfButton_copy(const sfButton*);
void sfButton_destroy(sfButton*);

/* General manipulation */
void sfButton_setSize(sfButton*, sfVector2f);
sfVector2f sfButton_getSize(const sfButton*);

void sfButton_setPosition(sfButton*, sfVector2f);
sfVector2f sfButton_getPosition(const sfButton*);

void sfButton_setOrigin(sfButton*, sfVector2f);
sfVector2f sfButton_getOrigin(const sfButton*);

/* Fill color manipulation */
void sfButton_setFillColor(sfButton*, sfColor);
sfColor sfButton_getFillColor(const sfButton*);

/* Text manipulation */
void sfButton_setTextString(sfButton*, const char*);
const char* sfButton_getTextString(const sfButton*);

void sfButton_setTextFont(sfButton*, const sfFont*);
const sfFont* sfButton_getTextFont(const sfButton*);

void sfButton_setCharacterSize(sfButton*, unsigned int);
unsigned int sfButton_getCharacterSize(const sfButton*);

void sfButton_setLetterSpacing(sfButton*, float);
float sfButton_getLetterSpacing(const sfButton*);

void sfButton_setTextColor(sfButton*, sfColor);
sfColor sfButton_getTextColor(const sfButton*);

/* Texture manipulation */
void sfButton_setTexture(sfButton*, const sfTexture*, sfBool);
const sfTexture* sfButton_getTexture(const sfButton*);

void sfButton_setTextureRect(sfButton*, sfIntRect);
sfIntRect sfButton_getTextureRect(const sfButton*);

/* Outline manipulation */
void sfButton_setOutlineColor(sfButton*, sfColor);
sfColor sfButton_getOutlineColor(const sfButton*);

void sfButton_setOutlineThickness(sfButton*, float);
float sfButton_getOutlineThickness(const sfButton*);

/* Utility */
sfFloatRect sfButton_getGlobalBounds(const sfButton*);
void sfButton_draw(sfRenderWindow*, const sfButton*);

#endif // BUTTON_H