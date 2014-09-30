//
//  similarity_score_calculator.c
//  hpc_hw02
//
//  Created by Ehsan Valizadeh on 9/29/14.
//  Copyright (c) 2014 Ehsan Valizadeh. All rights reserved.
//

#include <stdio.h>
#include "similarity_score_calculator.h"
#include "similarity_matrix.h"

void initialize(char *sequence, char *polymerase)
{
    _sequence = sequence;
    _column_numbers = strlen(_sequence) + 1;
    _polymerase = polymerase;
    _row_numbers = strlen(_polymerase) + 1;

}

void initialize_similarity_matrix()
{
    _similarity_matrix = (int**) malloc(_row_numbers * sizeof(int*));
    
    long i;
    for (i = 0; i < _row_numbers; i++) {
        _similarity_matrix[i] = (int*) malloc(_column_numbers * sizeof(int));
    }
    
    set_initial_value_similarity_matrix();
}


void set_initial_value_similarity_matrix()
{
    initialize_first_row();
    initialize_first_column();
    long i;
    long j;
    for (i = 1; i < _row_numbers; i++) {
        for (j = 1; j < _column_numbers; j++) {
            _similarity_matrix[i][j] = 0;  // ????????????
        }
    }
}

void initialize_first_row()
{
    int i;
    for (i = 0; i < _column_numbers; i++) {
        _similarity_matrix[0][i] = 0;
    }
}

void initialize_first_column()
{
    int i;
    for (i = 0; i < _row_numbers; i++) {
        _similarity_matrix[i][0] = 0;
    }
}

void calculate_similarity()
{
    int i;
    struct SimilarityMatrix* sim_matrix = create_similarity_matrix();
    for (i = 1; i < _row_numbers; i++) {
        sim_matrix->row_index = 1;
    }
}

struct SimilarityMatrix* create_similarity_matrix() {
    struct SimilarityMatrix* sim_matrix = malloc(sizeof(struct SimilarityMatrix));
    sim_matrix->matrix = _similarity_matrix;
    sim_matrix->row_numbers = _row_numbers;
    sim_matrix->column_numbers = _column_numbers;
    
    return sim_matrix;
}





