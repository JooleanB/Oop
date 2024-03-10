#include "console.h"
#include "Service.h"
#include "Repo.h"
#include "validator.h"
#include "RepoCos.h"
#include "Service_cos.h"


void testAll() {
	testeRepo();
	testCtr();
	testValidator();
	teste_service_cos();
	test_repo_cos();
}

int main() {
	//testAll();

	OfertaRepo rep;
	CosRepo cos_rep{ rep };
	Validator val;
	Agentie ctr{ rep,val };
	CosService cos_serv{ cos_rep,val };
	ConsolUI ui{ ctr , cos_serv };
	ui.start();
}
