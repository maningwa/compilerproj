#ifndef TYPES_H
#define TYPES_H

typedef enum{false,true}bool;

//define the tokenizer state machine states
typedef enum{START,READCHAR,READBLOCK,READOP,CALIBOP,READCOMMENT,DUMPTOKEN,READSCOPEDEF}TokenEngineState;

//define the parser state machine state
typedef enum{BEG,DEC,PARAM,SCOPING,EXIT_SCOPE,ACC,ARGS,EXP}ParseEngineState;


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
	WHILE,IF,ELSE,FOR,SWITCH,CASE,STRUCT,RETURN,
	ADD,SUB,MUL,DIV,ASSIGN,
	INC_BY,DEC_BY,DIV_WITH,INC,DECREASE,
	BITSHIFT_RIGHT,BITSHIFT_LEFT,
	LOGIC_OR,LOGIC_AND,LOGIC_NOT_EQUAL,LOGIC_EQUAL,NEGATOR,
	STRING_BLOCK,VAR_ACCESS,VAR_DEC,
	FUNC_DEC,FUNC_CALL,FUNC_ARG,
	UNDEFINED
}NodeType;

const char *NODES[]=
{
	"(",")","{","}","[","]",",",":",";","()",
	"void","char","int","float","long","const",
	"while","if","else","for","switch","case","struct","return",
	"+","-","*","/","=",		//math operators acting as nodes
	"+=","-=","/=","++","--",	//Math operators as expressions
	">>","<<",			//Bit Operatopsn
	"||","&&","!=","==",		//Logical Operators
	"!",				//expression negator
	"String","Var access","var dec", //other tokentypes
	"Func Declaration","Function Call","Function Argument",
	"Erroneous Token"
};

#endif
