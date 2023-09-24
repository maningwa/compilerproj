#ifndef STRINGOPS
#define STRINGOPS

#include "type.h"

bool StrCmp(char* str1,char* str2){
	if(str1 == NULL || str2 ==NULL){
		return false;
	};
	int i = 0;
	while(str1[i]!= '\0' && str2[i] != '\0'){
		if(str1[i] != str2[i]){ 
			return false;
		}
		i++;
	}
	if(str1[i] != str2[i]){
		return false;
	}else{
		return true;
	}
};

bool isScopeDef(char chr){
	switch(chr){
		case '{':
		case '"':
		case '\'':
		case '}':
		case ':':
		case ';':
		case ',':
			return true;
		default:
			return false;
	}
}

int getOPerator(char * str){
	for(int i = 0; i<UNDEFINED;i++){
		if(StrCmp(str,NODES[i])){
			return i;
		}
	}
	return UNDEFINED;
}
#endif
