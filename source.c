#include <stdlib.h>
#include <stdio.h>
#define SECRET_PASS 123
#define MODE_EASY 1 

int * p_global ;

void index_user ( int *p) {
	int * p_global_save ;
	p_global_save = p_global ;
	p_global =p;
	if( * p_global == 1) {
		printf (" UAF mode on\n");
		return ; 
	}else {
		printf (" UAF mode off \n");
		p_global = p_global_save ; 
		return ;
	}
}

int main () {
	int * p_index ,* p_pass ;
	int mode = 0;
	scanf("%d", &mode);
	if(mode != 1 ) {
		printf ("test stop\n");
		return 0; 
	}
	p_global =( int *) malloc ( sizeof ( int ));
	* p_global = SECRET_PASS ;
	if( mode == MODE_EASY ) {
		p_index =( int *) malloc ( sizeof ( int ));
		printf (" Give a number between 0 and 1\n");
		scanf ("%d",p_index );
		index_user ( p_index );
		free ( p_index ); 
	}else { 
		printf (" Good luck ! \n"); 
	}
		p_pass =( int *) malloc ( sizeof ( int ));
		printf (" Give the secret \n");
		scanf ("%d",p_pass );
	if (* p_pass ==* p_global ) {
		printf (" Congrats ! \n"); 
	}else { 
		printf (" Sorry ...\n"); 
	}
	return 0; 
}
