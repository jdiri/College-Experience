// Assignment #: 5
//         Name: John Diri
//    StudentID: 1221905451
//      Lecture: 11:15-12:05
//  Description: subclass of player entity to create a different type of hero with different instance variables

import java.text.DecimalFormat;

public class Fighter extends PlayerEntity{
	private double armor;
	private int maxAttack;
	private boolean isRanged;
	private String ranged;
	
	DecimalFormat fmt = new DecimalFormat("00%");
	
	public Fighter(double health, String name, int stamina, int attack, boolean isRanged) {
		super(health, name, stamina, attack);
		this.isRanged = isRanged;
		if(this.isRanged == true) {
			armor = .25;
			maxAttack = 125;
			ranged = "Ranged Type";
		}
		else {
			armor = .5;
			maxAttack = 100;
			ranged = "Melee Type";
		}	
	}

	public void computeCombatPower() {
		if(maxAttack <= atk) {
			combatPT = (int)((maxAttack + health) * (1 - armor));
		}
		else {
			combatPT = (int)((atk + health) * (1 - armor));
		}
	}
	
	public String toString() {
		return "\nFighter Hero:\t\t" + ranged 
				+ super.toString() + "Armor:\t\t\t" + fmt.format(armor) + "\n\n\n";
	}
}
