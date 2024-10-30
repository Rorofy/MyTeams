/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that read user input and write it into buffer
*/

#include <stdbool.h>
#include <types.h>
#include <unistd.h>

static void concat_buff_into_client(
    client_t *client,
    const char buff[BUFF_SIZE],
    ssize_t read_size)
{
    client->reading_buff = reallocarray(
        client->reading_buff,
        client->read_size + read_size,
        sizeof(unsigned char)
    );
    memcpy(client->reading_buff + client->read_size, buff, read_size);
    client->read_size += read_size;
}

bool buffer_user_input(client_t *client)
{
    char buff[BUFF_SIZE] = {0};
    ssize_t read_size;

    read_size = read(client->fd, buff, BUFF_SIZE);
    if (read_size < 1)
        return (false);
    concat_buff_into_client(client, buff, read_size);
    return (true);
}
