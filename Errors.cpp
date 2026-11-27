#include "stdafx.h"

#include "Errors.h"

vector<string> Errors::m_ErrorMsgs;


/**/
  /*

  NAME

    Errors::DisplayErrors()

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

    Errors::RecordError()

  SYNOPSIS

     static void Errors::RecordError( string a_emsg )

     a_emsg -> an error message that will be added to the vector of errors

  DESRIPTION

      This function takes an error message and records it to an vector of errors. 
      
  RETURNS

     No return value.
     
  */
  /**/
static void Errors::RecordError( string a_emsg )
{
    cout << "This is the RecordError function" << endl;
}
/* static void RecordError( string a_emsg ) */




/**/
  /*

  NAME

    Errors::InitErrorReporting()()

  SYNOPSIS

     static void Errors::InitErrorReporting()

  DESRIPTION

      This function initializes error reports. 
      
  RETURNS

     No return value.
     
  */
  /**/
static void Errors::InitErrorReporting( )
{
    cout << "This is the InitErrorReporting function" << endl;
}
/* static void Errors::InitErrorReporting() */
