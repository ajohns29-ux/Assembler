//
//		Emulator class - supports the emulation of Duck2200 programs
//
#ifndef _EMULATOR_H      // UNIX way of preventing multiple inclusions.
#define _EMULATOR_H

class emulator {

public:

    const static int MEMSZ = 100'000;	// The size of the memory of the Duck2200.

    /**/
    /*
    
    NAME	
    
    	emulator()
    
    SYNOPSIS
    
    	emulator()
    
    DESRIPTION
    
       This function is a consturctor that resizes the emulator to have 100000 spaces all set to 0.
    
    RETURNS
    
        No return value
    
    */
    /**/
    emulator() {

         m_memory.resize(MEMSZ, 0);
    }

    /**/
    /*
    
    NAME	
    
    	insertMemory()
    
    SYNOPSIS
    
    	bool insertMemory( int a_location, long long a_contents )

        a_location -> the location where the contents will be recorded
        a_contents -> value to be recorded into memory
    
    DESRIPTION
    
        This function inserts data into the memory location of the emulator. 
    
    RETURNS
    
        Returns true if the insertion was successful and returns false if the location arguments is out of the bounds of memory. 
    
    */
    /**/
    bool insertMemory( int a_location, long long a_contents )
    {
        if(a_location < 0 || a_location >= MEMSZ)
        {
            return false;
        }
        m_memory[a_location] = a_contents;
        return true;
    } 

    /**/
    /*
    
    NAME	
    
    	runProgram( )
    
    SYNOPSIS
    
    	bool runProgram( )
    
    DESRIPTION
    
        This function runs the program recorded in memory. Each line in memory is split into its parts and the opcode dertermines what happens to the operands. 
    
    RETURNS
    
        Returns true if the program runs completly through and returns false if the program in memory contains errors. 
    
    */
    /**/
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
                case 10:
                    if(m_memory[operand2] < 0)
                    {
                        loc = operand1;
                    }
                    else
                    {
                        loc++;
                    }
                default:
                    break;
            }
        }
    }
    

private:

    vector<long long> m_memory;  	// Memory for the Duck2200
};

#endif
