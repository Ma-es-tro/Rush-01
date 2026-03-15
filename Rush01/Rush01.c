#include <unistd.h>
#include <stdlib.h>



void	grid_init(char *str, int *clues)
{
    int i = 0;
    int count = 0;
    
    while (str[count] != '\0')
    {
        if (str[count] != ' ')
        {
            clues[i] = str[count] - 48;
            i++;
        }
        count++;
    }
}

int count_visible(int *line, int size)
{
    int count = 0;
    int max_so_far = 0;
    int i = 0;
    
    while (i < size)
    {
        if (line[i] > max_so_far)
        {
            count++;
			max_so_far = line[i];
        }
        i++;
    }
    return count;
}

int check_clues(int grid[4][4], int *clues)
{
    int i;
    int j;
    int reversed[4];

    // check LEFT clues 
    i = 0;
    while (i < 4)
    {
        if (count_visible(grid[i], 4) != clues[8 + i])
		{
			 return 0;
		}   
        i++;
    }

    // check RIGHT 
    i = 0;
    while (i < 4)
    {
        // fill reversed with grid[i] backwards
        j = 0;
        while (j < 4)
        {
            reversed[j] = grid[i][3 - j];  // hint: if j=0 you want grid[i][3], if j=1 you want grid[i][2]...
            j++;
        }
        if (count_visible(reversed, 4) != clues[12 + i])
            return 0;
        i++;
    }

    // check TOP clues 
    i = 0;
    while (i < 4)
    {
        // extract column i into temp array
        int col[4];
        j = 0;
        while (j < 4)
        {
            col[j] = grid[j][i];  // hint: you want each row of column i
            j++;
        }
        if (count_visible(col, 4) != clues[i])
            return 0;
        i++;
    }

	//Bottom
	i = 0;
    while (i < 4)
    {
        int col[4];
        j = 0;
        while (j < 4)
        {
            reversed[j] = grid[3 - j][i]; 
			j++;
        }
        if (count_visible(reversed, 4) != clues[4 + i])
            return 0;
        i++;
    }

    return 1;  // all clues passed!
}

int is_valid(int grid[4][4], int row, int col, int num)
{
    int i;
    
    i = 0;
    while (i < col)  // check current row
    {
        if (grid[row][i] == num)
            return 0;  // num already in this row
        i++;
    }
    i = 0;
    while (i < row)  
    {
        if (grid[i][col] == num)
            return 0;  
        i++;
    }
    return 1;  
}

void prt_grid(int grid[4][4])
{
	char c;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if(j < 3)
			{
				write(1, " ", 1);
			}
		}
		write(1, "\n", 1);
	}
}

int	grid_gen(int grid[4][4], int row, int col, int *clues)
{
    int next_row;
    int next_col;
    
    if (row == 4)
    {
        if(check_clues(grid, clues))
		{
			prt_grid(grid);
			return 1;
		}
        return 0;
    }
    if (col == 3)
    {
        next_row = row + 1;
        next_col = 0;
    }
    else
    {
        next_row = row;
        next_col = col + 1;
    }
    for (int num = 1; num <= 4; num++)
    {
        if (is_valid(grid, row, col, num))
        {
            grid[row][col] = num;
			if(grid_gen(grid, next_row, next_col, clues))
			{
				return 1;
			}
            grid[row][col] = 0;
        }
    }

	return 0;
}

int main(int argc, char **argv)
{

	if(argc != 2)
	{
		return 1;
	}

    int *clues = malloc(16 * sizeof(int));
    int grid[4][4] = {0};  
    
    grid_init(argv[1], clues);
	if(!grid_gen(grid, 0, 0, clues))
	{
		write(1, "Error\n", 6);
	}
    free(clues);
    return 0;
}