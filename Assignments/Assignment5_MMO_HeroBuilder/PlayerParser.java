// Assignment #: 5
//         Name: John Diri
//    StudentID: 1221905451
//      Lecture: 11:15-12:05
//  Description: This class takes in and reads the input from user and creates
//  the variables to pass to the parent class.

public class PlayerParser {
	private static String[] entityInfo = new String[6];
	public static PlayerEntity parseNewPlayer(String lineToParse) {
		entityInfo = lineToParse.split("/");
		if(entityInfo[0].compareToIgnoreCase("Fighter") == 0) {
			String newType = entityInfo[0];
			double newHealth = Integer.valueOf(entityInfo[1]);
			String newName = entityInfo[2];
			int newSta = Integer.valueOf(entityInfo[3]);
			int newAtk = Integer.valueOf(entityInfo[4]);
			boolean newVer;
			if(entityInfo[5].compareToIgnoreCase("Range") == 0) {
				newVer = true;
			}
			else {
				newVer = false;
			}
			Fighter newHero = new Fighter(newHealth,newName,newSta,newAtk,newVer);
			return newHero;
		}
		else {
			String newType = entityInfo[0];
			double newHealth = Integer.valueOf(entityInfo[1]);
			String newName = entityInfo[2];
			int newSta = Integer.valueOf(entityInfo[3]);
			int newAtk = Integer.valueOf(entityInfo[4]);
			double newMana = Double.valueOf(entityInfo[5]);
			Mage newHero = new Mage(newHealth,newName,newSta,newAtk,newMana);
			return newHero;
		}
	}
}
