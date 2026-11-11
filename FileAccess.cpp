//
//  Implementation of file access class.
//
#include "stdafx.h"
#include "FileAccess.h"

/**/
/*

NAME	

    FileAccess::FileAccess()

SYNOPSIS

    FileAccess::FileAccess( int argc, char *argv[] )

    argc -> the number of arguments 
    *argv[] -> the value of each argument

DESRIPTION

    The function is a constructor that checks that the correct number of files have been used and opens the file containing the assembler input.

RETURNS

    No return value 

*/
/**/
FileAccess::FileAccess( int argc, char *argv[] )
{
    // Check that there is exactly one run time parameter.
    if( argc != 2 ) {
        cerr << "Usage: Assem <FileName>" << endl;
        exit( 1 );
    }
    // Open the file.  One might question if this is the best place to open the file.
    // One might also question whether we need a file access class.
    m_sfile.open( argv[1], ios::in );

    // If the open failed, report the error and terminate.
    if( ! m_sfile ) {
        cerr << "Source file could not be opened, assembler terminated."
            << endl;
        exit( 1 ); 
    }
}

/**/
/*

NAME	

    ~FileAccess()

SYNOPSIS

    FileAccess::~FileAccess()

DESRIPTION

    This function is a deconstructor that ensures that the file will be closed when the program terminates. 

RETURNS

    No return value

*/
/**/
FileAccess::~FileAccess( )
{
    // Not that necessary in that the file will be closed when the program terminates, but good form.
    m_sfile.close( );
}

/**/
/*

NAME	

    FileAccess::GetNextLine()

SYNOPSIS

    bool FileAccess::GetNextLine( string &a_line)

    &a_line -> current line inside the file

DESRIPTION

    This program gets the next line from the file and checks if the end of the input file has been reached.

RETURNS

    Returns true if a new line was retrieved and returns false if the end of the file has been met.

*/
/**/
bool FileAccess::GetNextLine( string &a_line )
{
    // If there is no more data, return false.
    if( m_sfile.eof() ) {
    
        return false;
    }
    getline( m_sfile, a_line );
    
    // Return indicating success.
    return true;
}

/**/
/*

NAME	

    FileAccess::rewind( )

SYNOPSIS

    void FileAccess::rewind( )

DESRIPTION

    This function rewinds back to the beginning of the file by clearing flags and moves the pointer back to the start of the file. 

RETURNS

    No return value

*/
/**/
void FileAccess::rewind( )
{
    // Clean all file flags and go back to the beginning of the file.
    m_sfile.clear();
    m_sfile.seekg( 0, ios::beg );
}
    
