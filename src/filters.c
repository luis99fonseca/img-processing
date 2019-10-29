const float edgeDetection1[9] = { 1, 0, -1,
                            0, 0, 0,
                            -1, 0, 1};

const float edgeDetection2[9] = { 0, 1, 0,
                            1, -4, 1,
                            0, 1, 0};

const float edgeDetection3[9] = { -1, -1, -1,
                            -1, 8, -1,
                            -1, -1, -1};

const float sharpen[9] = { 0, -1, 0,
                    -1, 5, -1,
                    0, -1, 0};

const float boxBlur[9] = { 1.0/9, 1.0/9, 1.0/9,
                    1.0/9, 1.0/9, 1.0/9,
                    1.0/9, 1.0/9, 1.0/9};                            


const float gaussianBlur[9] = { 1.0/16, 1.0/8, 1.0/16,
                        1.0/8, 1.0/4, 1.0/8,
                        1.0/16, 1.0/8, 1.0/16};                