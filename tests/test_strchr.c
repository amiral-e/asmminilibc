/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_strchr
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(strchr, strchr_str)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strchr)(const char *, int) = dlsym(handl, "strchr");
    char *str = "helloworld";

    cr_assert_str_eq(strchr(str, 'w'), my_strchr(str, 'w'));
    dlclose(handl);
}

Test(strchr, strchr_none)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strchr)(const char *, int) = dlsym(handl, "strchr");
    char *str = "helloworld";

    cr_assert_eq(strchr(str, 'z'), my_strchr(str, 'z'));
    dlclose(handl);
}

Test(strchr, strchr_end)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strchr)(const char *, int) = dlsym(handl, "strchr");
    char *str = "helloworld";

    cr_assert_str_eq(strchr(str, '\0'), my_strchr(str, '\0'));
    dlclose(handl);
}
