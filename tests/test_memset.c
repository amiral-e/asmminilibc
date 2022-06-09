/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_memset
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(memset, memset_good)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    void *(*my_memset)(void *, int, size_t) = dlsym(handl, "memset");
    char str[11] = "helloworld";

    memset(str, 'x', 5);
    cr_assert_str_eq(str, "xxxxxworld");
    dlclose(handl);
}