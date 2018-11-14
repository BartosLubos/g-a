void dying_time(jedinec *population, int *population_count) {
	float average_fitness;
	int i;
	get_average_fitness(population, population_count, &average_fitness);

	for(i = 0; i < *population_count; i++) {
		if(population[i]->finess < average_fitness){
			kill_creature(population, i);
		}
	}
}

void create_initial_population(jedinec *population, int count_of_creatures, environment *env){
    int i;

    for (i = 0; i < count_of_creatures; i++) {
        create_creature(population + i, env); //gene, fitness, next creature
    }

}

void create_creature(jedinec *creature, environment *env) {
	char *executable = env->executable;
	char *parameters = env->parameters;
	char *intervals = env->intervals;


	char *gene;
	int fitness;
	Jedinec * next_creature;

	create_random_gene(gene, env);

    creature = malloc (sizeof (jedinec));
    if (creature == NULL)
        return NULL;

    // Try to allocate vector data, free structure if fail.

    creature->gene = malloc (strlen(gene) * sizeof (char));
    if (creature->gene == NULL) {
        free (creature);
        return NULL;
    }



	// let previous creature point to this one


}

void create_random_gene(char *gene, environment *env){

	char parameters[]

}


void mating_time(jedinec *population, int *population_count, int mutation_percentage, environment *env) {
	int i;
	int pairs[*population_count/2][2];
	jedinec offspring[*population_count/2];

	create_pairs(population, population_count, &pairs);
	for(i = 0; i < population_count/2; i++) {
		breed_offspring(population, pairs[i][0], pairs[i][1], &(offspring + i), mutation_percentage);
	}
}

void kill_creature(jedinec *population, int index) {
	population[index] = NULL;
    return;
}


void test_creature(jedinec * creature, float *result, environment *env) {
	char *creature_executable;
	create_creature_executable(creature, creature_executable);

    char buf[BUFSIZE];
    FILE *fp;
    char results[14][300];
    int count_of_results = 0;
    int counting_array[env->number_of_variables];
    int i;

    if ((fp = popen(creature_executable, "r")) == NULL) {
        printf("Error opening pipe!\n");
    }

    while (fgets(results[count_of_results], BUFSIZE, fp) != NULL) {
        count_of_results++;
    }

    if(pclose(fp))  {
        printf("Command not found or exited with error status\n");
    }

    for (i = 1; i < 14 ; i++) { //from 1 because first line is "starting"
        if (i == 13) {
            *result = atof(results[i]); //this is what we want???
            continue;
        }

        //counting...48765 -> 48765
        counting_array[i] = atoi(results[i]+11);
        printf("%d.: %d \n", i, counting_array[i]);
    }
}



// pushes new offspring to population array
void breed_offspring(jedinec *mother, jedinec *mother, jedinec **offspring, environment *env, int mutation_percentage){
	int i;
	char *offspring_gene;
	char *father_gene = population[father_index]->gene;
	char *mother_gene = population[mother_index]->gene;

	cross_gene(mother_gene, father_gene, &offspring_gene, mutation_percentage);


	jedinec offspring = {}; //allocate
	*offspring = malloc(sizeof(char)*sizeof(offspring_gene) + sizeof(int));
	// push to population
}


void cross_gene(char *mother_gene, char *father_gene, char **offspring_gene, environment *env, int mutation_percentage){
	char param;
	char *value;
	int offset = 0;
	int param_count = 0;

	//get count of variables from environment
	//init that big array of strings
	//split with ';'

	// while(mother_gene[offset] != 0){
	// 	if (mother_gene[offset] == ';') {
	// 		if (env->parameters[param_count] == 'Z') { 
	// 			cross_binary(value);
	// 		} else if (env->parameters[param_count] == 'R') {
	// 			cross_real(value);
	// 		}
	// 		param_count++;
	// 		value = 0;
	// 	} else {
	// 		//cislo
	// 		value = value*10 + atoi(mother_gene[offset]);
	// 	}
	// 	offset++;
	// }
}
