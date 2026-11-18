//
//		File access to source file and retrieve each line using fstream
//
#ifndef _FILEACCESS_H  // This is the way that multiple inclusions are defended against often used in UNIX
#define _FILEACCESS_H  

#include <fstream>
#include <stdlib.h>
#include <string>

// class allows program to access and read the file that holds the VC1620 code 
class FileAccess {

public:

    // Opens the file.
    FileAccess( int argc, char *argv[] );

    // Closes the file.
    ~FileAccess( );

    // Get the next line from the source file.  Returns true if there was one.
    bool GetNextLine( string &a_line );

    // Put the file pointer back to the beginning of the file.
    void Rewind( );

private:

    ifstream m_sfile;		// Source file object.
};
#endif
