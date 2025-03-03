/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** events
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

void cli(sfRenderWindow *window, enemy_t *enemy, audio_t *audio, sfEvent event)
{
    sfMouseButtonEvent click;

    click = event.mouseButton;
    enemy->bs_hitbox = sfSprite_getGlobalBounds(enemy->small_bonus_sp);
    enemy->hitbox = sfSprite_getGlobalBounds(enemy->enemy_sprite);
    if (sfFloatRect_contains(&enemy->hitbox, click.x, click.y) == 1) {
        enemy_hit(window, enemy, audio);
    } else
        cl2(window, enemy, audio, click);
}

void events(sfRenderWindow *window, enemy_t *enemy, audio_t *audio, bg_t *bg)
{
    sfEvent event;
    sfMouseButtonEvent click;

    while (sfWindow_pollEvent((sfWindow *)window, &event)) {
        if (event.type == sfEvtClosed)
            sfWindow_close((sfWindow *)window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfWindow_close((sfWindow *)window);
        if (event.type == sfEvtMouseButtonPressed) {
            shot_sound(audio);
            cli(window, enemy, audio, event);
        }
    }
}

void enemy_hit(sfRenderWindow *window, enemy_t *enemy, audio_t *audio)
{
    enemy->max_speed = 115.0;
    hit_sound(audio);
    enemy->score++;
    if (enemy->speed < enemy->max_speed)
        enemy->speed *= 1.05;
    enemy->pos = (sfVector2f){-300, 150 + rand() % 750};
}

void spawn_bonus(enemy_t *enemy)
{
    enemy->big_bonus_time_elapsed =
        sfClock_getElapsedTime(enemy->big_bonus_clock);
    enemy->big_bonus_time = sfTime_asSeconds(enemy->big_bonus_time_elapsed);
    enemy->bonus_time_elpased = sfClock_getElapsedTime(enemy->bonus_clock);
    enemy->bonus_time = sfTime_asSeconds(enemy->bonus_time_elpased);
    sfSprite_setPosition(enemy->small_bonus_sp, enemy->bonus_pos);
    sfSprite_setPosition(enemy->big_bonus_spr, enemy->big_bonus_pos);
}
