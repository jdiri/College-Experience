// Assignment #: 10
//         Name: John Diri
//    StudentID: 1221905451
//      Lecture: 11:15-12:05
//  Description: linked lists

public class LinkedList {
    Table first;
    int size;
    public LinkedList(){
        first = null;
        size = 0;
    }

    public void add(int numberOfGuests, String name){
        Table newGuest = new Table(numberOfGuests, name);
        if(first == null){
            first = newGuest;
        }
        else{
            Table pointer = first;
            while(pointer.next != null)
                pointer = pointer.next;

            pointer.next = newGuest;
        }
        size++;
    }
    
    public Table removeFirst() {
    	Table temp = first;
    	if(first == null) {
    		return new Table.EmptyTable();
    	}
    	else {
    		first = first.next;
    		size--;
    		return temp;
    	}
    	
    }
    
    public Table removeLast() {
    	Table pointer = first;
    	while(pointer.next != null) {
	   		pointer = pointer.next;		
    	}
    	for(int i = 0;i<getPosition(pointer.name);i++) {
    		first = pointer;
    		pointer = pointer.next;
    	}
    	first.next = null;
    	return pointer;
    }
    
    public int getPosition(String name) {
    	Table temp = first;
    	int i = 0;
    	while(temp.next != null) {
    		if(temp.name.compareToIgnoreCase(name) == 0) {
    			return i;
    		}
    		temp = temp.next;
    		i++;
    	}
    	return -1;
    }
    
    public Table removeMiddle(String name) {
    	Table temp;
    	if(getPosition(name) <= 0) {
    		for(int i = 0; i<getPosition(name);i++) {
    			if(i == getPosition(name)-1) {
    				first.next=first.next.next;
    				if(i == getPosition(name)) {
    					temp = first;
    					first = null;
    					size--;
    					return temp;
    				}
    			}
    		}
    	}
    	return new Table.EmptyTable();
    }
    
    public Table removeGuest(String name) {
    	if(size == 0) {
    		return new Table.EmptyTable();
    	}
    	if(getPosition(name)==0) {
    		return removeFirst();
   		}
    	if(getPosition(name)==size) {
    		return removeLast();
    	}
    	else
    		return removeMiddle(name);
    }
    
    public int getNumberOfParties(int number) {
    	int total = 0;
    	Table temp = first;
    	while(temp != null) {
    		if(temp.guests==number) {
    			total++;
    			temp = temp.next;
    		}
    		else
    			temp = temp.next;
    		/*if(first.next.guests==number) {
    			total++;
    			first = first.next;
    		}
    		if(first.next.next==null) {
    			if(first.next.guests==number) {
    				total++;
    			}
    		}*/
    	}
    	return total;
    }
    
    public String listReservations() {
    	Table temp = first;
    	int i = 0;
    	String s = "";
    	if(size == 0) {
    		return "No reservations in queue at this time\\n";
    	}
    	else if(size == 1) {
    		return temp.toString() + "\nTotal reservations: " + size + ".\n";
    	}
    	else {
    		while(i<size) {
    			s =  s + temp.toString();
    			temp = temp.next;
    			i++;
    		}
    		return s + "\nTotal reservations: " + size + ".\n";
    	}
    		
    }
}
