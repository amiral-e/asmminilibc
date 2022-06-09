/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test_strrchr
*/

#include <dlfcn.h>
#include <criterion/criterion.h>

static const char *lib_name = "./libasm.so";

Test(strrchr, strrchr_str)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strrchr)(const char *, int) = dlsym(handl, "strrchr");
    char *str = "hellowwworld";

    cr_assert_str_eq(strrchr(str, 'w'), my_strrchr(str, 'w'));
    dlclose(handl);
}

Test(strrchr, strrchr_none)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strrchr)(const char *, int) = dlsym(handl, "strrchr");
    char *str = "hellowwworld";

    cr_assert_eq(strrchr(str, 'z'), my_strrchr(str, 'z'));
    dlclose(handl);
}

Test(strrchr, strrchr_end)
{
    void *handl = dlopen(lib_name, RTLD_LAZY);
    char *(*my_strrchr)(const char *, int) = dlsym(handl, "strrchr");
    char *str = "hellowwworld";

    cr_assert_str_eq(strrchr(str, '\0'), my_strrchr(str, '\0'));
    dlclose(handl);
}
