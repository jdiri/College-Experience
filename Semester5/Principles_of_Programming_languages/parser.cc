
 #include <cstddef>
#include <cstdio>
 #include <cstring>
 #include <iostream>
 #include <cstdlib>
 #include <string>
#include <unordered_map>
 #include <vector>
 #include "parser.h"
 #include "lexer.h"
 #include "execute.h"
 
 using namespace std;

 unordered_map<string, int> loc_table;
 vector<string> orderOfInputs;

 Token Parser::expect(TokenType expected_type)
 {
    Token t = lexer.GetToken();
    if (t.token_type != expected_type){
        syntax_error();
    }
    return t;
 }
 
 void Parser::syntax_error()
 {   
     Token t = lexer.peek(1);
     cout << "SYNTAX ERROR !!!!!!!!!!!!!!\n";
     exit(1);
 }

 int Parser::location(string s){
    return loc_table[s];
 }

 struct InstructionNode* Parser::parse_program(){
    struct InstructionNode* instructionList = new InstructionNode;
    parse_var_section();
    instructionList = parse_body();
    parse_inputs();
    expect(END_OF_FILE);
    return instructionList;
 }

 void Parser::parse_var_section(){
    parse_id_list();
    expect(SEMICOLON);
 }
 
 void Parser::parse_id_list(){
    Token t = expect(ID);
    loc_table[t.lexeme]=next_available;
    next_available++;
    
    if (lexer.peek(1).token_type == COMMA) {
        expect(COMMA);
        parse_id_list();
    }
    if (lexer.peek(1).token_type == SEMICOLON) {
        return;
    }
    else {
        syntax_error();
    }
 }

 struct InstructionNode* Parser::parse_body(){
    struct InstructionNode* instructionsList = new InstructionNode;
    expect(LBRACE);
    instructionsList = parse_stmt_list();
    expect(RBRACE);
    return instructionsList;
 }

 struct InstructionNode* Parser::parse_stmt_list(){
    struct InstructionNode* instructionsHead;
    struct InstructionNode* instructionsList;
    instructionsHead = parse_stmt(); 
    Token t = lexer.peek(1);

    if (t.token_type != RBRACE) {
        instructionsList = parse_stmt_list();
        struct InstructionNode* last = instructionsHead;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = instructionsList;
    }


    // struct InstructionNode* instructionsHead = new InstructionNode;
    // struct InstructionNode* instructionsList = new InstructionNode;
    // instructionsHead = parse_stmt(); 
    // Token t = lexer.peek(1);
    // if (t.token_type == LBRACE) {
    //     instructionsList = parse_stmt_list();
    //     struct InstructionNode* last = instructionsHead;
    //     while (last->next != nullptr) {
    //         last = last->next;
    //     }
    //     last->next = instructionsList;
    // }else if (t.token_type != RBRACE) {
    //     instructionsList = parse_stmt_list();
    //     instructionsHead->next = instructionsList;
    // }
    // return instructionsHead;
    return instructionsHead;
 }

 struct InstructionNode* Parser::parse_stmt(){
    struct InstructionNode* instruction = new InstructionNode;
    
    Token t = lexer.peek(1);
    if (t.token_type == ID) {   //assign stmt
        instruction = parse_assign_stmt();
        return instruction;
    }

    else if (t.token_type == WHILE) {        //while stmt
        instruction = parse_while_stmt();
        return instruction;
    }

    else if (t.token_type == IF) {        //if stmt
        instruction = parse_if_stmt();
        return instruction;
    }

    else if (t.token_type == SWITCH) {        //switch stmt
        instruction = parse_switch_stmt();
        return instruction;
    }

    else if (t.token_type == FOR) {        //for stmt
        instruction = parse_for_stmt();
        return instruction;
    }

    else if (t.token_type == OUTPUT) {        //output stmt
        instruction = parse_output_stmt();
        return instruction;
    }

    else if (t.token_type == INPUT) {        //input stmt
        instruction = parse_input_stmt();
        return instruction;
    }

    else {
        syntax_error();
    }
 }

 struct InstructionNode* Parser::parse_assign_stmt(){
    struct InstructionNode* instruction = new InstructionNode;
    instruction->next = nullptr;
    instruction->type = ASSIGN;
    instruction->assign_inst.lhs_loc = location(expect(ID).lexeme);
    expect(EQUAL);
    Token t = lexer.peek(2);
    if (t.token_type == PLUS || t.token_type == MINUS || t.token_type == MULT || t.token_type == DIV) {
        InstructionNode* rhs = parse_expr();
        instruction->assign_inst.op1_loc = rhs->assign_inst.op1_loc;
        instruction->assign_inst.op2_loc = rhs->assign_inst.op2_loc;
        instruction->assign_inst.op = rhs->assign_inst.op;
        expect(SEMICOLON);
    }
    else {
        instruction->assign_inst.op1_loc = parse_primary();
        instruction->assign_inst.op = OPERATOR_NONE;
        expect(SEMICOLON);
    }
    return instruction;
 }

 struct InstructionNode* Parser::parse_expr(){
    struct InstructionNode* rhs = new InstructionNode;
    rhs->assign_inst.op1_loc = parse_primary();
    rhs->assign_inst.op = parse_op();
    rhs->assign_inst.op2_loc = parse_primary();
    return rhs;
 }

 int Parser::parse_primary(){
    Token t = lexer.peek(1);
    if (t.token_type == ID) {
        expect(ID);
        return loc_table[t.lexeme];
    }
    else if (t.token_type == NUM) {
        Token t1 = expect(NUM);

        loc_table[t1.lexeme] = next_available;
        mem[next_available] = stoi(t.lexeme);
        next_available++;
        return location(t1.lexeme);
    }
    else {
        syntax_error();
        return -1;
    }
 }

 ArithmeticOperatorType Parser::parse_op(){
    Token t = lexer.peek(1);
    if (t.token_type == PLUS) {
        expect(PLUS);
        return OPERATOR_PLUS;
    }
    else if (t.token_type == MINUS) {
        expect(MINUS);
        return OPERATOR_MINUS;
    }
    else if (t.token_type == MULT) {
        expect(MULT);
        return OPERATOR_MULT;
    }
    else if (t.token_type == DIV) {
        expect(DIV);
        return OPERATOR_DIV;
    }
    else {
        syntax_error();
    }
 }

 struct InstructionNode* Parser::parse_while_stmt(){
    expect(WHILE);
    struct InstructionNode* instruction = parse_condition();
    instruction->next = parse_body();

    InstructionNode* jmpNode = new InstructionNode;
    jmpNode->type = JMP;
    jmpNode->jmp_inst.target = instruction;
    jmpNode->next = nullptr;
    struct InstructionNode* temp = instruction;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = jmpNode;

    struct InstructionNode* noopNode = new InstructionNode;
    noopNode->type = NOOP;
    noopNode->next = nullptr;
    struct InstructionNode* temp2 = instruction;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = noopNode;
    instruction->cjmp_inst.target = noopNode;
    return instruction;
 }

 struct InstructionNode* Parser::parse_if_stmt(){
    expect(IF);
    struct InstructionNode* instruction = parse_condition();

    instruction->next= parse_body();
    struct InstructionNode* noopNode = new InstructionNode;
    noopNode->type = NOOP;
    noopNode->next = nullptr;
    struct InstructionNode* temp = instruction;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = noopNode;
    instruction->cjmp_inst.target = noopNode;
    
    return instruction;
 }

 struct InstructionNode* Parser::parse_switch_stmt() {
    expect(SWITCH);
    int loc = location(expect(ID).lexeme);
    expect(LBRACE);

    InstructionNode* noopNode = new InstructionNode;
    noopNode->type = NOOP;
    noopNode->next = nullptr;

    InstructionNode* head = parse_case_list(loc, noopNode);

    if (lexer.peek(1).token_type == RBRACE) {
        expect(RBRACE);
        InstructionNode* temp = head;
       
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = noopNode; 
        return head;
    }
    else if (lexer.peek(1).token_type == DEFAULT) {
        InstructionNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = parse_default_case(noopNode);
        expect(RBRACE);

        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = noopNode; 
        return head;
    }
    else {
        syntax_error(); 
    }
}

 struct InstructionNode* Parser::parse_for_stmt(){
    expect(FOR);                    //gather parts
    expect(LPAREN);
    struct InstructionNode* assign1 = parse_assign_stmt();
    struct InstructionNode* instruction = parse_condition();
    expect(SEMICOLON);
    struct InstructionNode* assign2 = parse_assign_stmt();
    expect(RPAREN);
    instruction->next = parse_body();

    assign1->next = instruction;                    //make first instruction the initialization

    struct InstructionNode* temp = instruction;     //append 2nd assignment stmt to end
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = assign2;

    InstructionNode* jmpNode = new InstructionNode;
    jmpNode->type = JMP;
    jmpNode->jmp_inst.target = instruction;
    jmpNode->next = nullptr;
    temp = instruction;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = jmpNode;


    struct InstructionNode* noopNode = new InstructionNode;
    noopNode->type = NOOP;
    noopNode->next = nullptr;
    temp = instruction;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = noopNode;
    instruction->cjmp_inst.target = noopNode;

    return assign1;
 }

 struct InstructionNode* Parser::parse_output_stmt(){
    struct InstructionNode* outputStmt = new InstructionNode;
    expect(OUTPUT);
    outputStmt->type = OUT;
    outputStmt->output_inst.var_loc = location(expect(ID).lexeme);
    outputStmt->next = NULL;
    expect(SEMICOLON);
    return outputStmt;
 }

 struct InstructionNode* Parser::parse_input_stmt(){
    struct InstructionNode* inputStmt = new InstructionNode;
    expect(INPUT);
    inputStmt->type = IN;
    inputStmt->next = NULL;
    inputStmt->input_inst.var_loc = location(expect(ID).lexeme);
    expect(SEMICOLON);
    return inputStmt;
 }

 struct InstructionNode* Parser::parse_condition(){
    struct InstructionNode* conditionstmt = new InstructionNode;
    conditionstmt->next = nullptr;
    conditionstmt->type = CJMP;
    conditionstmt->cjmp_inst.op1_loc = parse_primary();
    conditionstmt->cjmp_inst.condition_op = parse_relop();
    conditionstmt->cjmp_inst.op2_loc = parse_primary();
    return conditionstmt;
 }

 ConditionalOperatorType Parser::parse_relop(){
    Token t = lexer.peek(1);
    if (t.token_type == GREATER) {
        expect(GREATER);
        return CONDITION_GREATER;
    }
    else if (t.token_type == LESS) {
        expect(LESS);
        return CONDITION_LESS;
    }
    else if (t.token_type == NOTEQUAL) {
        expect(NOTEQUAL);
        return CONDITION_NOTEQUAL;
    }
    else {
        syntax_error();
    }
 }
 
 InstructionNode* Parser::parse_case_list(int op1, InstructionNode* noopNode) {
    InstructionNode* caseList = parse_case(op1, noopNode);
    if (lexer.peek(1).token_type == RBRACE || lexer.peek(1).token_type == DEFAULT) {
        return caseList;
    }
    InstructionNode* temp = caseList;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = parse_case_list(op1, noopNode); // Recursively parse the next case
    return caseList;
}

