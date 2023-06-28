#include "main.h"

/*
* _strcat_cd - concatenates cd error
* @data: data struct
* @msg: prints err msg
* @err: output error
* @count: count lines
*/
char _strcat_cd(my_shell *data, char *msg, char *count, char *err)
{
    char *flag;

    _strcpy(err, data->args[0]);
    _strcat(err, ": ");
    _strcat(err, count);
    _strcat(err, ": ");
    _strcat(err, data->args[0]);
    _strcat(err, msg);
    if (data->args[0][1] == '-')
    {
        flag = malloc(3);
        flag[0] = '-';
        flag[1] = data->args[1][1];
        flag[2] = '\0';
        _strcat(err, flag);
        free(flag);
    }
    else
    {
        _strcat(err, data->args[1]);
    }

    _strcat(err, "\n");
    _strcat(err, "\0");
    return (err);
}

/*
* error_cd - error msg for cd 
* @data: data struct
* return: nothing
*/
char *error_cd(my_shell *data)
{
    int len, i;
    char *err, *count, *msg;

    count = _itoa(data->counter);
    if (data->args[1][0] == '-')
    {
        msg = ": Invalid option ";
        i = 2;
    }
    else
    {
        msg = ": can't cd to ";
        i = _strlen(data->args[1]);
    }

    len = _strlen(data->av[0]) + _strlen(data->args[0]);
    len += _strlen(count) + _strlen(msg) + i + 5;
    err = malloc(sizeof(char) * (len + 1));

    if (err == 0)
    {
        free(count);
        return (NULL);
    }

    err = _strcat_cd(data, msg, err, count);

    free(count);

    return (err);
}

/*
* err_not_found - cmd not found err
* @data: data struct
* return: err message
*/
char *err_not_found(my_shell *data)
{
    int len;
    char *error, *count;

    count = _itoa(data->counter);
    length = _strlen(data->av[0] + _strlen(count));
    length += _strlen(data->args[0]) + 16;
    error = malloc(sizeof(char) * (length + 1));
    if (error == 0)
    {
        free(error);
        free(count);
        return (NULL);
    }
    _strcpy(error, data->av[0]);
    _strcat(error, ": ");
    _strcat(error, count);
    _strcat(error, ": ");
    _strcat(error, data->args[0]);
    _strcat(error, ": not found\n");
    _strcat(error, "\0");
    free(count);
    return(error);
}

/*
* err_exit- handles exit errors
* @data: data struct*
* return: nothing
*/
char *err_exit(my_shell *data)
{
    int length;
    char *err, *count;

    count = _itoa(data->counter);
    length = _strlen(data->av[0] + _strlen(count));
    length += _strlen(data->args[0] + _strlen(data->args[1]) + 23);
    err = malloc(sizeof(char) * (length + 1));
    if (err == 0)
    {
        free(count);
        return;
    }
    _strcpy(err, data->av[0]);
    _strcat(err, ": ");
    _strcat(err, count);
    _strcat(err, ": ");
    _strcat(err, data->args[0]);
    _strcat(err, ": Invalid number: ");
    _strcat(err, data->args[1]);
    _strcat(err, "\n\0");
    free(count);

    return (err);
}