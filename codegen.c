#ifndef CODEGEN_C
#define CODEGEN_C
#include "parser.c"

const char * INST[]=
{
	"ADD","SUB","MUL","DIV"
};

void traverse(Node* root, int* indexer){
	
	if(root->visited) return;
	if(!root->codeObj) return;
	static bool accumFree = true;
	root->visited = true;

	if(root->type == FUNC_DEC){
		printf("__%s:\n",root->string);
		return;
	}

//	printf("Working out token %d : %s\n",root->id,root->string);
	if(root->parent != NULL){
		//printf("Has Ancestor\n");
	}
	if(root->right_child != NULL){
//		printf("R_child of %s\n",root->string);
		traverse(root->right_child, indexer);
	}
	
	if(root->left_child != NULL){
//		printf("L_child of %s\n", root->string);
		traverse(root->left_child, indexer);
	}
	switch(root->type){
		case ADD:
		case DIV:
		case MUL:
		case SUB:
			printf("%s\n",INST[root->type-ADD]);
			break;
				
		case LOGIC_EQUAL:
			printf("XOR\n");
			break;

		case ASSIGN:
			printf("MOV [R1],R0\n");
			accumFree = true;
			break;
		case FUNC_CALL:
			printf("MOV [sp],ip+2\t;assign return address\nMOV ip,%s\t;jumping to instruction\nMOV sp--, 0\n",root->string);
			break;

		case FUNC_ARG:
			printf("MOV [sp++],%s\n",root->string);
			break;

		case RETURN:
			printf("MOV ip,sp\t;jumping back to caller\n\n");
			accumFree = true;
			break;
		case UNDEFINED:
			accumFree ? printf("MOV RO,[%s]\n",root->string) : printf("MOV R1,[%s]\n",root->string);
			accumFree=false;
			break;
	}
	return;
}

#endif
