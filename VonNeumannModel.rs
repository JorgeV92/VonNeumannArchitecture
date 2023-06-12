struct CPU {
    memory: [i32; 1024],
    program_counter: usize,
    accumulator: i32,
}

impl CPU {
    fn new() -> Self {
        CPU {
            memory: [0; 1024],
            program_counter: 0,
            accumulator: 0,
        }
    }

    fn load_program(&mut self, program: &[i32]) {
        for (i, &instruction) in program.iter().enumerate() {
            self.memory[i] = instruction;
        }
        self.program_counter = 0;
        self.accumulator = 0;
    }

    fn execute_program(&mut self) {
        loop {
            let instruction = self.memory[self.program_counter];
            self.program_counter += 1;

            if instruction == -1 { // halt instruction
                break;
            }
            // here we could define more instructions like addition, subtraction, etc.
        }
    }
}

fn main() {
    let mut cpu = CPU::new();

    // a very simple program that halts immediately
    let program = [-1]; // -1 is the halt instruction

    cpu.load_program(&program);
    cpu.execute_program();
}
