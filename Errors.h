//
// Class to manage error reporting.
//
#ifndef _ERRORS_H    // avoids multiple inclusions of Errors.h 
#define _ERRORS_H

#include <string>
#include <vector>

// class that holds errors while running the assembler
class Errors 
{

    public:
        
        // Initializes error reports.
        static void InitErrorReporting( );
    
        // Records an error message.
        static void RecordError( string a_emsg );
    
        // Displays the collected error message.
        static void DisplayErrors( );
    
    private:
    
        static vector<string> m_ErrorMsgs;  
    									
};
#endif.have
