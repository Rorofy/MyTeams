/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** file that contains all events bindings
*/

#ifndef EVENTS_H
#define EVENTS_H

#define CREATE_PAIR(fun_name, type) \
    { &fun_name, type }

#define EVENTS_NUM (sizeof(events) / sizeof(event_pair_t))

#include <server_packet.h>
#include "types.h"

void channel_created(client_t *client, server_packet_t *packet);
void logged_in(client_t *client, server_packet_t *packet);
void logged_out(client_t *client, server_packet_t *packet);
void private_message_received(client_t *client, server_packet_t *packet);
void team_created(client_t *client, server_packet_t *packet);
void thread_created(client_t *client, server_packet_t *packet);
void thread_reply_received(client_t *client, server_packet_t *packet);
void user_listed(client_t *client, server_packet_t *packet);

typedef void (event_t)(client_t *client, server_packet_t *packet);

typedef struct {
    event_t *event;
    uint8_t type;
} event_pair_t;

event_pair_t events[] = {
    CREATE_PAIR(channel_created, EVENT_CHANNEL_CREATED),
    CREATE_PAIR(logged_in, EVENT_LOGGED_IN),
    CREATE_PAIR(logged_out, EVENT_LOGGED_OUT),
    CREATE_PAIR(private_message_received, EVENT_PRIVATE_MESSAGE_RECEIVED),
    CREATE_PAIR(team_created, EVENT_TEAM_CREATED),
    CREATE_PAIR(thread_created, EVENT_THREAD_CREATED),
    CREATE_PAIR(thread_reply_received, EVENT_THREAD_REPLY_RECEIVED),
    CREATE_PAIR(user_listed, EVENT_USER_LISTED),
};

#endif //EVENTS_H
