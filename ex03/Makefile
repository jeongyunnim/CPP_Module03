NAME 		=	ex03

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCS		=	./ClapTrap.hpp\
				./ScavTrap.hpp\
				./FragTrap.hpp\
				./DiamondTrap.hpp\

SRCS		=	./main.cpp\
				./ClapTrap.cpp\
				./ScavTrap.cpp\
				./FragTrap.cpp\
				./DiamondTrap.cpp\

OBJS		=	$(SRCS:%.cpp=%.o)

RM			=	rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%o:	%.c
	$(CXX) $(CXXFLAGS) $(INCS) -c $^ -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re