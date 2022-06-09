/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_memcpy
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(memcpy, memcpy_good)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    void *(*my_memcpy)(void *, int, size_t) = dlsym(handl, "memcpy");
    char str[11] = "helloworld";
    char dest[6];

    memcpy(dest, str, 5);
    cr_assert_str_eq(dest, "hello");
    dlclose(handl);
}