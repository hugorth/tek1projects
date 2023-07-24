/*
** EPITECH PROJECT, 2023
** algo
** File description:
** algo
*/

#include "../include/my.h"

static void go_left(n4s *sped)
{
    double dir = 0;

    if (sped->mid >= 1500) {
        dir = 0.005;
    }
    if (sped->mid >= 1300 && sped->mid < 1500) {
        dir = 0.01;
    } if (sped->mid >= 1000 && sped->mid < 1300) {
        dir = 0.05;
    } if (sped->mid >= 800 && sped->mid < 1000) {
        dir = 0.075;
    } if (sped->mid >= 600 && sped->mid < 800) {
        dir = 0.1;
    } if (sped->mid >= 400 && sped->mid < 600) {
        dir = 0.2;
    } if (sped->mid >= 200 && sped->mid < 400) {
        dir = 0.3;
    } if (sped->mid < 200)
        dir = 0.9;
    set_direction(dir, 0);
}

static void go_right(n4s *sped)
{
    double dir = 0;

    if (sped->mid >= 1500) {
        dir = 0.005;
    } if (sped->mid >= 1300 && sped->mid < 1500) {
        dir = 0.01;
    } if (sped->mid >= 1000 && sped->mid < 1300) {
        dir = 0.05;
    } if (sped->mid >= 800 && sped->mid < 1000) {
        dir = 0.075;
    } if (sped->mid >= 600 && sped->mid < 800) {
        dir = 0.1;
    } if (sped->mid >= 400 && sped->mid < 600) {
        dir = 0.2;
    } if (sped->mid >= 200 && sped->mid < 400) {
        dir = 0.3;
    } if (sped->mid < 200)
        dir = 0.9;
    set_direction(dir, 1);
}

int launch_ia(n4s *sped, char **tab)
{
    sped->left = atof(tab[3]);
    sped->mid = atof(tab[18]);
    sped->right = atof(tab[34]);
    control_speed(sped);
    (sped->left > sped->right) ? go_left(sped) : go_right(sped);
    if (detect_end(tab[34]))
        exit(0);
    return (0);
}

void control_speed(n4s *sped)
{
    double speed = 0;

    if (sped->mid >= 2000) {
        speed = 1.0;
    } if (sped->mid >= 1700 && sped->mid < 2000) {
        speed = 0.9;
    } if (sped->mid >= 1500 && sped->mid < 1700) {
        speed = 0.8;
    } if (sped->mid >= 1300 && sped->mid < 1500) {
        speed = 0.7;
    } if (sped->mid >= 1000 && sped->mid < 1300) {
        speed = 0.6;
    } if (sped->mid >= 600 && sped->mid < 1000) {
        speed = 0.5;
    } if (sped->mid >= 400 && sped->mid < 600) {
        speed = 0.4;
    } if (sped->mid < 400) {
        speed = 0.1;
    }
    set_speed(speed);
}