import java.io.*;
import java.util.*;

class Test {
	
	public static void main (String[] args){
		groupingDishes();
	}

	public static void groupingDishes() {
		ArrayList<String> a = new ArrayList<String>();
		a.add("c");
		a.add("b");
		a.add("a");
		Collections.sort(a);
		System.out.println(a);
	}

}