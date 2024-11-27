name = cmdcalc
cfiles = main.c labpzrl.c
objects = $(cfiles:.c=.o)
input = 41 + 33 111 - 8 22 \* 5 221 % 111 100 + 13 -k 2

$(name): $(objects)
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

clean:
	rm $(name) $(objects)

run:
	./$(name) $(input)
