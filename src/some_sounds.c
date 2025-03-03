/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myhunter-yannick.kahl
** File description:
** some_sounds
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

sfMusic *shot_sound(audio_t *audio)
{
    audio->piou = sfMusic_createFromFile("Music/piou.ogg");
    sfMusic_setVolume(audio->piou, 100);
    sfMusic_play(audio->piou);
    return audio->piou;
}

sfMusic *hit_sound(audio_t *audio)
{
    audio->hit_sound = sfMusic_createFromFile("Music/shot.ogg");
    sfMusic_setVolume(audio->hit_sound, 100);
    sfMusic_play(audio->hit_sound);
    return audio->hit_sound;
}

sfMusic *put_music(audio_t *audio)
{
    audio->music = sfMusic_createFromFile("Music/music2.ogg");
    sfMusic_setVolume(audio->music, 50);
    sfMusic_setLoop(audio->music, sfTrue);
    sfMusic_play(audio->music);
    return audio->music;
}

sfMusic *death_sound(audio_t *audio)
{
    audio->death_sound = sfMusic_createFromFile("Music/lose.ogg");
    sfMusic_setVolume(audio->death_sound, 100);
    sfMusic_play(audio->death_sound);
    return audio->death_sound;
}

sfMusic *hurt_sound(audio_t *audio)
{
    audio->hurt_sound = sfMusic_createFromFile("Music/down.ogg");
    sfMusic_setVolume(audio->hurt_sound, 100);
    sfMusic_play(audio->hurt_sound);
}
