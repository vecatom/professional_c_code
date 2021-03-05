build: bin/test_param_main

bin/test_param_main: obj/jx_params.o obj/jx_delog.o obj/jx_defines.o obj/test_param_main.o
	gcc $^ -o $@

.depend: src/test_param_main.c src/jx_defines.c src/jx_delog.c src/jx_params.c
	gcc -MM -Iinc $^ > $@
    sed -i '' '/.o:/ s,^,obj/,' $@

sinclude .depend
obj/%.o:src/%.c $(MAKEFILE_list)
	gcc -Iinc -c -DDEBUG $< -o $@
rebuild: clean build

clean:
	-rm obj/*
	-rm bin/*

.PHONY: build rebuild clean


