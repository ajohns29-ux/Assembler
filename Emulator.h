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
    bool insertMemory( int a_location, long long a_contents );
    
    // Runs the program recorded in memory.
    bool runProgram( );

private:

    vector<long long> m_memory;  	// Memory for the Duck2200
};

#endif
