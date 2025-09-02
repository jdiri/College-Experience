package pack;

import java.util.ArrayList;
import java.util.Comparator;

public class Sorts{
	
	public static void sort(ArrayList<Restuarant> reviewList, Comparator<Restuarant> xComparator) {
		//private static final long serialVersionUID = 205L;
		Restuarant temp;
		for(int i = 0; i<reviewList.size()-1;i++) {
			if(xComparator.compare(reviewList.get(i), reviewList.get(i+1)) < 0) {
				temp = reviewList.get(i);
				reviewList.set(i, reviewList.get(i+1));
				reviewList.set(i+1, temp);
			}
			i++;
		}

	}

}
