//
//		Emulator class - supports the emulation of VC1620 programs
//
#ifndef _EMULATOR_H      // UNIX way of preventing multiple inclusions.
#define _EMULATOR_H

// class that stores the memory of the instructions
class Emulator 
{
    public:
    
    const static int MEMSZ = 100'000;	// The size of the memory of the Duck2200.
    
    // This function is a consturctor that resizes the emulator to have 100000 spaces all set to 0.
    Emulator();
    
    // inserts data into the memory 
    bool insertMemory( int a_location, long long a_contents );
    
    //runs the program recorded in memory
    bool runProgram( );
    
    
    private:
    
    vector<long long> m_memory;  	// Memory for the Duck2200
};

#endif
