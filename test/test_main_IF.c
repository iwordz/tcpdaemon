#include "tcpdaemon.h"

extern int tcpmain( struct TcpdaemonServerEnvironment *p_env , int sock , void *p_addr );

int main()
{
	struct TcpdaemonEntryParameter	ep ;
	
	memset( & ep , 0x00 , sizeof(struct TcpdaemonEntryParameter) );
	
	snprintf( ep.log_pathfilename , sizeof(ep.log_pathfilename) , "%s/log/test_main_IF.log" , getenv("HOME") );
	ep.log_level = LOGLEVEL_ERROR ;
	
	strcpy( ep.server_model , "IF" );
	strcpy( ep.ip , "0" );
	ep.port = 9527 ;
	
	ep.process_count = 10 ;
	
	ep.pfunc_tcpmain = & tcpmain ;
	ep.param_tcpmain = NULL ;
	
	return -tcpdaemon( & ep );
}

