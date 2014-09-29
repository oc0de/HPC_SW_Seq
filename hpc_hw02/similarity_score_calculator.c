//
//  similarity_score_calculator.c
//  hpc_hw02
//
//  Created by Ehsan Valizadeh on 9/29/14.
//  Copyright (c) 2014 Ehsan Valizadeh. All rights reserved.
//

#include <stdio.h>
#include "similarity_score_calculator.h"


void initialize(char *sequence, char *polymerase)
{
    _sequence = sequence;
    _column_numbers = strlen(_sequence) + 1;
    _polymerase = polymerase;
    _row_numbers = strlen(_polymerase) + 1;
    
    printf("column numbers ~> %ld\n", _column_numbers);
    printf("row_numbers ~> %ld", _row_numbers);

}