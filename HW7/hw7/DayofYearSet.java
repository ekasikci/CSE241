package hw7;

import java.io.*;
import java.util.ArrayList;
/**
 * 
 * @author Ertugrul Kasikci
 */

public class DayofYearSet {
    
    /**
     * This is a static inner class
     */
    public static class DayofYear{
        
        /**
         * default constructor 
         * 0 values will not be tought as a day
         */
        public DayofYear ()
        {
             day = 0; month = 0;
             ++totalDayofYear;
        }
        /**
         * construsctor that takes just day value
         * @param dayV this value is going to be converted day and month  
         */
        public DayofYear (int dayV) // constructor takes just day and converts is to day and month
        {
            if (dayV < 1 || dayV > 365)
                return;
        
            int monthV = 0;
            
            if(dayV > 0 && dayV < 32) monthV = 1;
            else if( dayV > 31 && dayV < 60 ) {monthV = 2; dayV -= 31;} 
            else if( dayV > 59 && dayV < 91 ) {monthV = 3; dayV -= 59;}
            else if( dayV > 90 && dayV < 121 ) {monthV = 4; dayV -= 90;}
            else if( dayV > 120 && dayV < 152 ) {monthV = 5; dayV -= 120;}
            else if( dayV > 151 && dayV < 182 ) {monthV = 6; dayV -= 151;}
            else if( dayV > 181 && dayV < 213 ) {monthV = 7; dayV -= 181;}
            else if( dayV > 212 && dayV < 244 ) {monthV = 8; dayV -= 212;}
            else if( dayV > 243 && dayV < 274 ) {monthV = 9; dayV -= 243;}
            else if( dayV > 273 && dayV < 305 ) {monthV = 10; dayV -= 273;}
            else if( dayV > 304 && dayV < 335 ) {monthV = 11; dayV -= 304;}
            else if( dayV > 334)  {monthV = 12; dayV -= 334;}
          
            day = dayV; month = monthV;
            ++totalDayofYear;
        }
        /**
         * cınstructor that takes both day and month values
         * @param dayV day parameter
         * @param monthV month parameter
         */
        public DayofYear (int dayV, int monthV)
        {
            if (monthV < 1 || monthV > 12)
                return;
        
            if (dayV < 1 || dayV > 31) 
                return;
            day = dayV; month = monthV;
            ++totalDayofYear;
        }
        
        /**
         * this function returns static variavle that indicates total number of DayofYear object that has been created
         * @return int 
         */
        public static int igetTotalDayofyear() // returns number of DayofYear objects alive;
        {
            return totalDayofYear;
        }
        /**
         * overloaded finalize function. decreases totalDayofYear variable by one
         */
        protected void finalize() // decreases totalDayofYear object variable by one because one of them has been deleted
        {
            --totalDayofYear;
            System.gc(); // Calls garbage collecter to get accurate result when getting number of DayofYear objects
        }
        /**
         * returns day value
         * @return day value
         */
        public int getday()
        {
            return day;
        }
        /**
         * Takes month variable and converts it to a string
         * @return month string
         */
        private String monthtoString() // converts int month value to a string
        {
            switch (month)
            {
                case 1: return "January";
                case 2: return "February";
                case 3: return "March";
                case 4: return "April";
                case 5: return "May";
                case 6: return "June";
                case 7: return "July";
                case 8: return "August";
                case 9: return "September";
                case 10: return "October";
                case 11: return "November";
                case 12: return "December";            
            }
            return "";
        }   
        private int month, day, size, currentLoc;
	private static int totalDayofYear = 0;
    }
    
