/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** login function
*/

#include <types.h>
#include <unistd.h>
#include <misc.h>

char *parse_input(const char *input)
{
    for (int i = 0; input[i] != '\0'; ++i)
        if (input[i] == '"')
            return (get_first_string(input + i));
    return (strdup(input));
}

void login(
    client_t *client,
    const char *input)
{
    char *parsed_input = parse_input(input);
    client_packet_t packet = {
        .header = {
            .type = LOGIN
        }
    };

    if (parsed_input == NULL)
        return;
    strcpy(packet.data.username, parsed_input);
    write(client->fd, &packet, sizeof(packet));
    free(parsed_input);
}
