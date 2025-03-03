/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** more_setup
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio.h>
#include <SFML/Window/Mouse.h>
#include "../include/hunter.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void set_cursor(bg_t *bg, sfRenderWindow *window)
{
    bg->cursor_txt = sfTexture_createFromFile("Images/cursor.png", NULL);
    bg->cursor_spr = sfSprite_create();
    sfSprite_scale(bg->cursor_spr, (sfVector2f){0.5, 0.5});
    sfSprite_setTexture(bg->cursor_spr, bg->cursor_txt, sfTrue);
}

void set_big_bonus(enemy_t *enemy, sfRenderWindow *window)
{
    enemy->big_bonus_time = 0;
    enemy->bonus_time = 0;
    enemy->big_bonus_txt = sfTexture_createFromFile("Images/Bbonus.png", NULL);
    enemy->big_bonus_spr = sfSprite_create();
    sfSprite_scale(enemy->big_bonus_spr, (sfVector2f){0.3, 0.3});
    enemy->big_bonus_pos = (sfVector2f){(10 + rand() % 1800), -300};
    sfSprite_setPosition(enemy->big_bonus_spr, enemy->big_bonus_pos);
    sfSprite_setTexture(enemy->big_bonus_spr, enemy->big_bonus_txt, sfTrue);
}

void set_ending(bg_t *bg, sfRenderWindow *window)
{
    bg->ending_txt = sfTexture_createFromFile("Images/end.jpg", NULL);
    bg->ending_spr = sfSprite_create();
    sfSprite_scale(bg->ending_spr, (sfVector2f){1, 1});
    sfSprite_setTexture(bg->ending_spr, bg->ending_txt, sfTrue);
    sfSprite_setPosition(bg->ending_spr, (sfVector2f){0, 0});
}
