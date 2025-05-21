#include "db_handler.h"
#include <stdio.h>
#include <stdlib.h>

void insert_process_data(sqlite3 *db, int pid, int pc, const char* state, void* sp) {
    char query[256];
    snprintf(query, sizeof(query),
             "INSERT INTO process_data (pid, pc, state, sp) VALUES (%d, %d, '%s', '%p');",
             pid, pc, state, sp);

    char *err_msg = NULL;
    if (sqlite3_exec(db, query, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQLite error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Inserted process %d into DB.\n", pid);
    }
}
