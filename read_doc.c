#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = -1;
	char buffer[10] = {0};
	int ret = 0;

	if (argc != 2)
	{
		printf("Please provide the filename as argument to read\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);

	if( fd == -1)
	{
		printf("Error in opening the file error=%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	while (ret = read(fd, buffer, sizeof(buffer)) > 0)
	{
		printf("%s", buffer);
		memset(buffer, 0, sizeof(buffer));
	}
	close(fd);

	return EXIT_SUCCESS;
}
