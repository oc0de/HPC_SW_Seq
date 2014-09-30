//
//  main.c
//  hpc_hw02
//
//  Created by Ehsan Valizadeh on 9/29/14.
//  Copyright (c) 2014 Ehsan Valizadeh. All rights reserved.
//

#include "similarity_score_calculator.h"
#include <stdio.h>
#include <stdlib.h>

char *read_file_content();

int main(int argc, const char * argv[]) {
    char *sequence = read_file_content(
                                       "/Users/ehsan/Documents/Uni/HPC/HW02/HIV-1_db.fasta.txt");
    char *polymerase = read_file_content(
                                         "/Users/ehsan/Documents/Uni/HPC/HW02/HIV-1_Polymerase.txt");
    
    initialize(sequence, polymerase);
    initialize_similarity_matrix();

    
    free(sequence);
    free(polymerase);
    return 0;
}

char *read_file_content(char* file_path) {
    long f_size;
    char *content;
    size_t code_s;
    FILE *fp = fopen(file_path, "r");
    fseek(fp, 0, SEEK_END);
    f_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    code_s = sizeof(char) * f_size;
    content = malloc(code_s);
    fread(content, 1, f_size, fp);
    
    return content;
}