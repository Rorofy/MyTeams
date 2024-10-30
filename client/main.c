/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** client entry point
*/

#include <unistd.h>
#include <init.h>
#include <core.h>
#include <misc.h>

int main(int ac, char const **av)
{
    options_t *options = get_options(ac, av);
    client_t *client;

    if (ac == 2 && strcmp(options->ip, "-help") == 0) {
        display_help();
        return (0);
    }
    if (ac == 3) {
        client = init_client(options);
        if (client == NULL)
            return (84);
        free(options);
        return (loop(client));
    }
    return (84);
}
