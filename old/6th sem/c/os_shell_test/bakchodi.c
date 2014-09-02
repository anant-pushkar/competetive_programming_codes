/*We use execvp to run the executables.
  From the man page of execvp...
  The file is sought in the colon-separated list
  of directory pathnames specified in the PATH  environment  variable.   If  this
  variable  isn't  defined,  the path list defaults to the current directory followed 
  by the list of directories returned by  confstr(_CS_PATH).   
  (This  confstr(3) call typically returns the value "/bin:/usr/bin".)*/
void handleExec(char input[], char PATH[])
{
	command com = getCommand(input);
	char filePath[BUFSIZE];
	int pid = fork();

	if(pid==0)
	{
		char *argv[BUFSIZE];
		char argument[BUFSIZE];
		int j, len = strlen(com.arguments),i, index=0;
		argv[index] = (char*)malloc(sizeof(com.command));
		strcpy(argv[index++],com.command);
		
		for(i=0;i<len;i++)
		{
			j = 0;
			while(com.arguments[i]!=' ' && com.arguments[i]!='\0')
				argument[j++] = com.arguments[i++];
			argument[j] = '\0';

			argv[index] = (char*)malloc(sizeof(argument));
			strcpy(argv[index++],argument);
		}
		com.arguments[i-1]='\0';
		argv[index] = (char*)malloc(sizeof(char));
		argv[index] = NULL;
		if(execvp(com.command,argv)<0)
			printf("error in executing file : %s",strerror(errno));
  		fflush(stdout);
		exit(0);
	}
	else wait(NULL);
}