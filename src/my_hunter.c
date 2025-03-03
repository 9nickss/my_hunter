/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** my_hunter
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

sfRenderWindow *create_window(void)
{
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    return sfRenderWindow_create(video_mode, "feur", sfDefaultStyle, NULL);
}

static void destroy_more(bg_t *bg, enemy_t *enemy,
    audio_t *audio)
{
    sfSprite_destroy(enemy->small_bonus_sp);
    sfClock_destroy(enemy->animation);
    sfClock_destroy(enemy->bonus_clock);
    sfClock_destroy(enemy->big_bonus_clock);
    sfText_destroy(enemy->score_display);
    sfTexture_destroy(bg->cursor_txt);
    sfSprite_destroy(bg->cursor_spr);
    sfSprite_destroy(bg->ending_spr);
    sfTexture_destroy(bg->ending_txt);
}

void clear(bg_t *bg, enemy_t *enemy, audio_t *audio, sfRenderWindow *window)
{
    sfMusic_destroy(audio->music);
    sfSprite_destroy(bg->bg_sprite);
    sfTexture_destroy(bg->bg_texture);
    sfTexture_destroy(bg->health_bar_txt);
    sfSprite_destroy(bg->health_bar);
    sfTexture_destroy(enemy->enemy_texture);
    sfSprite_destroy(enemy->enemy_sprite);
    sfTexture_destroy(enemy->small_bonus_txt);
    sfTexture_destroy(enemy->big_bonus_txt);
    sfSprite_destroy(enemy->big_bonus_spr);
    destroy_more(bg, enemy, audio);
    sfRenderWindow_destroy(window);
    free(audio);
    free(bg);
    free(enemy);
}

void gameloop(sfRenderWindow *window, bg_t *bg, audio_t *audio, enemy_t *enemy)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg->bg_sprite, NULL);
        events(window, enemy, audio, bg);
        cursor_mvt(window, bg);
        health(bg, enemy, window, audio);
        display_score(enemy, window, bg);
        enemy->time_elapsed = sfClock_getElapsedTime(enemy->animation);
        enemy->time = sfTime_asMilliseconds(enemy->time_elapsed);
        animation_loop(enemy);
        spawn_bonus(enemy);
        sfSprite_setTextureRect(enemy->enemy_sprite, enemy->rect);
        sfRenderWindow_drawSprite(window, enemy->enemy_sprite, NULL);
        sfRenderWindow_drawSprite(window, enemy->small_bonus_sp, NULL);
        sfRenderWindow_drawSprite(window, enemy->big_bonus_spr, NULL);
        sfRenderWindow_display(window);
    }
    clear(bg, enemy, audio, window);
}

int helper(audio_t *audio)
{
    audio->lore = sfMusic_createFromFile("Music/lore_earrape.ogg");
    if (audio->lore == NULL)
        return 84;
    sfMusic_play(audio->lore);
    sfMusic_setVolume(audio->lore, 100);
    write(1, "===============FEET_HUNTER================\n", 44);
    write(1, "SOUND ON!!! EVEN FOR -h!!!!!!!!!!\n", 35);
    write(1, "Shoot the feet before they reach the other side. ", 50);
    write(1, "If they reach the other side 5 times, you lose.\n", 48);
    write(1, "There also are bonuses falling from the sky! ", 46);
    write(1, "Small bonuses bring 10 points. ", 32);
    write(1, "Big bonuses reset your lives to 5.\n", 36);
    write(1, "LEFT CLICK to shoot. ", 21);
    write(1, "press TAB to pause the game(WIP). ", 35);
    write(1, "press ESC to close the game.\n", 30);
    while (sfMusic_getStatus(audio->lore) == sfPlaying) {
    }
    sfMusic_destroy(audio->lore);
}

int main(int argc, char **argv)
{
    bg_t *bg = malloc(sizeof(bg_t));
    audio_t *audio = malloc(sizeof(audio_t));
    enemy_t *enemy = malloc(sizeof(enemy_t));
    sfRenderWindow *window;

    srand(time(NULL));
    if (argc != 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            helper(audio);
    } else {
        window = create_window();
        setup(window, bg, audio, enemy);
        gameloop(window, bg, audio, enemy);
    }
    return 0;
}
