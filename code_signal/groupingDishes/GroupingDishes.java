import java.io.*;
import java.util.*;
import java.util.Enumeration;

public class GroupingDishes {

	public static class Compare implements Comparator<ArrayList<String> > {
	    public int compare(ArrayList<String> a, ArrayList<String> b){
	        return a.get(0).compareTo(b.get(0) );
	    }
	}

	public static void main (String[] args){
		String[][] test = { {"Salad","Tomato","Cucumber","Salad","Sauce"}, 
							   {"Pizza","Tomato","Sausage","Sauce","Dough"}, 
							   {"Quesadilla","Chicken","Cheese","Sauce"}, 
							   {"Sandwich","Salad","Bread","Tomato","Cheese"} };
		String[][] res = groupingDishes(test);
		for(int i = 0 ; i < res.length ; i++){
			System.out.println();
			for(int j = 0 ; j < res[i].length ; j++){
				System.out.println(res[i][j] );
			}
		}
	}

	public static String[][] groupingDishes(String[][] dishes) {
	    Hashtable<String, HashSet<String> > res = new Hashtable<String, HashSet<String> >();
	    for(int i = 0 ; i < dishes.length ; i++){
	        for(int j = 1 ; j < dishes[i].length ; j++){
	        	if(res.get(dishes[i][j]) == null){
		            res.put(dishes[i][j], new HashSet<String>() );   
		        	res.get(dishes[i][j]).add(dishes[i][0]);
	        	}

		        else{
			        res.get(dishes[i][j]).add(dishes[i][0]);
		        }
	    	}
	    }
		
		ArrayList<ArrayList<String> > list = new ArrayList<ArrayList<String> >();
		Enumeration<String> e = res.keys();
		ArrayList<String> temp;
		String key;
		while(e.hasMoreElements() ){
			key = e.nextElement();
			if(res.get(key).size() >= 2){
				temp = new ArrayList<String>();
				temp.add(key);
				// https://howtodoinjava.com/java/sort/collections-sort/
				ArrayList<String> temp1 = new ArrayList<String>(res.get(key) );
				Collections.sort(temp1);
				temp.addAll(temp1);
				list.add(temp);
			}
		}
		// https://howtodoinjava.com/java/sort/collections-sort/
		Collections.sort(list, new Compare() );

		// https://stackoverflow.com/questions/36810443/two-dimensional-array-with-different-lengths-java
		String[][] arr = new String[list.size() ][];
		for(int i = 0 ; i < list.size() ; i++){
			arr[i] = new String[list.get(i).size() ];
			for(int j = 0 ; j < list.get(i).size() ; j++){
				arr[i][j] = list.get(i).get(j);
			}
		}
		
		return arr;
	}

}