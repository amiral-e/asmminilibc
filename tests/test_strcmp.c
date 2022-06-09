/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_strcmp
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(strcmp, strcmp_equ)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strcmp)(const char *, const char *) = dlsym(handl, "strcmp");
    char *str = "hellowwworld";
    char *str2 = "hellowwworld";

    cr_assert_eq(strcmp(str, str2), my_strcmp(str, str2));
    dlclose(handl);
}

Test(strcmp, strcmp_more)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strcmp)(const char *, const char *) = dlsym(handl, "strcmp");
    char *str = "hellowwworldxxx";
    char *str2 = "hellowwworld";

    cr_assert_eq(strcmp(str, str2), my_strcmp(str, str2));
    dlclose(handl);
}

Test(strcmp, strcmp_less)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strcmp)(const char *, const char *) = dlsym(handl, "strcmp");
    char *str = "hellowwworld";
    char *str2 = "hellowwworldxxx";

    cr_assert_eq(strcmp(str, str2), my_strcmp(str, str2));
    dlclose(handl);
}
