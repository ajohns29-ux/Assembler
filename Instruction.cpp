#include "stdafx.h"
#include "Instruction.h"
#include <sstream>
#include <string>
#include <algorithm>

/**/
/*

NAME	

	Instruction::ParseInstruction()

SYNOPSIS

	Instruction::InstructionType Instruction::ParseInstruction( string a_line )

	a_line -> the current line to be parsed

DESRIPTION

	This function determines the instruction type of an instruction by parsing it into its parts.
    
RETURNS

	Returns the type of instruction the current line is. This means a comment, end, machine language, or assembly instruction.

*/
/**/
Instruction::InstructionType Instruction::ParseInstruction( string a_line )
{
	// remove comments from instruction
    string line = RemoveComment(a_line);
    
    // Break line into lable, opt code, and up two operands
    ParseLine(line, m_Label, m_OpCode, m_Operand1, m_Operand2);

	// if there is no opt code, the instruction is a comment
    if(m_OpCode.empty() )
    {
        return Instruction::ST_Comment;
    }

	// if the opcode has END, the instuction is the end instruction
	if(m_OpCode == "END")
	{
		return Instruction::ST_End;
	}

	// if the first character of the label is a number, the instruction is a machine language instruction
	if( m_Label[0] >= '0' && m_Label[0] <= '9')
	{
		return Instruction::ST_MachineLanguage;
	}

	// in any other case, assume the instruction is an assembler instruction
	return Instruction::ST_AssemblerInstr;
   
  
}

/**/
/*

NAME	

	Instruction::RemoveComment()

SYNOPSIS

	string Instruction::RemoveComment(const string& line)

	&line -> current instruction that may have a comment
	
DESRIPTION

	This function removes the comments from the current instruction by finding the semicolon and removing everything after it. 
    
RETURNS

	Returns a string of the same instruction without the comment. 

*/
/**/
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

/**/
/*

NAME	

	Instruction::ParseLine()

SYNOPSIS

	bool Instruction::ParseLine(string line, string &label, string& opcode, string& operand1, string &operand2)

	line -> current line of instruction
	&label -> variable to store the label of the instruction
	&opcode -> variable to store the opcode of the instruction
	&operand1 -> variable to store the first operand of the instruction
	&operand2 -> variable to store the seconds operand of the instruction

DESRIPTION

	This function parses a line into label, opcode, and operands using istringstream.
    
RETURNS

	Returns true if the second operand was the end of the instruction and returns false if the second operand was not at the end of the instruction. In other words, the function returns if the current instruction is in the correct format.

*/
/**/
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
