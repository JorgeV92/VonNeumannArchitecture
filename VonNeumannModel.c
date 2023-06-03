#include <stdio.h>

#define MEMORY_SIZE 1024

typedef struct {
    int memory[MEMORY_SIZE];
    int program_counter;
    int accumulator;
} CPU;

void load_program(CPU *cpu, int program[], int program_size) {
    for (int i = 0; i < program_size; i++) {
        cpu->memory[i] = program[i];
    }
    cpu->program_counter = 0;
    cpu->accumulator = 0;
}

void execute_program(CPU *cpu) {
    while (1) {
        int instruction = cpu->memory[cpu->program_counter];
        cpu->program_counter++;

        if (instruction == -1) { // halt instruction
            break;
        }
        // here we could define more instructions like addition, subtraction, etc.
    }
}

int main() {
    CPU cpu;

    // a very simple program that halts immediately
    int program[] = {-1}; // -1 is the halt instruction
    int program_size = sizeof(program) / sizeof(program[0]);

    load_program(&cpu, program, program_size);
    execute_program(&cpu);

    return 0;
}
