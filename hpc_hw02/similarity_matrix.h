//
//  similarity_matrix.h
//  hpc_hw02
//
//  Created by butb0rn on 9/29/14.
//  Copyright (c) 2014 butb0rn. All rights reserved.
//

#ifndef hpc_hw02_similarity_matrix_h
#define hpc_hw02_similarity_matrix_h

struct SimilarityMatrix {
    int  **matrix;
    long column_numbers;
    long row_numbers;
    int  row_index;
};

#endif
