#include <stdio.h>
#include "tokenizer.c"
#include "parser.c"
#include "codegen.c"


int main(int args, char** argvs){
//	if(args < 2){
//		printf("Fatal Error! No input files specified\n USAGE: './main [filename] [options]...'\n");
//		return 1;
//	};

	FILE * file = fopen("test.c","r");
	if(!file){
		printf("Unable to open File!!!\n");
		return 1;
	};

	char src[2048] = {};

	while(!feof(file)){
		fread(src,2048,1,file);
	};
	int nodespace = Tokenizer(src);
//	for(int i = 0; i < nodespace;i++){
//		printf("%d:\t%s\t----> %s\n",tokens[i].id,NODES[tokens[i].type],tokens[i].string);
//	}

	Node root = parse();
	int posind = 0;

	for(int i = 0; i < tkncnt;i++){
		int offset = 0;
		if(tokens[i].type >= ADD && tokens[i].type <= LOGIC_EQUAL){
			traverse(&tokens[i],&posind);
		}else if(tokens[i].type == RETURN){
			traverse(&tokens[i],&posind);
		}else if(tokens[i].type == FUNC_CALL){
			traverse(&tokens[i],&posind);
		}else if(tokens[i].type == FUNC_DEC){
		  	traverse(&tokens[i],&posind);
		}else{
		//	printf("Default token %s\n",tokens[i].string);
		}
	};
//	printf("------\n%s",src);

	return 0;
};
