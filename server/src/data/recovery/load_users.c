/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that loads users
*/

#include <types.h>
#include <fcntl.h>
#include <unistd.h>
#include "vlib/vlib.h"

void load_users(vector(user_t) *vec)
{
    int fd;

    if (access("teams.save", R_OK | F_OK) == 0) {
        fd = open("teams.save", O_RDONLY);

        read(fd, vec, sizeof(vector(user_t)));
        vec->data = calloc(vec->size, sizeof(user_t));
        read(fd, vec->data, vec->size * sizeof(user_t));
        close(fd);
    }
}
