package hw8;

import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

/**
 *
 * @author ekasi
 */
public class PegClass implements PegSolitaireGame {

    class Cell {
        
        /**
         * Default Cell constructor. Makes cellType A(absent)
         */
        Cell()
        {
            cellType = CellState.A;
        }
        

        /**
         * 
         * @param x cell type
         * @param y row value
         * @param z column value
         */
        Cell(CellState x, int y, int z)
        {
            cellType = x;
            row = y;
            column = z;
        }
        
        /**
         * 
         * @return row value
         */
        public int getRow()
        {
            return row;
        }
        /**
         * 
         * @return column value
         */
        public int getColumn()
        {
            return column;
        }
        
        /**
         * 
         * @return cell type
         */
        public CellState getcellType()
        {
            return cellType;
        }
        
        public void setcellType(CellState x)
        {
            cellType = x;
        }
        
        /**
         * equals method overriding
         * @param x CellState to compare
         * @return true if x equals cellType otherwise false
         */
        public boolean equals (CellState x)
        {
            if (cellType == x) return true;
            
            return false;
        }
        
        
        private CellState cellType;
        private int row, column;
    }
    
    /**
     * default constructor
     */
    PegClass()
    {
        currentPegs = 0;
        totalPegs = 0;
    }
    
    /**
     * 
     * @param x double dimensional CellState
     */
    PegClass(CellState x[][])
    {
        board = new Cell[x.length][x[0].length];
        
        for(int i = 0; i < x.length; ++i)
        {
            for(int j = 0; j < x[0].length; ++j)
            {
                board[i][j] = new Cell(x[i][j], i, j);
                if (board[i][j].getcellType() == CellState.P) ++totalPegs;
            }
        }
        currentPegs = totalPegs; 
    }
    
    /**
     * 
     * @param x double dimensional CellState
     * @param y total pegs value
     */
    PegClass(CellState x[][], int y)
    {
        var newBoard = new CellState[x.length][x[0].length];
        
        for(int i = 0; i < x.length; ++i)
        {
            for(int j = 0; j < x[0].length; ++j)
            {
                board[i][j] = new Cell(x[i][j], i, j);
                if (board[i][j].getcellType() == CellState.P) ++currentPegs;
            }
        }
        totalPegs = y; 
    }
    
    /**
     * 
     * @return clone Object
     * @throws CloneNotSupportedException 
     */
    @Override
    public Object clone() throws CloneNotSupportedException
    {
        var newBoard = new CellState[this.board.length][this.board[0].length];
      
        for(int i = 0; i < this.board.length; ++i)
        {
            for(int j = 0; j < this.board[0].length; ++j)
            {
                newBoard[i][j] = this.board[i][j].getcellType();
            }
        }
        
        PegClass toReturn = new PegClass(newBoard);
        toReturn.totalPegs = this.totalPegs;
        
        return toReturn;
    }
    
    /**
     * 
     * @param x first cell
     * @param y second cell
     * @return true if the movement is valid otherwise false
     */
    public boolean move(Cell x, Cell y)
    {
        if ((x.getcellType() == CellState.P && y.getcellType() == CellState.E) && (x.getRow() == y.getRow()))
        {
            if ((x.getColumn() - y.getColumn() == 2) && board[x.getRow()][x.getColumn() - 1].getcellType() == CellState.P)
            {
                x.setcellType(CellState.E);
                y.setcellType(CellState.P);
                board[x.getRow()][x.getColumn() - 1].setcellType(CellState.E);
                return true;
            }
            else if ((x.getColumn() - y.getColumn() == -2) && board[x.getRow()][x.getColumn() + 1].getcellType() == CellState.P)
            {
                x.setcellType(CellState.E);
                y.setcellType(CellState.P);
                board[x.getRow()][x.getColumn() - 1].setcellType(CellState.E);
                return true;
            }
        }
        else if((x.getcellType() == CellState.P && y.getcellType() == CellState.E) && (x.getColumn() == y.getColumn()))
        {
            if ((x.getRow() - y.getRow() == 2) && board[x.getRow() - 1][x.getColumn()].getcellType() == CellState.P)
            {
                x.setcellType(CellState.E);
                y.setcellType(CellState.P);
                board[x.getRow() - 1][x.getColumn()].setcellType(CellState.E);
                return true;
            }
            else if ((x.getRow() - y.getRow() == -2) && board[x.getRow() + 1][x.getColumn()].getcellType() == CellState.P)
            {
                x.setcellType(CellState.E);
                y.setcellType(CellState.P);
                board[x.getRow() + 1][x.getColumn()].setcellType(CellState.E);
                return true;
            }
        }   
        if (isEnded())
        {
            System.out.println("Game is over");
        }
        return false;
    }
    
