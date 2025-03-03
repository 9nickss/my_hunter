/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** hunter
*/


#ifndef HUNTER_H_
    #define HUNTER_H_

    #include <stddef.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Audio.h>
    #include <SFML/Window/Mouse.h>

typedef struct audio {
    sfMusic *music;
    sfMusic *hit_sound;
    sfMusic *hurt_sound;
    sfMusic *death_sound;
    sfMusic *lore;
    sfMusic *lick;
    sfMusic *piou;
    sfMusic *big_bonus;
} audio_t;

typedef struct bg {
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfTexture *health_bar_txt;
    sfSprite *health_bar;
    sfIntRect rect_bar;
    sfVector2f cursor_pos;
    sfTexture *cursor_txt;
    sfSprite *cursor_spr;
    sfTexture *ending_txt;
    sfSprite *ending_spr;
} bg_t;

typedef struct enemy {
    int health;
    sfSprite *enemy_sprite;
    sfTexture *enemy_texture;
    sfTexture *enemy_dead_txt;
    sfSprite *enemy_dead_spr;
    sfIntRect rect;
    sfClock *animation;
    sfTime time_elapsed;
    int time;
    sfVector2f pos;
    float speed;
    float max_speed;
    sfFloatRect hitbox;
    int score;
    sfText *score_display;
    char *score_text;
    sfFont *font;
    int direction;
    sfTexture *small_bonus_txt;
    sfSprite *small_bonus_sp;
    sfTexture *big_bonus_txt;
    sfSprite *big_bonus_spr;
    sfVector2f bonus_pos;
    sfVector2f big_bonus_pos;
    sfClock *bonus_clock;
    sfClock *big_bonus_clock;
    sfTime bonus_time_elpased;
    sfTime big_bonus_time_elapsed;
    int big_bonus_time;
    int bonus_time;
    float bonus_speed;
    sfFloatRect bs_hitbox;
    sfFloatRect big_hitbox;
    sfText *ending_disp;
} enemy_t;

int main(int argc, char **argv);
void gameloop(sfRenderWindow *window, bg_t *bg, audio_t *audio,
    enemy_t *enemy);
void setup(sfRenderWindow *window, bg_t *bg, audio_t *audio, enemy_t *enemy);
void animation(enemy_t *enemy);
void animate_bonus(enemy_t *enemy);
void spawn_bonus(enemy_t *enemy);
void animation_loop(enemy_t *enemy);
void clear(bg_t *bg, enemy_t *enemy, audio_t *audio, sfRenderWindow *window);
sfRenderWindow *create_window(void);
void set_healthbar(bg_t *bg, enemy_t *enemy, sfRenderWindow *window);
void set_background(bg_t *bg);
void set_enemy(enemy_t *enemy);
void set_small_bonus(enemy_t *enemy, sfRenderWindow *window);
void events(sfRenderWindow *window, enemy_t *enemy, audio_t *audio, bg_t *bg);
void enemy_hit(sfRenderWindow *window, enemy_t *enemy, audio_t *audio);
void display_score(enemy_t *enemy, sfRenderWindow *window, bg_t *bg);
char *int_to_str(enemy_t *enemy);
sfMusic *hit_sound(audio_t *audio);
sfMusic *put_music(audio_t *audio);
void health(bg_t *bg, enemy_t *enemy, sfRenderWindow *window, audio_t *audio);
sfMusic *death_sound(audio_t *audio);
sfMusic *hurt_sound(audio_t *audio);
void pause_event(audio_t *audio);
sfMusic *shot_sound(audio_t *audio);
void cli(sfRenderWindow *window, enemy_t *enemy, audio_t *audio,
    sfEvent event);
void small_bonus(sfRenderWindow *window, enemy_t *enemy, audio_t *audio);
void cl2(sfRenderWindow *window, enemy_t *enemy, audio_t *audio,
    sfMouseButtonEvent click);
void cl3(sfRenderWindow *window, enemy_t *enemy, audio_t *audio,
    sfMouseButtonEvent click);
void set_big_bonus(enemy_t *enemy, sfRenderWindow *window);
void set_cursor(bg_t *bg, sfRenderWindow *window);
void cursor_mvt(sfRenderWindow *window, bg_t *bg);
void set_ending(bg_t *bg, sfRenderWindow *window);
void display_ending(enemy_t *enemy, sfRenderWindow *window, bg_t *bg);

#endif /*HUNTER_H_*/
