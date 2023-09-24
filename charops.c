#ifndef CHAROPS
#define CHAROPS
#include "type.h"

bool isSpecial(char chr){
	switch(chr){
		case '~':
		case '`':
		case '!':
		case '@':
		case '#':
		case '$':
		case '%':
		case '^':
		case '&':
		case '*':
		case '(':
		case ')':
		case '_':
		case '-':
		case '+':
		case '=':
		case '{':
		case '[':
		case '}':
		case ']':
		case '|':
		case '\\':
		case ':':
		case ';':
		case '"':
		case '\'':
		case '<':
		case ',':
		case '>':
		case '.':
		case '?':
		case '/':
			return true;
		default:
			return false;
	}
};

bool isSpace(char chr){
	switch(chr){
		case ' ':
		case '\b':
		case '\n':
		case '\t':
		case '\r':
			return true;
		default:
			return false;
	};
};

bool isNum(char chr){
	if('0'<=chr && '9'>=chr){
		return true;
	} else return false;
}

bool isAlpha(char chr){
	if(('A'<=chr && 'Z' >= chr) || ('a'<= chr && 'z' >= chr) || '_' == chr){
		return true;
	}else return false;
}
#endif
