#include "Matrix.hpp"
#include <bits/stdc++.h>
using namespace zich;

namespace zich
{

    Matrix::Matrix() // empty constructor
    {
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
        if (vect.size() != row * col)
        {
            throw invalid_argument{"vector size does not match rows times columns!"};
        }

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = vect.at((i * (unsigned int)col + j));
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
        int row = mat.row;
        int col = mat.col;

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = mat.get_element_at(i, j);
            }
        }

        this->matrix = vec;
        this->row = row;
        this->col = col;
    }

    Matrix::~Matrix()
    {
        // no dynamic memory allocated
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

    Matrix Matrix::add_matrix(const Matrix &mat) const
    {
        check_dimensions(mat);

        int row = mat.row;
        int col = mat.col;

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = (*this).get_element_at(i, j) + mat.get_element_at(i, j);
            }
        }
        Matrix m = Matrix(vec, row, col);
        return m;
    }

    Matrix Matrix::add_scalar(const double &scalar) const
    {
        int row = this->row;
        int col = this->col;

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = (*this).get_element_at(i, j) + scalar;
            }
        }
        Matrix m = Matrix(vec, row, col);
        return m;
    }

    Matrix Matrix::multiply_matrix(const Matrix &mat) const
    {
        if ((*this).get_col() != mat.get_row())
        {
            throw invalid_argument{"the left matrix' column amount must match the right matrix' row amount"};
        }

        int row = (*this).get_row();
        int col = mat.get_col();

        double sum = 0; // this will be used for storing the line * column multiplication later

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                sum = 0;

                for (unsigned int r = 0; r < mat.get_row(); r++) // this loop is for the row * column multiplication.
                {
                    sum += (*this).get_element_at(i, r) * mat.get_element_at(r, j);
                }

                vec[i][j] = sum;
            }
        }
        Matrix m = Matrix(vec, row, col);
        return m;
    }

    Matrix Matrix::multiply_scalar(const double &scalar) const
    {
        int row = this->row;
        int col = this->col;

        vector<vector<double>> vec((unsigned int)row, vector<double>((unsigned int)col, 0));
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                vec[i][j] = (*this).get_element_at(i, j) * scalar;
            }
        }
        Matrix m = Matrix(vec, row, col);
        return m;
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
        if ((*this).get_row() != mat.get_row())
        {
            throw invalid_argument{"Row mismatch between these matrices."};
        }
        if ((*this).get_col() != mat.get_col())
        {
            throw invalid_argument{"Column mismatch between these matrices."};
        }
    }

    string Matrix::__tostring__() const
    {
        const vector<vector<double>> &vect = this->matrix;
        int row = this->row;
        int col = this->col;

        string ans;
        string temp;
        string sub_string;
        unsigned int index = 0;
        for (unsigned int i = 0; i < row; i++)
        {
            temp = "[";
            for (unsigned int j = 0; j < col; j++)
            {
                if (j != 0 && j < col)
                {
                    temp += " ";
                }
                sub_string = std::to_string((*this).get_element_at(i, j));
                index = sub_string.find('.', 0);
                sub_string = sub_string.substr(0, index);
                temp += sub_string;
            }
            temp += "]";
            if (i < row - 1)
            {
                temp += "\n";
            }
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

        bool ans = true;

        if (func == __neq__<double> || func == __eq__<double>)
        {
            if (func == __neq__<double>)
            {
                ans = false; // different logic is needed for the neq (not equal to) comparison
            }

            int row = mat1.get_row();
            int col = mat1.get_col();

            for (unsigned int i = 0; i < row; i++)
            {
                for (unsigned int j = 0; j < col; j++)
                {
                    if (!func(mat1.get_element_at(i, j), mat2.get_element_at(i, j)) && func == __eq__<double>)
                    {
                        return false;
                    }

                    if (func(mat1.get_element_at(i, j), mat2.get_element_at(i, j)) && func == __neq__<double>)
                    {
                        ans = true;
                    }
                }
            }
        }
        else
        {
            double sum_mat1 = mat1.sum_matrix();
            double sum_mat2 = mat2.sum_matrix();
            return func(sum_mat1, sum_mat2);
        }

        return ans; // reaches here iff function is __neq__ or __eq__
    }

    double Matrix::sum_matrix() const
    {
        double sum = 0;
        for (unsigned int i = 0; i < this->row; i++)
        {
            for (unsigned int j = 0; j < this->col; j++)
            {
                sum += (*this).get_element_at(i, j);
            }
        }
        return sum;
    }

    Matrix &Matrix::operator=(const Matrix &mat)
    {
        this->set_matrix(mat.get_matrix());
        this->set_row(mat.get_row());
        this->set_col(mat.get_col());

        return *this;
    }

    Matrix Matrix::operator+() const // unary operator
    {
        Matrix m = Matrix(*this);
        return m;
    }
    Matrix Matrix::operator+(const Matrix &mat) const
    {
        return add_matrix(mat);
    }

    Matrix Matrix::operator+(const double &scalar) const
    {
        return add_scalar(scalar);
    }

    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        *this = *this + mat;
        return *this;
    }

    Matrix &Matrix::operator+=(const double &scalar)
    {
        *this = *this + scalar;
        return *this;
    }

    Matrix Matrix::operator++(int a) // a++
    {
        Matrix m = Matrix(*this);
        (*this) += 1;
        return m;
    }

    Matrix &Matrix::operator++() // ++a
    {
        (*this) += 1;
        return *this;
    }

    Matrix Matrix::operator-() // unary operator
    {
        // Matrix m = Matrix((*this) * -1);
        return (*this) * -1;
    }

    Matrix Matrix::operator-(const Matrix &mat) const
    {
        return add_matrix(mat * -1); // notice that it's adding the negative.
    }

    Matrix Matrix::operator-(const double &scalar) const
    {
        return add_scalar(-scalar); // notice that it's adding the negative.
    }

    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        *this = *this - mat;
        return *this;
    }

    Matrix &Matrix::operator-=(const double &scalar)
    {
        *this = *this - scalar;
        return *this;
    }

    Matrix Matrix::operator--(int a) // a--
    {
        Matrix m = Matrix(*this);
        (*this) -= 1;
        return m;
    }

    Matrix &Matrix::operator--() // --a
    {
        (*this) -= 1;
        return *this;
    }

    Matrix Matrix::operator*(const Matrix &mat) const
    {
        return multiply_matrix(mat);
    }

    Matrix Matrix::operator*(const double &scalar) const
    {
        return multiply_scalar(scalar);
    }
    Matrix &Matrix::operator*=(const Matrix &mat)
    {
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
        return compare_matrices_by_sign(*this, mat, &__lt__); // passing less then comparison method
    }
    bool Matrix::operator<=(const Matrix &mat) const
    {
        return compare_matrices_by_sign(*this, mat, &__let__); // passing less equal then comparison method
    }
    bool Matrix::operator==(const Matrix &mat) const
    {
        return compare_matrices_by_sign(*this, mat, &__eq__); // passing equal to comparison method
    }
    bool Matrix::operator!=(const Matrix &mat) const
    {
        return compare_matrices_by_sign(*this, mat, &__neq__); // passing not equal to comparison method
    }
    bool Matrix::operator>(const Matrix &mat) const
    {
        return compare_matrices_by_sign(*this, mat, &__mt__); // passing more then comparison method
    }
    bool Matrix::operator>=(const Matrix &mat) const
    {
        return compare_matrices_by_sign(*this, mat, &__met__); // passing more equal then comparison method
    }

    ostream &operator<<(ostream &out, const Matrix &mat)
    {
        string mat_str = mat.__tostring__();
        out << mat_str;
        return out;
    }

    void operator>>(istream &in, Matrix &mat)
    {
        string in_str(istreambuf_iterator<char>(in), {});

        string blacklist = ", ";
        string::size_type index = 0; // https://stackoverflow.com/questions/49566816/comparison-of-unsigned-int-is-always-true-npos-issue
        string tokenized;

        in_str.erase(in_str.size() - 1, 1); // erases the '\n'
        index = in_str.find(blacklist);
        while (index != string::npos)
        {
            tokenized += in_str.substr(0, index);
            in_str = in_str.erase(0, index + 2); // also deletes two more unwatned char's
            index = in_str.find(blacklist);
        }
        tokenized += in_str.substr(0, in_str.size());

        unsigned int counter = 1;
        for (auto &ch : tokenized)
        {
            if (ch == ' ')
            {
                counter += 1;
            }
            if (ch == ']')
            {
                break;
            }
        }
        unsigned int columns = counter;
        if (columns == 1)
        {
            throw invalid_argument{"bad input in >> operator."};
        }

        string final_token;

        for (auto &ch : tokenized)
        {

            if (ch != '[')
            {
                if (ch == ']')
                {
                    final_token += ' ';
                }
                else{
                    final_token += ch;
                }
            }
        }

        // https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
        
        vector<string> values_as_string;
        stringstream check(final_token);
        string helper;

        while(getline(check, helper, ' '))
        {
            values_as_string.push_back(helper);
        }

        vector<double> values;
        for(unsigned int i = 0; i < values_as_string.size(); i++){
            values.push_back(stod(values_as_string.at(i)));
        }

        if (columns == 0){
            throw invalid_argument{"bad input in >> operator"};
        }

        unsigned int rows = values.size()/columns;

        if (rows == 0){
            throw invalid_argument{"bad input in >> operator"};
        }
        
        mat = Matrix(values, (int)rows, (int)columns);
    }
    Matrix operator*(double num, const Matrix &mat)
    {
        return mat * num;
    }
    Matrix operator+(int num, const Matrix &mat)
    {
        return mat + num;
    }
}