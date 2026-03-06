#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include "execute.h"
#include "lexer.h"
#include "execute.h"
#include "parser.h"


// NOTE: even though this file does not peek() at or get() any
// tokens, the very fact that a lexer is declared
// requires that you provide input to the program
// when you execute it even if you don't add any code
// to execute just run ./a.out < test, where test is any
// test case
LexicalAnalyzer lexer;   
Parser parser;

struct InstructionNode *parse_Generate_Intermediate_Representation()
{
    InstructionNode* instructionList;
    instructionList = parser.parse_program();

    return instructionList;
 }
