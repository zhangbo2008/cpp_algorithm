#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

int main (void)
{
    int fd = -1;// 先开一个文件描述id

    fd = open("tmp", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    /* if error */

#if 1
    close(1); // 关闭标准输出
    dup(fd);
#endif
    dup2(fd, 1);
    close(fd);

    /* 要求在不改变下面的内容的情况下，使输出的内容到文件中  */

    puts("dup test.");

    return 0;
}