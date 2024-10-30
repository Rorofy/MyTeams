/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that init client
*/

#include <types.h>
#include <init.h>

client_t *init_client(options_t *options)
{
    client_t *res;

    if (options == NULL)
        return (NULL);
    res = calloc(1, sizeof(client_t));
    if (res == NULL)
        return (NULL);
    res->fd = init_socket(options->ip, options->port);
    if (res->fd == -1)
        return (NULL);
    return (res);
}
