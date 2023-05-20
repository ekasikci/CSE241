package hw8;

import java.awt.Color;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;


/**
 * 
 * @author ekasi
 */
public class HW8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        CellState[][] board;
        BoardTypes boardT = new BoardTypes();
        board = boardT.getboard1();
        
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(640, 640);
        
        
        JPanel back = new JPanel();
        back.setBackground(Color.black);
        back.setBounds(0,0,640,640);
        
        
        
        back.setLayout(new GridLayout());
        Jbuttons jButtons = new Jbuttons(board);
        RadioButtons radioButtons = new RadioButtons(jButtons);
        radioButtons.setRadioButtons(frame);
        jButtons.setJbuttons(frame);
        jButtons.setJbuttons2(frame);
        frame.add(back);
        frame.setVisible(true);
    }  
}

