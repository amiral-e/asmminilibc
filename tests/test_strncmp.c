/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_strncmp
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(strncmp, strncmp_equ)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strncmp)(const char *, const char *, size_t) = dlsym(handl, "strncmp");
    char *str = "hellowwworld";
    char *str2 = "hellowwworld";

    cr_assert_eq(strncmp(str, str2, 3), my_strncmp(str, str2, 3));
    dlclose(handl);
}

Test(strncmp, strncmp_more)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strncmp)(const char *, const char *, size_t) = dlsym(handl, "strncmp");
    char *str = "hellowwworldxxx";
    char *str2 = "hellowwworld";

    cr_assert_eq(strncmp(str, str2, 15), my_strncmp(str, str2, 15));
    dlclose(handl);
}

Test(strncmp, strncmp_less)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strncmp)(const char *, const char *, size_t) = dlsym(handl, "strncmp");
    char *str = "hellowwworld";
    char *str2 = "hellowwworldxxx";

    cr_assert_eq(strncmp(str, str2, 15), my_strncmp(str, str2, 15));
    dlclose(handl);
}
