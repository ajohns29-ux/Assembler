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
Instruction::InstructionType Instruction::ParseInstruction(string a_line)
{
	// remove comments from instruction
	string line = RemoveComment(a_line);

	// Break line into lable, opt code, and up two operands
	ParseLine(a_line, m_Label, m_OpCode, m_Operand1, m_Operand2);

	// if there is no opt code, the instruction is a comment
	if (m_OpCode.empty())
	{
		return Instruction::ST_Comment;
	}

	// if the opcode has END, the instuction is the end instruction
	if (m_OpCode == "END")
	{
		return Instruction::ST_End;
	}

	// if the first character of the label is a number, the instruction is a machine language instruction
	if (m_Label[0] >= '0' && m_Label[0] <= '9')
	{
		return Instruction::ST_MachineLanguage;
	}

	// in any other case, assume the instruction is an assembler instruction
	return Instruction::ST_AssemblerInstr;


}
/* Instruction::InstructionType Instruction::ParseInstruction( string a_line ) /*



/**/
/*

NAME

	Instruction::RemoveComment()

SYNOPSIS

	string Instruction::RemoveComment(const string& a_line)

	&a_line -> current instruction that may have a comment

DESRIPTION

	This function removes the comments from the current instruction by finding the semicolon and removing everything after it.

RETURNS

	Returns a string of the same instruction without the comment.

*/
/**/
string Instruction::RemoveComment(const string& a_line)
{
	size_t pos = a_line.find(';');

	if (pos == string::npos)
	{
		return a_line;
	}
	string temp = a_line;

	return temp.erase(pos);
}
/* string Instruction::RemoveComment(const string& a_line) */



/**/
/*

NAME

	Instruction::ParseLine()

SYNOPSIS

	bool Instruction::ParseLine(string a_line, string &a_label, string& a_opcode, string& a_operand1, string &a_operand2)

	a_line -> current line of instruction
	&a_label -> variable to store the label of the instruction
	&a_opcode -> variable to store the opcode of the instruction
	&a_operand1 -> variable to store the first operand of the instruction
	&a_operand2 -> variable to store the seconds operand of the instruction

DESRIPTION

	This function parses a line into label, opcode, and operands using istringstream.

RETURNS

	Returns true if the second operand was the end of the instruction and returns false if the second operand was not at the end of the instruction. In other words, the function returns if the current instruction is in the correct format.

*/
/**/
bool Instruction::ParseLine(string a_line, string& a_label, string& a_opcode, string& a_operand1, string& a_operand2)
{
	// Replace commas with blanks.  I will leave this for you to figure out how to do it.
	replace(a_line.begin(), a_line.end(), ',', ' ');

	// create istring stream object with line and declare string arguments 
	istringstream ins(a_line);
	a_label = a_opcode = a_operand1 = a_operand2 = "";

	// if there is no instruction, nothing to parse
	if (a_line.empty()) return true;

	string extra = "";

	// if first character is not a space or a tab, there is a label
	// using istringstream object, retrieve the label, opcode, and operands
	if (a_line[0] != ' ' && a_line[0] != '\t')
	{
		ins >> a_label;
	}
	ins >> a_opcode >> a_operand1 >> a_operand2 >> extra;

	return extra == "";
}
/* bool Instruction::ParseLine(string a_line, string &a_label, string& a_opcode, string& a_operand1, string &a_operand2 ) */



/**/
/*

NAME

	Instruction::LocationNextInstruction()

SYNOPSIS

	int Instruction::LocationNextInstruction( int a_loc )

	a_loc -> The current location of the instruction

DESRIPTION

	This function computes the location of the next instruction based on the opcode.

RETURNS

	Returns the integer position of the next instruction.

*/
/**/
int Instruction::LocationNextInstruction(int a_loc)
{
	// variable of operand1 as a integer
	// what if x isn't a number
	int opInt = stoi(m_Operand1);

	// if define constant, allocate space 
	if (m_OpCode == "DS")
	{
		return a_loc + opInt;
	}

	// if org, go to address
	if (m_OpCode == "ORG")
	{
		return opInt;
	}

	// if else, plus 1
	return a_loc + 1;
}
/* int Instruction::LocationNextInstruction( int a_loc ) */
