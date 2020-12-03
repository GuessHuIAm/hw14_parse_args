#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char * args[5];

char ** parse_args(char * s){
	char * p = s;
	int c = 0;
	while(p){
		args[c] = strsep(&p, " ");
		c++;
	}
	args[c] = NULL;
	return args;
}


int main(){
	char s[] = "ls -a -l";
	char ** args = parse_args(s);
	execvp(args[0], args);
	return 0;
}
