/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** score
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

char *int_to_str(enemy_t *enemy)
{
    int points = enemy->score;
    int temp = points;
    int length = 0;

    if (points == 0) {
        enemy->score_text = malloc(2);
        enemy->score_text[0] = '0';
        enemy->score_text[1] = '\0';
        return enemy->score_text;
    }
    for (; temp > 0; temp /= 10)
        length++;
    enemy->score_text = malloc(length + 1);
    enemy->score_text[length] = '\0';
    for (int i = length - 1; points > 0; i--) {
        enemy->score_text[i] = '0' + (points % 10);
        points /= 10;
    }
    return enemy->score_text;
}

void display_score(enemy_t *enemy, sfRenderWindow *window, bg_t *bg)
{
    int_to_str(enemy);
    sfText_setColor(enemy->score_display, sfBlack);
    sfText_setString(enemy->score_display, enemy->score_text);
    sfText_setPosition(enemy->score_display, (sfVector2f){962, 22});
    sfRenderWindow_drawText(window, enemy->score_display, NULL);
    sfText_setColor(enemy->score_display, sfWhite);
    sfText_setString(enemy->score_display, enemy->score_text);
    sfText_setPosition(enemy->score_display, (sfVector2f){960, 20});
    sfRenderWindow_drawText(window, enemy->score_display, NULL);
    free(enemy->score_text);
}
