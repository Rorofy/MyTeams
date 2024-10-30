##
## EPITECH PROJECT, 2021
## myteams
## File description:
## client's makefile
##

CLIENT_SRC			=	main.c									\
						src/init/init_client.c					\
						src/init/init_socket.c					\
						src/init/get_options.c					\
						src/core/loop.c							\
						src/core/parse_command.c				\
						src/core/parse_event.c					\
						src/core/treat_ready_fds.c				\
						src/core/treat_server_data.c			\
						src/misc/display_help.c					\
						src/misc/get_first_string.c				\
						src/misc/pop_first_server_msg.c			\
						src/misc/remove_newline.c				\
						src/events/channel_created.c			\
						src/events/logged_in.c					\
						src/events/logged_out.c					\
						src/events/private_message_received.c	\
						src/events/team_created.c				\
						src/events/thread_created.c				\
						src/events/thread_reply_received.c		\
						src/events/event_user_listed.c			\
						src/commands/create.c					\
						src/commands/help.c						\
						src/commands/info.c						\
						src/commands/list.c						\
						src/commands/login.c					\
						src/commands/logout.c					\
						src/commands/messages.c					\
						src/commands/send.c						\
						src/commands/subscribe.c				\
						src/commands/subscribed.c				\
						src/commands/unsubscribe.c				\
						src/commands/use.c						\
						src/commands/user.c						\
						src/commands/users.c

TMP_CLIENT_SRCS		=	$(addprefix client/, $(CLIENT_SRC))
CLIENT_OBJ			=	$(TMP_CLIENT_SRCS:%.c=$(OBJ_DIR)%.o)
unexport TMP_CLIENT_SRCS

CLIENT_NAME	=	myteams_cli
