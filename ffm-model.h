#pragma once

#include "ffm.h"

class ffm_model {
    float * ffm_weights;
    float * lin_weights;

    float bias_w;
    float bias_wg;

    float eta;
    float lambda;

    ffm_uint max_b_field;
    ffm_uint min_a_field;
public:
    ffm_model(int seed, bool restricted, float eta = 0.2, float lambda = 0.00002);
    ~ffm_model();

    float predict(const ffm_feature * start, const ffm_feature * end, float norm, uint64_t * mask);
    void update(const ffm_feature * start, const ffm_feature * end, float norm, float kappa, uint64_t * mask);
};
