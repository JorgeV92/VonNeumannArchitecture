class Memory:
    def __init__(self, size):
        self.data = [0] * size

    def __getitem__(self, address):
        return self.data[address]

    def __setitem__(self, address, value):
        self.data[address] = value

class CPU:
    def __init__(self, memory):
        self.memory = memory
        self.acc = 0  # accumulator
        self.pc = 0  # program counter

    def fetch(self):
        opcode = self.memory[self.pc]
        self.pc += 1
        return opcode

    def execute(self, opcode):
        if opcode == 0:  # LOAD
            address = self.memory[self.pc]
            self.pc += 1
            self.acc = self.memory[address]
        elif opcode == 1:  # STORE
            address = self.memory[self.pc]
            self.pc += 1
            self.memory[address] = self.acc
        # implement other opcodes...

    def run(self):
        while True:
            opcode = self.fetch()
            self.execute(opcode)

memory = Memory(256)
cpu = CPU(memory)

# A simple program: load the number 42 into the accumulator, then store it at memory location 0
memory[0] = 0  # LOAD
memory[1] = 1  # memory location 1
memory[2] = 1  # STORE
memory[3] = 0  # memory location 0
memory[1] = 42  # number to load

cpu.run()
