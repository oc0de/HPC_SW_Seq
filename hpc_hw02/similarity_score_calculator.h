//
//  similarity_score_calculator.h
//  hpc_hw02
//
//  Created by Ehsan Valizadeh on 9/29/14.
//  Copyright (c) 2014 Ehsan Valizadeh. All rights reserved.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#ifndef hpc_hw02_similarity_score_calculator_h
#define hpc_hw02_similarity_score_calculator_h

void initialize(char *sequence, char *polymerase);


char *_polymerase;
char *_sequence;
long _column_numbers;
long _row_numbers;



#endif

