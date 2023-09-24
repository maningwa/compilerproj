#ifndef CODEGEN_C
#define CODEGEN_C
#include "parser.c"

const char * INST[]= {"ADD","SUB","MUL","DIV"};
const char * LOGOPS[] = {"OR","AND","XOR","CMP","CMP","NOT","CMP"};

void traverse(Node* root, int* indexer){
	FILE * output = fopen("prog.asm","a+");
	Node* tmpl = root->left_child;
	Node* tmpr = root->right_child;
	if(root->visited) return;
	if(!root->codeObj) return;
	static bool accumFree = true;
	root->visited = true;

	if(root->type == FUNC_DEC){
		fprintf(output,"__%s:\n",root->string);
		accumFree = true;
		return;
	}
	switch(root->type){
		case WHILE:
		case IF:
		case ELSE:
			fprintf(output,"\t%s%s:\n",NODES[root->type],"1");
		default:
			break;
	}

//	printf(":::::Working out token %d : %s (%s)\n",root->id,root->string,NODES[root->type]);
	if(root->parent != NULL){
		//printf("Has Ancestor\n");
	}
	if(root->right_child != NULL){
//		printf("R_child of %s --> %s(%s)\n",root->string,tmpr!=NULL ? tmpr->string : "",NODES[tmpr->type]);
		traverse(root->right_child, indexer);
	}
	
	if(root->left_child != NULL){
//		printf("L_child of %s --> %s(%s)\n", root->string, tmpl!=NULL ? tmpl->string : "",NODES[tmpl->type]);
		traverse(root->left_child, indexer);
	}
	//printf("\n::CodeGen:: %s (%s)\n-----------\n",root->string, NODES[root->type]);
	switch(root->type){
		case ADD:
		case DIV:
		case MUL:
		case SUB:
			fprintf(output,"\t%s\n",INST[root->type-ADD]);
			break;
				
		case ASSIGN:
			fprintf(output,"\tMOV %r1,r0\t;place contents of RO(return value) in address in r1\n");
			accumFree = true;
			break;
		case FUNC_CALL:
			fprintf(output,"\tMOV rsp,rip;assign return address\n\tINC rsp;\n\tMOV ip,__%s\t;jumping to instruction ::%s\n\tMOV rsp, 0\n",root->string,root->string);
			accumFree = false;
			break;

		case FUNC_ARG:
			fprintf(output,"\tMOV sp,%s\t;place arguments on stack\n",root->string);
			break;

		case RETURN:
			fprintf(output,"\tMOV rip,rsp\t;jumping back to caller\n\n");
			accumFree = false;
			break;
		case UNDEFINED:
			accumFree ? fprintf(output,"\tMOV r0,#%s\n",root->string) : fprintf(output,"\tMOV r1,#%s\n",root->string);
			accumFree=false;	
			break;
		case WHILE:
			fprintf(output,"\tJNZ _endwhile\t;exit whileloop%s\n","1");
			 
			break;
		case IF:
			fprintf(output,"\tJZ _endif%s\t;exit ifloop\n","1");
			break;

		case ELSE:
			fprintf(output,"\tJZ _endif1\n");
			break;

		case ENDIF:
			fprintf(output,"_endif:\n");
		case ENDWHILE:
			fprintf(output,"\tJMP _while1\n");
			break;

		
		case LOGIC_OR:
		case LOGIC_AND:
		case LOGIC_EQUAL:
		case LOGIC_GREATER:
		case LOGIC_LESS:
		case NEGATOR:
		case LOGIC_NOT_EQUAL:
			fprintf(output,"\t%s\n",LOGOPS[root->type-LOGIC_OR]);
			break;

		default:
			fprintf(output,"Missed token type {%s} ((%s))\n",root->string,NODES[root->type]);
			break;
	}
	usleep(100);
	return;
	fclose(output);
}

#endif
