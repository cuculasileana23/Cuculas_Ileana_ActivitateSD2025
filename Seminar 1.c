#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int nrKm;
	char* model;
	float pret;
	char tipMotor;
};

struct Masina initializare(int id, int nrKm, char* model, float pret, char tipMotor) {
	struct Masina m;
	m.id = 1;
	m.nrKm = nrKm;
	m.model = (char*)malloc(sizeof(model)+1);
	strcpy(m.model, model);
	m.pret = pret;
	m.tipMotor = tipMotor;
	//initializare structura 
	return m;
}

void afisare(struct Masina m) {
	printf("Id-ul este %d, nr. de km: %d, modelul este %s, pretul este %f, motorul %c\n", m.id, m.nrKm, m.model, m.pret, m.tipMotor);
}

void modifica_Pret(struct Masina* m, float pretNou) {
	if(pretNou>0)
	m->pret=pretNou;
}

void dezalocare(struct Masina* m) {
	free(m->model);
	m->model = NULL;
	
}

int main() {
	struct Masina masina;
	masina = initializare(1, 50000, "Logan", 3000.50, 'B'); //'B'
	afisare(masina);
	modifica_Pret(&masina, 1000.50);
	afisare(masina);
	dezalocare(&masina);
	return 0;
}