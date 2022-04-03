#include "Matrix.hpp"
#include "doctest.h"
#include <array>
#include <string>
using namespace zich;

TEST_CASE("BAD INPUT"){

    SUBCASE("Horizontal"){

        Matrix *mat1 = new Matrix(3,5);
        Matrix *mat2 = new Matrix(5,3);

        bool tmp;

        CHECK_THROWS(tmp = (*mat1 > *mat2));
        CHECK_THROWS(tmp = (*mat1 >= *mat2));
        CHECK_THROWS(tmp = (*mat1 < *mat2));
        CHECK_THROWS(tmp = (*mat1 <= *mat2));
        CHECK_THROWS(tmp = (*mat1 == *mat2));
        CHECK_THROWS(tmp = (*mat1 != *mat2));
        CHECK_THROWS(tmp = (*mat1 == (*mat2++)));
        CHECK_THROWS(tmp = (*mat1 == (*mat2*2)));
        CHECK_THROWS(tmp = (2*(*mat1) == *mat2));
        CHECK_THROWS(tmp = (*mat1 *3.5 == 2.7 * (*mat2)));

    }
}

TEST_CASE("GOOD INPUT"){

    SUBCASE("basic func"){

        Matrix *mat1 = new Matrix(5,5);
        Matrix *mat2 = new Matrix(5,5);

        bool tmp;

        CHECK((*mat1 > *mat2));
        CHECK((*mat1 >= *mat2));
        CHECK((*mat1 < *mat2));
        CHECK((*mat1 <= *mat2));
        CHECK((*mat1 == *mat2));
        CHECK((*mat1 != *mat2));
        CHECK((*mat1 == (*mat2++)));
        CHECK((*mat1 == (*mat2*2)));
        CHECK((2*(*mat1) == *mat2));
        CHECK((*mat1 *3.5 == 2.7 * (*mat2)));
    }
}