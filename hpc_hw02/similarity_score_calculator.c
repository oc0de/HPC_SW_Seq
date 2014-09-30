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


#define MIN_VALUE 0

///////////// Do not forget free malloc memory  ************

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
            _similarity_matrix[i][j] = -1;  // ????????????
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
    struct SimilarityMatrix* sim_matrix = create_similarity_matrix();
    
    int i;
    for (i = 1; i < _row_numbers; i++) {
        sim_matrix->row_index = i;
        similarity_measures((void*)sim_matrix);
        
    }
    
    
}

struct SimilarityMatrix* create_similarity_matrix() {
    struct SimilarityMatrix* sim_matrix = malloc(sizeof(struct SimilarityMatrix));
    sim_matrix->matrix = _similarity_matrix;
    sim_matrix->row_numbers = _row_numbers;
    sim_matrix->column_numbers = _column_numbers;
    
    return sim_matrix;
}

void *similarity_measures(void *arg)
{
    int neighbors_value[4];
    neighbors_value[3] = MIN_VALUE;
    struct SimilarityMatrix *simi_matrix = arg;
    int i;
    for (i = 1; i < simi_matrix->column_numbers; i++) {
        neighbors_value[0] = match_mismatch_calculator(simi_matrix->row_index, i);
        neighbors_value[1] = vertical_gap_penalty(simi_matrix->row_index, i);
        neighbors_value[2] = horizontal_gap_penalty(simi_matrix->row_index, i);
        
        simi_matrix->matrix[simi_matrix->row_index][i] =
        max(neighbors_value);
                        
    }
    return 0;
}


int match_mismatch_calculator(long row_index, long column_index)
{
    if (_polymerase[row_index] == _sequence[column_index]) {
        return _similarity_matrix[row_index - 1][column_index - 1] + 1;
    }
    
    return _similarity_matrix[row_index - 1][column_index - 1] - 1;
}

int vertical_gap_penalty(long row_index, long column_index)
{
    return _similarity_matrix[row_index - 1][column_index] - 2;
}

int horizontal_gap_penalty(long row_index, long column_index)
{
    return _similarity_matrix[row_index][column_index - 1] - 2;
}
                        
int max(int numbers[])
{
    int max = MIN_VALUE;
    int i;
    for (i = 0; i < length(numbers); i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

int length(int *arr)
{
    int count = 0;
    while (*arr != 0) {
        ++count;
        ++arr;
    }
    return count;
}









