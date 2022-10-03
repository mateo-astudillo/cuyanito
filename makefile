OBJS = src/main.o src/menu.o
INC = inc/menu.h
BIN = ex
CFLAGS = -g -Wall

app: $(OBJS) $(INC)
	$(CC) -o $(BIN) $(OBJS)

debug: $(OBJS) $(INC)
	$(CC) -o $(BIN) $(OBJS) $(CFLAGS)

src/%.o: src/%.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(BIN) $(OBJS)
