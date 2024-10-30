##
## EPITECH PROJECT, 2021
## myteams
## File description:
## server's makefile
##

SERVER_SRC	=	main.c									\
				src/init/create_user.c					\
				src/init/init_client.c					\
				src/init/init_server_struct.c			\
				src/init/init_server_socket.c			\
				src/init/init_raw_socket.c				\
				src/core/accept_client.c				\
				src/core/disconnect_client.c			\
				src/core/loop.c							\
				src/core/process_read_fds.c				\
				src/core/process_write_fds.c			\
				src/core/send_message.c					\
				src/core/treat_read_fd.c				\
				src/core/treat_write_fd.c				\
				src/data/save/save_users.c				\
				src/data/recovery/load_users.c			\
				src/commands/create.c					\
				src/commands/info.c						\
				src/commands/login.c					\
				src/commands/logout.c					\
				src/commands/send.c						\
				src/commands/subscribe.c				\
				src/commands/subscribed.c				\
				src/commands/unsubscribe.c				\
				src/commands/user.c						\
				src/commands/users.c					\
				src/misc/broadcast_message.c			\
				src/misc/buffer_user_input.c			\
				src/misc/destroy_socket.c				\
				src/misc/display_help.c					\
				src/misc/error_management.c				\
				src/misc/get_client_from_fd.c			\
				src/misc/get_command.c					\
				src/misc/get_first_packet_from_buff.c	\
				src/misc/mem_checkval.c					\
				src/misc/parse_user_input.c				\
				src/misc/treat_incoming_packet.c		\
				src/misc/write_buffered_output.c

TMP_SERVER_SRCS		=	$(addprefix server/, $(SERVER_SRC))
SERVER_OBJ	=	$(TMP_SERVER_SRCS:%.c=$(OBJ_DIR)%.o)
unexport TMP_SERVER_SRCS

SERVER_NAME	=	myteams_server
