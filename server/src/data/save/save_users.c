/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that save users
*/

#include <types.h>
#include <fcntl.h>
#include <unistd.h>
#include "vlib/vlib.h"

void save_users(vector(user_t) *vec)
{
    int fd = open("teams.save", O_WRONLY | O_CREAT, S_IRWXU);

    if (fd == -1)
        return;
    lseek(fd, SEEK_SET, 0);
    write(fd, vec, sizeof(vector(user_t)));
    write(fd, vec->data, sizeof(user_t) * vec->size);
    close(fd);
}
