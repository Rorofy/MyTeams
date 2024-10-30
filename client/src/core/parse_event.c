/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that parse the event received from server
*/

#include <events.h>

void parse_event(client_t *client, server_packet_t *packet)
{
    for (unsigned long i = 0; i < EVENTS_NUM; ++i)
        if (events[i].type == packet->header.type) {
            events[i].event(client, packet);
            break;
        }
}