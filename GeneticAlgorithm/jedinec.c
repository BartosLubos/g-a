struct Jedinec {
	char *gene;
	int fitness;
	Jedinec * next_creature;
} jedinec;

void create_pairs(jedinec *population, int *population_count, int *pairs){
	int i;
	//zatim parujem od koncu ke stredu
	for (i = 0; i < *population_count; i++) {
		pairs[i][0] = i;
		pairs[i][1] = *population_count - i;
	}
}

void get_average_fitness(jedinec *population, int *population_count, float *average_fitness){
	float sum = 0;

	// sum of all fitnesses
	for(int i = 0; i < *population_count; i++) {
		sum += population->fitness;
	}

	//save average
	*average_fitness = sum/(*population_count);
}
