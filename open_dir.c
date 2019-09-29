#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dir;

	if (argc !=2)
	{
		printf("Please provide the directory to list out\n");
		exit(0);
	}
	
	if ((dp = opendir(argv[1])) == NULL)
	{
		printf("Cannot open directory error=%s", strerror(errno));
	}

	while ((dir = readdir(dp)) != NULL)
		printf("%s\n", dir->d_name);
	
	closedir(dp);
	exit(0);
}
