#include <sqlite3.h>

void insert_process_data(sqlite3 *db, int pid, int pc, const char* state, void* sp);
