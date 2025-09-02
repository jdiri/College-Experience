package pack;

import java.util.Comparator;

public class ReviewRatingComparator implements Comparator<Restuarant> {
	@Override
	public int compare(Restuarant x, Restuarant y) {
		if(x.getStars() != y.getStars()) {
			return x.getStars()-y.getStars();
		}
		else 
			if(x.getName().compareToIgnoreCase(y.getName()) == -1)
			return x.getName().compareToIgnoreCase(y.getName());
			else {
				return y.getName().compareToIgnoreCase(x.getName());
			}
	}

}