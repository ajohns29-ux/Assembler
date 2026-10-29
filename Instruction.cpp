#include "stdafx.h"
#include "Instruction.h"
#include <sstream>
#include <string>
#include <algorithm>

Instruction::InstructionType Instruction::ParseInstruction( string a_line )
{
    string line = RemoveComment(a_line);
    
    // Break line into lable, opt code, and up two operands
    ParseLine(line, m_Label, m_OpCode, m_Operand1, m_Operand2);
    
    if(m_OpCode.empty() )
    {
        return Instruction::ST_Comment;
    }

	// what makes an instruction a machine language instruction, assembly language, or end statement
    return Instruction::ST_MachineLanguage;
  
}

string Instruction::RemoveComment(const string& line) 
{
    size_t pos = line.find(';');

    if (pos == string::npos)
    {
        return line;
    }
    string temp = line;

    return temp.erase(pos);
}

// Will parse a line into label, op code, and operand.
bool Instruction::ParseLine(string line, string &label, string& opcode, string& operand1, string &operand2 )
{
	// Replace commas with blanks.  I will leave this for you to figure out how to do it.
	replace( line.begin(), line.end(), ',', ' ');
	
    istringstream ins(line);
    label = opcode = operand1 = operand2 = "";
    if (line.empty()) return true;

    string extra;

    if (line[0] != ' ' && line[0] != '\t')
    {
        ins >> label;
    }
    ins >> opcode >> operand1 >> operand2 >> extra;

    return extra == "";
}
