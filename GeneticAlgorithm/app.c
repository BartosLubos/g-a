
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jedinec.c"

double evaluate(char *result) {
    for (int i = 0; i < 14; i++) {
        printf((result+i));
    }
    return 1.0;
}


void write_to_file() {
    printf("writing to file\n");
}

//population count se muze menit, proto ukazatel
// evolves a population for number of generations in environment
void evolve(jedinec *population, int *population_count, int mutation_percentage, environment *env) {

    float results[*population_count];
    int i;

    for(i = 0; i < *population_count; i++) {
        test_creature(population[i], &result[i], env);
    }

    dying_time(population, population_count); //die before you fuck you weakling
    mating_time(population, population_count, mutation_percentage, environment *env);
}





//starts the evolution with given arguments
// int count_of_generations - count of generations
// int mutation_percentage - mutation percentage
void life(int count_of_generations, int mutation_percentage, environment *env) {

	int generation_number;
	int population_count = 10;
    jedinec population[population_count];

    create_initial_population(population, population_count);

	for ( generation_number = 0 ; generation_number < count_of_generations ; generation_number++ ) {
		evolve(population, population_count, count_of_generations, mutation_percentage, env);
	}
}





int main(int argc, char *argv[]) {
    int count_of_generations;
    int mutation_percentage;
    char meta_data_file;
    environment env;


	zpracujArgumenty(argc, argv, &meta_data_file, &count_of_generations, &mutation_percentage);

    get_environment(meta_data_file, &env);

	life(count_of_generations, mutation_percentage, &env);

    return 0;
}





















