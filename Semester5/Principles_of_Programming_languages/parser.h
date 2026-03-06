#ifndef __PARSER_H__
#define __PARSER_H__

#include <cstddef>
#include <string>
#include <vector>
#include "execute.h"
#include "lexer.h"

using namespace std;

class Parser {
  public:
    struct InstructionNode* parse_program();
    void parse_var_section();
    void parse_id_list();
    struct InstructionNode* parse_body();
    struct InstructionNode* parse_stmt_list();
    struct InstructionNode* parse_stmt();
    struct InstructionNode* parse_assign_stmt();
    struct InstructionNode* parse_expr();
    int parse_primary();
    ArithmeticOperatorType parse_op();
    struct InstructionNode* parse_output_stmt();
    struct InstructionNode* parse_input_stmt();
    struct InstructionNode* parse_while_stmt();
    struct InstructionNode* parse_if_stmt();
    struct InstructionNode* parse_condition();
    ConditionalOperatorType parse_relop();
    struct InstructionNode* parse_switch_stmt();
    struct InstructionNode* parse_for_stmt();
    InstructionNode* parse_case_list(int,InstructionNode*);
    InstructionNode* parse_case(int,InstructionNode*);
    InstructionNode* parse_default_case(InstructionNode*);
    void parse_inputs();
    void parse_num_list();

    int location(string);

  private:
    LexicalAnalyzer lexer;
    void syntax_error();
    Token expect(TokenType expected_type);
};

#endif