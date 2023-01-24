OBJS = objs/main.o objs/menu.o \
	objs/insert-repair.o \
<<<<<<< HEAD
	objs/search-by-employee.o \
=======
	objs/search-by-business.o \
>>>>>>> beta
	objs/search-by-business.o \
	objs/repair-by-business.o \
	objs/repair-by-employee.o \
	objs/repair-by-date.o \
	objs/save.o \
	objs/show.o

INC = inc/menu.h # Final
BIN = ex
CFLAGS = -Wall
CFLAGSDEBUG = -Wall -g

app: $(OBJS) 
	$(CC) -o $(BIN) $(OBJS) $(CFLAGS)

debug: $(OBJS) 
	$(CC) -o $(BIN) $(OBJS) $(CFLAGSDEBUG)

objs/%.o: src/%.c inc/menu.h
	$(CC) -c $< -o $@

objs/%.o: src/insert/%.c inc/insert.h
	$(CC) -c $< -o $@

objs/%.o: src/search/%.c inc/search.h
	$(CC) -c $< -o $@

objs/%.o: src/show/%.c inc/show.h
	$(CC) -c $< -o $@

objs/%.o: src/update/%.c inc/update.h
	$(CC) -c $< -o $@

clean:
	$(RM) $(BIN) $(OBJS)
