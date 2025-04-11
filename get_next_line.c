#include "get_next_line.h"

char *ft_strdup(char *str)
{
    int i = 0;
    int j = 0;
    char *new;
    while (str[i])
    {
        i++;
    }
    
    new = (char *)malloc(i + 1);
    if (!new)
        return (NULL);
    while (str[j])
    {
        new[j] = str[j];
        j++;
    }
    new[j] = '\0';
    return (new);
}

char *get_next_line(int fd)
{
    int i;
    static char buff[BUFFER_SIZE];
    static int buff_read;
    static int buff_pos;
    char line[70000];
    
    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buff_pos >= buff_read)
        {
            buff_read = read(fd, buff, BUFFER_SIZE);
            buff_pos = 0;
            if (buff_read <= 0)
                break;
        }
        line[i++] = buff[buff_pos++];
        if (line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}
