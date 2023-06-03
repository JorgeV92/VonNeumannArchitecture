#include <iostream>
#include <vector>

// Memory
class Memory {
    std::vector<int> data;

public:
    Memory(size_t size) : data(size, 0) {}

    int operator[](size_t address) {
        return data[address];
    }

    void set(size_t address, int value) {
        data[address] = value;
    }
};

// CPU
class CPU {
    Memory& memory;
    int acc;  // accumulator
    size_t pc;  // program counter

public:
    CPU(Memory& memory) : memory(memory), acc(0), pc(0) {}

    int fetch() {
        int opcode = memory[pc];
        pc += 1;
        return opcode;
    }

    void execute(int opcode) {
        if (opcode == 0) {  // LOAD
            size_t address = memory[pc];
            pc += 1;
            acc = memory[address];
        } else if (opcode == 1) {  // STORE
            size_t address = memory[pc];
            pc += 1;
            memory.set(address, acc);
        }
        // implement other opcodes...
    }

    void run() {
        while (true) {
            int opcode = fetch();
            execute(opcode);
        }
    }
};

int main() {
    Memory memory(256);
    CPU cpu(memory);

    // A simple program: load the number 42 into the accumulator, then store it at memory location 0
    memory.set(0, 0);  // LOAD
    memory.set(1, 1);  // memory location 1
    memory.set(2, 1);  // STORE
    memory.set(3, 0);  // memory location 0
    memory.set(1, 42);  // number to load

    cpu.run();

    return 0;
}
