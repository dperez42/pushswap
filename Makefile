# NAMES ====================================================================================
NAME_CHK	=	checker
NAME_SWP	=	push_swap

# COMPILADOR ====================================================================================
CC			=	gcc

# INCLUDES ====================================================================================
INCS_DIR_CHK = src_checker/checker.h
INCS_DIR_SWP = src_pushswap/pushswap.h
INCLUDES_CHK = -I$(INCS_DIR_CHK)
INCLUDES_SWP = -I$(INCS_DIR_SWP)

# FLAGS ====================================================================================
FLAGS 		= -Wall -Wextra -Werror

# PATHS ============================
SRCS_DIR_PUSHSWAP 	= 	src_pushswap/
SRCS_DIR_CHECKER 	= 	src_checker/
SRCS_CHK =  main.c \
			ft_getnextline.c \
			ft_lista.c  \
			ft_listb.c \
			ft_listc.c \
			errors.c \
			ft_commands.c \
			ft_aux.c \
			ft_aux2.c \
			ft_split.c
SRCS_SWP =  main.c \
			ft_getnextline.c \
			ft_lista.c  \
			ft_swap.c \
			ft_rotaty.c \
			ft_rotaty_aux.c \
			ft_reversy.c \
			ft_reversy_aux.c \
			ft_push.c \
			ft_listc.c \
			ft_errors.c \
			ft_aux.c \
			ft_aux2.c \
			ft_check.c \
			ft_short_aux.c \
			ft_short.c \
			ft_short_15.c \
			ft_split.c \
			ft_distance.c \
			ft_parse.c \
			ft_order_stacks.c \
			ft_methods.c \
			ft_methods_aux.c \
			ft_methods2.c \
			ft_methods2_aux.c

SRCS_CHK2	=	$(addprefix $(SRCS_DIR_CHECKER), $(SRCS_CHK)) 
SRCS_SWP2	=	$(addprefix $(SRCS_DIR_PUSHSWAP), $(SRCS_SWP)) 

# COLOURS ====================================================================================

RED = \033[0;31m
REDBOLD = \033[1;31m
GREEN = \033[0;32m
GREENBOLD = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m
PURPLE = \033[0;35m
YELLOW = \033[0;33m

# OBJS =====================================================================================
OBJS_DIR 		= 	./
OBJ_CHK			=	$(SRCS_CHK2:.c=.o)
OBJ_SWP			=	$(SRCS_SWP2:.c=.o)
OBJS_CHK 		= 	$(addprefix $(OBJS_DIR), $(OBJ_CHK))
OBJS_SWP 		= 	$(addprefix $(OBJS_DIR), $(OBJ_SWP))

# ==========================================================================================

# FROM SUBJECT =============================================================================
all: $(NAME_SWP)

bonus: $(NAME_SWP) $(NAME_CHK)

$(NAME_CHK): 	$(OBJS_CHK)
				$(CC) $(FLAGS) $(INCLUDES_CHK) -o $(NAME_CHK) $(OBJS_CHK)

$(NAME_SWP): 	$(OBJS_SWP)
				$(CC) $(FLAGS) $(INCLUDES_SWP) $(INCLUDES_CHK) -o $(NAME_SWP) $(OBJS_SWP)
clean:
	@echo "$(RED)Objects files $(REDBOLD)$(OBJS_CHK) $(OBJS_SWP)$(RED) removed. $(RESET)"
	@/bin/rm -rf $(OBJS_CHK)
	@/bin/rm -rf $(OBJS_SWP)
fclean: clean
	@echo "$(GREEN)Executable $(GREENBOLD)$(NAME_CHK) $(NAME_SWP)$(GREEN) removed. $(RESET)"
	@/bin/rm -rf $(NAME_CHK)
	@/bin/rm -rf $(NAME_SWP)

re: fclean all

.PHONY: clean fclean re bonus
