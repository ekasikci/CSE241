package hw7;


import hw7.DayofYearSet.DayofYear;
import java.io.IOException;
import java.util.ArrayList;

/**
 * 
 * @author Ertugrul Kasikci
 */
public class HW7 {
    /**
     * 
     * @param args consol argument
     * @throws IOException exception 
     */
    public static void main(String[] args) throws IOException {	
        
        var doyAl = new ArrayList<DayofYear>();
        
        DayofYear[] doyA = new DayofYear[4];
        
        doyAl.add(new DayofYear(14,8));
        doyAl.add(new DayofYear(1,1));
        
        doyA[0] = new DayofYear(6,11);
        doyA[1] = new DayofYear(2,5);
        doyA[2] = new DayofYear(4,3);
        doyA[3] = new DayofYear(4,1);
        
	var s1 = new DayofYearSet();
        var s2 = new DayofYearSet(doyAl);
        var s3 = new DayofYearSet();
        var s4 = new DayofYearSet(doyA);
        
        
        
        System.out.println("s1:");
	s1.add(4,12);
	s1.add(14,8);
	s1.add(14,8); // duplication is not allowed
	s1.add(6, 1);
        s1.ToString();
        
        System.out.println("s2:");
	s2.add(14, 8);
        s2.add(1, 1);
        s2.ToString();
        
        System.out.println("s3:");
	s3.add(1,9);
	s3.add(3,1);
        s3.ToString();
        
        System.out.println("s4:");
	s4.add(6, 11);
	s4.add(2, 5);
	s4.add(4, 3);
	s4.add(4, 1);
        s4.ToString();    
        
        System.out.println("union set of s1 and s2:\n");
        (s1.union(s2)).ToString();
        
        System.out.println("difference set of s1 and s2:\n");
        (s1.difference(s2)).ToString();
        
        System.out.println("intersection set of s1 and s2:\n");
        (s1.intersection(s2)).ToString();
        
        System.out.printf("complement set of s1 ^ s2 has %d elements\n\n",((s1.intersection(s2)).complement()).size());
        
        System.out.printf("%d DayofYear objects has been created\n\n", s1.getTotalDayofYear());
        
        // does test 6 different pair of sets to see if De morgan rule is working
	if (((s1.union(s2)).complement()).equals((s1.complement().intersection(s2.complement())))&& // !(s1 + s2) == !s1 ^ !s2
            ((s1.union(s3)).complement()).equals((s1.complement().intersection(s3.complement())))&& // !(s1 + s3) == !s1 ^ !s3
            ((s1.union(s4)).complement()).equals((s1.complement().intersection(s4.complement())))&& // !(s1 + s4) == !s1 ^ !s4
            ((s2.union(s3)).complement()).equals((s2.complement().intersection(s3.complement())))&& // !(s2 + s3) == !s2 ^ !s3
            ((s2.union(s4)).complement()).equals((s2.complement().intersection(s4.complement())))&& // !(s2 + s4) == !s2 ^ !s4
            ((s3.union(s4)).complement()).equals((s3.complement().intersection(s4.complement()))))  // !(s3 + s4) == !s3 ^ !s4
            System.out.println("De Morgan rule is working\n");
        
        s1.printToFile("s1");
        s2.printToFile("s2");
        s3.printToFile("s3");
        s4.printToFile("s4");      
    }
}
