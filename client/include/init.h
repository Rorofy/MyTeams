/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** header that contains init proto
*/

#ifndef INIT_H
#define INIT_H

#include <types.h>

options_t *get_options(int ac, const char **av);
client_t *init_client(options_t *options);
int init_socket(const char *addr, uint16_t port);

#endif //INIT_H
