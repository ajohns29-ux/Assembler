//
//		Emulator class - supports the emulation of Duck2200 programs
//
#ifndef _EMULATOR_H      // UNIX way of preventing multiple inclusions.
#define _EMULATOR_H

class emulator {

public:

    const static int MEMSZ = 100'000;	// The size of the memory of the Duck2200.
    emulator() {

         m_memory.resize(MEMSZ, 0);
    }
    // Records instructions and data into simulated memory.
    bool insertMemory( int a_location, long long a_contents )
    {
        if(a_location < 0 || a_location >= MEMSZ)
        {
            return false;
        }
        m_memory[a_location] = a_contents;
        return true;
    } 
    
    // Runs the program recorded in memory.
    bool runProgram( )
    {
        int loc = 100;
        while(true)
        {
            if(loc >= MEMSZ)
            {
                // Complain and terminate
            }
            long long instr = m_memory[loc];
            int opcode = int(instr / 1'000'000'000LL);
            int operand1 = int(instr / 100'000 % 100'000);
            int operand2 = int(instr % 100'000);

            switch(opcode)
            {
                case 1: 
                    m_memory[operand1] += m_memory[operand2];
                    loc++;
                    continue;
                default:
                    break;
            }
        }
    }
    

private:

    vector<long long> m_memory;  	// Memory for the Duck2200
};

#endif
