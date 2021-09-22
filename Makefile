help:
	@echo "Targets:"
	@echo "    make preprocessor"
	@echo "    make compile"
	@echo "    make assemble"

preprocessor:
	gcc -E main.c
compile:
	gcc -c main.c
assemble:
	gcc main.c -o main