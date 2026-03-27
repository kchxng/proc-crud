#ifdef EMP_H
#define EMP_H
int emp_insert(int id, const char* name);
int emp_delete(int id);
int emp_update(int id, const char* name);
int emp_select(int id, char* name_buffer, int buffer_size);
#endif // EMP_H