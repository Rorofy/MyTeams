/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** create function
*/

#include <types.h>
#include <unistd.h>
#include <misc.h>
#include <stdbool.h>

static void assign_arg(client_packet_t *packet, const char *input)
{
    const size_t input_len = strlen(input);

    if (*packet->data.creation_data.name == '\0')
        memcpy(packet->data.creation_data.name, input, input_len);
    else
        if (input_len > sizeof(packet->data.creation_data.description))
            memcpy(packet->data.creation_data.message, input, input_len);
        else
            memcpy(packet->data.creation_data.description, input, input_len);
}

static void get_data(client_packet_t *packet, const char *input)
{
    char *str = get_first_string(input);

    if (str == NULL)
        return;
    assign_arg(packet, str);
    free(str);
}

static void parse_data(client_packet_t *packet, const char *input)
{
    bool in_open = false;

    for (size_t i = 0; input[i] != '\0'; ++i) {
        if (input[i] == '"' && !in_open)
            get_data(packet, input + i);
        if (input[i] == '"')
            in_open = !in_open;
    }
}

void create(
    client_t *client,
    const char *input)
{
    client_packet_t packet = {
        .header = {
            .type = CREATE
        }
    };

    memset(&(packet.data), 0, sizeof(packet.data));
    memcpy(
        packet.data.creation_data.context,
        client->context,
        sizeof(client->context)
    );
    parse_data(&packet, input);
    write(client->fd, &packet, sizeof(client_packet_t));
}
