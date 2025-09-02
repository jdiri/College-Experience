package pack;
import java.util.Comparator;

public class ReviewCuisineComparator implements Comparator<Restuarant>{
	@Override
	public int compare(Restuarant x, Restuarant y) {
		if(x.getCuisine().getName().compareToIgnoreCase(y.getCuisine().getName()) == 0) {
			if(x.getPriceRange() == y.getPriceRange()) {
				if(x.getName().compareToIgnoreCase(y.getName()) == 0) {
					if(x.getLocation().compareToIgnoreCase(y.getLocation())==0) {
						return -1;
					}
					else {
						//if(x.getLocation().compareToIgnoreCase(y.getLocation())==-1) {
							return x.getLocation().compareToIgnoreCase(y.getLocation());
						/*}
						else
							return y.getLocation().compareToIgnoreCase(x.getLocation());*/
					}
				}
				else {
					//if(x.getName().compareToIgnoreCase(y.getName()) == -1) {
						return x.getName().compareToIgnoreCase(y.getName());
					/*}
					else
						return y.getName().compareToIgnoreCase(x.getName());*/
				}
			}
			else {
				if(x.getPriceRange() < y.getPriceRange()) {
					return x.getPriceRange();
				}
				else
					return y.getPriceRange();
			}
		}
		else
			//if(x.getCuisine().getName().compareToIgnoreCase(y.getCuisine().getName()) == -1) {
				return x.getCuisine().getName().compareToIgnoreCase(y.getCuisine().getName());
			/*}
			else
				return y.getCuisine().getName().compareToIgnoreCase(x.getCuisine().getName());*/
	}
}
