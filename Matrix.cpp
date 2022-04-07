#include "Matrix.hpp"
#include <functional>
using namespace zich;
using zich::Matrix;

namespace zich
{
    Matrix::Matrix() // empty constructor fills all with 0
    {
        vector<vector<double>> vec(0, vector<double>(0, 0));
        this->matrix = vec;
        this->row = 0;
        this->col = 0;
    }

    Matrix::Matrix(int row, int col) // emty constructor fills all with 0
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
                vec[i][j] = vect.at((i * row + j));
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

    Matrix &Matrix::operator+()
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }
    Matrix &Matrix::operator+(const Matrix &mat) const
    {
        check_dimensions(mat);
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator+(double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        check_dimensions(mat);
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator+=(double scalar)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator++() const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    } // TODO: void?

    Matrix &Matrix::operator-()
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator-(const Matrix &mat) const
    {
        check_dimensions(mat);
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator-(double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        check_dimensions(mat);
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator-=(const double scalar)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator--() const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    } // TODO: void?s

    Matrix &Matrix::operator*(const Matrix &mat) const
    {
        check_dimensions(mat);
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    Matrix &Matrix::operator*(double scalar) const
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }
    Matrix &Matrix::operator*=(const Matrix &mat)
    {
        check_dimensions(mat);
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }
    Matrix &Matrix::operator*=(double scalar)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    bool Matrix::operator<(const Matrix &mat) const
    {
        check_dimensions(mat);
        return true; // not implemented
    }
    bool Matrix::operator<=(const Matrix &mat) const
    {
        check_dimensions(mat);
        return true; // not implemented
    }
    bool Matrix::operator==(const Matrix &mat) const
    {
        check_dimensions(mat);
        return true; // not implemented
    }
    bool Matrix::operator!=(const Matrix &mat) const
    {
        check_dimensions(mat);
        return true; // not implemented
    }
    bool Matrix::operator>(const Matrix &mat) const
    {
        check_dimensions(mat);
        return true; // not implemented
    }
    bool Matrix::operator>=(const Matrix &mat) const
    {
        check_dimensions(mat);
        return true; // not implemented
    }

    ostream &operator<<(ostream &out, const Matrix &mat)
    {
        return out; // not implemented
    }
    void operator>>(istream &in, const Matrix &mat)
    {
    }

    Matrix &operator*(int num, const Matrix &mat)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }
    Matrix &operator*(double num, const Matrix &mat)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }
    Matrix &operator+(int num, const Matrix &mat)
    {
        Matrix *m = new Matrix(1, 1); // not implemented
        return *m;
    }

    // Helpers:

    double Matrix::get_element_at(unsigned int row, unsigned int column) const
    {
        int mat_row = this->get_row();
        int mat_col = this->get_col();
        if (row >= mat_row || col >= mat_col)
        {
            throw invalid_argument{"row or col out of bounds for this matrix!"};
        }
        return this->matrix.at(row).at(col);
    }

    void Matrix::check_dimensions(const Matrix &mat) const
    {
        if (this->row != mat.get_row() || this->col != mat.get_col())
        {
            throw invalid_argument{"row or col mismatch between these matrices."};
        }
    }

    bool compare_matrices_by_sign(const Matrix &mat1, const Matrix &mat2, std::function<bool(bool, bool)> func)
    {
        mat1.check_dimensions(mat2);

        int row = mat1.get_row();
        int col = mat1.get_col();

        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                func(mat1.get_element_at(i, j), mat2.get_element_at(i, j));
            }

            return true;
        }
    }

    // privates:

    /*
    Matrix &add_matrices(const Matrix &mat1, const Matrix &mat2)
    {

    }

    Matrix &add_scalar(const Matrix &mat, double scalar)
    {

    }
    */
}