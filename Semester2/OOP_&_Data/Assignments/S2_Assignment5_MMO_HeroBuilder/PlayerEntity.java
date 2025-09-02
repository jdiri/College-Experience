// Assignment #: 5
//         Name: John Diri
//    StudentID: 1221905451
//      Lecture: 11:15-12:05
//  Description: this is the parent class to all heros
public abstract class PlayerEntity {
	protected Double health;
	protected String entityName;
	protected int combatPT, atk, sta;
	
	//Constructor
	public PlayerEntity(double health, String name, int stamina, int attack) {
		this.health = health;
		entityName = name;
		sta = stamina;
		atk = attack;
	}
	
	//getter
	public int getCombatPoints() {
		return combatPT;
	}
	
	//used by fighter and mage class to update combat points
	public abstract void computeCombatPower();
	
	//to string
	public String toString() {
		return "\nHero name:\t\t" + entityName + "\n"
				+ "Current Health:\t\t" + health + "\n"
				+ "Stamina:\t\t" + sta + "\n"
				+ "Attack Damage:\t\t" + atk + "\n"
				+ "Current Combat Points:\t" + combatPT + "\n";
	}
}
