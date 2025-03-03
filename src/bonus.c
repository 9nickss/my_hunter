/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** bonus
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

static sfMusic *big_bonus_sound(audio_t *audio)
{
    audio->big_bonus = sfMusic_createFromFile("Music/EL_MORDJENE.ogg");
    sfMusic_setVolume(audio->big_bonus, 100);
    sfMusic_play(audio->big_bonus);
    return audio->big_bonus;
}

sfMusic *bonus_sound(audio_t *audio)
{
    audio->lick = sfMusic_createFromFile("Music/lick2.ogg");
    sfMusic_setVolume(audio->lick, 100);
    sfMusic_play(audio->lick);
    return audio->lick;
}

void big_bonus(sfRenderWindow *window, enemy_t *enemy, audio_t *audio)
{
    big_bonus_sound(audio);
    enemy->health = 5;
    enemy->big_bonus_pos = (sfVector2f){-300, 2000};
}

void small_bonus(sfRenderWindow *window, enemy_t *enemy, audio_t *audio)
{
    bonus_sound(audio);
    enemy->score += 10;
    enemy->bonus_pos = (sfVector2f){-300, 2000};
}

void cl3(sfRenderWindow *window, enemy_t *enemy, audio_t *audio,
    sfMouseButtonEvent click)
{
    if (sfFloatRect_contains(&enemy->big_hitbox, click.x, click.y) == 1) {
        big_bonus(window, enemy, audio);
    } else
        enemy->health -= 1;
}

void cl2(sfRenderWindow *window, enemy_t *enemy, audio_t *audio,
    sfMouseButtonEvent click)
{
    enemy->big_hitbox = sfSprite_getGlobalBounds(enemy->big_bonus_spr);
    if (sfFloatRect_contains(&enemy->bs_hitbox, click.x, click.y) == 1) {
        small_bonus(window, enemy, audio);
    } else
        cl3(window, enemy, audio, click);
}
