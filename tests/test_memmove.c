/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_memmove
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(memmove, memmove_good)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    void *(*my_memmove)(void *, const void *, size_t) = dlsym(handl, "memmove");
    char dest[] = "old";
    const char src[]  = "new";

    cr_assert_str_eq(my_memmove(dest, src, 3), "new");
    cr_assert_str_eq(dest, "new");
    dlclose(handl);
}