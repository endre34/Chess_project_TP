#ifndef __INTERACTABLE_H
#define __INTERACTABLE_H

#include <SFML/Graphics.h>

#include "interactables.h"


sfButton* sfButton_create(void);

// // General manipulation
void sfButton_setSize(sfButton*, const sfVector2f);
sfVector2f sfButton_getSize(sfButton*);

void sfButton_setPosition(sfButton*, const sfVector2f);
sfVector2f sfButton_getPosition(sfButton*);

void sfButton_setOrigin(sfButton*, const sfVector2f);
sfVector2f sfButton_getOrigin(sfButton*);

// // // Looks
// // Inside
void sfButton_setFillColor(sfButton*, const sfColor);
sfColor sfButton_getFillColor(sfButton*);

// Text
void sfButton_setTextString(sfButton*, const char*);
const char* sfButton_getTextString(sfButton*);

void sfButton_setTextFont(sfButton*, const sfFont*);

void sfButton_setCharacterSize(sfButton*, unsigned int);

void sfButton_setCharacterSpacing(sfButton*, float);

void sfButton_setTextColor(sfButton*, sfColor);

// // Outside
void sfButton_setOutlilneColor(sfButton*, const sfColor);
sfColor sfButton_getOulineColor(sfButton*);

void sfButton_setOutlineThickness(sfButton*, const float);
float sfButton_getOulineThicness(sfButton*);



sfFloatRect sfButton_getGlobalBounds(sfButton*);



void sfButton_destroy(sfButton*);


#endif // __INTERACTABLE_H