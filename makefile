OBJS = objs/main.o objs/menu.o \
			 src/search/by-employee.c \
			 src/search/by-business.c
INC = inc/menu.h
BIN = ex
CFLAGS = -g -Wall

app: $(OBJS) $(INC)
	$(CC) -o $(BIN) $(OBJS)

debug: $(OBJS) $(INC)
	$(CC) -o $(BIN) $(OBJS) $(CFLAGS)

objs/%.o: src/%.c
	$(CC) -c $< -o $@

objs/%.o: src/search/%.c inc/search.h
	$(CC) -c $< -o $@

clean:
	$(RM) $(BIN) $(OBJS)
