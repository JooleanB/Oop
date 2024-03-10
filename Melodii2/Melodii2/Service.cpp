#include "Service.h"
#include <assert.h>

void Service::exportare() {
	repo.exportare();
}

vector<Melodii>& Service::getAll() {
	return repo.getAll();
}

void Service::store(int id, string nume, string artist, string gen) {
	repo.store(id, nume, artist, gen);
}

void Service::sterge(int id) {
	repo.sterge(id);
}
//write tests for the service
void testService() {
	Repo repo;
	Service service{ repo };
	service.store(1, "nume1", "artist1", "pop");
	service.store(2, "nume2", "artist2", "rock");
	service.store(3, "nume3", "artist3", "folk");
	service.store(4, "nume4", "artist4", "disco");
	assert(service.getAll().size() == 4);
	service.sterge(1);
	assert(service.getAll().size() == 3);
	//service.exportare();
}