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

      This function displays the collected error messages.
  RETURNS

     No return value.
     
  */
  /**/
static void Errors::DisplayErrors( )
{
    cout << "This is Display Errors function" << endl;
}
/* static void Errors::DisplayErrors */




/**/
  /*

  NAME

    Errors:DisplayErrors()

  SYNOPSIS

     static void Errors::DisplayErrors()

  DESRIPTION

      This function displays the collected error messages.
  RETURNS

     No return value.
     
  */
  /**/
// Records an error message.
static void RecordError( string a_emsg )
{
    cout << "This is the RecordError function" << endl;
}
/* static void RecordError( string a_emsg ) */
