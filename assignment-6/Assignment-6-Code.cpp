#include<bits/stdc++.h>
using namespace std;
struct point 				// which is used to specify the element at that pos and flag int which determines whether it is used or not.
{
	int data;
	int used;
};
int temp = 0;
void func3(int** matrix,int m) // prints the matrix 
{
	for (int i = 0; i < m; i++) {
        for (int l = 0; l < m; l++){
            int amount = to_string(matrix[i][l]).size();
            for (int j = 0; j < 6 - amount; j++){ cout << ' ';}
            cout << matrix[i][l] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void func13(point** matrix,int m) //print point** matrix
{
	temp += 1;
    cout<< "STEP #"<< temp <<endl;
    for (int i = 0; i < m; i++) 
	{
        for (int l = 0; l < m; l++)
		{
            int amount = to_string(matrix[i][l].data).size();
            for (int j = 0; j < 6 - amount; j++)
			{
				cout << ' ';
			}
            cout << matrix[i][l].data << "(" << (int)matrix[i][l].used << ") ";
        }
        cout << endl;
    }
    cout << endl;
}
int func5(int* matrix,int m)	//To find the minimum value of a particular row
{
	int min = matrix[0];
    for (int i = 0; i < m; i++) 
	{
        if (matrix[i] < min) 
			min = matrix[i];
    }
    return min;
}
void func4(int** matrix,int m)	// To substract minimum element of row from its elements of same row
{
	for (int i = 0; i < m; i++) {
        int min = func5(matrix[i], m);	//function func6() is called to find minimum element of the row.
        for (int j = 0; j < m; j++) {
            matrix[i][j] = matrix[i][j] - min;
        }
    }
}
int func7(int **matrix,int column_index,int m)	//To find the minimum value of a particular column
{
	int min = matrix[0][column_index];
    for (int i = 0; i < m; i++) 
	{
        if (matrix[i][column_index] < min) 
			min = matrix[i][column_index];
    }
    return min;
}
void func6(int **matrix,int m)	//function func6() is called to substract the minimum element of a column from the respective elments of the same column
{
	for (int l = 0; l < m; l++) {
        int min = func7(matrix, l, m);	//calls function func7() to find the minimum element of a column.
        for (int i = 0; i < m; i++) {
            matrix[i][l] = matrix[i][l] - min;
        }
    }
}
int func10(point** points,int m,int row_index)
{
	for(int i=0;i < m;i++)
	{
		if(points[row_index][i].used == 1 && points[row_index][i].data == 0)
		{
			return i;
		}
	}
	return -1;
}
void func12(point** matrix,int m,int column_index)
{
	for (int l = 0; l < m; l++) 
	{
        if (matrix[l][column_index].data == 0 && matrix[l][column_index].used == 1) 
		{
            matrix[l][column_index].used = 0;
            break;
        }
    }
}
bool func11(point** new_matrix,int m,int column,int start_column)
{
	if (start_column == column) 
		return false;
    int count = 0;
    for (int i = 0; i < m; i++) 
	{
        if (new_matrix[i][column].data == 0) 
		{
            count++;
            int index = func10(new_matrix, m, i);
            if (index == -1)
			{
                func12(new_matrix, m, column);
                new_matrix[i][column].used = 1;
                return true;
            }
        }
    }
    if (count == 1) 
		return false;
    for (int l = 0; l < m; l++) 
	{
        if (new_matrix[l][column].data == 0) 
		{
            int column_index = func10(new_matrix, m, l);
            if (func11(new_matrix, m, column_index, start_column)) 
			{
                new_matrix[l][column].used = 1;
                return true;
            }
        }
    }
    return false;
}
void func9(point** new_matrix,int m,int i)	//assigning matrix[i][j].used and matrix[i][j].data values
{
	bool flag = false;
    for (int l = 0; l < m; l++) 
	{
        if (new_matrix[l][i].data == 0) {
            int row_index = func10(new_matrix, m, l);	//check whether any zero is used or not
            if (row_index == -1) 
			{
                flag = true;
                new_matrix[l][i].used = 1;
                break;
            }
        }
    }
    if (!flag)
	{
        for (int l = 0; l < m; l++) 
		{
            if (new_matrix[l][i].data == 0) 
			{
                int column_index = func10(new_matrix, m, l);	//check whether any zero is used or not
                if (func11(new_matrix, m, column_index, i)) 	//
				{
                    new_matrix[l][i].used = 1;
                    new_matrix[l][column_index].used = 0;
                    break;
                } 
				else 
					new_matrix[l][i].used = 2;
            }
        }
    }
    func13(new_matrix, m);			// print point** new_matrix
}
point **func8(int **matrix,int m)	// function func8() is called to initialise matrix.used in order to check whether it is used for assignment solution or not.
{
	point** new_matrix = new point *[m] ;
	for (int i = 0; i < m; i++) 
	{
        new_matrix[i] = new point[m];
        for (int l = 0; l < m; l++) 
		{
            new_matrix[i][l].data = matrix[i][l];
        }
    }
    for (int i = 0; i < m; i++) 
	{
        func9(new_matrix, m, i);	//assigning matrix[i][j].used and matrix[i][j].data values
    }
    return new_matrix;
}
point** func16(point **matrix,int m)
{
	for (int i = 0; i < m; i++) 
	{
        func9(matrix, m, i);
    }
    return matrix;
}
int func17(int** matrix,point** point_matrix,int m)
{
	int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int l = 0; l < m; l++) {
            if (point_matrix[l][i].used == 1){
                sum += matrix[l][i];
            }
        }
    }
    return sum;
}
bool func14(point** matrix,int m)
{
	for (int i = 0; i < m; i++) {
        bool flag = false;
        for (int l = 0; l < m; l++){
            if (matrix[l][i].used == 1) 
			{
                flag = true;
                break;
            }
        }
        if (!flag) 
			return false;
    }
    return true;
}
void func15(point** matrix,int m)
{
	bool *rows = new bool[m];
    bool *columns = new bool[m];
    for (int i = 0; i < m; i++) 
	{
        rows[i] = false;
        columns[i] = false;
    }
    bool flag = false;
    for (int i = 0; i < m; i++) 
	{
        for (int l = 0; l < m; l++) 
		{
            if (matrix[l][i].used == 1) 
			{
                for (int j = 0; j < m; j++) 
				{
                    if (matrix[l][j].used == 2) 
					{
                        rows[l] = true;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        if (!flag) 
		{
            for (int l = 0; l < m; l++) 
			{
                if (matrix[l][i].used == 1) 
				{
                    columns[i] = true;
                    break;
                }
            }
        }
        flag = false;
    }
    int min = INT16_MAX;
    for (int i = 0; i < m; i++) 
	{
        for (int l = 0; l < m; l++) 
		{
            if (!rows[i] && !columns[l])
                if (min > matrix[i][l].data) 
					min = matrix[i][l].data;
        }
    }
	for (int i = 0; i < m; i++) {
        for (int l = 0; l < m; l++) {
            if (!rows[i] && !columns[l]) 
				matrix[i][l].data-= min;
            if (rows[i] && columns[l]) 
				matrix[i][l].data+= min;
            matrix[i][l].used = 0;
        }
    }
}
void func2(int**matrix,int m) // function which makes operations on matrix and calls several functions .
{
	int** spare_matrix = new int*[m];
	for (int i = 0; i < m; i++) 
	{
        spare_matrix[i] = new int[m];
        for (int l = 0; l < m; l++) 
        {
            spare_matrix[i][l] = matrix[i][l];
        }
    }
	func3(matrix,m);			// function func3() is called to print the matrix generated by rand() function on which operations are being done.
    cout << endl;
	cout <<"Matrix after deleting" << endl;
    func4(matrix, m);			//function func4() is called to substract the minimum element of a row from the respective elments of the same row
	func6(matrix,m);			//function func6() is called to substract the minimum element of a column from the respective elments of the same column
    func3(matrix ,m);
	point** final_matrix = func8(matrix, m);	// function func8() is called to initialise matrix.used in order to check whether it is used for assignment solution or not.
	if (!func14(final_matrix, m)) 
	{
        func15(final_matrix, m);
        func16(final_matrix, m);
    }
	int answer = func17(spare_matrix, final_matrix, m);
	cout << "Result: " << answer << endl;
}
void func1(int m)		// creates a matrix of m m and calls func2() which makes operations on that matrix
{
	srand(time(NULL));
    int** matrix = new int *[m];
    for (int i = 0; i < m; i++)  // creating a matrix on which operations are being done.
	{
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) 
		{
           matrix[i][j] = (rand() % 20) + 1;
        }
    }
    func2(matrix,m);
}
int main()					// calls func1() which is creating matrix
{
	int m = rand()%10 + 1;
	func1(m);
	return 0;
}