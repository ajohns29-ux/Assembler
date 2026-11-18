//
//		Symbol table class that stores all the symbols and their locations.
//
#pragma once



// Allows full details of symbols in assmbler to be in one place
class SymbolTable {

public:

    // Get rid of constructor and destructor later if you don't need them.
    SymbolTable( ) {};
    ~SymbolTable( ) {};

    // Add a new symbol to the symbol table.
    void AddSymbol( const string &a_symbol, int a_loc );

    // Display the symbol table.
    void DisplaySymbolTable( ) {cout << "DisplaySymbolTable - Aidan J" << endl;}

    // Lookup a symbol in the symbol table.
    bool LookupSymbol( const string &a_symbol, int &a_loc ) {cout << "LookupSymbol - Aidan J" << endl;}

private:

    // This is the actual symbol table.  The symbol is the key to the map.  The value is the location.
    map<string, int> m_symbolTable;

    // ORGINALLY IN PUBLIC MAY NEED TO MOVE BACK
    const int multiplyDefinedSymbol = -999;

};
