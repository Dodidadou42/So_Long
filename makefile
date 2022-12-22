# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddychus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 10:46:50 by ddychus           #+#    #+#              #
#    Updated: 2022/12/01 11:38:16 by ddychus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
NAME_BONUS		= so_long_bonus

SRCS			= srcs/animate_player.c srcs/animate_portal.c srcs/animations.c \
				  srcs/check_map.c srcs/handle_foe.c srcs/init_game.c \
				  srcs/init_map.c srcs/keyboard_input.c srcs/pathfinding.c \
				  srcs/render_map.c srcs/so_long.c srcs/utils.c

SRCS_BONUS		= srcs_bonus/animate_player_bonus.c srcs_bonus/animate_portal_bonus.c srcs_bonus/animations_bonus.c \
				  srcs_bonus/check_map_bonus.c srcs_bonus/handle_foe_bonus.c srcs_bonus/init_game_bonus.c \
				  srcs_bonus/init_map_bonus.c srcs_bonus/keyboard_input_bonus.c srcs_bonus/pathfinding_bonus.c \
				  srcs_bonus/render_map_bonus.c srcs_bonus/so_long_bonus.c srcs_bonus/utils_bonus.c
SRCS_UTILS		= gnl/get_next_line.c gnl/join_free.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_itoa.c \
				  libft/ft_split.c libft/ft_strchr.c libft/ft_strcmp.c libft/ft_strdup.c libft/ft_strjoin.c \
				  libft/ft_strlen.c printf/ft_num.c printf/ft_printf.c printf/ft_string.c

CC				= gcc

C_FLAGS			= -Wextra -Werror -Wall
MINILIB_FLAGS	= -lmlx -framework OpenGL -framework Appkit -L /usr/local/lib/

RM				= rm -f
INCLUDES		= -I /usr/local/includes

${NAME}:		
				${CC} ${INCLUDES} ${C_FLAGS} ${MINILIB_FLAGS} ${SRCS} ${SRCS_UTILS} -o ${NAME}
${NAME_BONUS}:		
				${CC} ${INCLUDES} ${C_FLAGS} ${MINILIB_FLAGS} ${SRCS_BONUS} ${SRCS_UTILS} -o ${NAME_BONUS}
all:			${NAME}
bonus:			${NAME_BONUS}
clean:			
				${RM} ${NAME} 
fclean:			clean
				${RM} ${NAME_BONUS}
re:				fclean all
.PHONY:			all clean fclean re
