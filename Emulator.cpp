 /**/
  /*
  
  NAME	
  
    Emulator::insertMemory()
  
  SYNOPSIS
  
    bool Emulator::insertMemory( int a_location, long long a_contents )

      a_location -> the location where the contents will be recorded
      a_contents -> value to be recorded into memory
  
  DESRIPTION
  
      This function inserts data into the memory location of the emulator. 
  
  RETURNS
  
      Returns true if the insertion was successful and returns false if the location arguments is out of the bounds of memory. 
  
  */
  /**/
  bool Emulator::insertMemory( int a_location, long long a_contents )
  {
      if(a_location < 0 || a_location >= MEMSZ)
      {
          return false;
      }
      m_memory[a_location] = a_contents;
      return true;
  } 
  /*     bool Emulator::insertMemory( int a_location, long long a_contents ) */
