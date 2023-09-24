#ifndef TOKENIZER_C
#define TOKENIZER_C

#include "type.h"
#include "charops.c"
#include "stringops.c"

int tkncnt = 0;
Node tokens[2048] = {};
int Tokenizer(char* src){
	TokenEngineState state = START;
	int srcpos = 0;
	char endchar = 0;
	int lexpos = 0;
	Node tmp = {.id = tkncnt ,.left_child = NULL, .right_child = NULL,.parent = NULL, .string = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'}};
	while(src[srcpos] != '\0'){
		switch (state){
			case DUMPTOKEN:	
		//		printf("%d:\t%s\t%s\n",tmp.id,NODES[tmp.type],tmp.string);
				tokens[tkncnt] = tmp;
				lexpos = 0;
				Node swp =  {.id = ++tkncnt,.type = UNDEFINED,.parent = NULL, .left_child = NULL, .right_child = NULL,.type = UNDEFINED,.string = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},.codeObj = false};
				tmp = swp;
				state = START;

			case START:
//				printf("Entering Start State\n");
				if(isSpace(src[srcpos]) ){
					srcpos +=1;

				}else if(isScopeDef(src[srcpos])){
					state = READSCOPEDEF;

				}else if(src[srcpos]=='/' && src[srcpos+1]=='/'){
					srcpos +=2;
					state = READCOMMENT;

				} else if(srcpos == '"'){
					state = READBLOCK;
					endchar = '"';
					srcpos++;

				}else if(isSpecial(src[srcpos])){
					state = READOP;
				}else{
					state = READCHAR;
				};
				break;

			case READSCOPEDEF:
				tmp.string[0] = src[srcpos];
				tmp.string[1] = '\0';
				state = CALIBOP;
				srcpos++;
				break;

			case READOP:
//				printf("Entering ReadOp state\n");
				if(isSpace(src[srcpos]) || isAlpha(src[srcpos]) || isNum(src[srcpos])){
					//if is a space / alpha / numerical calibrate token
					tmp.string[lexpos] = '\0';
					state = CALIBOP;
				}else if(isScopeDef(src[srcpos])){
					tmp.string[lexpos] = '\0';
					state = CALIBOP;
				}else{
					tmp.string[lexpos++] = src[srcpos++];
				}
				break;

			case READCHAR:
//				printf("Entering Readchar state\n");
				if(isSpace(src[srcpos]) || isSpecial(src[srcpos]) || isScopeDef(src[srcpos])){
					state = CALIBOP;
				}else{
					tmp.string[lexpos++] = src[srcpos++];
				}
				break;

			case CALIBOP:
//				printf("Entering Calibrate Operand state\n");
				tmp.type = getOPerator(&tmp.string[0]);
				if(tmp.type == UNDEFINED) tmp.codeObj = true;
				state = DUMPTOKEN;
				break;

			case READBLOCK:
//				printf("Entering ReadBlock mode\n");
				if(endchar == src[srcpos]){
					state = DUMPTOKEN;
					srcpos++;
					endchar = 0;
				}else{
					tmp.string[lexpos++]=src[srcpos++];
				};
				break;

			case READCOMMENT:
//				printf("Entering Read Comment State");
				if(src[srcpos]=='\n'){
					state = START;
				}else srcpos++;
				break;
		}
	}
	//printf("Exiting State Machine\n");
	return tkncnt;
}


#endif

