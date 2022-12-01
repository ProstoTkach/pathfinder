name = libmx.a
files_src = $(wildcard src/*.c)
files_obj = $(addprefix obj/, $(notdir $(files_src:%.c=%.o)))
files_inc = $(wildcard inc/*.h)

all: $(name) clean

$(name): $(files_obj)
	@ar rcs $@ $^

$(files_obj): | obj

obj/%.o: src/%.c $(files_inc)
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c $< -o $@ -I inc

obj:
	mkdir -p $@

clean:
	rm -rf obj

uninstall:
	rm -rf obj
	rm -rf $(name)

reinstall: uninstall all

.PHONY: all uninstall clean reinstall

