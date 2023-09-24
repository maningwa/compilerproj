#ifndef TYPES_H
#define TYPES_H

typedef enum{false,true}bool;

//define the tokenizer state machine states
typedef enum{START,READCHAR,READBLOCK,READOP,CALIBOP,READCOMMENT,DUMPTOKEN,READSCOPEDEF}TokenEngineState;

//define the parser state machine state
typedef enum{BEG,DEC,PARAM,SCOPING,EXIT_SCOPE,ACC,ARGS,EXP,COND,COND_EXP,COND_TERM}ParseEngineState;

//define token types
typedef struct{
	int id;
	int type;
	char string[16];
	struct Node * parent;
	struct Node * left_child;
	struct Node * right_child;
	int address;
	int size;
	bool codeObj;
	bool visited;
}Node;

typedef enum{
	LEFT_PAREN,RIGHT_PAREN,LEFT_BRACES,RIGHT_BRACES,LEFT_BRACKET,RIGHT_BRACKET,COMMA,COLON,SEMI_COLON,EMPTY_ARGS,
	VOID,CHAR,INT,FLOAT,LONG,CONST,
	WHILE,IF,ELSE,ENDIF,ENDWHILE,STRUCT,RETURN,
	ADD,SUB,MUL,DIV,ASSIGN,
	INC_BY,DEC_BY,DIV_WITH,INC,DECREASE,
	BITSHIFT_RIGHT,BITSHIFT_LEFT,
	LOGIC_OR,LOGIC_AND,LOGIC_EQUAL,LOGIC_GREATER,LOGIC_LESS,NEGATOR,LOGIC_NOT_EQUAL,
	STRING_BLOCK,VAR_ACCESS,VAR_DEC,
	FUNC_DEC,FUNC_CALL,FUNC_ARG,
	UNDEFINED
}NodeType;

const char *NODES[]=
{
	"(",")","{","}","[","]",",",":",";","()",
	"void","char","int","float","long","const",
	"while","if","else","endif","endwhile","struct","return",
	"+","-","*","/","=",			//math operators acting as nodes
	"+=","-=","/=","++","--",		//Math operators as expressions
	">>","<<",				//Bit Operatopsn
	"||","&&","==",">","<","!","!="		//Logical Operator
	"String","Var access","var dec",	//other tokentypes
	"FuncDec","FuncCall","FuncCallArgument",
	"Undefi"
};

#endif
