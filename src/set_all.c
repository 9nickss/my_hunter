/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** set_all
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

void set_healthbar(bg_t *bg, enemy_t *enemy, sfRenderWindow *window)
{
    bg->health_bar_txt = sfTexture_createFromFile("Images/health.png", NULL);
    bg->health_bar = sfSprite_create();
    sfSprite_setTexture(bg->health_bar, bg->health_bar_txt, sfTrue);
    sfSprite_scale(bg->health_bar, (sfVector2f){5, 5});
    bg->rect_bar = (sfIntRect){10, 120, 60, 15};
}

void set_background(bg_t *bg)
{
    bg->bg_texture = sfTexture_createFromFile("Images/bg3.jpg", NULL);
    bg->bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg->bg_sprite, bg->bg_texture, sfTrue);
    sfSprite_scale(bg->bg_sprite, (sfVector2f){1.35, 1.3});
}

void set_enemy(enemy_t *enemy)
{
    enemy->speed = 24.0;
    enemy->max_speed = 150.0;
    enemy->enemy_texture = sfTexture_createFromFile("Images/feet1.png", NULL);
    enemy->enemy_sprite = sfSprite_create();
    enemy->enemy_dead_txt = sfTexture_createFromFile("Images/feet2.png", NULL);
    enemy->enemy_dead_spr = sfSprite_create();
    enemy->score_display = sfText_create();
    sfText_setCharacterSize(enemy->score_display, 50);
    sfText_setFont(enemy->score_display, enemy->font);
    sfSprite_scale(enemy->enemy_dead_spr, (sfVector2f){1.5, 2});
    enemy->rect = (sfIntRect) {12, 25, 250, 120};
    enemy->pos = (sfVector2f){-300, (150 + rand() % 750)};
    sfSprite_setPosition(enemy->enemy_sprite, enemy->pos);
    sfSprite_setTexture(enemy->enemy_sprite, enemy->enemy_texture, sfTrue);
}

void set_small_bonus(enemy_t *enemy, sfRenderWindow *window)
{
    enemy->bonus_speed = 35.0;
    enemy->small_bonus_txt = sfTexture_createFromFile("Images/sbon.png", NULL);
    enemy->small_bonus_sp = sfSprite_create();
    sfSprite_scale(enemy->small_bonus_sp, (sfVector2f){0.3, 0.3});
    enemy->bonus_pos = (sfVector2f){(10 + rand() % 1800), -300};
    sfSprite_setPosition(enemy->small_bonus_sp, enemy->bonus_pos);
    sfSprite_setTexture(enemy->small_bonus_sp, enemy->small_bonus_txt, sfTrue);
}

void setup(sfRenderWindow *window, bg_t *bg, audio_t *audio, enemy_t *enemy)
{
    enemy->score = 0;
    enemy->health = 5;
    enemy->animation = sfClock_create();
    enemy->bonus_clock = sfClock_create();
    enemy->big_bonus_clock = sfClock_create();
    audio->hurt_sound = sfMusic_createFromFile("Music/down.ogg");
    enemy->score_display = sfText_create();
    enemy->font = sfFont_createFromFile("fonts/Tiny5-Regular.ttf");
    sfText_setFont(enemy->score_display, enemy->font);
    sfMusic_setVolume(audio->hurt_sound, 100);
    sfRenderWindow_clear(window, sfBlack);
    set_background(bg);
    set_cursor(bg, window);
    set_enemy(enemy);
    set_healthbar(bg, enemy, window);
    set_small_bonus(enemy, window);
    set_big_bonus(enemy, window);
    set_ending(bg, window);
    put_music(audio);
}
