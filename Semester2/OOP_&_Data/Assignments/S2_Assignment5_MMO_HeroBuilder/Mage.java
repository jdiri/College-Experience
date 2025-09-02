// Assignment #: 5
//         Name: John Diri
//    StudentID: 1221905451
//      Lecture: 11:15-12:05
//  Description: subclass of player entity to create a different type of hero with different instance variables

import java.text.DecimalFormat;
public class Mage extends PlayerEntity{
	DecimalFormat fmt = new DecimalFormat("00%");
	
	private double mana;
	
	public Mage(double health, String name, int stamina, int attack, double mana) {
		super(health,name,stamina,attack);
		this.mana = mana;
	}
	
	 public void computeCombatPower() {
		 combatPT = (int)((atk + health) * (1 + mana));		 
	 }
	 
	 public String toString() {
		 return "\nMage Hero:" + super.toString() 
		 	+ "Mana:\t\t\t" + fmt.format(mana) + "\n\n\n";
	 }
}
