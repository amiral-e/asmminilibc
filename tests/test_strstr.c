/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_strstr
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(strstr, strstr_str)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strstr)(const char *, const char *) = dlsym(handl, "strstr");
    char *str = "hellowwworldd";

    cr_assert_str_eq(my_strstr(str, "world"), strstr(str, "world"));
    dlclose(handl);
}

Test(strstr, strstr_not_found)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strstr)(const char *, const char *) = dlsym(handl, "strstr");
    char *str = "hellowwworld";

    cr_assert_eq(my_strstr(str, "z"), strstr(str, "z"));
    dlclose(handl);
}

Test(strstr, strstr_null_needle)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strstr)(const char *, const char *) = dlsym(handl, "strstr");
    char *str = "hellowwworld";

    cr_assert_eq(my_strstr(str, ""), strstr(str, ""));
    dlclose(handl);
}

Test(strstr, strstr_null_haystack)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strstr)(const char *, const char *) = dlsym(handl, "strstr");
    char *str = "hellowwworld";

    cr_assert_eq(my_strstr("", str), strstr("", str));
    dlclose(handl);
}

Test(strstr, strstr_null_both)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strstr)(const char *, const char *) = dlsym(handl, "strstr");

    cr_assert_eq(my_strstr("", ""), strstr("", ""));
    dlclose(handl);
}
