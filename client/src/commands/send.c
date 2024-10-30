/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** send function
*/

#include <types.h>
#include <stdio.h>
#include <stdbool.h>
#include <misc.h>
#include <unistd.h>

static void assign_arg(client_packet_t *packet, const char *input)
{
    const size_t input_len = strlen(input);
    uuid_t zero = {0};

    if (memcmp(
            packet->data.msg_send_data.user_uuid,
            zero,
            sizeof(uuid_t)
        ) == 0)
        uuid_parse(input, packet->data.msg_send_data.user_uuid);
    else
        memcpy(packet->data.msg_send_data.message_body, input, input_len);
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

void send(
    client_t *client,
    const char *input)
{
    client_packet_t packet = {
        .header = {
            .type = SEND
        }
    };

    parse_data(&packet, input);
    write(client->fd, &packet, sizeof(client_packet_t));
}
