/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** animations
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

void cursor_mvt(sfRenderWindow *window, bg_t *bg)
{
    int x = 10;
    int y = 10;

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    bg->cursor_pos.x = sfMouse_getPositionRenderWindow(window).x - x;
    bg->cursor_pos.y = sfMouse_getPositionRenderWindow(window).y - y;
    sfSprite_setPosition(bg->cursor_spr, bg->cursor_pos);
    sfRenderWindow_drawSprite(window, bg->cursor_spr, NULL);
}

void animation_loop(enemy_t *enemy)
{
    if (enemy->time > 75) {
        animation(enemy);
        animate_bonus(enemy);
        sfSprite_setPosition(enemy->enemy_sprite, enemy->pos);
        sfClock_restart(enemy->animation);
    }
}

void health(bg_t *bg, enemy_t *enemy, sfRenderWindow *window, audio_t *audio)
{
    bg->rect_bar.width = enemy->health * 12;
    sfSprite_setTextureRect(bg->health_bar, bg->rect_bar);
    sfSprite_setPosition(bg->health_bar, (sfVector2f){30, 10});
    sfRenderWindow_drawSprite(window, bg->health_bar, NULL);
    if (enemy->pos.x >= 2000) {
        enemy->pos = (sfVector2f){-300, 400};
        enemy->health -= 1;
        hurt_sound(audio);
        enemy->speed *= 0.9;
    }
    if (enemy->health <= 0) {
        death_sound(audio);
        sfRenderWindow_drawSprite(window, bg->ending_spr, NULL);
        sfRenderWindow_display(window);
        sfSleep(sfSeconds(2));
        sfRenderWindow_close(window);
    }
}

void animation(enemy_t *enemy)
{
    static int current_frame = 0;

    current_frame = (current_frame + 1) % 4;
    enemy->rect.left = current_frame * enemy->rect.width;
    enemy->pos.x += enemy->speed;
}

void animate_bonus(enemy_t *enemy)
{
    if (enemy->bonus_time >= 7) {
        enemy->bonus_pos = (sfVector2f){(10 + rand() % 1800), -10};
        sfSprite_setPosition(enemy->small_bonus_sp, enemy->bonus_pos);
        sfClock_restart(enemy->bonus_clock);
    }
    if (enemy->big_bonus_time >= 17) {
        enemy->big_bonus_pos = (sfVector2f){(10 + rand() % 1800), -10};
        sfSprite_setPosition(enemy->big_bonus_spr, enemy->big_bonus_pos);
        sfClock_restart(enemy->big_bonus_clock);
    }
    enemy->bonus_pos.y += enemy->bonus_speed;
    enemy->big_bonus_pos.y += enemy->bonus_speed;
    sfSprite_setPosition(enemy->small_bonus_sp, enemy->bonus_pos);
    sfSprite_setPosition(enemy->big_bonus_spr, enemy->big_bonus_pos);
}