InstructionNode* Parser::parse_case(int op1, InstructionNode* noopNode) {
    InstructionNode* kase = new InstructionNode;
    expect(CASE);
    kase->type = CJMP;
    kase->cjmp_inst.op1_loc = op1;
    Token t = expect(NUM);
    loc_table[t.lexeme] = next_available;
    mem[next_available] = stoi(t.lexeme);
    next_available++;
    int loc = location(t.lexeme);
    kase->cjmp_inst.op2_loc = loc;
    kase->cjmp_inst.condition_op = CONDITION_NOTEQUAL;
    expect(COLON);

    InstructionNode* endOfCase = new InstructionNode;
    endOfCase->next = nullptr;
    endOfCase->type = NOOP;

    InstructionNode* body = parse_body();
    InstructionNode* jmpNode = new InstructionNode;
    jmpNode->type = JMP;
    jmpNode->jmp_inst.target = noopNode;
    jmpNode->next = endOfCase;
    

    InstructionNode* temp = body;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = jmpNode;
    
    kase->cjmp_inst.target = body;
    kase->next = endOfCase;
    return kase;
}

 InstructionNode* Parser::parse_default_case(InstructionNode* noopNode){
    expect(DEFAULT);
    expect(COLON);
    InstructionNode* defaultCase = parse_body();
    // InstructionNode* jmpNode = new InstructionNode;
    // jmpNode->type = JMP;
    // jmpNode->jmp_inst.target = noopNode;
    // jmpNode->next = nullptr;
    
    // InstructionNode* endOfCase = new InstructionNode;
    // endOfCase->next = jmpNode;
    // endOfCase->type = JMP;

    // InstructionNode* temp = defaultCase;
    // while (temp->next != nullptr) {
    //     temp = temp->next;
    // }
    // temp->next = jmpNode;
    // //defaultCase->next = endOfCase;
    return defaultCase;
 }

 void Parser::parse_inputs(){
    parse_num_list();
 }

 void Parser::parse_num_list(){
    inputs.push_back(stoi(expect(NUM).lexeme));
    if (lexer.peek(1).token_type == NUM) {
        parse_num_list();
    }
    /*for (int i = 0; i<orderOfInputs.size(); i++) {
        mem[location(orderOfInputs[next_input])] = inputs[next_input];
        next_input++;
    }*/
 }

 struct InstructionNode *parse_Generate_Intermediate_Representation()
{
    Parser parser;
    InstructionNode* instructionList = parser.parse_program();
    return instructionList;
 }
 