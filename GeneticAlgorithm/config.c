Konfigurace Evoluce = interface pro ruzna nastaveni evoluce, výběru, konfigurace a tak
kvantita/kvalita
random
rostoucí populace/stálá velikost
učení se od jiných jedinců?

typedef struct Configuration {
	char *executable;
	int count_of_parameters;
	char *parameters;
	char *intervals;
} environment;

//reads file with meta data
void get_environment(char* file_name, environment *config) {

    char *executable;
	char *parameters;
	char *intervals;
	int param_count = 0;
	char *konstanta;
	char *type;
	char *interval;

    FILE * file_pointer;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    file_pointer = fopen("/etc/motd", "r");
    if (file_pointer == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, file_pointer)) != -1) {

    	if (line[0] != '#') { 
    	// konstanta
    		store_const_from_line(line, konstanta);
    		append_string(parameters, konstanta);
    		param_count++;
    	} else { 
    	// file or variable

    		if (line[2] == '(') { 
    		// variable
    			store_variable_from_line(line, interval, type);
	    		append_string(parameters, type);
	    		append_string(intervals, interval);
    			param_count++;

    		} else {
    		// file
    			executable = strdup(line+2); // prvni dva znaky ne TODO osetrit zda se to neposralo 
    		}

    	}

    	
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }

    config->parameters = parameters; //realloc probably
    config->intervals  = intervals; //realloc probably
    config->executable = executable; //realloc probably

    fclose(file_pointer);
    if (line){
        free(line);
    }
    exit(EXIT_SUCCESS);
}
