//
//  main.c
//  SQLite clone
//
//  Created by Nhat Minh on 23/05/2023.
//

#include <stdio.h>
#include <string.h>
#include "REPL.h"
#include "DATA_FIELD.h"

int main(int argc, const char * argv[]) {
    InputBuffer* input_buffer = new_input_buffer();
    while (1) {
        print_prompt();
        read_input(input_buffer);
        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            if(input_buffer->buffer[0] == '.') {
                switch(do_meta_command(input_buffer)) {
                    case (META_COMMAND_SUCCESS):
                        continue;
                    case (META_COMMAND_UNRECOGNIZED_COMMAND):
                        printf("Unreconized command %s\n", input_buffer -> buffer);
                        continue;
                }
            }
        }
        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
            case (PREPARE_SUCCESS):
                break;
            case (PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
                continue;
        }
        execute_statement(&statement);
        printf("Executed.\n");
    }
    return 0;
}
