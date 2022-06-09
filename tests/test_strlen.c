/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_strlen
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(strlen, strlen_str)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    int (*my_strlen)(char *) = dlsym(handl, "strlen");
    char *str = "helloworld";

    cr_assert_eq(strlen(str), my_strlen(str));
    dlclose(handl);
}

Test(strlen, strlen_null)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    int (*my_strlen)(char *) = dlsym(handl, "strlen");
    char *str = "";

    cr_assert_eq(strlen(str), my_strlen(str));
    dlclose(handl);
}
