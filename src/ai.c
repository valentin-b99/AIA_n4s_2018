/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test2
*/

#include "../include/ai.h"

int set_dir(int mid, int left, int right)
{
    if (right > left)
        my_putstr("WHEELS_DIR:-0.");
    else if (left > right)
        my_putstr("WHEELS_DIR:0.");
    if ((left < 200 || right < 200) && mid >= 600)
        return (my_putstr("15\n"));
    if (mid >= 1500)
        return (my_putstr("01\n"));
    if (mid >= 1000)
        return (my_putstr("07\n"));
    if (mid >= 600)
        return (my_putstr("15\n"));
    if (mid >= 400)
        return (my_putstr("25\n"));
    if (mid >= 200)
        return (my_putstr("35\n"));
    return (my_putstr("55\n"));
}

int set_speed(int mid, int left, int right)
{
    int coef = 0;
    if (left - right > 0)
        coef = left - right;
    else
        coef = right - left;
    if (mid >= 2000 && coef < 1600)
        return (my_putstr("CAR_FORWARD:1.0\n"));
    if (mid >= 1500 && coef < 1300)
        return (my_putstr("CAR_FORWARD:0.8\n"));
    if (mid >= 1000)
        return (my_putstr("CAR_FORWARD:0.5\n"));
    if (mid >= 600)
        return (my_putstr("CAR_FORWARD:0.4\n"));
    if (mid >= 400)
        return (my_putstr("CAR_FORWARD:0.2\n"));
    return (my_putstr("CAR_FORWARD:0.1\n"));
}

void set_vars(int *left, int *right, int *mid, char **array)
{
    *left = my_getnbr(array[3]);
    *right = my_getnbr(array[34]);
    *mid = (my_getnbr(array[17]) + my_getnbr(array[11]) +
    my_getnbr(array[23])) / 3;
    set_speed((my_getnbr(array[17]) + my_getnbr(array[5]) +
    my_getnbr(array[29])) / 3, *left, *right);
}

int ai_loop(void)
{
    int left = 0;
    int right = 0;
    int mid = 0;
    char **array = NULL;
    char *str = NULL;

    my_putstr("GET_INFO_LIDAR\n");
    if ((str = get_next_line(0)) == NULL)
        return (puttest("STOP_SIMULATION\n", 1));
    if ((array = my_str_to_word_array_two(str, ':')) == NULL)
        return (puttest("STOP_SIMULATION\n", 1));
    if (my_strcmp(array[35], "Track Cleared") == 0)
        return(0);
    set_vars(&left, &right, &mid, array);
    if (get_next_line(0) == NULL)
        return (puttest("STOP_SIMULATION\n", 1));
    set_dir(mid, left, right);
    if (get_next_line(0) == NULL)
        return (puttest("STOP_SIMULATION\n", 1));
    return (1);
}

int main(void)
{
    char *str;
    int res = 0;

    my_putstr("START_SIMULATION\n");
    if ((str = get_next_line(0)) == NULL)
        return (puttest("STOP_SIMULATION\n", 1));
    else if (str[0] != '1' && str[0] != '2')
        return (84);
    my_putstr("CAR_FORWARD:0.3\n");
    if ((str = get_next_line(0)) == NULL)
        return (puttest("STOP_SIMULATION\n", 1));
    while (1) {
        if ((res = ai_loop()) == 84)
            return (84);
        else if (res == 0)
            break;
    }
    my_putstr("STOP_SIMULATION\n");
    return (0);
}