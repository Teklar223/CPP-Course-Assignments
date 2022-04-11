#include "Matrix.hpp"
#include <functional>
using namespace zich;
using zich::Matrix;

namespace zich
{

    Matrix::Matrix() // empty constructor fills 0*0 with 0
    {
        vector<vector<double>> vec(0, vector<double>(0, 0));
        this->matrix = vec;
        this->row = 0;
        this->col = 0;
    }

    Matrix::Matrix(int row, int col) // empty constructor that fills row*col with 0's
    {
        // https://stackoverflow.com/questions/65311502/how-to-initialize-vector-of-a-vector-with-custom-values
        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        this->matrix = vec;
        this->row = row;
        this->col = col;
    }

    Matrix::Matrix(const vector<double> &vect, int row, int col)
    {
        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = vect.at((i * (unsigned int)row + j));
            }
        }

        this->matrix = vec;
        this->row = row;
        this->col = col;
    }

    Matrix::Matrix(const vector<vector<double>> &vect, int row, int col)
    {
        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = vect.at(i).at(j);
            }
        }

        this->matrix = vec;
        this->row = row;
        this->col = col;
    }

    Matrix::Matrix(const Matrix &mat)
    {
        const vector<vector<double>> &vect = mat.matrix;
        int row = mat.row;
        int col = mat.col;

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = vect.at(i).at(j);
            }
        }

        this->matrix = vec;
        this->row = row;
        this->col = col;
    }

    Matrix::~Matrix()
    {
        // not implemented
    }

    // Helpers:

    template <class T>
    bool __eq__(T a, T b) // equals
    {
        return a == b;
    }
    template <class T>
    bool __neq__(T a, T b) // not equals
    {
        return a != b;
    }
    template <class T>
    bool __lt__(T a, T b) // less then
    {
        return a < b;
    }
    template <class T>
    bool __let__(T a, T b) // less equals then
    {
        return a <= b;
    }
    template <class T>
    bool __mt__(T a, T b) // more then
    {
        return a > b;
    }
    template <class T>
    bool __met__(T a, T b) // more equals then
    {
        return a >= b;
    }

    Matrix &Matrix::add_matrix(const Matrix &mat) const
    {

        check_dimensions(mat);

        const vector<vector<double>> &vect1 = mat.matrix;
        const vector<vector<double>> &vect2 = this->matrix;
        int row = mat.row;
        int col = mat.col;

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = vect1.at(i).at(j) + vect2.at(i).at(j);
            }
        }
        Matrix *m = new Matrix(vec, row, col);
        return *m;
    }

    Matrix &Matrix::add_scalar(const double &scalar) const
    {
        const vector<vector<double>> &vect = this->matrix;
        int row = this->row;
        int col = this->col;

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = vect.at(i).at(j) + scalar;
            }
        }
        Matrix *m = new Matrix(vec, row, col);
        return *m;
    }

    Matrix &Matrix::multiply_matrix(const Matrix &mat) const
    {
        check_multiplication_dimensions(mat); // this multiplication is defind only when this.columns = mat.rows

        const vector<vector<double>> &vect1 = mat.matrix;
        const vector<vector<double>> &vect2 = this->matrix;
        int row = mat.row;
        int col = mat.col;

        double sum = 0; // this will be used for storing the line * column multiplication later

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                sum = 0;

                for (unsigned int r = 0; r < col; r++) // this loop is for the row * column multiplication.
                {
                    sum += vect1.at(i).at(r) * vect2.at(r).at(i);
                }

                vec[i][j] = sum;
            }
        }
        Matrix *m = new Matrix(vec, row, col);
        return *m;
    }

    Matrix &Matrix::multiply_scalar(const double &scalar) const
    {
        const vector<vector<double>> &vect = this->matrix;
        int row = this->row;
        int col = this->col;

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = vect.at(i).at(j) * scalar;
            }
        }
        Matrix *m = new Matrix(vec, row, col);
        return *m;
    }

    double Matrix::get_element_at(unsigned int row, unsigned int column) const
    {
        int mat_row = this->get_row();
        int mat_col = this->get_col();
        if (row > mat_row || col > mat_col)
        {
            throw invalid_argument{"row or col out of bounds for this matrix! "};
        }
        return this->matrix.at(row).at(column);
    }

    void Matrix::check_dimensions(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
    }

    void Matrix::check_multiplication_dimensions(const Matrix &mat) const
    {
        if (this->row != mat.get_col())
        {
            throw invalid_argument{"the left matrix' column amount must match the right matrix' row amount"};
        }
    }

    string Matrix::to_string() const
    {
        const vector<vector<double>> &vect = this->matrix;
        int row = this->row;
        int col = this->col;

        string ans;
        string temp;
        for (unsigned int i = 0; i < row; i++)
        {
            temp = "[";
            for (unsigned int j = 0; j < col; j++)
            {
                if (j!=0 || j!=col-1){
                    temp += " ";
                }

                temp += (*this).get_element_at(i,j);

            }
            temp += "]\n";
            ans += temp;
        }
        return ans;
    }

    bool compare_matrices_by_sign(const Matrix &mat1, const Matrix &mat2, bool func(double, double))
    {
        /**
         * @brief receives two matrices, and a comparison function to be used
         */
        mat1.check_dimensions(mat2);

        int row = mat1.get_row();
        int col = mat1.get_col();

        bool neq_flag = false;
        if (__neq__<double> == func)
        { // different logic is needed for the neq (not equal to) comparison
            neq_flag = true;
        }

        bool ans = true;
        if (neq_flag)
        {
            ans = false;
        }

        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                if (!func(mat1.get_element_at(i, j), mat2.get_element_at(i, j)))
                {
                    if (neq_flag)
                    {
                        ans = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return ans;
    }

    Matrix &Matrix::operator=(const Matrix &mat)
    {
        this->set_matrix(mat.get_matrix());
        this->set_row(mat.get_row());
        this->set_col(mat.get_col());

        return *this;
    }

    Matrix &Matrix::operator+() // unary operator
    {
        Matrix *m = new Matrix(*this);
        return *m;
    }
    Matrix &Matrix::operator+(const Matrix &mat) const
    {
        check_dimensions(mat);
        return add_matrix(mat);
    }

    Matrix &Matrix::operator+(const double &scalar) const
    {
        return add_scalar(scalar);
    }

    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        check_dimensions(mat);
        *this = *this + mat;
        return *this;
    }

    Matrix &Matrix::operator+=(const double &scalar)
    {
        *this = *this + scalar;
        return *this;
    }

    Matrix &Matrix::operator++(int a) // a++
    {
        Matrix *m = +this;
        (*this) += 1;
        return *m;
    }

    Matrix &Matrix::operator++() // ++a
    {
        (*this) += 1;
        return *this;
    }

    Matrix &Matrix::operator-() // unary operator
    {
        Matrix *m = new Matrix((*this) * -1);
        return *m;
    }

    Matrix &Matrix::operator-(const Matrix &mat) const
    {
        check_dimensions(mat);
        return add_matrix(mat * -1); // notice that it's adding the negative.
    }

    Matrix &Matrix::operator-(const double &scalar) const
    {
        return add_scalar(-scalar); // notice that it's adding the negative.
    }

    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        check_dimensions(mat);
        *this = *this - mat;
        return *this;
    }

    Matrix &Matrix::operator-=(const double &scalar)
    {
        *this = *this - scalar;
        return *this;
    }

    Matrix &Matrix::operator--(int a) // a--
    {
        Matrix *m = +this;
        (*this) -= 1;
        return *m;
    }

    Matrix &Matrix::operator--() // --a
    {
        (*this) -= 1;
        return *this;
    }

    Matrix &Matrix::operator*(const Matrix &mat) const
    {
        check_dimensions(mat);
        return multiply_matrix(mat);
    }

    Matrix &Matrix::operator*(const double &scalar) const
    {
        return multiply_scalar(scalar);
    }
    Matrix &Matrix::operator*=(const Matrix &mat)
    {
        check_dimensions(mat);
        *this = *this * mat;
        return *this;
    }
    Matrix &Matrix::operator*=(const double &scalar)
    {
        *this = *this * scalar;
        return *this;
    }

    bool Matrix::operator<(const Matrix &mat) const
    {
        check_dimensions(mat);
        return compare_matrices_by_sign(*this, mat, &__lt__); // passing less then comparison method
    }
    bool Matrix::operator<=(const Matrix &mat) const
    {
        check_dimensions(mat);
        return compare_matrices_by_sign(*this, mat, &__let__); // passing less equal then comparison method
    }
    bool Matrix::operator==(const Matrix &mat) const
    {
        check_dimensions(mat);
        return compare_matrices_by_sign(*this, mat, &__eq__); // passing equal to comparison method
    }
    bool Matrix::operator!=(const Matrix &mat) const
    {
        check_dimensions(mat);
        return compare_matrices_by_sign(*this, mat, &__neq__); // passing not equal to comparison method
    }
    bool Matrix::operator>(const Matrix &mat) const
    {
        check_dimensions(mat);
        return compare_matrices_by_sign(*this, mat, &__mt__); // passing more then comparison method
    }
    bool Matrix::operator>=(const Matrix &mat) const
    {
        check_dimensions(mat);
        return compare_matrices_by_sign(*this, mat, &__met__); // passing more equal then comparison method
    }

    ostream &operator<<(ostream &out, const Matrix &mat)
    {
        string mat_str = mat.to_string();
        return out; // not implemented
    }
    void operator>>(istream &in, const Matrix &mat)
    {
        // not implemented
    }
    Matrix &operator*(double num, const Matrix &mat)
    {
        return mat * num;
    }
    Matrix &operator+(int num, const Matrix &mat)
    {
        return mat + num;
    }
}