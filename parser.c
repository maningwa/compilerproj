#ifndef PARSER_C
#define PARSER_C
#include "tokenizer.c"
#include "type.h"
#include <unistd.h>


int delaytime = 1000;
Node parse(){
	ParseEngineState state = BEG;
	Node root = {.string = {'R','o','o','t','\0'}}; 	//the static node of the compiler state
	Node *current = &root; 	//pointer to the current node initialized at root
	Node *lasthold;
	int i = 0;		//Node index initialized at 0;
	while(i<tkncnt){
	//	printf("\t\tCurrent %s\n",current->string);
		switch(state){
			case BEG:
				if(tokens[i].type == RIGHT_BRACES){
					i++;
					state = EXIT_SCOPE;
				}else if(tokens[i].type == SEMI_COLON){
					//basically skip misplaced colon
					i++;
				}else if(tokens[i].type == UNDEFINED){
					if(tokens[i-1].type >= VOID && tokens[i-1].type <= CONST){
						state = DEC;
					}else {
						state = ACC;
					}
				}else if(tokens[i].type == RETURN){
					state = EXP;
				}else{
					i++;
				//	printf("Defaulting at start\n");
				}
				usleep(delaytime);			
				break;

			case DEC:
	//			printf("Dec %s\n",tokens[i].string);
				//always assigning parent to current node under declaration
				tokens[i].parent = current;
				if(tokens[i+1].type == LEFT_PAREN){
					//Push current node into the declarations
					tokens[i].type = FUNC_DEC;
					tokens[i].codeObj = true;
					lasthold = &tokens[i];
					i+=3;
					state = PARAM;
				}else if(tokens[i+1].type >= ADD && tokens[i].type){
					//push next token to the operator
					tokens[i].codeObj = true;
					i+=1;
					state = EXP;
				}else if (tokens[i].type == SEMI_COLON){
					//exit from the declaration;
					i+=2;
					state = BEG;
				}
				usleep(delaytime);
				break;

			case PARAM:
	//			printf("param %s\n",tokens[i].string);
				if (tokens[i+1].type == COMMA){
					tokens[i].left_child = &tokens[i+3];
					i+=3;
				}
				if(tokens[i+2].type == LEFT_BRACES){
					i+=2;
					state = SCOPING;

				}else if(tokens[i+2].type == SEMI_COLON){
					i+=2;
					state = BEG;
				}

				usleep(delaytime);
				break;

			case SCOPING:
	//			printf("scoping In\n");
				current = lasthold;
				state = BEG;
				usleep(delaytime);
				break;

			case EXIT_SCOPE:
	//			printf("Scoping Out\n");
				current = current->parent;
				usleep(delaytime);
				state = BEG;
				break;

			case ACC:
				tokens[i].codeObj = true;
	//			printf("varacc %s\n",tokens[i].string);
				if(tokens[i+1].type == SEMI_COLON){
					i+=1;
					state = BEG;
				}else if(tokens[i+1].type == LEFT_PAREN){
					tokens[i].type = FUNC_CALL;
					i+=2;
					state = ARGS;
				}else if(tokens[i+1].type >= ADD && tokens[i+1].type <= LOGIC_EQUAL){
					i+=1;
					state = EXP;
				}
				usleep(delaytime);
				break;

			case EXP:
				tokens[i].codeObj = true;
//				printf("%s<--\t{%s}\t-->%s\n",tokens[i-1].string,tokens[i].string,tokens[i+2].string);
				if(tokens[i+2].type == LEFT_PAREN){
					tokens[i].left_child = &tokens[i+1];
					i+=3;
					state = ARGS;
					break;
				}else if(tokens[i+2].type == SEMI_COLON){
					if(tokens[i].type == RETURN){
	//					printf(" %s\t%s\n",tokens[i].string,tokens[i+1].string);
						tokens[i].left_child = &tokens[i+1];
						i+=2;
						state = BEG;
					}else{
						tokens[i].left_child = &tokens[i-1];
						tokens[i].right_child = &tokens[i+1];
						i+=3;
						state = BEG;
					}
				}else{
					tokens[i].left_child = &tokens[i-1];
					tokens[i].right_child = &tokens[i+2];			
					i+=2;
				};
				
				usleep(delaytime);
				break;

			case ARGS:
				tokens[i].codeObj = true;
	//			printf("args\n");
				tokens[i-2].left_child = &tokens[i];
				while(tokens[i+1].type == COMMA){
					tokens[i].type = FUNC_ARG;
	//				printf("%s\n",tokens[i].string);
					tokens[i].left_child = &tokens[i+2];
					i+=2;
				}
				tokens[i].type = FUNC_ARG;
	//			printf("%s\n",tokens[i].string);
				i+=2;
				state = BEG;
				usleep(delaytime);
				break;
		}
	}
}
#endif
