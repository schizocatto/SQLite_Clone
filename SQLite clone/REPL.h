//
//  REPL.h
//  SQLite clone
//
//  Created by Nhat Minh on 23/05/2023.
//

#ifndef REPL_h
#define REPL_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Buffer Stream
typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer(void);

void print_prompt(void);
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);

//Meta Commands
typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

//Statements
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
    StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

void execute_statement(Statement* statement);

#endif /* REPL_h */