    /**
     * default constructor
     */
    public DayofYearSet()
    {
        days = new DayofYear[365];
        currentLoc = 0;
    }
    /**
     * constructor that takes array of DayofYear object
     * @param x array parameter
     */
    public DayofYearSet(DayofYear[] x)
    {    
        days = new DayofYear[365];
        for (int i= 0; i < x.length ; ++i)
        {  
            if(x[0].day != 0)
            {
               days[i] = x[i];
               ++currentLoc;
            }              
        }
        days = x;
    }
    /**
     * constructor that takes ArrayList of DayofYear object
     * @param x ArrayList parameter
     */
    public DayofYearSet(ArrayList<DayofYear> x)
    {    
        days = new DayofYear[365];

        for (int i = 0; i < x.size() ; ++i)
        {  
            
            days[i] = new DayofYear(x.get(i).day, x.get(i).month);
               ++currentLoc;
        }
    }
    /**
     * takes day and month values and creates object with them, then adds this object at the end of the DayofYear array
     * @param dayV day parameter
     * @param monthV month parameter
     */
    public void add(int dayV, int monthV)
    {
        if (monthV < 1 || monthV > 12)
            return;
        
        if (dayV < 1 || dayV > 31)  
            return;
        var x = new DayofYear(dayV, monthV);
        
        for(int i = 0; i < currentLoc; ++i) // avoids rewriting the same value
        {
            if( this.days[i].day == dayV && this.days[i].month == monthV)
                return;
        }
        days[currentLoc] = x;
        ++currentLoc;
        
        setOrder(this); // shorts DayofYear objects to keep them ordered
    }
    /**
     * removes DayofYear object from end of the DayofYear array
     */
    public void remove() // removes the day at the end of the set
    {
        this.days[currentLoc] = null;
        --currentLoc;
    }
    /**
     * removes DayofYear object from indicated location by x parameter
     * @param x the location that indicates index that points the DayofYear object that is going to be removed
     */
    public void remove(int x) // removes the day at the pointed location
    {
        if (x < currentLoc && x >= 0)
            for(int i = x; i < currentLoc - 1; ++i)
            {
                this.days[i] = this.days[i + 1];
            }
        
        this.days[currentLoc - 1] = null;
        --currentLoc;
    }
    /**
     * 
     * @return size of current array
     */
    public int size() // returns size of the set
    {
        return currentLoc; 
    }
    /**
     * takes one object and make that object and calling object union then returns object
     * @param x a set that is going to be union with calling object
     * @return union set of calling object and x object
     */
    public DayofYearSet union(DayofYearSet x)
    {
        var toReturn = new DayofYearSet();
        
        for (int i = 0; i < this.size(); ++ i)
            toReturn.add(this.days[i].day, this.days[i].month);
       
        for (int i = 0; i < x.size(); ++ i)
            toReturn.add(x.days[i].day, x.days[i].month);

        return toReturn;
    }
    /**
     * takes one object and removes the DayofYear objects from calling object that are present in taken object
     * @param x a set that is going to be removed from calling object
     * @return difference set of calling object and x object
     */
    public DayofYearSet difference(DayofYearSet x)
    {
        var toReturn = new DayofYearSet();
        
        boolean flag = true;
        
        for (int i = 0; i < this.size(); ++ i)  
        {
            for (int j = 0; j < x.size(); ++ j)
            {
                if ( (this.days[i].day == x.days[j].day && this.days[i].month == x.days[j].month) )
                {
                    flag = false;
                    break;
                }
            }
            if (flag) toReturn.add(this.days[i].day, this.days[i].month);
            flag = true;
        }
        return toReturn;   
    }
    /**
     * takes one object and make that object and calling object intersect then returns new object
     * @param x a set that is going to be intersect with calling object
     * @return intersection set of calling object and x object
     */
    public DayofYearSet intersection(DayofYearSet x) // returns intersection set of calling object and x object
    {
        var toReturn = new DayofYearSet();
        
        for (int i = 0; i < this.size(); ++ i)  
        {
            for (int j = 0; j < x.size(); ++ j)
            {
                if ( (this.days[i].day == x.days[j].day && this.days[i].month == x.days[j].month) )
                {
                    toReturn.add(this.days[i].day, this.days[i].month);
                    break;
                }
            }
        }       
        return toReturn;
    }
    /**
     * 
     * @return complement set of calling object
     */
    public DayofYearSet complement() // returns complement set of calling object
    {
        var temp = new DayofYearSet();
        for(int i = 0; i < 365; ++i)
        {
            temp.days[i] = new DayofYear(i + 1);
            ++temp.currentLoc;
        }
        return temp.difference(this);
    }
    /**
     * prints all objects in the array with specified style
     * @return trivia string
     */
    public String ToString() // Prints days in the set
    {
        for(int i = 0; i < currentLoc; ++i)
            System.out.printf("%d. day is %d %s\n", i + 1, this.days[i].day, this.days[i].monthtoString());
        
        System.out.println("\n");
        return String.format("");
    }
    /**
     * checks if the calling object and x are equal by comparing every object in their array
     * @param x parameter to be compared with calling object
     * @return bool value
     */
    public Boolean equals(DayofYearSet x)
    {
        if(this.currentLoc != x.currentLoc)
            return false;
        else
        {
            boolean flag = false;
            for(int i = 0; i < this.currentLoc; ++i)
            {
                for(int j = 0; j < x.currentLoc; ++j)
                {
                    if (this.days[i].day == x.days[j].day && this.days[i].month == x.days[j].month)
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag == false) return false;
            }
            return true;
        }
    }
    /**
     * 
     * @return total DayofYear object that has been created
     */
    public int getTotalDayofYear()
    {
        return this.days[0].igetTotalDayofyear();
    }
    /**
     * prints the objects information in a file that named with calling object
     * @param name calling variables name
     * @throws IOException exception
     */
    public void printToFile(String name) throws IOException
    {
	var file = new File(name + ".txt");
        var fw = new FileWriter(file);
        var pw = new PrintWriter(fw);

	for (int i = 0; i < size(); ++i)
            pw.printf("%d. element is: %d %s\n", i+1, this.days[i].day, this.days[i].monthtoString());
        pw.close();
    }
    /**
     * Sorts the days of the array to get a set
     * @param x the object that is going to be ordered
     */
    private void setOrder(DayofYearSet x)
    {
        var temp = new DayofYear();
        for (int i = 0; i < x.size(); ++ i)  
        {
            for (int j = i + 1; j < x.size(); ++ j)
            {
                if ( ( x.days[i].month > x.days[j].month ) || ( x.days[i].month == x.days[j].month && x.days[i].day > x.days[j].day ) )
                {
                    temp = x.days[j];
                    for (int k = j; k > i; --k)
                    {
                        x.days[k] = x.days[k - 1];
                    }               
                    x.days[i] = temp;
                    break;
                }
            }
        }     
    }  
    private DayofYear[] days;
    private int currentLoc = 0;
}
