#include "stdafx.h"

#include "Errors.h"

vector<string> Errors::m_ErrorMsgs;


/**/
  /*

  NAME

    Errors:DisplayErrors()

  SYNOPSIS

     static void Errors::DisplayErrors()

  DESRIPTION

      This function displays all the errors logged while running the assembler.

  RETURNS

     No return value.
     
  */
  /**/
// Displays the collected error message.
static void Errors::DisplayErrors( )
{
    cout << "This is Display Errors function" << endl;
}
/* static void Errors::DisplayErrors */