    /**
     * Prints the number of the remeaning pegs
     */
    @Override
    public int outPegs()
    {
        return currentPegs;
    }
    
    /**
     * computer makes one move
     */
    @Override
    public void move()
    {
        int line1, column1,line2, column2, choice;
        boolean move_f = false;
        
        Random rand = new Random();

        while (!move_f)
        {  
            line1 = rand.nextInt(board.length);
            column1 =  rand.nextInt(board[0].length);
            line2 = rand.nextInt(board.length);
            column2 =  rand.nextInt(board[0].length);
            
            move_f = move(board[line1][column1], board[line2][column2]);
        }   
    }
    
    /**
     * Saves current game
     * @throws java.io.IOException
     */
    @Override
    public void saveGame() throws IOException
    {
        var file = new File("save_" + String.valueOf(gameNumber + 1) + ".txt");
        var fw = new FileWriter(file);
        var pw = new PrintWriter(fw);

	for (int i = 0; i < board.length; ++i)
        {
            for (int j = 0; j < board[i].length; ++j)
            {
                if(board[i][j].equals(CellState.P))
                    pw.printf("P");
                else if(board[i][j].equals(CellState.E))
                    pw.printf("E");
                else
                    pw.printf("A");
            }
        }     
        pw.close();
        
        ++gameNumber;
    }
    
    /**
     * Loads the saved games
     * @throws java.io.IOException
     */
    @Override
    public CellState[][] loadGame() throws IOException
    {
        var fr = new FileReader("save_" + String.valueOf(gameNumber + 1) + ".txt");
        int rRow, rColumn, rtotalPegs, i = 0, j = 0, t;
        char c;
        
        CellState newArray[][] = new CellState[board.length][board[0].length];
            
        while ((t = fr.read()) != -1)
        {
            switch ((char)t) {
                case 'P':
                    newArray[i][j] = CellState.P;
                    break;
                case 'E':
                    newArray[i][j] = CellState.E;
                    break;
                case 'A':
                    newArray[i][j] = CellState.A;
                    break;
                default:
                    break;
            }
            ++j;
            if (j == board[0].length)
            {
                j = 0;
                ++i;
            }
        }
        return newArray;
    } 
    
    /**
     * Return true if the game has ended
     */
    @Override
    public boolean isEnded()
    {
        for(int i = 0; i < board.length; i++) 
        {
            for(int j = 0; j < board[i].length - 1; j++)
                if ((board[i][j].getcellType() == CellState.P && board[i][j].getcellType() == board[i][j + 1].getcellType()) || 
                        (board[i][j].getcellType() == CellState.P && board[i][j].getcellType() == board[i + 1][j].getcellType()))
                return false;
        }
        return true;
    }
    
    /**
     * 
     * @param x row value
     * @param y column value
     * @return Cell at indicated place
     */
    public Cell getCell(int x, int y)
    {
        return board[x][y];
    }
    
    /**
     * 
     * @return row length of the objects board variable
     */
    public int rowlength()
    {
        return board.length;
    }
    
    /**
     * 
     * @return column length of the objects board variable
     */
    public int columnlength()
    {
        return board[0].length;
    }  
    
    private Cell board[][];
    
    private int totalPegs;
    private int currentPegs;
    private static int gameNumber = 0;
}
